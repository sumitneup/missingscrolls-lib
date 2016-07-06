/*
	Create Group parameter definition.

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
DEFINES                                                            |
----------------------------------------------------------------- */

#define SIMPLE_CREATE_GROUP_PRM(defaultvalue, callbackname)\
CUSTOM_TOOGLE_OFF_JOIN_PRM("creategroup", "Group", callbackname, "Create ouput groups options.", createGroup)\
CUSTOM_SEPARATOR_PARM("creategroupseparator", createGroup)\
DEFAULT_STRING_NO_JOIN_PRM("groupname", "Name", defaultvalue, "Specify group name.", groupName)

#define CREATE_GROUP_PRM(defaultname)\
CUSTOM_TOOGLE_OFF_JOIN_PRM("creategroup", "Group", 0, "Create ouput groups options.", createGroup)\
CUSTOM_SEPARATOR_PARM("creategroupseparator", createGroup)\
DEFAULT_STRING_JOIN_PRM("groupname", "Name", defaultname, "Specify group name.", groupName)\
CUSTOM_TOOGLE_OFF_PRM("makeuniquename", "Unique", 0, "Make sure the created group doesn't overwrite existing groups by creating unique group name.", makeUniqueName)\
DEFAULT_GROUP_MERGEMENU_PRM(mergeOperation)\
CUSTOM_EMPTY_STRING_PRM("uniquename", "Unique Name", "Unique group name.", uniqueName)