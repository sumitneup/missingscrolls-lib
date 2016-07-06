/*
	INT PRM macros.

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
INTEGER DEFAULTS                                                   |
----------------------------------------------------------------- */

#define ____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, rangemin, rangemax, rangemintype, rangemaxtype, defaultvalue, helptext, varname)\
static auto varname##IntegerParm_Name = PRM_Name(smallname, bigname);\
static auto varname##IntegerParm_Default = PRM_Default(defaultvalue);\
static auto varname##IntegerParm_Range = PRM_Range(rangemintype, rangemin, rangemaxtype, rangemax);\
auto varname##Integer_Parameter = PRM_Template(PRM_INT, 1, &varname##IntegerParm_Name, &varname##IntegerParm_Default, 0, &varname##IntegerParm_Range, 0, 0, 1, helptext);

// ready to use

#define CUSTOM_INT_0R_TO_MAXU_PRM(smallname, bigname, rangemax, defaultvalue, helptext, varname)					____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, 0, rangemax, PRM_RANGE_RESTRICTED, PRM_RANGE_UI, defaultvalue, helptext, varname)
#define CUSTOM_INT_0R_TO_MAXR_PRM(smallname, bigname, rangemax, defaultvalue, helptext, varname)					____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, 0, rangemax, PRM_RANGE_RESTRICTED, PRM_RANGE_RESTRICTED, defaultvalue, helptext, varname)
#define CUSTOM_INT_MINU_TO_MAXU_PRM(smallname, bigname, rangemin, rangemax, defaultvalue, helptext, varname)		____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, rangemin, rangemax, PRM_RANGE_UI, PRM_RANGE_UI, defaultvalue, helptext, varname)
#define CUSTOM_INT_MINR_TO_MAXU_PRM(smallname, bigname, rangemin, rangemax, defaultvalue, helptext, varname)		____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, rangemin, rangemax, PRM_RANGE_RESTRICTED, PRM_RANGE_UI, defaultvalue, helptext, varname)
#define CUSTOM_INT_MINR_TO_MAXR_PRM(smallname, bigname, rangemin, rangemax, defaultvalue, helptext, varname)		____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, rangemin, rangemax, PRM_RANGE_RESTRICTED, PRM_RANGE_RESTRICTED, defaultvalue, helptext, varname)
#define CUSTOM_INT_MINUS1R_TO_MAXR_PRM(smallname, bigname, rangemax, helptext, varname)								____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, -1, rangemax, PRM_RANGE_RESTRICTED, PRM_RANGE_RESTRICTED, -1, helptext, varname)
#define CUSTOM_INT_MINUS1R_TO_1R_PRM(smallname, bigname, defaultvalue, helptext, varname)							____custom_int_rangemintype_t_rangemaxtype_t_parameter____(smallname, bigname, -1, 1, PRM_RANGE_RESTRICTED, PRM_RANGE_RESTRICTED, defaultvalue, helptext, varname)
