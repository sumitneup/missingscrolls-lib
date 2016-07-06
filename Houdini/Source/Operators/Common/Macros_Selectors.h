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