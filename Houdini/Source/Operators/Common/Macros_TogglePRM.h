/*
	Toggle PRM macros.

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
TOGGLE DEFAULTS                                                    |
----------------------------------------------------------------- */

#define ____custom_toggle_data____(smallname, bigname, defaultstate, varname)\
static auto varname##ToggleParm_Name = PRM_Name(smallname, bigname);\
static auto varname##ToggleParm_Default = PRM_Default(defaultstate);\
static auto varname##ToggleParm_Range = PRM_Range(PRM_RANGE_RESTRICTED, 0, PRM_RANGE_RESTRICTED, 1);

// ready to use

#define CUSTOM_TOOGLE_NO_JOIN_PRM(smallname, bigname, exportlevel, defaultstate, callbackname, helptext, varname)\
____custom_toggle_data____(smallname, bigname, defaultstate, varname)\
auto varname##Toggle_Parameter = PRM_Template(PRM_TOGGLE, exportlevel, 1, &varname##ToggleParm_Name, &varname##ToggleParm_Default, 0, &varname##ToggleParm_Range, callbackname, 0, 1, helptext);

#define CUSTOM_TOOGLE_JOIN_PRM(smallname, bigname, exportlevel, defaultstate, callbackname, helptext, varname)\
____custom_toggle_data____(smallname, bigname, defaultstate, varname)\
auto varname##Toggle_Parameter = PRM_Template(PRM_TOGGLE | PRM_TYPE_JOIN_NEXT, exportlevel, 1, &varname##ToggleParm_Name, &varname##ToggleParm_Default, 0, &varname##ToggleParm_Range, callbackname, 0, 1, helptext);

#define CUSTOM_TOOGLE_ON_PRM(smallname, bigname, callbackname, helptext, varname)				CUSTOM_TOOGLE_NO_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_MIN, 1, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_OFF_PRM(smallname, bigname, callbackname, helptext, varname)				CUSTOM_TOOGLE_NO_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_MIN, 0, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_ON_JOIN_PRM(smallname, bigname, callbackname, helptext, varname)			CUSTOM_TOOGLE_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_MIN, 1, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_OFF_JOIN_PRM(smallname, bigname, callbackname, helptext, varname)			CUSTOM_TOOGLE_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_MIN, 0, callbackname, helptext, varname)

#define CUSTOM_TOOGLE_ON_TBX_PRM(smallname, bigname, callbackname, helptext, varname)			CUSTOM_TOOGLE_NO_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_TBX, 1, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_OFF_TBX_PRM(smallname, bigname, callbackname, helptext, varname)			CUSTOM_TOOGLE_NO_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_TBX, 0, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_ON_JOIN_TBX_PRM(smallname, bigname, callbackname, helptext, varname)		CUSTOM_TOOGLE_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_TBX, 1, callbackname, helptext, varname)
#define CUSTOM_TOOGLE_OFF_JOIN_TBX_PRM(smallname, bigname, callbackname, helptext, varname)		CUSTOM_TOOGLE_JOIN_PRM(smallname, bigname, PRM_Template::PRM_EXPORT_TBX, 0, callbackname, helptext, varname)

#define CUSTOM_TOGGLE_WITH_SEPARATOR_ON_PRM(smallname, bigname, callbackname, helptext, varname)\
CUSTOM_TOOGLE_ON_JOIN_PRM(smallname, bigname, callbackname, helptext, varname)\
CUSTOM_SEPARATOR_PARM (smallname, varname)

#define CUSTOM_TOGGLE_WITH_SEPARATOR_OFF_PRM(smallname, bigname, separatorsmallname, callbackname, helptext, varname)\
CUSTOM_TOOGLE_OFF_JOIN_PRM(smallname, bigname, callbackname, helptext, varname)\
CUSTOM_SEPARATOR_PARM (separatorsmallname, varname)

#define DEFAULT_FLIP_NORMALS_PRM()																CUSTOM_TOOGLE_OFF_PRM("flipnormals", "Flip Normals", 0, "Flips geometry normals", flipNormals)
#define DEFAULT_FLIP_NORMALS_TBX_PRM()															CUSTOM_TOOGLE_OFF_TBX_PRM("flipnormals", "Flip Normals", 0, "Flips geometry normals", flipNormals)