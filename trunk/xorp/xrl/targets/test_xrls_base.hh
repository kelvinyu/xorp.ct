/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP$
 */


#ifndef __XRL_INTERFACES_TEST_XRLS_BASE_HH__
#define __XRL_INTERFACES_TEST_XRLS_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlTestXrlsTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlTestXrlsTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlTestXrlsTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlTestXrlsTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "test_xrls/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    virtual XrlCmdError test_xrls_0_1_start_transmission() = 0;

    virtual XrlCmdError test_xrls_0_1_end_transmission() = 0;

    virtual XrlCmdError test_xrls_0_1_add_xrl0() = 0;

    virtual XrlCmdError test_xrls_0_1_add_xrl1(
	// Input values,
	const string&	data1) = 0;

    virtual XrlCmdError test_xrls_0_1_add_xrl2(
	// Input values,
	const string&	data1,
	const string&	data2) = 0;

    virtual XrlCmdError test_xrls_0_1_add_xrl9(
	// Input values,
	const bool&	data1,
	const int32_t&	data2,
	const IPv4&	data3,
	const IPv4Net&	data4,
	const IPv6&	data5,
	const IPv6Net&	data6,
	const Mac&	data7,
	const string&	data8,
	const vector<uint8_t>&	data9) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_start_transmission(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_end_transmission(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_add_xrl0(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_add_xrl1(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_add_xrl2(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_test_xrls_0_1_add_xrl9(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_TEST_XRLS_BASE_HH__ */
