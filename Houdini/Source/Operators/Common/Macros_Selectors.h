/*
	Selecor macros..

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
SELECTOR CLASS SNIPPETS											   |
----------------------------------------------------------------- */

#define REUSABLESELECTOR_DECLARATION(selectorname)\
namespace Nodeway {\
namespace Selector {\
class SOP_SELECTOR_NAME(____unique_sop_title____, selectorname) : public MSS_ReusableSelector {\
public:\
static auto Create_Selector(BM_View& viewer, PI_SelectorTemplate& templ) -> BM_InputSelector*;\
virtual ~SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)() override;\
virtual auto className() const -> const char* override;\
private:\
SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)(OP3D_View& viewer, PI_SelectorTemplate& templ);\
};}}

// setAllowUseExistingSelection - make sure we cannot use existing selection => http://www.sidefx.com/index.php?option=com_forum&Itemid=172&page=viewtopic&t=31494&highlight=

#define REUSABLESELECTOR_IMPLEMENTATION(selectorname, selectorstringclassname, sopsmallname, operatorparametername, useexisting)\
SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)::SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)(OP3D_View& viewer, PI_SelectorTemplate& templ)\
: MSS_ReusableSelector(viewer, templ, sopsmallname, operatorparametername##.getToken(), 0, true)\
{\
	this->setAllowUseExistingSelection(useexisting);\
}\
SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)::~SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)() {}\
SOP_SELECTOR(selectorname)::Create_Selector(BM_View& viewer, PI_SelectorTemplate &templ) -> BM_InputSelector*\
{ return new SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)((OP3D_View&)viewer, templ); }\
SOP_SELECTOR(selectorname)::className() const -> const char*\
{ return selectorstringclassname; }

/* -----------------------------------------------------------------
REGISTRATION											           |
----------------------------------------------------------------- */

#define REGISTER_SELECTOR(sopsmallname, selectorvarname, selectorsmallname, selectorbigname, operatorname, selectorname, selectiontype, prompt, bindto, connectto, isrequired)\
auto selectorvarname##forSOP = OP_Network::getOperatorTable(SOP_TABLE_NAME)->getOperator(sopsmallname);\
if(!selectorvarname##forSOP) { UT_ASSERT(!sopsmallname); return; }\
auto selectorvarname##Selector = new PI_SelectorTemplate(selectorsmallname, selectorbigname, SOP_TABLE_NAME);\
selectorvarname##Selector->constructor((void*) &SOP_SELECTOR_NAME(operatorname, selectorname)::Create_Selector);\
selectorvarname##Selector->data(selectiontype);\
wasSuccess = m->registerSelector(selectorvarname##Selector);\
wasSuccess = m->bindSelector(selectorvarname##forSOP, selectorsmallname, selectorbigname, prompt, bindto.getToken(), connectto, isrequired, "0x00000001", 0, 0, 0, 0, false);