/*
	Color PRM macros.

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
COLOR DEFAULTS                                                     |
----------------------------------------------------------------- */

#define ____custom_color_t_data____(smallname, bigname, size, defaults, varname)\
static auto varname##Color##Parm_Name = PRM_Name(smallname, bigname);\
auto varname##Color##_Parameter = PRM_Template(PRM_RGB, size, &varname##Color##Parm_Name, defaults);

// ready to use

#define CUSTOM_COLOR_PRM(smallname, bigname, defaultr, defaultg, defaultb, varname)\
static PRM_Default varname##ColorParm_Defaults[] =\
{ PRM_Default(defaultr), PRM_Default(defaultg), PRM_Default(defaultb) };\
____custom_color_t_data____(smallname, bigname, 3, varname##ColorParm_Defaults, varname)

#define DEFAULT_COLOR_RED_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 1, 0, 0, varname)
#define DEFAULT_COLOR_GREEN_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 0, 1, 0, varname)
#define DEFAULT_COLOR_BLUE_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 0, 0, 1, varname)
#define DEFAULT_COLOR_WHITE_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 1, 1, 1, varname)
#define DEFAULT_COLOR_BLACK_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 0, 0, 0, varname)
#define DEFAULT_COLOR_YELLOW_PRM(smallname, bigname, varname) CUSTOM_COLOR_PRM(smallname, bigname, 1, 1, 0, varname)