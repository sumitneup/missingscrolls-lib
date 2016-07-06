/*
	Use this as a starting template for any SOP operator.

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

#include "SOP_Template_Parameters.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		SOP_TEMPLATE_NAME

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

		UI::filterSectionSwitcher_Parameter,
		UI::mainSectionSwitcher_Parameter,

		UI::additionalSectionSwitcher_Parameter,
		DESCRIPTION_PARAMETERLIST(),

		UI::debugSectionSwitcher_Parameter,

		DEFAULT_AUTHOR_PARAMETERLIST(),

____SWITCH_VISIBILITY()

		TITLE::title_Parameter,
		UI::filterSectionSwitcher_Parameter,
		UI::mainSectionSwitcher_Parameter,
		UI::additionalSectionSwitcher_Parameter,
		UI::debugSectionSwitcher_Parameter,

____SWITCH_INVERT_VISIBILITY()

		TITLE::input0NotConnectedErrorMessage_Parameter,

____SWITCH_BUTDONTFORCE_VISIBILITY()

SOP_END_PARAMETERLIST()

/* -----------------------------------------------------------------
INITIALIZATION                                                     |
----------------------------------------------------------------- */

SOP_OPERATOR_INITIALIZATION(SOP_TEMPLATE_OPERATOR_ICONNAME)
{
	return SOP_TEMPLATE_OPERATOR_INPUTNAME0;
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

	visibilityState = is0Connected ? 1 : 0;

	// update global parameters visibility
	PARAMETERS_VISIBLESTATE_UPDATE(is0Connected)

	// update title visibility
	changed |= this->setVisibleState(TITLE::title_Parameter.getToken(), visibilityState);
	changed |= this->setVisibleState(TITLE::input0NotConnectedErrorMessage_Parameter.getToken(), !visibilityState);

	/* ---------------------------- Set States --------------------------------------- */

	// update description active state
	DESCRIPTION_ACTIVESTATE_UPDATE(is0Connected)

	return changed;
}

SOP_OPERATOR()::Tool_BirthDate() 
-> string 
{ return SOP_TEMPLATE_DATE; }

SOP_OPERATOR()::Setup_Information() 
-> void 
{ SETUP_INFORMATION_DEFAULTS_V1() }

/* -----------------------------------------------------------------
HELPERS                                                             |
----------------------------------------------------------------- */
// you code here

/* -----------------------------------------------------------------
MAIN                                                               |
----------------------------------------------------------------- */

SOP_OPERATOR()::cookMySop(OP_Context& context) 
-> OP_ERROR
{
	COOKMYSOP_DEFAULTS()

	return error();
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef TITLE
#undef UI
#undef AUTHOR

#undef ____unique_sop_title____