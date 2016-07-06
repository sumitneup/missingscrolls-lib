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