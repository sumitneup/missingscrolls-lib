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