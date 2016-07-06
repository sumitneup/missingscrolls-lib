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