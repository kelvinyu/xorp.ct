/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/finder_client_base.cc,v 1.27 2009/01/05 18:31:15 jtc Exp $"


#include "finder_client_base.hh"


const struct XrlFinderclientTargetBase::handler_table XrlFinderclientTargetBase::handlers[] = {
    { "common/0.1/get_target_name",
      &XrlFinderclientTargetBase::handle_common_0_1_get_target_name },
    { "common/0.1/get_version",
      &XrlFinderclientTargetBase::handle_common_0_1_get_version },
    { "common/0.1/get_status",
      &XrlFinderclientTargetBase::handle_common_0_1_get_status },
    { "common/0.1/shutdown",
      &XrlFinderclientTargetBase::handle_common_0_1_shutdown },
    { "finder_client/0.2/hello",
      &XrlFinderclientTargetBase::handle_finder_client_0_2_hello },
    { "finder_client/0.2/remove_xrl_from_cache",
      &XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrl_from_cache },
    { "finder_client/0.2/remove_xrls_for_target_from_cache",
      &XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrls_for_target_from_cache },
    { "finder_client/0.2/dispatch_tunneled_xrl",
      &XrlFinderclientTargetBase::handle_finder_client_0_2_dispatch_tunneled_xrl },
};

const size_t XrlFinderclientTargetBase::num_handlers = (sizeof(XrlFinderclientTargetBase::handlers) / sizeof(XrlFinderclientTargetBase::handlers[0]));


XrlFinderclientTargetBase::XrlFinderclientTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlFinderclientTargetBase::~XrlFinderclientTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlFinderclientTargetBase::set_command_map(XrlCmdMap* cmds)
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
XrlFinderclientTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
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
XrlFinderclientTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
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
XrlFinderclientTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
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
XrlFinderclientTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
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
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_2_hello(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "finder_client/0.2/hello");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_2_hello();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_client/0.2/hello", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrl_from_cache(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "finder_client/0.2/remove_xrl_from_cache");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_2_remove_xrl_from_cache(
	    xa_inputs.get(0, "xrl").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_client/0.2/remove_xrl_from_cache", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrls_for_target_from_cache(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "finder_client/0.2/remove_xrls_for_target_from_cache");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_2_remove_xrls_for_target_from_cache(
	    xa_inputs.get(0, "target_name").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_client/0.2/remove_xrls_for_target_from_cache", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_2_dispatch_tunneled_xrl(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "finder_client/0.2/dispatch_tunneled_xrl");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t xrl_error;
    string xrl_error_note;
    try {
	XrlCmdError e = finder_client_0_2_dispatch_tunneled_xrl(
	    xa_inputs.get(0, "xrl").text(),
	    xrl_error,
	    xrl_error_note);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_client/0.2/dispatch_tunneled_xrl", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("xrl_error", xrl_error);
	pxa_outputs->add("xrl_error_note", xrl_error_note);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

void
XrlFinderclientTargetBase::add_handlers()
{
    for (size_t i = 0; i < num_handlers; ++i) {
        if (!_cmds->add_handler(handlers[i].name,
                                callback(this, handlers[i].method))) {
            XLOG_ERROR("Failed to register xrl handler finder://%s/%s", "finderclient", handlers[i].name);
        }
    }
    _cmds->finalize();
}

void
XrlFinderclientTargetBase::remove_handlers()
{
     for (size_t i = 0; i < num_handlers; ++i) {
         _cmds->remove_handler(handlers[i].name);
     }
}
