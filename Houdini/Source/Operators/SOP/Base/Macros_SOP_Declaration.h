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
OPERATOR CLASS DECLARATION SNIPPETS								   |
----------------------------------------------------------------- */

#define ____default_sop_declaration_start____()\
class SOP_OPERATOR_NAME(____unique_sop_title____) : public BASE_SOP_OPERATOR_NAME() {

#define ____default_sop_public_scope_declaration____()\
public:\
static auto Create_Operator(OP_Network* network, const char* name, OP_Operator* op) -> OP_Node*;\
virtual ~SOP_OPERATOR_NAME(____unique_sop_title____)() override;\
static PRM_Template parametersList[];

#define ____default_sop_private_scope_declaration____()\
private:\
SOP_OPERATOR_NAME(____unique_sop_title____)(OP_Network* network, const char* name, OP_Operator* op);\
virtual auto Tool_BirthDate() -> string override;\
virtual auto Setup_Information() -> void override;

#define ____default_sop_protected_scope_declaration_one_output_v1____()\
protected:\
virtual auto cookMySop(OP_Context &context) -> OP_ERROR override;\
virtual auto inputLabel(unsigned input) const -> const char* override;\
virtual auto updateParmsFlags() -> bool override;

#define ____default_sop_protected_scope_declaration_one_output_v2____()\
____default_sop_protected_scope_declaration_one_output_v1____()\
virtual auto cookMyGuide1(OP_Context& context) -> OP_ERROR override;

#define ____default_sop_protected_scope_declaration_one_output_v3____()\
____default_sop_protected_scope_declaration_one_output_v2____()\
virtual auto cookMyGuide2(OP_Context& context) -> OP_ERROR override;

#define ____default_sop_protected_scope_declaration_two_outputs_v1____()\
____default_sop_protected_scope_declaration_one_output_v1____()\
virtual auto cookMySopOutput(OP_Context& context, int outputidx, SOP_Node* interest) -> GU_DetailHandle override;

#define ____default_sop_protected_scope_declaration_two_outputs_v2____()\
____default_sop_protected_scope_declaration_two_outputs_v1____()\
virtual auto cookMyGuide1(OP_Context& context) -> OP_ERROR override;

#define ____default_sop_protected_scope_declaration_two_outputs_v3____()\
____default_sop_protected_scope_declaration_two_outputs_v1____()\
virtual auto cookMyGuide2(OP_Context& context) -> OP_ERROR override;

#define ____default_sop_base_declaration____()\
____default_sop_declaration_start____()\
____default_sop_public_scope_declaration____()\
____default_sop_private_scope_declaration____()

// Ready to use declarations

#define SOP_OPERATOR_DECLARATION_ONE_OUTPUT_V1_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_one_output_v1____()

#define SOP_OPERATOR_DECLARATION_ONE_OUTPUT_V2_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_one_output_v2____()

#define SOP_OPERATOR_DECLARATION_ONE_OUTPUT_V3_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_one_output_v3____()

#define SOP_OPERATOR_DECLARATION_TWO_OUTPUTS_V1_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_two_outputs_v1____()

#define SOP_OPERATOR_DECLARATION_TWO_OUTPUTS_V2_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_two_outputs_v2____()

#define SOP_OPERATOR_DECLARATION_TWO_OUTPUTS_V3_START()\
____default_sop_base_declaration____()\
____default_sop_protected_scope_declaration_two_outputs_v3____()

#define SOP_OPERATOR_DECLARATION_END____ };

//#define ____base_sop_declaration_start____()\
//namespace Nodeway{\
//namespace SOP{\
//class SOP_OPERATOR_NAME(____unique_sop_title____)

//#define BASE_SOP_OPERATOR_DECLARATION()\
//____base_sop_declaration_start____()