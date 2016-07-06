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
SEPARATOR DEFAULTS                                                 |
----------------------------------------------------------------- */

#define CUSTOM_SEPARATOR_PARM(smallname, varname)\
static auto varname##SeparatorParm_Name = PRM_Name(smallname, "");\
auto varname##Separator_Parameter = PRM_Template(PRM_SEPARATOR, 1, &varname##SeparatorParm_Name);