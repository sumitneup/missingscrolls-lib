/*
	Common parameters code snippets that allows shorten parameters generation.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!	

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- Fix BASE_SOP_OPERATOR_NAME()::groupMenu etc. not working.
	  Right now we have to use SOP_Node instead.
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
GROUP MENU DEFAULTS												   |
----------------------------------------------------------------- */

#define ____custom_group_type_t_input_n_parameter____(smallname, bigname, varname, menutype, input, helptext)\
static auto varname##GroupParm_Name = PRM_Name(smallname, bigname);\
auto varname##Group_Parameter = PRM_Template(PRM_STRING, 1, &varname##GroupParm_Name, 0, &menutype, 0, 0, &input, 1, helptext);

#define DEFAULT_GROUP_MENU_BIGNAME							"Group"
#define DEFAULT_POINTGROUP_MENU_BIGNAME						"Point Group"
#define DEFAULT_EDGEGROUP_MENU_BIGNAME						"Edge Group"
#define DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME					"Primitive Group"

// ready to use

#define DEFAULT_GROUP_INPUT_0_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput0", DEFAULT_GROUP_MENU_BIGNAME, varname, SOP_Node::groupMenu, SOP_Node::theFirstInput, "Specify geometry group from first input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_GROUP_INPUT_1_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput1", DEFAULT_GROUP_MENU_BIGNAME, varname, SOP_Node::groupMenu, SOP_Node::theSecondInput, "Specify geometry group from second input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_GROUP_INPUT_2_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput2", DEFAULT_GROUP_MENU_BIGNAME, varname, SOP_Node::groupMenu, SOP_Node::theThirdInput, "Specify geometry group from third input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_GROUP_INPUT_3_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput3", DEFAULT_GROUP_MENU_BIGNAME, varname, SOP_Node::groupMenu, SOP_Node::theFourthInput, "Specify geometry group from fourth input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_POINTGROUP_INPUT_0_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput0", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, SOP_Node::pointGroupMenu, SOP_Node::theFirstInput, "Specify point group from first input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_POINTGROUP_INPUT_1_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput1", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, SOP_Node::pointGroupMenu, SOP_Node::theSecondInput, "Specify point group from second input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_POINTGROUP_INPUT_2_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput2", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, SOP_Node::pointGroupMenu, SOP_Node::theThirdInput, "Specify point group from third input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_POINTGROUP_INPUT_3_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput3", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, SOP_Node::pointGroupMenu, SOP_Node::theFourthInput, "Specify point group from fourth input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_EDGEGROUP_INPUT_0_PRM(varname)				____custom_group_type_t_input_n_parameter____("edgegroupinput0", DEFAULT_EDGEGROUP_MENU_BIGNAME, varname##Edge, SOP_Node::edgeGroupMenu, SOP_Node::theFirstInput, "Specify edge group from first input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_EDGEGROUP_INPUT_1_PRM(varname)				____custom_group_type_t_input_n_parameter____("edgegroupinput1", DEFAULT_EDGEGROUP_MENU_BIGNAME, varname##Edge, SOP_Node::edgeGroupMenu, SOP_Node::theSecondInput, "Specify edge group from second input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_EDGEGROUP_INPUT_2_PRM(varname)				____custom_group_type_t_input_n_parameter____("edgegroupinput2", DEFAULT_EDGEGROUP_MENU_BIGNAME, varname##Edge, SOP_Node::edgeGroupMenu, SOP_Node::theThirdInput, "Specify edge group from third input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_EDGEGROUP_INPUT_3_PRM(varname)				____custom_group_type_t_input_n_parameter____("edgegroupinput3", DEFAULT_EDGEGROUP_MENU_BIGNAME, varname##Edge, SOP_Node::edgeGroupMenu, SOP_Node::theFourthInput, "Specify edge group from fourth input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_PRIMITIVEGROUP_INPUT_0_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput0", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, SOP_Node::primGroupMenu, SOP_Node::theFirstInput, "Specify primitive group from first input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_PRIMITIVEGROUP_INPUT_1_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput1", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, SOP_Node::primGroupMenu, SOP_Node::theSecondInput, "Specify primitive group from second input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_PRIMITIVEGROUP_INPUT_2_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput2", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, SOP_Node::primGroupMenu, SOP_Node::theThirdInput, "Specify primitive group from third input. Leaving it empty will use whole incoming geometry.")
#define DEFAULT_PRIMITIVEGROUP_INPUT_3_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput3", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, SOP_Node::primGroupMenu, SOP_Node::theFourthInput, "Specify primitive group from fourth input. Leaving it empty will use whole incoming geometry.")

/*
#define DEFAULT_GROUP_INPUT_0_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput0", DEFAULT_GROUP_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::groupMenu, BASE_SOP_OPERATOR_NAME()::theFirstInput)
#define DEFAULT_GROUP_INPUT_1_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput1", DEFAULT_GROUP_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::groupMenu, BASE_SOP_OPERATOR_NAME()::theSecondInput)
#define DEFAULT_GROUP_INPUT_2_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput2", DEFAULT_GROUP_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::groupMenu, BASE_SOP_OPERATOR_NAME()::theThirdInput)
#define DEFAULT_GROUP_INPUT_3_PRM(varname)					____custom_group_type_t_input_n_parameter____("groupinput3", DEFAULT_GROUP_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::groupMenu, BASE_SOP_OPERATOR_NAME()::theFourthInput)
#define DEFAULT_POINTGROUP_INPUT_0_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput0", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, BASE_SOP_OPERATOR_NAME()::pointGroupMenu, BASE_SOP_OPERATOR_NAME()::theFirstInput)
#define DEFAULT_POINTGROUP_INPUT_1_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput1", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, BASE_SOP_OPERATOR_NAME()::pointGroupMenu, BASE_SOP_OPERATOR_NAME()::theSecondInput)
#define DEFAULT_POINTGROUP_INPUT_2_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput2", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, BASE_SOP_OPERATOR_NAME()::pointGroupMenu, BASE_SOP_OPERATOR_NAME()::theThirdInput)
#define DEFAULT_POINTGROUP_INPUT_3_PRM(varname)				____custom_group_type_t_input_n_parameter____("pointgroupinput3", DEFAULT_POINTGROUP_MENU_BIGNAME, varname##Point, BASE_SOP_OPERATOR_NAME()::pointGroupMenu, BASE_SOP_OPERATOR_NAME()::theFourthInput)
#define DEFAULT_PRIMITIVEGROUP_INPUT_0_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput0", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, BASE_SOP_OPERATOR_NAME()::primGroupMenu, BASE_SOP_OPERATOR_NAME()::theFirstInput)
#define DEFAULT_PRIMITIVEGROUP_INPUT_1_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput1", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, BASE_SOP_OPERATOR_NAME()::primGroupMenu, BASE_SOP_OPERATOR_NAME()::theSecondInput)
#define DEFAULT_PRIMITIVEGROUP_INPUT_2_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput2", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, BASE_SOP_OPERATOR_NAME()::primGroupMenu, BASE_SOP_OPERATOR_NAME()::theThirdInput)
#define DEFAULT_PRIMITIVEGROUP_INPUT_3_PRM(varname)			____custom_group_type_t_input_n_parameter____("primitivegroupinput3", DEFAULT_PRIMITIVEGROUP_MENU_BIGNAME, varname##Primitive, BASE_SOP_OPERATOR_NAME()::primGroupMenu, BASE_SOP_OPERATOR_NAME()::theFourthInput)
*/