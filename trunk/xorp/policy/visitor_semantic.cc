// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2008 XORP, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/policy/visitor_semantic.cc,v 1.20 2008/08/06 08:18:31 abittau Exp $"

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#include <sstream>

#include "policy_module.h"
#include "libxorp/xorp.h"
#include "libxorp/debug.h"
#include "policy/common/elem_null.hh"
#include "visitor_semantic.hh"
#include "policy_map.hh"

VisitorSemantic::VisitorSemantic(SemanticVarRW& varrw, 
				 VarMap& varmap,
				 SetMap& setmap,
				 PolicyMap& pmap,
				 const string& protocol, 
				 PolicyType ptype) : 
		_varrw(varrw), _varmap(varmap), _setmap(setmap), _pmap(pmap),
		_protocol(protocol), _ptype(ptype) 
{
}

const Element* 
VisitorSemantic::visit(PolicyStatement& policy)
{
    do_policy_statement(policy);

    // helps for garbage gollection in varrw
    _varrw.sync();

    return NULL;
}

void
VisitorSemantic::do_policy_statement(PolicyStatement& policy)
{
    PolicyStatement::TermContainer& terms = policy.terms();
    PolicyStatement::TermContainer::iterator i;

    // go through all terms
    for (i = terms.begin(); i != terms.end(); ++i)
	(i->second)->accept(*this);
}

const Element* 
VisitorSemantic::visit(Term& term)
{
    Term::Nodes& source = term.source_nodes();
    Term::Nodes& dest = term.dest_nodes();
    Term::Nodes& actions = term.action_nodes();

    Term::Nodes::iterator i;

    _current_protocol = "";
    // assume import policy, so set protocol to whatever protocol instantiated
    // the policy
    change_protocol(_protocol);

    // go through the source block
    bool empty_source = true;
    debug_msg("[POLICY] source size: %u\n", XORP_UINT_CAST(source.size()));
    for (i = source.begin(); i != source.end(); ++i) {
        (i->second)->accept(*this);
	empty_source = false;
    }

    // if it was an export policy maybe varrw was switched to some other
    // protocol during source match, so replace it with original protocol.
    change_protocol(_protocol);

    // if it is an export policy, a source protocol must be specified [XXX: need
    // to fix this]
    if (_ptype == EXPORT && _current_protocol == "") {
	// Currently, allow empty source blocks... which means:
	// if something manages to get to the export filter, then match it.
	if (!empty_source) {
	    string err = "No protocol specified in source match of export policy";

	    err += " in term: " + term.name();

	    xorp_throw(sem_error, err);
	}
    }

    // import policies should not have dest blocks
    if (_ptype == IMPORT && !(dest.empty())) {
	xorp_throw(sem_error, "Invalid use of dest in import policy in term " + 
		   term.name());
    }

    // check dest block
    for (i = dest.begin(); i != dest.end(); ++i) {
         (i->second)->accept(*this);

    }

    // check actions
    for (i = actions.begin(); i != actions.end(); ++i) {
         (i->second)->accept(*this);
    }
    return NULL;
}
    
const Element* 
VisitorSemantic::visit(NodeUn& node)
{
    // check argument
    const Element* arg = node.node().accept(*this);

    Element* res;
   
    // see if we may execute unary operation
    try {
	res = _disp.run(node.op(),*arg);

	if (res->refcount() == 1)
	    _trash.insert(res);

	return res;
    } 
    // we can't
    catch (const PolicyException& e) {
	ostringstream error;

	error << "Invalid unop " << e.str() << " at line " << node.line();
	xorp_throw(sem_error, error.str());
    }
}

const Element* 
VisitorSemantic::visit(NodeBin& node)
{
    // check arguments
    const Element* left = node.left().accept(*this);
    const Element* right = node.right().accept(*this);

    return do_bin(*left, *right, node.op(), node);
}

const Element*
VisitorSemantic::do_bin(const Element& left, const Element& right,
			const BinOper& op, const Node& node)
{
    // see if we may execute bin operation.
    try {
	Element* res = _disp.run(op, left, right);

	if (res->refcount() == 1)
	    _trash.insert(res);

	return res;
    }
    // nope
    catch (const PolicyException& e) {
        ostringstream error;

        error << "Invalid binop " << e.str() << " at line " << node.line();
    
        xorp_throw(sem_error, error.str());
    }
}

const Element* 
VisitorSemantic::visit(NodeAssign& node)
{
    // check argument
    const Element* rvalue = node.rvalue().accept(*this);

    // try assignment
    try {
	VarRW::Id id = _varmap.var2id(semantic_protocol(), node.varid());

	// see if there's a modifier to the assignment
	if (node.mod()) {
	    const Element* left = &_varrw.read(id);

	    rvalue = do_bin(*left, *rvalue, *node.mod(), node);
	}

	_varrw.write(id, *rvalue);
    } catch (SemanticVarRW::var_error e) {
        ostringstream error;

        error << e.str() << " at line " << node.line();

        xorp_throw(sem_error, error.str());
    }
    return NULL;
}

const Element* 
VisitorSemantic::visit(NodeVar& node)
{
    // try reading a variable
    try {
	VarRW::Id id = _varmap.var2id(semantic_protocol(), node.val());
	return &_varrw.read(id);
    } catch(SemanticVarRW::var_error e) {
        ostringstream error;

        error << e.str() << " at line " << node.line();
    
        xorp_throw(sem_error, error.str());
    }
}
    
const Element* 
VisitorSemantic::visit(NodeSet& node)
{
    // try getting a set [setdep should have caught there errors]
    try {
	const Element& e = _setmap.getSet(node.setid());
	_sets.insert(node.setid());
	return &e;
    } catch(const PolicyException& e) {
        ostringstream error;
        error << "Set not found: " << node.setid() << " at line " << node.line();
    
        xorp_throw(sem_error, error.str());
    }
}

const Element* 
VisitorSemantic::visit(NodeElem& node)
{
    return &node.val();
}

const Element* 
VisitorSemantic::visit(NodeAccept& /* node */)
{
    return NULL;
}

const Element* 
VisitorSemantic::visit(NodeReject& /* node */)
{
    return NULL;
}

const Element* 
VisitorSemantic::visit(NodeProto& node)
{
    ostringstream err;

    // import policies may not use protocol directive
    if(_ptype == IMPORT) {
	err << "May not define protocol for import policy at line " <<
        node.line();
        
        xorp_throw(sem_error, err.str());
    }

    string proto = node.proto();
    

    // check for redifinition in same term.
    if(_current_protocol != "") {
        err << "Redifinition of protocol from " << _current_protocol << 
	    " to " << proto << " at line " << node.line();
    
        xorp_throw(sem_error, err.str());
    }

    // do the switch
    _current_protocol = proto;
    // make the varrw emulate the new protocol
    change_protocol(_current_protocol);
    return NULL;
}

void
VisitorSemantic::change_protocol(const string& proto)
{
    _semantic_protocol = proto;
    _varrw.set_protocol(_semantic_protocol);
}

const string&
VisitorSemantic::semantic_protocol()
{
    return _semantic_protocol;
}

const Element*
VisitorSemantic::visit(NodeNext& /* node */)
{
    return NULL;
}

const Element*
VisitorSemantic::visit(NodeSubr& node)
{
    // XXX check for recursion.
    PolicyStatement& policy = _pmap.find(node.policy());

    string proto = _protocol;
    do_policy_statement(policy);
    change_protocol(proto);

    return NULL;
}
