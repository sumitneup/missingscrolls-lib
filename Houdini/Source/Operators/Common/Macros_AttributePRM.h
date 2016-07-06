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
PRM                                                                |
----------------------------------------------------------------- */

#define SIMPLE_CREATE_ATTRIBUTE_PRM(togglesmallname, togglebigname, separatorname, smallname, bigname, callbackname, togglehelptext, helptext, defaultvalue, varname)\
CUSTOM_TOOGLE_OFF_JOIN_PRM(togglesmallname, togglebigname, callbackname, togglehelptext, varname)\
CUSTOM_SEPARATOR_PARM(separatorname, varname)\
CUSTOM_STRING_PRM(smallname, bigname, defaultvalue, helptext, varname)

/* -----------------------------------------------------------------
MENUS                                                              |
----------------------------------------------------------------- */

#define CUSTOM_VERTEX_POINT_PRIMITIVE_DETAIL_MENU_PRM(smallname, bigname, varname)\
static auto varname##VertexPointPrimitiveDetailClassMenuParm_Name = PRM_Name(smallname, bigname);\
static PRM_Name varname##VertexPointPrimitiveDetailClassMenuParm_Choices[] =\
{\
	PRM_Name("0", "Vertex"),\
	PRM_Name("1", "Point"),\
	PRM_Name("2", "Primitive"),\
	PRM_Name("3", "Detail"),\
	PRM_Name(0)\
};\
static auto varname##VertexPointPrimitiveDetailClassMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##VertexPointPrimitiveDetailClassMenuParm_Choices);\
auto varname##VertexPointPrimitiveDetailClassMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##VertexPointPrimitiveDetailClassMenuParm_Name, 0, &varname##VertexPointPrimitiveDetailClassMenuParm_ChoiceList);

#define CUSTOM_POINT_PRIMITIVE_CLASS_MENU_PRM(smallname, bigname, varname)\
static auto varname##PointPrimitiveClassMenuParm_Name = PRM_Name(smallname, bigname);\
static PRM_Name varname##PointPrimitiveClassMenuParm_Choices[] =\
{\
	PRM_Name("0", "Point"),\
	PRM_Name("1", "Primitive"),\
	PRM_Name(0)\
};\
static auto varname##PointPrimitiveClassMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##PointPrimitiveClassMenuParm_Choices);\
auto varname##PointPrimitiveClassMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##PointPrimitiveClassMenuParm_Name, 0, &varname##PointPrimitiveClassMenuParm_ChoiceList);

#define CUSTOM_ATTRIBUTE_TYPE_MENU_PRM(smallname, bigname, varname)\
static auto varname##AttributeTypeMenuParm_Name = PRM_Name(smallname, bigname);\
static PRM_Name varname##AttributeTypeMenuParm_Choices[] =\
{\
	PRM_Name("0", "Integer"),\
	PRM_Name("1", "Float"),\
	PRM_Name("2", "Vector2"),\
	PRM_Name("3", "Vector3"),\
	PRM_Name("4", "Vector4"),\
	PRM_Name(0)\
};\
static auto varname##AttributeTypeMenuParm_ChoiceList = PRM_ChoiceList(PRM_CHOICELIST_SINGLE, varname##AttributeTypeMenuParm_Choices);\
auto varname##AttributeTypeMenu_Parameter = PRM_Template(PRM_ORD, 1, &varname##AttributeTypeMenuParm_Name, 0, &varname##AttributeTypeMenuParm_ChoiceList);