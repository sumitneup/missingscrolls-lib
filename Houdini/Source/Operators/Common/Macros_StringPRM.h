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
STRING FIELD DEFAULTS                                              |
----------------------------------------------------------------- */

#define ____default_string_field_data____(smallname, bigname, defaultvalue, varname)\
static auto varname##StringParm_Name = PRM_Name(smallname, bigname);\
static auto varname##StringParm_Default = PRM_Default(0, defaultvalue);

// ready to use

#define DEFAULT_STRING_NO_JOIN_PRM(smallname, bigname, defaultvalue, helptext, varname)\
____default_string_field_data____(smallname, bigname, defaultvalue, varname)\
auto varname##String_Parameter = PRM_Template(PRM_STRING, 1, &varname##StringParm_Name, &varname##StringParm_Default, 0, 0, 0, 0, 1, helptext);

#define DEFAULT_STRING_JOIN_PRM(smallname, bigname, defaultvalue, helptext, varname)\
____default_string_field_data____(smallname, bigname, defaultvalue, varname)\
auto varname##String_Parameter = PRM_Template(PRM_STRING | PRM_TYPE_JOIN_NEXT, 1, &varname##StringParm_Name, &varname##StringParm_Default, 0, 0, 0, 0, 1, helptext);

#define CUSTOM_EMPTY_STRING_PRM(smallname, bigname, helptext, varname)					DEFAULT_STRING_NO_JOIN_PRM(smallname, bigname, "", helptext, varname)
#define CUSTOM_EMPTY_STRING_JOIN_PRM(smallname, bigname, helptext, varname)				DEFAULT_STRING_JOIN_PRM(smallname, bigname, "", helptext, varname)
#define CUSTOM_STRING_PRM(smallname, bigname, defaultvalue, helptext, varname)			DEFAULT_STRING_NO_JOIN_PRM(smallname, bigname, defaultvalue, helptext, varname)
#define CUSTOM_STRING_JOIN_PRM(smallname, bigname, defaultvalue, helptext, varname)		DEFAULT_STRING_JOIN_PRM(smallname, bigname, defaultvalue, helptext, varname)