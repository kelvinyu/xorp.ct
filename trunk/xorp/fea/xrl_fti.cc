// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
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

#ident "$XORP: xorp/fea/xrl_fti.cc,v 1.3 2003/03/18 01:01:30 pavlin Exp $"

#include "xrl_fti.hh"

static const char* FTI_MAX_OPS_HIT =
"Resource limit on number of operations in a transaction hit.";

static const char* FTI_MAX_TRANSACTIONS_HIT =
"Resource limit on number of pending transactions hit.";

static const char* FTI_BAD_ID =
"Expired or invalid transaction id presented.";

XrlCmdError
XrlFtiTransactionManager::start_transaction(uint32_t& tid)
{
    if (_ftm.start(tid))
	return XrlCmdError::OKAY();
    return XrlCmdError::COMMAND_FAILED(FTI_MAX_TRANSACTIONS_HIT);
}

XrlCmdError
XrlFtiTransactionManager::commit_transaction(uint32_t tid)
{
    if (_ftm.commit(tid)) {
	const string& errmsg = _ftm.error();
	if (errmsg.empty())
	    return XrlCmdError::OKAY();
	return XrlCmdError::COMMAND_FAILED(errmsg);
    }
    return XrlCmdError::COMMAND_FAILED(FTI_BAD_ID);
}

XrlCmdError
XrlFtiTransactionManager::abort_transaction(uint32_t tid)
{
    if (_ftm.abort(tid))
	return XrlCmdError::OKAY();
    return XrlCmdError::COMMAND_FAILED(FTI_BAD_ID);
}

XrlCmdError
XrlFtiTransactionManager::add(uint32_t tid,
			      const FtiTransactionManager::Operation& op)
{
    uint32_t n_ops;

    if (_ftm.retrieve_size(tid, n_ops) == false)
	return XrlCmdError::COMMAND_FAILED(FTI_BAD_ID);

    if (_max_ops <= n_ops)
	return XrlCmdError::COMMAND_FAILED(FTI_MAX_OPS_HIT);

    if (_ftm.add(tid, op))
	return XrlCmdError::OKAY();

    //
    // In theory, resource shortage is the only thing that could get us
    // here.
    //
    return XrlCmdError::COMMAND_FAILED("Unknown resource shortage");
}

XrlCmdError
XrlFtiTransactionManager::add_fib_client4(const string& target_name)
{
    // Test if we have this client already
    if (_fib_clients4.find(target_name) != _fib_clients4.end()) {
	string error_msg = c_format("Target %s is already an IPv4 FIB client",
				    target_name.c_str());
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }

    // Add the client
    _fib_clients4.insert(make_pair(target_name,
				   FibClient4(target_name, *this)));
    FibClient4& fib_client = _fib_clients4.find(target_name)->second;

    // Activate the client
    list<Fte4> fte_list;
    if (ftic().get_table4(fte_list) != true) {
	string error_msg = "Cannot get the IPv4 FIB";
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }
    fib_client.activate(fte_list);

    return XrlCmdError::OKAY();
}

XrlCmdError
XrlFtiTransactionManager::add_fib_client6(const string& target_name)
{
    // Test if we have this client already
    if (_fib_clients6.find(target_name) != _fib_clients6.end()) {
	string error_msg = c_format("Target %s is already an IPv6 FIB client",
				    target_name.c_str());
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }

    // Add the client
    _fib_clients6.insert(make_pair(target_name,
				   FibClient6(target_name, *this)));
    FibClient6& fib_client = _fib_clients6.find(target_name)->second;

    // Activate the client
    list<Fte6> fte_list;
    if (ftic().get_table6(fte_list) != true) {
	string error_msg = "Cannot get the IPv6 FIB";
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }
    fib_client.activate(fte_list);

    return XrlCmdError::OKAY();
}

XrlCmdError
XrlFtiTransactionManager::delete_fib_client4(const string& target_name)
{
    map<string, FibClient4>::iterator iter;

    iter = _fib_clients4.find(target_name);
    if (iter == _fib_clients4.end()) {
	string error_msg = c_format("Target %s is not an IPv4 FIB client",
				    target_name.c_str());
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }

    _fib_clients4.erase(iter);

    return XrlCmdError::OKAY();
}

XrlCmdError
XrlFtiTransactionManager::delete_fib_client6(const string& target_name)
{
    map<string, FibClient6>::iterator iter;

    iter = _fib_clients6.find(target_name);
    if (iter == _fib_clients6.end()) {
	string error_msg = c_format("Target %s is not an IPv6 FIB client",
				    target_name.c_str());
	return XrlCmdError::COMMAND_FAILED(error_msg);
    }

    _fib_clients6.erase(iter);

    return XrlCmdError::OKAY();
}

int
XrlFtiTransactionManager::send_fib_client_add_route(const string& target_name,
						    const Fte4& fte)
{
    bool success;

    success = _xrl_fea_fib_client.send_add_route4(
	target_name.c_str(),
	fte.net(),
	fte.gateway(),
	fte.ifname(),
	fte.vifname(),
	fte.metric(),
	fte.admin_distance(),
	string("NOT_SUPPORTED"),
	fte.xorp_route(),
	callback(this,
		 &XrlFtiTransactionManager::send_fib_client_add_route4_cb,
		 target_name));

    if (success)
	return XORP_OK;
    else
	return XORP_ERROR;
}

