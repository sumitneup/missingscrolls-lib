/*
	Use this template to test all the parameters that are available in HDK.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- add examples of collapsible/toggle switchers
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
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "SOP_ParametersTemplate_Operator.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____ SOP_PARAMETERSTEMPLATE_NAME

/* -----------------------------------------------------------------
PARAMETERS                                                         |
----------------------------------------------------------------- */

SOP_PARMS_NAMESPACE()
{
	OPERATOR_TITLE_SECTION(SOP_PARAMETERSTEMPLATE_OPERATOR_TITLE)
	namespace TITLE
	{
		DEFAULT_INPUT_0_NOT_CONNECTED_ERROR_MESSAGE()
	}

	namespace UI
	{
		// switchers
		
		// collapsible
		//static auto collapsibleSwitcherParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_COLLAPSIBLESWITCHER_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_COLLAPSIBLESWITCHER_BIGNAME);
		//auto collapsibleSwitcher_Parameter = PRM_Template(PRM_SWITCHER, 1, &collapsibleSwitcherParm_Name, 0, );

		// tabs
		static auto switcherParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_SWITCHER_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_SWITCHER_BIGNAME);
		static PRM_Default switcherParm_Defaults[] =
		{
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_PARMCOUNTTAB0, SOP_PARAMETERSTEMPLATE_OPERATOR_TABNAME0),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_PARMCOUNTTAB1, SOP_PARAMETERSTEMPLATE_OPERATOR_TABNAME1),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_PARMCOUNTTAB2, SOP_PARAMETERSTEMPLATE_OPERATOR_TABNAME2)
		};
		auto switcher_Parameter = PRM_Template(PRM_SWITCHER, sizeof(switcherParm_Defaults) / sizeof(PRM_Default), &switcherParm_Name, switcherParm_Defaults);
		
		//auto switcher_Parameter = PRM_Template(PRM_SWITCHER, sizeof(switcherParm_Defaults) / sizeof(PRM_Default), &switcherParm_Name, switcherParm_Defaults, 0, 0, 0, &PRM_SpareData::groupTypeSimple);

		// -------------------------- labels //	
		// standard
		static auto labelParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_LABEL_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_LABEL_BIGNAME);
		static PRM_Default labelParm_Defaults[] =
		{
			PRM_Default(0, SOP_PARAMETERSTEMPLATE_OPERATOR_LABEL_COLUMNNAME0),
			PRM_Default(0, SOP_PARAMETERSTEMPLATE_OPERATOR_LABEL_COLUMNNAME1)
		};
		auto label_Parameter = PRM_Template(PRM_LABEL, 2, &labelParm_Name, labelParm_Defaults);

		// centered
		static auto labelCenteredParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_LABELCENTERED_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_LABELCENTERED_BIGNAME);
		static PRM_Default labelCenteredParm_Default[] =
		{
			PRM_Default(0, SOP_PARAMETERSTEMPLATE_OPERATOR_LABELCENTERED_COLUMNNAME0),
			PRM_Default()
		};
		auto labelCentered_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &labelCenteredParm_Name, labelCenteredParm_Default);

		// -------------------------- separator //	
		static auto separatorParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_SEPARATOR_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_SEPARATOR_BIGNAME);
		auto separator_Parameter = PRM_Template(PRM_SEPARATOR, 1, &separatorParm_Name);

		// -------------------------- toggle //
		static auto toggleParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_TOGGLE_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_TOGGLE_BIGNAME);
		auto toggle_Parameter = PRM_Template(PRM_TOGGLE, 1, &toggleParm_Name);

		// -------------------------- int/float //
		static PRM_Name valueParm_Names[] =
		{
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_INT_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_INT_BIGNAME),
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_FLOAT_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_FLOAT_BIGNAME)
		};
		static PRM_Default valueParm_Defaults[] =
		{
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_INT_DEFAULT),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_FLOAT_DEFAULT)
		};
		static auto valueParm_Range = PRM_Range(PRM_RANGE_RESTRICTED, SOP_PARAMETERSTEMPLATE_OPERATOR_INT_RANGEMIN, PRM_RANGE_UI, SOP_PARAMETERSTEMPLATE_OPERATOR_INT_RANGEMAX);
		auto integer_Parameter = PRM_Template(PRM_INT, 1, &valueParm_Names[0], &valueParm_Defaults[0], 0, &valueParm_Range);
		auto float_Parameter = PRM_Template(PRM_FLT, 1, &valueParm_Names[1], &valueParm_Defaults[1], 0, &valueParm_Range);

		// -------------------------- text field //
		static auto textParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_TEXTFIELD_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_TEXTFIELD_BIGNAME);
		auto text_Parameter = PRM_Template(PRM_STRING, 1, &textParm_Name, 0);

		// -------------------------- vectors //
		static PRM_Name vectorParm_Names[] =
		{
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR2_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR2_BIGNAME),
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR3_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR3_BIGNAME)
		};
		static PRM_Default vector2DParm_Defaults[] =
		{
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR2_DEFAULTX),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR2_DEFAULTY)
		};
		static PRM_Default vector3DParm_Defaults[] =
		{
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR3_DEFAULTX),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR3_DEFAULTY),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_VECTOR3_DEFAULTZ)
		};
		auto vector2D_Parameter = PRM_Template(PRM_XYZ, 2, &vectorParm_Names[0], vector2DParm_Defaults);
		auto vector3D_Parameter = PRM_Template(PRM_XYZ, 3, &vectorParm_Names[1], vector3DParm_Defaults);

		// -------------------------- ramp parameters //
		// create ramps
		static auto colorRampParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_COLORRAMP_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_COLORRAMP_BIGNAME);
		static auto floatRampParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_FLOATRAMP_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_FLOATRAMP_BIGNAME);
		static PRM_Default rampParm_Defaults[] =
		{
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_COLORRAMP_DEFAULT0),
			PRM_Default(SOP_PARAMETERSTEMPLATE_OPERATOR_COLORRAMP_DEFAULT1)
		};
		auto colorRamp_Parameter = PRM_Template(PRM_MULTITYPE_RAMP_RGB, NULL, 1, &colorRampParm_Name, rampParm_Defaults);
		auto floatRamp_Parameter = PRM_Template(PRM_MULTITYPE_RAMP_FLT, NULL, 1, &floatRampParm_Name, rampParm_Defaults);

		// -------------------------- menu parameters //
		// create menus
		static auto ordinalMenuParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_BIGNAME);
		static PRM_Name ordinalMenu_Choices[] =
		{
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_SMALLNAME0, SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_BIGNAME0),
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_SMALLNAME1, SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_BIGNAME1),
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_SMALLNAME2, SOP_PARAMETERSTEMPLATE_OPERATOR_ORDINALMENU_CHOICE_BIGNAME2),
			PRM_Name(0)
		};
		static auto ordinalMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, ordinalMenu_Choices);
		PRM_Template ordinalMenu_Parameter = PRM_Template(PRM_ORD, 1, &ordinalMenuParm_Name, 0, &ordinalMenuParm_ChoiceList);

		static auto stringMenuParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_BIGNAME);
		static PRM_Name stringMenu_Choices[] =
		{
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_CHOICE_SMALLNAME0, SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_CHOICE_BIGNAME0),
			PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_CHOICE_SMALLNAME1, SOP_PARAMETERSTEMPLATE_OPERATOR_STRINGMENU_CHOICE_BIGNAME1),
			PRM_Name(0)
		};
		static auto stringMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_TOGGLE, stringMenu_Choices);
		auto stringMenu_Parameter = PRM_Template(PRM_STRING, 1, &stringMenuParm_Name, 0, &stringMenuParm_ChoiceList);

		static auto groupMenuParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_GROUPMENU_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_GROUPMENU_BIGNAME);
		auto groupMenu_Parameter = PRM_Template(PRM_STRING, 1, &groupMenuParm_Name, 0, &SOP_Node::groupMenu);//&BASE_SOP_OPERATOR_NAME()::groupMenu);

		static auto objectPathMenuParm_Name = PRM_Name(SOP_PARAMETERSTEMPLATE_OPERATOR_OBJECTPATHMENU_SMALLNAME, SOP_PARAMETERSTEMPLATE_OPERATOR_OBJECTPATHMENU_BIGNAME);
		auto objectPathMenu_Parameter = PRM_Template(PRM_STRING, PRM_TYPE_DYNAMIC_PATH, 1, &objectPathMenuParm_Name, 0, 0, 0, 0, &PRM_SpareData::objPath);

		// default node parameters
		__ADDITIONAL_SECTION_PRM(4)		
		DESCRIPTION_PRM()
	}

	__DEFAULT_AUTHOR_SECTION_PRM()
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____