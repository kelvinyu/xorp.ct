/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/packet_acl_base.cc,v 1.6 2007/02/16 22:47:53 pavlin Exp $"


#include "packet_acl_base.hh"


XrlPacketAclTargetBase::XrlPacketAclTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlPacketAclTargetBase::~XrlPacketAclTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlPacketAclTargetBase::set_command_map(XrlCmdMap* cmds)
{
    if (_cmds == 0 && cmds) {
        _cmds = cmds;
        add_handlers();
        return true;
    }
    if (_cmds && cmds == 0) {
	remove_handlers();
        _cmds = cmds;
        return true;
    }
    return false;
}

const XrlCmdError
XrlPacketAclTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_target_name");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name;
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_target_name", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_version");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version;
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_version", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_status");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t status;
    string reason;
    try {
	XrlCmdError e = common_0_1_get_status(
	    status,
	    reason);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_status", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("status", status);
	pxa_outputs->add("reason", reason);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/shutdown");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = common_0_1_shutdown();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/shutdown", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_get_backend(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/get_backend");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name;
    try {
	XrlCmdError e = packet_acl_0_1_get_backend(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/get_backend", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_set_backend(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/set_backend");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_set_backend(
	    xa_inputs.get_string("name"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/set_backend", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/get_version");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version;
    try {
	XrlCmdError e = packet_acl_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/get_version", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_start_transaction(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/start_transaction");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t tid;
    try {
	XrlCmdError e = packet_acl_0_1_start_transaction(
	    tid);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/start_transaction", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("tid", tid);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_commit_transaction(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/commit_transaction");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_commit_transaction(
	    xa_inputs.get_uint32("tid"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/commit_transaction", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_abort_transaction(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/abort_transaction");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_abort_transaction(
	    xa_inputs.get_uint32("tid"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/abort_transaction", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_add_entry4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 9) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(9), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/add_entry4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_add_entry4(
	    xa_inputs.get_uint32("tid"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_ipv4net("src"),
	    xa_inputs.get_ipv4net("dst"),
	    xa_inputs.get_uint32("proto"),
	    xa_inputs.get_uint32("sport"),
	    xa_inputs.get_uint32("dport"),
	    xa_inputs.get_string("action"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/add_entry4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_entry4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/delete_entry4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_delete_entry4(
	    xa_inputs.get_uint32("tid"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_ipv4net("src"),
	    xa_inputs.get_ipv4net("dst"),
	    xa_inputs.get_uint32("proto"),
	    xa_inputs.get_uint32("sport"),
	    xa_inputs.get_uint32("dport"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/delete_entry4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_all_entries4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/delete_all_entries4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_delete_all_entries4(
	    xa_inputs.get_uint32("tid"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/delete_all_entries4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_add_entry6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 9) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(9), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/add_entry6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_add_entry6(
	    xa_inputs.get_uint32("tid"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_ipv6net("src"),
	    xa_inputs.get_ipv6net("dst"),
	    xa_inputs.get_uint32("proto"),
	    xa_inputs.get_uint32("sport"),
	    xa_inputs.get_uint32("dport"),
	    xa_inputs.get_string("action"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/add_entry6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_entry6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/delete_entry6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_delete_entry6(
	    xa_inputs.get_uint32("tid"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_ipv6net("src"),
	    xa_inputs.get_ipv6net("dst"),
	    xa_inputs.get_uint32("proto"),
	    xa_inputs.get_uint32("sport"),
	    xa_inputs.get_uint32("dport"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/delete_entry6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_all_entries6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/delete_all_entries6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = packet_acl_0_1_delete_all_entries6(
	    xa_inputs.get_uint32("tid"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/delete_all_entries6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_get_entry_list_start4(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/get_entry_list_start4");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t token;
    bool more;
    try {
	XrlCmdError e = packet_acl_0_1_get_entry_list_start4(
	    token,
	    more);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/get_entry_list_start4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("token", token);
	pxa_outputs->add("more", more);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlPacketAclTargetBase::handle_packet_acl_0_1_get_entry_list_next4(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "packet_acl/0.1/get_entry_list_next4");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string ifname;
    string vifname;
    IPv4Net src;
    IPv4Net dst;
    uint32_t proto;
    uint32_t sport;
    uint32_t dport;
    string action;
    bool more;
    try {
	XrlCmdError e = packet_acl_0_1_get_entry_list_next4(
	    xa_inputs.get_uint32("token"),
	    ifname,
	    vifname,
	    src,
	    dst,
	    proto,
	    sport,
	    dport,
	    action,
	    more);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "packet_acl/0.1/get_entry_list_next4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("ifname", ifname);
	pxa_outputs->add("vifname", vifname);
	pxa_outputs->add("src", src);
	pxa_outputs->add("dst", dst);
	pxa_outputs->add("proto", proto);
	pxa_outputs->add("sport", sport);
	pxa_outputs->add("dport", dport);
	pxa_outputs->add("action", action);
	pxa_outputs->add("more", more);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

void
XrlPacketAclTargetBase::add_handlers()
{
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlPacketAclTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlPacketAclTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlPacketAclTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlPacketAclTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "common/0.1/shutdown");
	}
	if (_cmds->add_handler("packet_acl/0.1/get_backend",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_get_backend)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/get_backend");
	}
	if (_cmds->add_handler("packet_acl/0.1/set_backend",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_set_backend)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/set_backend");
	}
	if (_cmds->add_handler("packet_acl/0.1/get_version",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/get_version");
	}
	if (_cmds->add_handler("packet_acl/0.1/start_transaction",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_start_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/start_transaction");
	}
	if (_cmds->add_handler("packet_acl/0.1/commit_transaction",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_commit_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/commit_transaction");
	}
	if (_cmds->add_handler("packet_acl/0.1/abort_transaction",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_abort_transaction)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/abort_transaction");
	}
	if (_cmds->add_handler("packet_acl/0.1/add_entry4",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_add_entry4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/add_entry4");
	}
	if (_cmds->add_handler("packet_acl/0.1/delete_entry4",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_entry4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/delete_entry4");
	}
	if (_cmds->add_handler("packet_acl/0.1/delete_all_entries4",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_all_entries4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/delete_all_entries4");
	}
	if (_cmds->add_handler("packet_acl/0.1/add_entry6",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_add_entry6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/add_entry6");
	}
	if (_cmds->add_handler("packet_acl/0.1/delete_entry6",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_entry6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/delete_entry6");
	}
	if (_cmds->add_handler("packet_acl/0.1/delete_all_entries6",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_delete_all_entries6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/delete_all_entries6");
	}
	if (_cmds->add_handler("packet_acl/0.1/get_entry_list_start4",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_get_entry_list_start4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/get_entry_list_start4");
	}
	if (_cmds->add_handler("packet_acl/0.1/get_entry_list_next4",
	    callback(this, &XrlPacketAclTargetBase::handle_packet_acl_0_1_get_entry_list_next4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "packet_acl", "packet_acl/0.1/get_entry_list_next4");
	}
	_cmds->finalize();
}

void
XrlPacketAclTargetBase::remove_handlers()
{
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("packet_acl/0.1/get_backend");
	_cmds->remove_handler("packet_acl/0.1/set_backend");
	_cmds->remove_handler("packet_acl/0.1/get_version");
	_cmds->remove_handler("packet_acl/0.1/start_transaction");
	_cmds->remove_handler("packet_acl/0.1/commit_transaction");
	_cmds->remove_handler("packet_acl/0.1/abort_transaction");
	_cmds->remove_handler("packet_acl/0.1/add_entry4");
	_cmds->remove_handler("packet_acl/0.1/delete_entry4");
	_cmds->remove_handler("packet_acl/0.1/delete_all_entries4");
	_cmds->remove_handler("packet_acl/0.1/add_entry6");
	_cmds->remove_handler("packet_acl/0.1/delete_entry6");
	_cmds->remove_handler("packet_acl/0.1/delete_all_entries6");
	_cmds->remove_handler("packet_acl/0.1/get_entry_list_start4");
	_cmds->remove_handler("packet_acl/0.1/get_entry_list_next4");
}