int
XrlFtiTransactionManager::send_fib_client_add_route(const string& target_name,
						    const Fte6& fte)
{
    bool success;

    success = _xrl_fea_fib_client.send_add_route6(
	target_name.c_str(),
	fte.net(),
	fte.gateway(),
	fte.ifname(),
	fte.vifname(),
	fte.metric(),
	fte.admin_distance(),
	string("NOT_SUPPORTED"),
	fte.xorp_route(),
	callback(this,
		 &XrlFtiTransactionManager::send_fib_client_add_route6_cb,
		 target_name));

    if (success)
	return XORP_OK;
    else
	return XORP_ERROR;
}

int
XrlFtiTransactionManager::send_fib_client_delete_route(const string& target_name,
						       const Fte4& fte)
{
    bool success;

    success = _xrl_fea_fib_client.send_delete_route4(
	target_name.c_str(),
	fte.net(),
	callback(this,
		 &XrlFtiTransactionManager::send_fib_client_delete_route6_cb,
		 target_name));

    if (success)
	return XORP_OK;
    else
	return XORP_ERROR;
}

int
XrlFtiTransactionManager::send_fib_client_delete_route(const string& target_name,
						       const Fte6& fte)
{
    bool success;

    success = _xrl_fea_fib_client.send_delete_route6(
	target_name.c_str(),
	fte.net(),
	callback(this,
		 &XrlFtiTransactionManager::send_fib_client_delete_route6_cb,
		 target_name));

    if (success)
	return XORP_OK;
    else
	return XORP_ERROR;
}

void
XrlFtiTransactionManager::send_fib_client_add_route4_cb(
    const XrlError& xrl_error,
    string target_name)
{
    map<string, FibClient4>::iterator iter;

    iter = _fib_clients4.find(target_name);
    if (iter == _fib_clients4.end()) {
	// The client has probably gone. Silently ignore.
	return;
    }

    FibClient4& fib_client = iter->second;
    fib_client.send_fib_client_route_change_cb(xrl_error);
}

void
XrlFtiTransactionManager::send_fib_client_add_route6_cb(
    const XrlError& xrl_error,
    string target_name)
{
    map<string, FibClient6>::iterator iter;

    iter = _fib_clients6.find(target_name);
    if (iter == _fib_clients6.end()) {
	// The client has probably gone. Silently ignore.
	return;
    }

    FibClient6& fib_client = iter->second;
    fib_client.send_fib_client_route_change_cb(xrl_error);
}

void
XrlFtiTransactionManager::send_fib_client_delete_route4_cb(
    const XrlError& xrl_error,
    string target_name)
{
    map<string, FibClient4>::iterator iter;

    iter = _fib_clients4.find(target_name);
    if (iter == _fib_clients4.end()) {
	// The client has probably gone. Silently ignore.
	return;
    }

    FibClient4& fib_client = iter->second;
    fib_client.send_fib_client_route_change_cb(xrl_error);
}

void
XrlFtiTransactionManager::send_fib_client_delete_route6_cb(
    const XrlError& xrl_error,
    string target_name)
{
    map<string, FibClient6>::iterator iter;

    iter = _fib_clients6.find(target_name);
    if (iter == _fib_clients6.end()) {
	// The client has probably gone. Silently ignore.
	return;
    }

    FibClient6& fib_client = iter->second;
    fib_client.send_fib_client_route_change_cb(xrl_error);
}

template<class F>
void
XrlFtiTransactionManager::FibClient<F>::activate(const list<F>& fte_list)
{
    // Create the queue with the "add" commands
    typename list<F>::const_iterator iter;
    for (iter = fte_list.begin(); iter != fte_list.end(); ++iter) {
	const F& fte = *iter;
	_inform_fib_client_queue.push_back(make_pair(true, fte));
    }

    // Start the timer to send all FIB entries
    _inform_fib_client_queue_timer = eventloop().new_oneoff_after(
	TimeVal(0, 0),
	callback(this, &XrlFtiTransactionManager::FibClient<F>::send_fib_client_route_change));
}

template<class F>
void
XrlFtiTransactionManager::FibClient<F>::send_fib_client_route_change()
{
    int success = XORP_ERROR;

    if (_inform_fib_client_queue.empty())
	return;		// No more route changes to send

    AddDeleteFte& add_delete_fte = _inform_fib_client_queue.front();
    bool is_add = add_delete_fte.first;
    F& fte = add_delete_fte.second;

    //
    // Send the appropriate XRLs
    //
    if (is_add) {
	// Add a route
	success = _xftm.send_fib_client_add_route(_target_name, fte);
    } else {
	// Delete a route
	success = _xftm.send_fib_client_delete_route(_target_name, fte);
    }

    if (success == XORP_OK)
	return;		// OK

    //
    // If an error, then start a timer to try again
    // TODO: XXX: the timer value is hardcoded here!!
    //
    _inform_fib_client_queue_timer = eventloop().new_oneoff_after(
	TimeVal(1, 0),
	callback(this, &XrlFtiTransactionManager::FibClient<F>::send_fib_client_route_change));
}

template<class F>
void
XrlFtiTransactionManager::FibClient<F>::send_fib_client_route_change_cb(
    const XrlError& xrl_error)
{
    // If success, then send the next route change
    if (xrl_error == XrlError::OKAY()) {
	_inform_fib_client_queue.pop_front();
	send_fib_client_route_change();
	return;
    }

    //
    // If an error, then start a timer to try again
    // TODO: XXX: the timer value is hardcoded here!!
    //
    _inform_fib_client_queue_timer = eventloop().new_oneoff_after(
	TimeVal(1, 0),
	callback(this, &XrlFtiTransactionManager::FibClient<F>::send_fib_client_route_change));
}

template class XrlFtiTransactionManager::FibClient<Fte4>;
template class XrlFtiTransactionManager::FibClient<Fte6>;
