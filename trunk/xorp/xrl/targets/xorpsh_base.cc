/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/xorpsh_base.cc,v 1.19 2007/02/16 22:48:00 pavlin Exp $"


#include "xorpsh_base.hh"


XrlXorpshTargetBase::XrlXorpshTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlXorpshTargetBase::~XrlXorpshTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlXorpshTargetBase::set_command_map(XrlCmdMap* cmds)
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
XrlXorpshTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlXorpshTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlXorpshTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlXorpshTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
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
XrlXorpshTargetBase::handle_rtrmgr_client_0_2_new_config_user(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr_client/0.2/new_config_user");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_client_0_2_new_config_user(
	    xa_inputs.get_uint32("userid"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr_client/0.2/new_config_user", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_saved_done(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr_client/0.2/config_saved_done");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_client_0_2_config_saved_done(
	    xa_inputs.get_bool("success"),
	    xa_inputs.get_string("errmsg"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr_client/0.2/config_saved_done", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_change_done(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr_client/0.2/config_change_done");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_client_0_2_config_change_done(
	    xa_inputs.get_bool("success"),
	    xa_inputs.get_string("errmsg"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr_client/0.2/config_change_done", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_changed(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr_client/0.2/config_changed");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_client_0_2_config_changed(
	    xa_inputs.get_uint32("userid"),
	    xa_inputs.get_string("deltas"),
	    xa_inputs.get_string("deletions"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr_client/0.2/config_changed", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlXorpshTargetBase::handle_rtrmgr_client_0_2_module_status(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "rtrmgr_client/0.2/module_status");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rtrmgr_client_0_2_module_status(
	    xa_inputs.get_string("modname"),
	    xa_inputs.get_uint32("status"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rtrmgr_client/0.2/module_status", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

void
XrlXorpshTargetBase::add_handlers()
{
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlXorpshTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlXorpshTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlXorpshTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlXorpshTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "common/0.1/shutdown");
	}
	if (_cmds->add_handler("rtrmgr_client/0.2/new_config_user",
	    callback(this, &XrlXorpshTargetBase::handle_rtrmgr_client_0_2_new_config_user)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "rtrmgr_client/0.2/new_config_user");
	}
	if (_cmds->add_handler("rtrmgr_client/0.2/config_saved_done",
	    callback(this, &XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_saved_done)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "rtrmgr_client/0.2/config_saved_done");
	}
	if (_cmds->add_handler("rtrmgr_client/0.2/config_change_done",
	    callback(this, &XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_change_done)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "rtrmgr_client/0.2/config_change_done");
	}
	if (_cmds->add_handler("rtrmgr_client/0.2/config_changed",
	    callback(this, &XrlXorpshTargetBase::handle_rtrmgr_client_0_2_config_changed)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "rtrmgr_client/0.2/config_changed");
	}
	if (_cmds->add_handler("rtrmgr_client/0.2/module_status",
	    callback(this, &XrlXorpshTargetBase::handle_rtrmgr_client_0_2_module_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "xorpsh", "rtrmgr_client/0.2/module_status");
	}
	_cmds->finalize();
}

void
XrlXorpshTargetBase::remove_handlers()
{
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("rtrmgr_client/0.2/new_config_user");
	_cmds->remove_handler("rtrmgr_client/0.2/config_saved_done");
	_cmds->remove_handler("rtrmgr_client/0.2/config_change_done");
	_cmds->remove_handler("rtrmgr_client/0.2/config_changed");
	_cmds->remove_handler("rtrmgr_client/0.2/module_status");
}
