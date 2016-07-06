/*
	This is a place where you should specify common for all extensions enumerations.
	Most of the enumerations here is for templates, to help simplify method creation.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
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
ENUMS                                                              |
----------------------------------------------------------------- */

enum NW_GA_AttributeClass
{
	GA_INTEGER_ATTRIBUTECLASS,
	GA_FLOAT_ATTRIBUTECLASS,
	GA_VECTOR2_ATTRIBUTECLASS,
	GA_VECTOR3_ATTRIBUTECLASS,
	GA_VECTOR4_ATTRIBUTECLASS,
	GA_STRING_ATTRIBUTECLASS
};

enum NW_ERROR_LEVEL
{
	None,
	Warning,
	Error
};