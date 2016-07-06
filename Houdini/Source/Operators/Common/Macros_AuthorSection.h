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
AUTHOR SECTION                                                     |
----------------------------------------------------------------- */

#define ____default_author_section_base____()\
static auto authorParm_Name = PRM_Name("author", "");\
static auto authorEmailAdressParm_Name = PRM_Name("authoremailadress", "");\
static auto authorTwitterLinkParm_Name = PRM_Name("authortwitterlink", "");\
static auto blank_Default = PRM_Default(0, "");\
auto author_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorParm_Name, &blank_Default);\
auto authorEmailAdress_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorEmailAdressParm_Name, &blank_Default);\
auto authorTwitterLink_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorTwitterLinkParm_Name, &blank_Default);

#define ____custom_author_section_base____(parmcount)\
__AUTHOR_SECTION_PRM(3 + parmcount)\
____default_author_section_base____()

// ready to use

#define __DEFAULT_AUTHOR_SECTION_PRM()\
namespace AUTHOR\
{\
____custom_author_section_base____(0)\
}

#define __CUSTOM_AUTHOR_SECTION_PRM(parmcount)\
namespace AUTHOR\
{\
____custom_author_section_base____(parmcount)\
}

/* -----------------------------------------------------------------
PARAMETERSLIST                                                     |
----------------------------------------------------------------- */

#define DEFAULT_AUTHOR_PARAMETERLIST()\
AUTHOR::authorSectionSwitcher_Parameter,\
AUTHOR::author_Parameter,\
AUTHOR::authorEmailAdress_Parameter,\
AUTHOR::authorTwitterLink_Parameter