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

	LICENSE ------------------------------------------

	Copyright (c) 2016 Nodeway
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
	3. The names of the contributors may not be used to endorse or promote products derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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