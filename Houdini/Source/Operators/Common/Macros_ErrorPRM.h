/*
	Common parameters code snippets that allows shorten parameters generation.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!	

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
	-----------------------------------------------------

	TODO! -----------------------------------------------
	-----------------------------------------------------

	Author: 	Nodeway (2016)

	Email:		nodeway@hotmail.com
	Vimeo:		https://vimeo.com/nodeway
	Twitter:	https://twitter.com/nodeway
	Github:		https://github.com/nodeway
*/

#pragma once

/* -----------------------------------------------------------------
NOT CONNECTED INFORMATION                                          |
----------------------------------------------------------------- */

#define ____custom_message____(messagesmallname, messagetext, varname)\
static auto varname##MessageParm_Name = PRM_Name(messagesmallname, "");\
static PRM_Default varname##MessageParm_Default[] =\
{ PRM_Default(0, messagetext), PRM_Default() };\
auto varname##Message_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &varname##MessageParm_Name, varname##MessageParm_Default);

// ready to use

#define DEFAULT_INPUT_0_NOT_CONNECTED_ERROR_MESSAGE() ____custom_message____("input0notconnected", "SORRY... INPUT 0 NEEDS TO BE CONNECTED.", input0NotConnectedError)
#define DEFAULT_INPUT_1_NOT_CONNECTED_ERROR_MESSAGE() ____custom_message____("input1notconnected", "SORRY... INPUT 1 NEEDS TO BE CONNECTED.", input1NotConnectedError)
#define DEFAULT_INPUT_2_NOT_CONNECTED_ERROR_MESSAGE() ____custom_message____("input2notconnected", "SORRY... INPUT 2 NEEDS TO BE CONNECTED.", input2NotConnectedError)
#define DEFAULT_INPUT_3_NOT_CONNECTED_ERROR_MESSAGE() ____custom_message____("input3notconnected", "SORRY... INPUT 3 NEEDS TO BE CONNECTED.", input3NotConnectedError)
#define DEFAULT_ALL_INPUTS_NOT_CONNECTED_ERROR_MESSAGE() ____custom_message____("allinputsnotconnected", "SORRY... ALL INPUTS NEEDS TO BE CONNECTED.", allInputsNotConnectedError)