/*
	Use this template to test all the parameters that are available in HDK.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	-----------------------------------------------------

	Author: 	Nodeway (2016)

	Email:		nodeway@hotmail.com
	Vimeo:		https://vimeo.com/nodeway
	Twitter:	https://twitter.com/nodeway
	Github:		https://github.com/nodeway
*/

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "SOP_ParametersTemplate_Parameters.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		SOP_PARAMETERSTEMPLATE_NAME

#define TITLE							SOP_PARMS_NAMESPACE_TITLE()::TITLE
#define UI								SOP_PARMS_NAMESPACE_TITLE()::UI
#define AUTHOR							SOP_PARMS_NAMESPACE_TITLE()::AUTHOR

/* -----------------------------------------------------------------
PARAMETERS LIST                                                    |
----------------------------------------------------------------- */

SOP_START_PARAMETERLIST()

		TITLE::titleUpper_Parameter,
		TITLE::title_Parameter,
		TITLE::input0NotConnectedErrorMessage_Parameter,
		TITLE::titleLower_Parameter,
		UI::switcher_Parameter,
		UI::label_Parameter,
		UI::labelCentered_Parameter,
		UI::separator_Parameter,
		UI::toggle_Parameter,
		UI::integer_Parameter,
		UI::float_Parameter,
		UI::text_Parameter,
		UI::vector2D_Parameter,
		UI::vector3D_Parameter,
		UI::colorRamp_Parameter,
		UI::floatRamp_Parameter,
		UI::ordinalMenu_Parameter,
		UI::stringMenu_Parameter,
		UI::groupMenu_Parameter,
		UI::objectPathMenu_Parameter,

		UI::additionalSectionSwitcher_Parameter,
		DESCRIPTION_PARAMETERLIST(),

		DEFAULT_AUTHOR_PARAMETERLIST(),

____SWITCH_VISIBILITY()

		TITLE::title_Parameter,
		UI::switcher_Parameter,
		UI::label_Parameter,
		UI::labelCentered_Parameter,
		UI::separator_Parameter,
		UI::toggle_Parameter,
		UI::integer_Parameter,
		UI::float_Parameter,
		UI::text_Parameter,
		UI::vector2D_Parameter,
		UI::vector3D_Parameter,
		UI::colorRamp_Parameter,
		UI::floatRamp_Parameter,
		UI::ordinalMenu_Parameter,
		UI::stringMenu_Parameter,
		UI::groupMenu_Parameter,
		UI::objectPathMenu_Parameter,
		//UI::collapsibleSwitcher_Parameter,

		UI::additionalSectionSwitcher_Parameter,

____SWITCH_INVERT_VISIBILITY()

		TITLE::input0NotConnectedErrorMessage_Parameter,

____SWITCH_BUTDONTFORCE_VISIBILITY()

SOP_END_PARAMETERLIST()

/* -----------------------------------------------------------------
INITIALIZATION                                                     |
----------------------------------------------------------------- */

SOP_OPERATOR_INITIALIZATION(SOP_PARAMETERSTEMPLATE_OPERATOR_ICONNAME)
{
	return SOP_PARAMETERSTEMPLATE_OPERATOR_INPUTNAME0;
}

/* -----------------------------------------------------------------
DEFAULT IMPLEMENTATIONS                                            |
----------------------------------------------------------------- */

SOP_OPERATOR()::DESCRIPTION_IMPLEMENTATION()

/* -----------------------------------------------------------------
OVERRIDES                                                          |
----------------------------------------------------------------- */

SOP_OPERATOR()::updateParmsFlags()
-> bool
{
	UPDATEPARMSFLAGS_DEFAULTS()

	// is input connected?
	is0Connected = this->getInput(0) == NULL ? 0 : 1;

	/* ---------------------------- Set Global Visibility ---------------------------- */

	// update global parameters visibility
	PARAMETERS_VISIBLESTATE_UPDATE(is0Connected)

	/* ---------------------------- Set States --------------------------------------- */

	// update description active state
	DESCRIPTION_ACTIVESTATE_UPDATE(is0Connected)

	return changed;
}

SOP_OPERATOR()::Tool_BirthDate() 
-> string 
{ return SOP_PARAMETERSTEMPLATE_DATE; }

SOP_OPERATOR()::Setup_Information() 
-> void 
{ SETUP_INFORMATION_DEFAULTS_V1() }

/* -----------------------------------------------------------------
HELPERS                                                            |
----------------------------------------------------------------- */
// your code here

/* -----------------------------------------------------------------
MAIN                                                               |
----------------------------------------------------------------- */

SOP_OPERATOR()::cookMySop(OP_Context& context) 
-> OP_ERROR
{
	COOKMYSOP_DEFAULTS()	

	// to modify geometry we need to make copy of it
	wasSuccess = duplicatePointSource(0, context);

	return error();
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef TITLE
#undef UI
#undef AUTHOR

#undef ____unique_sop_title____