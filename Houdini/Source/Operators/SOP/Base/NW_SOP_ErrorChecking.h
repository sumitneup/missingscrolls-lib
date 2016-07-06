/*
	Methods for working with error checking.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- Perform_StandardStringErrorChecking() instead of OP_ERROR/UT_ErrorSeverity should return bool
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

#include "NW_SOP_Configuration.h"

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		NW_SOP_ERRORCHECKING_NAME

/* -----------------------------------------------------------------
DECLARATION                                                        |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	class NW_SOP_OPERATOR_TITLE() : public SOP_Node, public NW_MustHave
	{
	public:
		NW_SOP_OPERATOR_TITLE() (OP_Network* network, const char* name, OP_Operator* op) : SOP_Node(network, name, op), NW_MustHave() {};
		virtual ~NW_SOP_OPERATOR_TITLE() () override {};

	protected:

		SYS_DEPRECATED_HDK_REPLACE(15.0, the one that returns <bool>)
		virtual auto Perform_StandardStringErrorChecking(UT_String text, SOP_ErrorCodes errortype, bool allowwhitespace = false, bool allownumeric = false, bool allowempty = false, bool warnaboutempty = false) -> OP_ERROR;
		SYS_DEPRECATED_HDK_REPLACE(15.0, the one that returns <bool>)
		virtual auto Perform_StandardStringErrorChecking(UT_String text, bool allowwhitespace = false, bool allownumeric = false, bool allowempty = false) -> UT_ErrorSeverity;

		virtual auto Perform_StandardStringErrorChecking(UT_String text, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, SOP_ErrorCodes errortype = SOP_ErrorCodes::SOP_ERR_BADGROUP, bool allowwhitespace = false, bool allownumeric = false, bool allowempty = false, bool warnaboutempty = false) -> bool;

		virtual auto Check_EnoughPrimitives(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::Warning, exint requiredprimcount = 1, UT_String& errormessage = UT_String("")) -> bool;
		virtual auto Check_EnoughPoints(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::Warning, exint requiredpointcount = 4, UT_String& errormessage = UT_String("")) -> bool;
		virtual auto Check_NoZeroAreaPrimitives(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::Warning, fpreal threshold = 0.0f) -> bool;
		virtual auto Check_AllPrimitivesAreClosed(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::Warning, UT_String& errormessage = UT_String("Polygons are not closed.")) -> bool;		
	};

SOP_NAMESPACE_END

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____