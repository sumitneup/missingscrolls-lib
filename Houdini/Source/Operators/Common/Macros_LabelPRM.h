/*
	Label PRM macros.

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
LABEL DEFAULTS                                                     |
----------------------------------------------------------------- */

#define ____custom_centered_label_prm____(smallname, labeltext, varname)\
static auto varname##LabelParm_Name = PRM_Name(smallname, "");\
static auto varname##LabelParm_Default = PRM_Default(0, labeltext);\
	auto varname##Label_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &varname##LabelParm_Name, &varname##LabelParm_Default);

// ready to use

#define DEFAULT_CENTERED_EMPTY_LABEL_PRM(smallname, varname)		____custom_centered_label_prm____(smallname, "", varname)
#define CUSTOM_CENTERED_LABEL_PRM(smallname, labeltext, varname)	____custom_centered_label_prm____(smallname, labeltext, varname)