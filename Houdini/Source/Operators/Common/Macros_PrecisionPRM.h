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
PRECISION DEFAULTS                                                 |
----------------------------------------------------------------- */

#define CUSTOM_PRECISION_PRM(smallname, bigname, varname)\
static auto varname##MenuParm_Name = PRM_Name(smallname, bigname);\
static PRM_Name varname##MenuParm_Choices[] =\
{\
	PRM_Name("7", "7 Zeros"),\
	PRM_Name("6", "6 Zeros"),\
	PRM_Name("5", "5 Zeros"),\
	PRM_Name("4", "4 Zeros"),\
	PRM_Name("3", "3 Zeros"),\
	PRM_Name("2", "2 Zeros"),\
	PRM_Name("1", "1 Zero"),\
	PRM_Name("0", "Just integer Part"),\
	PRM_Name(0)\
};\
static auto varname##MenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##MenuParm_Choices);\
auto varname##Menu_Parameter = PRM_Template(PRM_ORD, 1, &varname##MenuParm_Name, 0, &varname##MenuParm_ChoiceList);

#define DEFAULT_PRECISION_PRM() CUSTOM_PRECISION_PRM("precision", "Precision", defaultPrecision)