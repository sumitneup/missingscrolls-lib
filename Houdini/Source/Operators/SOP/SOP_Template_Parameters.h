/*
	Use this as a starting template for any SOP operator.

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
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "SOP_Template_Operator.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____ SOP_TEMPLATE_NAME

/* -----------------------------------------------------------------
PARAMETERS                                                         |
----------------------------------------------------------------- */

SOP_PARMS_NAMESPACE()
{
	OPERATOR_TITLE_SECTION(SOP_TEMPLATE_OPERATOR_TITLE)
	namespace TITLE
	{
		DEFAULT_INPUT_0_NOT_CONNECTED_ERROR_MESSAGE()
	}

	namespace UI
	{
		__FILTER_SECTION_PRM(0)
		__MAIN_SECTION_PRM(0)

		__ADDITIONAL_SECTION_PRM(4)
		DESCRIPTION_PRM()

		__DEBUG_SECTION_PRM(0)
	}

	__DEFAULT_AUTHOR_SECTION_PRM()
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____