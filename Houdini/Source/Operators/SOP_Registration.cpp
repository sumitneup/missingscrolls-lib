/*
	This is a place where you should create and register all SOP's, Selectors and their custom states.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!

	#define WIP - Comment this directive if you don't want to compile operators that are used as test subjects or are still work in progress
	#define FINAL - Do not touch this. 
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
REGISTRATION SPECIFIC DEFINES                                      |
----------------------------------------------------------------- */

#define FINAL
//#define WIP

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include <UT/UT_DSOVersion.h>

#include "../Common/NW_MustHave.h"
#include "SOP/Base/NW_SOP_Operator.h"
#include "SOP/SOP_Template_Operator.h"
#include "SOP/SOP_ParametersTemplate_Operator.h"
#include "SOP/SOP_VHACDEngine_Operator.h"

#ifdef FINAL
#include "../Common/NW_MustHave.cpp"
#include "SOP/Base/NW_SOP_Operator.cpp"
#include "SOP/SOP_Template_Operator.cpp"
#include "SOP/SOP_ParametersTemplate_Operator.cpp"
#include "SOP/SOP_VHACDEngine_Operator.cpp"
#endif 

/* --------- Below define only operators that you want to test --------- */

#ifdef WIP
#include "SOP/SOP_VHACDFilter_Operator.h"
//#include "../WIP/Operators/SOP/SOP_AlignPoints_Operator.h"
//#include "../WIP/Operators/SOP/SOP_PerfectCircle_Operator.h"
#ifdef FINAL
#include "SOP/SOP_VHACDFilter_Operator.cpp"
//#include "../WIP/Operators/SOP/SOP_AlignPoints_Operator.cpp"
//#include "../WIP/Operators/SOP/SOP_PerfectCircle_Operator.cpp"
#endif 
#endif 

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
SOP REGISTRATION                                                   |
----------------------------------------------------------------- */

auto 
newSopOperator(OP_OperatorTable* table)
-> void
{
	auto success = false;

	// Creating	
	auto sopTemplate = new OP_Operator(
		SOP_TEMPLATE_OP_SMALLNAME,								// internal name
		SOP_TEMPLATE_OP_BIGNAME,								// external name
		SOP_OPERATOR_NAME(SOP_TEMPLATE_NAME)::Create_Operator,	// creator method name
		SOP_OPERATOR_NAME(SOP_TEMPLATE_NAME)::parametersList,	// parameters list name
		1,														// min inputs 
		1,														// max inputs
		0,														//
		OP_FLAG_GENERATOR,										// type of node
		0,														//
		1,														// outputs count
		SOP_TEMPLATE_SUBMENUPATH);								// tab menu path

	auto sopParametersTemplate =		new OP_Operator(SOP_PARAMETERSTEMPLATE_OP_SMALLNAME, SOP_PARAMETERSTEMPLATE_OP_BIGNAME, SOP_OPERATOR_NAME(SOP_PARAMETERSTEMPLATE_NAME)::Create_Operator, SOP_OPERATOR_NAME(SOP_PARAMETERSTEMPLATE_NAME)::parametersList, 0, 1, 0, OP_FLAG_GENERATOR, 0, 1, SOP_PARAMETERSTEMPLATE_SUBMENUPATH);
	auto sopVHACDEngine =				new OP_Operator(SOP_VHACDENGINE_OP_SMALLNAME, SOP_VHACDENGINE_OP_BIGNAME, SOP_OPERATOR_NAME(SOP_VHACDENGINE_NAME)::Create_Operator, SOP_OPERATOR_NAME(SOP_VHACDENGINE_NAME)::parametersList, 1, 1, 0, OP_FLAG_GENERATOR, 0, 1, SOP_VHACDENGINE_SUBMENUPATH);		

	// Adding			
	success = table->addOperator(sopTemplate);
	success = table->addOperator(sopParametersTemplate);
	success = table->addOperator(sopVHACDEngine);		

	// Hide nodes	
	table->addOpHidden(sopTemplate->getName());
	table->addOpHidden(sopParametersTemplate->getName());
	//table->addOpHidden(sopVHACDEngine->getName());	
	
	/* --------- Below register only operators that you want to test --------- */
	
#ifdef WIP		
	// Creating	
	auto sopVHACDFilter = new OP_Operator(SOP_VHACDFILTER_OP_SMALLNAME, SOP_VHACDFILTER_OP_BIGNAME, SOP_OPERATOR_NAME(SOP_VHACDFILTER_NAME)::Create_Operator, SOP_OPERATOR_NAME(SOP_VHACDFILTER_NAME)::parametersList, 1, 1, 0, OP_FLAG_GENERATOR, 0, 1, SOP_VHACDFILTER_SUBMENUPATH);
	//auto sopAlignPoints =				new OP_Operator(SOP_ALIGNPOINTS_OP_SMALLNAME, SOP_ALIGNPOINTS_OP_BIGNAME, SOP_OPERATOR_NAME(SOP_ALIGNPOINTS_NAME)::Create_Operator, SOP_OPERATOR_NAME(SOP_ALIGNPOINTS_NAME)::parametersList, 1, 2, 0, OP_FLAG_GENERATOR, 0, 1, SOP_ALIGNPOINTS_SUBMENUPATH);
	//auto sopPerfectCircle =				new OP_Operator(SOP_PERFECTCIRCLE_OP_SMALLNAME, SOP_PERFECTCIRCLE_OP_BIGNAME, SOP_OPERATOR_NAME(SOP_PERFECTCIRCLE_NAME)::Create_Operator, SOP_OPERATOR_NAME(SOP_PERFECTCIRCLE_NAME)::parametersList, 1, 1, 0, OP_FLAG_GENERATOR, 0, 1, SOP_PERFECTCIRCLE_SUBMENUPATH);	


	// Adding		
	success = table->addOperator(sopVHACDFilter);
	//success = table->addOperator(sopAlignPoints);
	//success = table->addOperator(sopPerfectCircle);	

	// Hide nodes		
	//table->addOpHidden(sopVHACDFilter->getName());
#endif
}