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

	LICENSE ------------------------------------------

	Copyright (c) 2016 Nodeway
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
	3. The names of the contributors may not be used to endorse or promote products derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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