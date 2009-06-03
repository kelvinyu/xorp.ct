/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/show_routes_base.cc,v 1.18 2009/01/05 18:31:15 jtc Exp $"


#include "show_routes_base.hh"


const struct XrlShowRoutesTargetBase::handler_table XrlShowRoutesTargetBase::handlers[] = {
    { "common/0.1/get_target_name",
      &XrlShowRoutesTargetBase::handle_common_0_1_get_target_name },
    { "common/0.1/get_version",
      &XrlShowRoutesTargetBase::handle_common_0_1_get_version },
    { "common/0.1/get_status",
      &XrlShowRoutesTargetBase::handle_common_0_1_get_status },
    { "common/0.1/shutdown",
      &XrlShowRoutesTargetBase::handle_common_0_1_shutdown },
    { "finder_event_observer/0.1/xrl_target_birth",
      &XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_birth },
    { "finder_event_observer/0.1/xrl_target_death",
      &XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_death },
    { "redist4/0.1/add_route",
      &XrlShowRoutesTargetBase::handle_redist4_0_1_add_route },
    { "redist4/0.1/delete_route",
      &XrlShowRoutesTargetBase::handle_redist4_0_1_delete_route },
    { "redist4/0.1/starting_route_dump",
      &XrlShowRoutesTargetBase::handle_redist4_0_1_starting_route_dump },
    { "redist4/0.1/finishing_route_dump",
      &XrlShowRoutesTargetBase::handle_redist4_0_1_finishing_route_dump },
    { "redist6/0.1/add_route",
      &XrlShowRoutesTargetBase::handle_redist6_0_1_add_route },
    { "redist6/0.1/delete_route",
      &XrlShowRoutesTargetBase::handle_redist6_0_1_delete_route },
    { "redist6/0.1/starting_route_dump",
      &XrlShowRoutesTargetBase::handle_redist6_0_1_starting_route_dump },
    { "redist6/0.1/finishing_route_dump",
      &XrlShowRoutesTargetBase::handle_redist6_0_1_finishing_route_dump },
};

const size_t XrlShowRoutesTargetBase::num_handlers = (sizeof(XrlShowRoutesTargetBase::handlers) / sizeof(XrlShowRoutesTargetBase::handlers[0]));


XrlShowRoutesTargetBase::XrlShowRoutesTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlShowRoutesTargetBase::~XrlShowRoutesTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlShowRoutesTargetBase::set_command_map(XrlCmdMap* cmds)
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
XrlShowRoutesTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlShowRoutesTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlShowRoutesTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
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
XrlShowRoutesTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
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
XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_birth");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_birth(
	    xa_inputs.get(0, "target_class").text(),
	    xa_inputs.get(1, "target_instance").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_birth", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_death");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_death(
	    xa_inputs.get(0, "target_class").text(),
	    xa_inputs.get(1, "target_instance").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_death", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_add_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/add_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_add_route(
	    xa_inputs.get(0, "dst").ipv4net(),
	    xa_inputs.get(1, "nexthop").ipv4(),
	    xa_inputs.get(2, "ifname").text(),
	    xa_inputs.get(3, "vifname").text(),
	    xa_inputs.get(4, "metric").uint32(),
	    xa_inputs.get(5, "admin_distance").uint32(),
	    xa_inputs.get(6, "cookie").text(),
	    xa_inputs.get(7, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/add_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_delete_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/delete_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_delete_route(
	    xa_inputs.get(0, "dst").ipv4net(),
	    xa_inputs.get(1, "nexthop").ipv4(),
	    xa_inputs.get(2, "ifname").text(),
	    xa_inputs.get(3, "vifname").text(),
	    xa_inputs.get(4, "metric").uint32(),
	    xa_inputs.get(5, "admin_distance").uint32(),
	    xa_inputs.get(6, "cookie").text(),
	    xa_inputs.get(7, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/delete_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_starting_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/starting_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_starting_route_dump(
	    xa_inputs.get(0, "cookie").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/starting_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_finishing_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/finishing_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_finishing_route_dump(
	    xa_inputs.get(0, "cookie").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/finishing_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_add_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/add_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_add_route(
	    xa_inputs.get(0, "dst").ipv6net(),
	    xa_inputs.get(1, "nexthop").ipv6(),
	    xa_inputs.get(2, "ifname").text(),
	    xa_inputs.get(3, "vifname").text(),
	    xa_inputs.get(4, "metric").uint32(),
	    xa_inputs.get(5, "admin_distance").uint32(),
	    xa_inputs.get(6, "cookie").text(),
	    xa_inputs.get(7, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/add_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_delete_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/delete_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_delete_route(
	    xa_inputs.get(0, "dst").ipv6net(),
	    xa_inputs.get(1, "nexthop").ipv6(),
	    xa_inputs.get(2, "ifname").text(),
	    xa_inputs.get(3, "vifname").text(),
	    xa_inputs.get(4, "metric").uint32(),
	    xa_inputs.get(5, "admin_distance").uint32(),
	    xa_inputs.get(6, "cookie").text(),
	    xa_inputs.get(7, "protocol_origin").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/delete_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_starting_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/starting_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_starting_route_dump(
	    xa_inputs.get(0, "cookie").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/starting_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_finishing_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/finishing_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_finishing_route_dump(
	    xa_inputs.get(0, "cookie").text());
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/finishing_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	return XrlCmdError::BAD_ARGS(e.str());
    }
    return XrlCmdError::OKAY();
}

void
XrlShowRoutesTargetBase::add_handlers()
{
    for (size_t i = 0; i < num_handlers; ++i) {
        if (!_cmds->add_handler(handlers[i].name,
                                callback(this, handlers[i].method))) {
            XLOG_ERROR("Failed to register xrl handler finder://%s/%s", "show_routes", handlers[i].name);
        }
    }
    _cmds->finalize();
}

void
XrlShowRoutesTargetBase::remove_handlers()
{
     for (size_t i = 0; i < num_handlers; ++i) {
         _cmds->remove_handler(handlers[i].name);
     }
}
