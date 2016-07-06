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
TITLE SECTION                                                      |
----------------------------------------------------------------- */

#define OPERATOR_TITLE_SECTION(operatortitle)\
namespace TITLE\
{\
	static auto titleUpperParm_Name = PRM_Name("titleupper", "");\
	static auto titleParm_Name = PRM_Name("title", "");\
	static auto titleLowerParm_Name = PRM_Name("titlelower", "");\
	static auto titleParm_Default = PRM_Default(0, operatortitle);\
	auto titleUpper_Parameter = PRM_Template(PRM_SEPARATOR, 1, &titleUpperParm_Name);\
	auto title_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &titleParm_Name, &titleParm_Default);\
	auto titleLower_Parameter = PRM_Template(PRM_SEPARATOR, 1, &titleLowerParm_Name);\
}