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