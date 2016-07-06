/*
	Common parameters code snippets that allows shorten parameters generation.

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
ATTRIBUTE MENU DEFAULTS                                            |
----------------------------------------------------------------- */

#define ____custom_attribute_type_t_input_n_parameter____(smallname, bigname, varname, menutype, input)\
static auto varname##AttributeMenuParm_Name = PRM_Name(smallname, bigname);\
auto varname##AttributeMenu_Parameter = PRM_Template(PRM_STRING, 1, &varname##AttributeMenuParm_Name, PRMzeroDefaults, &menutype, 0, 0, &input);

#define DEFAULT_POINTATTRIBUTE_MENU_BIGNAME "Point Attribute Name"
#define DEFAULT_PRIMITIVEATTRIBUTE_MENU_BIGNAME "Primitive Attribute Name"

// ready to use

#define DEFAULT_POINTATTRIBUTE_MENU_INPUT_0_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("pointattributenameinput0", DEFAULT_POINTATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::pointAttribMenu, BASE_SOP_OPERATOR_NAME()::theFirstInput)
#define DEFAULT_POINTATTRIBUTE_MENU_INPUT_1_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("pointattributenameinput1", DEFAULT_POINTATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::pointAttribMenu, BASE_SOP_OPERATOR_NAME()::)
#define DEFAULT_POINTATTRIBUTE_MENU_INPUT_2_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("pointattributenameinput2", DEFAULT_POINTATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::pointAttribMenu, BASE_SOP_OPERATOR_NAME()::theThirdInput)
#define DEFAULT_POINTATTRIBUTE_MENU_INPUT_3_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("pointattributenameinput3", DEFAULT_POINTATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::pointAttribMenu, BASE_SOP_OPERATOR_NAME()::theFourthInput)
#define DEFAULT_PRIMITIVETTRIBUTE_MENU_INPUT_0_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("primitiveattributenameinput0", DEFAULT_PRIMITIVEATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::primAttribMenu, BASE_SOP_OPERATOR_NAME()::theFirstInput)
#define DEFAULT_PRIMITIVETTRIBUTE_MENU_INPUT_1_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("primitiveattributenameinput1", DEFAULT_PRIMITIVEATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::primAttribMenu, BASE_SOP_OPERATOR_NAME()::theSecondInput)
#define DEFAULT_PRIMITIVETTRIBUTE_MENU_INPUT_2_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("primitiveattributenameinput2", DEFAULT_PRIMITIVEATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::primAttribMenu, BASE_SOP_OPERATOR_NAME()::theThirdInput)
#define DEFAULT_PRIMITIVETTRIBUTE_MENU_INPUT_3_PRM(varname) ____custom_attribute_type_t_input_n_parameter____("primitiveattributenameinput3", DEFAULT_PRIMITIVEATTRIBUTE_MENU_BIGNAME, varname, BASE_SOP_OPERATOR_NAME()::primAttribMenu, BASE_SOP_OPERATOR_NAME()::theFourthInput)