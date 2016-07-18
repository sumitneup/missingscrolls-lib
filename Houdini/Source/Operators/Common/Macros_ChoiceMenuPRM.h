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
CHOICE MENU														   |
----------------------------------------------------------------- */

#define ____custom_menu_n_choices_data____(smallname, bigname, varname) static auto varname##ChoiceMenuParm_Name = PRM_Name(smallname, bigname);

// ready to use

#define DEFAULT_GROUP_MERGEMENU_PRM(varname)\
____custom_menu_n_choices_data____("mergeoperation", "Merge Operation", varname)\
static PRM_Name varname##ChoiceMenuParm_Choices[] =\
{\
	PRM_Name("0", "Replace Existing"),\
	PRM_Name("1", "Union With Existing"),\
	PRM_Name(0)\
};\
static auto varname##ChoiceMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##ChoiceMenuParm_Choices);\
auto varname##ChoiceMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##ChoiceMenuParm_Name, 0, &varname##ChoiceMenuParm_ChoiceList, 0, 0, 0, 1, "0: Overwrite existing group, 1: Add to existing group.");

#define DEFAULT_ERRORLEVEL_MENU_PRM(varname)\
____custom_menu_n_choices_data____(SYS_TO_STRING(varname), "Error Level", varname)\
static PRM_Name varname##ChoiceMenuParm_Choices[] =\
{\
	PRM_Name("0", "None"),\
	PRM_Name("1", "Warning"),\
	PRM_Name("1", "Error"),\
	PRM_Name(0)\
};\
static auto varname##ChoiceMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##ChoiceMenuParm_Choices);\
auto varname##ChoiceMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##ChoiceMenuParm_Name, 0, &varname##ChoiceMenuParm_ChoiceList, 0, 0, 0, 1, "Set error level.");

#define DEFAULT_ERRORLEVEL_WITH_ATTRIBUTE_MENU_PRM(varname)\
____custom_menu_n_choices_data____(SYS_TO_STRING(varname), "Error Level", varname)\
static PRM_Name varname##ChoiceMenuParm_Choices[] =\
{\
	PRM_Name("0", "None"),\
	PRM_Name("1", "Warning"),\
	PRM_Name("1", "Error"),\
	PRM_Name("1", "Attribute"),\
	PRM_Name(0)\
};\
static auto varname##ChoiceMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##ChoiceMenuParm_Choices);\
auto varname##ChoiceMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##ChoiceMenuParm_Name, 0, &varname##ChoiceMenuParm_ChoiceList, 0, 0, 0, 1, "Set error level.");

#define DEFAULT_COMPARISION_MENU_PRM(varname)\
____custom_menu_n_choices_data____(SYS_TO_STRING(varname), "Compare", varname)\
static PRM_Name varname##ChoiceMenuParm_Choices[] =\
{\
	PRM_Name("0", "<"),\
	PRM_Name("1", "<="),\
	PRM_Name("1", "=="),\
	PRM_Name("1", ">="),\
	PRM_Name("1", ">"),\
	PRM_Name(0)\
};\
static auto varname##ChoiceMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##ChoiceMenuParm_Choices);\
auto varname##ChoiceMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##ChoiceMenuParm_Name, 0, &varname##ChoiceMenuParm_ChoiceList, 0, 0, 0, 1, "Set error level.");