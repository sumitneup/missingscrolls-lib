/*
	Vector PRM macros.

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
VECTOR DEFAULTS                                                    |
----------------------------------------------------------------- */

#define ____custom_vector_t_data____(smallname, bigname, size, defaults, helptext, varname)\
static auto varname##Vector##size##Parm_Name = PRM_Name(smallname, bigname);\
auto varname##Vector##size##_Parameter = PRM_Template(PRM_XYZ, size, &varname##Vector##size##Parm_Name, defaults, 0, 0, 0, 0, 0, helptext);


//static auto varname##IntegerParm_Range = PRM_Range(rangemintype, rangemin, rangemaxtype, rangemax);\

// ready to use

#define CUSTOM_VECTOR2_PRM(smallname, bigname, defaultx, defaulty, helptext, varname)\
static PRM_Default varname##Vector2Parm_Defaults[] = { PRM_Default(defaultx), PRM_Default(defaulty) };\
____custom_vector_t_data____(smallname, bigname, 2, varname##Vector2Parm_Defaults, helptext, varname)

#define CUSTOM_VECTOR3_PRM(smallname, bigname, defaultx, defaulty, defaultz, helptext, varname)\
static PRM_Default varname##Vector3Parm_Defaults[] = { PRM_Default(defaultx), PRM_Default(defaulty), PRM_Default(defaultz) };\
____custom_vector_t_data____(smallname, bigname, 3, varname##Vector3Parm_Defaults, helptext, varname)

#define DEFAULT_VECTOR2_00_PRM(smallname, bigname, helptext, varname)		CUSTOM_VECTOR2_PRM(smallname, bigname, 0.0f, 0.0f, helptext, varname)
#define DEFAULT_VECTOR3_000_PRM(smallname, bigname, helptext, varname)		CUSTOM_VECTOR3_PRM(smallname, bigname, 0.0f, 0.0f, 0.0f, helptext, varname)
#define DEFAULT_VECTOR3_010_PRM(smallname, bigname, helptext, varname)		CUSTOM_VECTOR3_PRM(smallname, bigname, 0.0f, 1.0f, 0.0f, helptext, varname)

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
/*
PRM_Template(PRM_Type thetype,
PRM_Export theexportlevel,
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