/*
	Description parameter definition.

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
PRM                                                                |
----------------------------------------------------------------- */

#define DESCRIPTION_MESSAGE_SMALLNAME		"descriptionmessage"

#define DESCRIPTION_PRM()\
static auto descriptionToggleParm_Name = PRM_Name("adddescription", "Description");\
static auto descriptionToggleParm_Default = PRM_Default(0);\
auto descriptionToggle_Parameter = PRM_Template(PRM_TOGGLE | PRM_TYPE_JOIN_NEXT, 1, &descriptionToggleParm_Name, &descriptionToggleParm_Default, 0, 0, &SOP_OPERATOR_TITLE()::Callback_Description, 0, 1, "Add description message to node.");\
static auto descriptionSeparatorParm_Name = PRM_Name("adddescriptionseparator", "");\
auto descriptionSeparator_Parameter = PRM_Template(PRM_SEPARATOR, 1, &descriptionSeparatorParm_Name);\
static auto cleanButtonuParm_Name = PRM_Name("clean", "Clean");\
auto cleanButton_Parameter = PRM_Template(PRM_CALLBACK, 1, &cleanButtonuParm_Name, 0, 0, 0, &SOP_OPERATOR_TITLE()::Callback_Description, 0, 1, "Clean description message field.");\
static auto descriptionTextFieldParm_Name = PRM_Name(DESCRIPTION_MESSAGE_SMALLNAME, "Message");\
static auto descriptionTextFieldParm_Range = PRM_Range(PRM_RANGE_RESTRICTED, 5, PRM_RANGE_RESTRICTED, 25);\
auto descriptionTextField_Parameter = PRM_Template(PRM_STRING, 1, &descriptionTextFieldParm_Name, 0, 0, &descriptionTextFieldParm_Range, 0, &PRM_SpareData::stringEditor, 1, "Description message.");

/*
PRM_Template(PRM_Type thetype = PRM_LIST_TERMINATOR,
			 int thevectorsize = 1, 
			 PRM_Name* thenameptr = 0,
			 PRM_Default* thedefaults = 0,
			 PRM_ChoiceList* thechoicelistptr = 0,
			 PRM_Range* therangeptr = 0,
			 PRM_Callback thecallbackfunc = 0,
			 PRM_SpareData* thespareptr = 0,
			 int theparmgroup = 1,
			 const char* thehelptext = 0,
			 PRM_ConditionalBase* thecondptr = 0);
*/

/* -----------------------------------------------------------------
PARAMETERLIST                                                      |
----------------------------------------------------------------- */

#define DESCRIPTION_PARAMETERLIST()\
UI::descriptionToggle_Parameter,\
UI::descriptionSeparator_Parameter,\
UI::cleanButton_Parameter,\
UI::descriptionTextField_Parameter

/* -----------------------------------------------------------------
DECLARATION												           |
----------------------------------------------------------------- */

#define DESCRIPTION_DECLARATION()\
public:\
static auto Callback_Description(void* data, int index, float time, const PRM_Template* tmp) -> int;\
protected:\
virtual auto getDescriptiveParmName(UT_String& name) const -> void override;

/* -----------------------------------------------------------------
IMPLEMENTATION												       |
----------------------------------------------------------------- */

#define DESCRIPTION_IMPLEMENTATION()\
getDescriptiveParmName(UT_String& name) const\
-> void\
{ name = UI::descriptionTextField_Parameter.getToken(); }\
SOP_OPERATOR()::Callback_Description(void* data, int index, float time, const PRM_Template* tmp)\
-> int\
{\
auto me = reinterpret_cast<SOP_OPERATOR_TITLE()*>(data);\
if (!me) return 0;\
for (auto p : me->parametersList)\
{ if (p.getToken() == UI::descriptionTextField_Parameter.getToken()) me->Set_StringPRM(UT_String(""), p, time); }\
return 1;\
}

/* -----------------------------------------------------------------
UPDATE_PARMS_FLAGS												   |
----------------------------------------------------------------- */

#define DESCRIPTION_ACTIVESTATE_UPDATE(inputconnected)\
bool currentDescriptionToggleValue;\
if (inputconnected){\
Get_IntPRM(currentDescriptionToggleValue, UI::descriptionToggle_Parameter, currentTime);\
activeState = currentDescriptionToggleValue? 1: 0;\
changed |= setVisibleState(UI::cleanButton_Parameter.getToken(), activeState);\
changed |= setVisibleState(UI::descriptionTextField_Parameter.getToken(), activeState);}