/*
	Switcher PRM macros.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!	

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- replace old author section
	-----------------------------------------------------

	Author: 	Nodeway (2016)

	Email:		nodeway@hotmail.com
	Vimeo:		https://vimeo.com/nodeway
	Twitter:	https://twitter.com/nodeway
	Github:		https://github.com/nodeway
*/

#pragma once

/* -----------------------------------------------------------------
SWITCHER DEFAULTS                                                  |
----------------------------------------------------------------- */

#define ____custom_switcher_data_start____(smallname, bigname, varname)\
static auto varname##SwitcherParm_Name = PRM_Name(smallname, bigname);\
static PRM_Default varname##SwitcherParm_Defaults[] = {

#define ____custom_switcher_data_end____(varname) };\
auto varname##Switcher_Parameter = PRM_Template(PRM_SWITCHER, sizeof(varname##SwitcherParm_Defaults) / sizeof(PRM_Default), &varname##SwitcherParm_Name, varname##SwitcherParm_Defaults, 0, 0, 0, &PRM_SpareData::groupTypeSimple);

#define ____custom_switcher_section_data____(smallname, bigname, parmcount, varname)\
____custom_switcher_data_start____(smallname, bigname, varname##Section)\
PRM_Default(parmcount, bigname)\
____custom_switcher_data_end____(varname##Section)

// ready to use

#define START_CUSTOM_SIMPLE_FOLDER_PRM(smallname, bigname, varname)			____custom_switcher_data_start____(smallname, bigname, varname)
#define END_CUSTOM_SIMPLE_FOLDER_PRM(varname)								____custom_switcher_data_end____(varname)

#define __FILTER_SECTION_PRM(parmcount)										____custom_switcher_section_data____("filtersection", "Filter", parmcount, filter)
#define __MAIN_SECTION_PRM(parmcount)										____custom_switcher_section_data____("mainsection", "Main", parmcount, main)
#define __ADDITIONAL_SECTION_PRM(parmcount)									____custom_switcher_section_data____("additionalsection", "Additional", parmcount, additional)
#define __DEBUG_SECTION_PRM(parmcount)										____custom_switcher_section_data____("debugsection", "Debug", parmcount, debug)
#define __AUTHOR_SECTION_PRM(parmcount)										____custom_switcher_section_data____("authorsection", "Author", parmcount, author)