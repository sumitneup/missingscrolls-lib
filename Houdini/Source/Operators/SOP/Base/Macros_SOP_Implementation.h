/*
	Common helper macros for SOP.
	
	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- Move here all SOP specific macros.
	-----------------------------------------------------

	Author: 	Nodeway (2016)

	Email:		nodeway@hotmail.com
	Vimeo:		https://vimeo.com/nodeway
	Twitter:	https://twitter.com/nodeway
	Github:		https://github.com/nodeway
*/

#pragma once

/* -----------------------------------------------------------------
OPERATOR CLASS IMPLEMENTATION SNIPPETS							   |
----------------------------------------------------------------- */

#define SOP_OPERATOR_INITIALIZATION(iconname)\
SOP_OPERATOR_NAME(____unique_sop_title____)::SOP_OPERATOR_NAME(____unique_sop_title____)(OP_Network* network, const char* name, OP_Operator* op)\
: BASE_SOP_OPERATOR_NAME()(network, name, op)\
{\
	op->setIconName(iconname);\
	this->Setup_Information();\
}\
SOP_OPERATOR_NAME(____unique_sop_title____)::~SOP_OPERATOR_NAME(____unique_sop_title____)() {}\
SOP_OPERATOR()::Create_Operator(OP_Network* network, const char* name, OP_Operator* op) -> OP_Node*\
{ return new SOP_OPERATOR_NAME(____unique_sop_title____) (network, name, op); }\
SOP_OPERATOR()::inputLabel(unsigned int input) const -> const char*