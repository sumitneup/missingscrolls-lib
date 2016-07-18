/*
	Methods for working with error checking.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!

	Methods starting and ending with '____' shouldn't be used anywhere outside of this file.
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

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "NW_SOP_ErrorChecking.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		NW_SOP_ERRORCHECKING_NAME

/* -----------------------------------------------------------------
PRIVATE IMPLEMENTATION                                             |
----------------------------------------------------------------- */

template <NW_COMPONENT_CLASS component>
NW_SOP_OPERATOR()::____enough_components____(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredcomponentcount /* = 1 */, UT_String& errormessage /* = UT_String("") */)
-> bool
{
	exint			currentComponentCount;
	UT_String		currentComponentErrorMessage;

	switch (component)
	{
		case NW_COMPONENT_CLASS::Vertex:
			{ 
				currentComponentCount = geometry->getVertexRange().getEntries();
				currentComponentErrorMessage = UT_String("Not enough vertices.");
			}
			break;

		case NW_COMPONENT_CLASS::Point:
			{
				currentComponentCount = geometry->getPointRange().getEntries();
				currentComponentErrorMessage = UT_String("Not enough points.");
			}
			break;

		case NW_COMPONENT_CLASS::Primitive:
			{ 
				currentComponentCount = geometry->getPrimitiveRange().getEntries(); 
				currentComponentErrorMessage = UT_String("Not enough points.");
			}
			break;
	}

	if (currentComponentCount < requiredcomponentcount)
	{
		switch (errorlevel)
		{
			case NW_ERROR_LEVEL::Warning:
				{ this->addWarning(SOP_MESSAGE, errormessage == UT_String("") ? currentComponentErrorMessage : errormessage.c_str()); }
				return false;

			case NW_ERROR_LEVEL::Error:
				{ this->addError(SOP_MESSAGE, errormessage == UT_String("") ? currentComponentErrorMessage : errormessage.c_str()); }
				return false;
		}
	}

	return true;
}

/* -----------------------------------------------------------------
PUBLIC IMPLEMENTATION                                              |
----------------------------------------------------------------- */

NW_SOP_OPERATOR()::Perform_StandardStringErrorChecking(UT_String text, SOP_ErrorCodes errortype, bool allowwhitespace /* = false */, bool allownumeric /* = false */, bool allowempty /* = false */, bool warnaboutempty /* = false */)
-> OP_ERROR
{
	// Make sure that text is a string
	if (!text.isstring())
	{
		if (text == "")
			if (allowempty)
			{
				if (warnaboutempty)
				{
					// Create warning message and compensate for different reporting formating 
					auto warningMessage = errortype == SOP_ERR_BADGROUP ? text : "()";
					addWarning(errortype, warningMessage);

					return error();
				}				
			}
			else addError(errortype, text);
	}

	// Make sure that text doesn't contain whitespace
	if (!allowwhitespace) 
		if (text.hasWhiteSpace()) addError(errortype, text);

	// Make sure that text is not numeric
	if (!allownumeric)
		if (text.isFloat() || text.isInteger()) addError(errortype, text);	

	return error();
}

NW_SOP_OPERATOR()::Perform_StandardStringErrorChecking(UT_String text, bool allowwhitespace /* = false */, bool allownumeric /* = false */, bool allowempty /* = false */) 
-> UT_ErrorSeverity
{
	auto errorCheck = UT_ERROR_NONE;

	if (!text.isstring()) 
		if (text == "") 
			if (!allowempty) errorCheck = UT_ERROR_ABORT;

	if (!allowwhitespace) if (text.hasWhiteSpace()) errorCheck = UT_ERROR_ABORT;

	if (!allownumeric) if (text.isFloat() || text.isInteger()) errorCheck = UT_ERROR_ABORT;

	return errorCheck;
}

NW_SOP_OPERATOR()::Perform_StandardStringErrorChecking(UT_String text, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, SOP_ErrorCodes errortype /* = SOP_ErrorCodes::SOP_ERR_BADGROUP */, bool allowwhitespace /* = false */, bool allownumeric /* = false */, bool allowempty /* = false */, bool warnaboutempty /* = false */)
-> bool
{
	// what happens when it's not string or empty
	if (!text.isstring())
	{
		if (text == "")
			if (!allowempty)
			{
				// Create warning message and compensate for different reporting formating 
				auto errorMessage = errortype == SOP_ERR_BADGROUP ? text : "()";

				switch (errorlevel)
				{
				case NW_ERROR_LEVEL::None:
					return false;

				case NW_ERROR_LEVEL::Warning:
					{ this->addWarning(errortype, errorMessage.c_str()); }
					return false;

				case NW_ERROR_LEVEL::Error:
					{ this->addError(errortype, errorMessage.c_str()); }
					return false;					
				}
			}
	}

	// Make sure that text doesn't contain whitespace
	if (!allowwhitespace)
		if (text.hasWhiteSpace())
		{
			switch (errorlevel)
			{
			case NW_ERROR_LEVEL::None:
				return false;

			case NW_ERROR_LEVEL::Warning:
				{ this->addWarning(errortype, text); }
				return false;

			case NW_ERROR_LEVEL::Error:
				{ this->addError(errortype, text); }
				return false;
			}
		}

	// Make sure that text is not numeric
	if (!allownumeric)
		if (text.isFloat() || text.isInteger())
		{
			switch (errorlevel)
			{
			case NW_ERROR_LEVEL::None:
				return false;

			case NW_ERROR_LEVEL::Warning:
				{ this->addWarning(errortype, text); }
				return false;

			case NW_ERROR_LEVEL::Error:
				{ this->addError(errortype, text); }
				return false;
			}
		}

	return true;
}

NW_SOP_OPERATOR()::Check_EnoughVertices(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredcomponentcount /* = 3 */, UT_String& errormessage /* = UT_String("") */)
-> bool
{ return ____enough_components____<NW_COMPONENT_CLASS::Vertex>(geometry, errorlevel, requiredcomponentcount, errormessage); }

NW_SOP_OPERATOR()::Check_EnoughPoints(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredcomponentcount /* = 4 */, UT_String& errormessage /* = UT_String("") */)
-> bool
{ return ____enough_components____<NW_COMPONENT_CLASS::Point>(geometry, errorlevel, requiredcomponentcount, errormessage); }

NW_SOP_OPERATOR()::Check_EnoughPrimitives(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredcomponentcount /* = 1 */, UT_String& errormessage /* = UT_String("") */)
-> bool
{ return ____enough_components____<NW_COMPONENT_CLASS::Primitive>(geometry, errorlevel, requiredcomponentcount, errormessage); }

NW_SOP_OPERATOR()::Check_NoZeroAreaPrimitives(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, fpreal threshold /* = 0.0f */)
-> bool
{
	auto errorMessage = UT_String("Contains zero area polygons.");

	auto primIt = GA_Iterator(geometry->getPrimitiveRange());
	for (primIt; !primIt.atEnd(); primIt.advance())
	{
		auto currPrim = geometry->getPrimitive(*primIt);		
		if (currPrim->calcArea() <= threshold)
		{
			switch (errorlevel)
			{
			case NW_ERROR_LEVEL::Warning:
				{ this->addWarning(SOP_MESSAGE, errorMessage.c_str()); }
				return false;

			case NW_ERROR_LEVEL::Error:
				{ this->addError(SOP_MESSAGE, errorMessage.c_str()); }
				return false;
			}
		}
	}

	return true;
}

NW_SOP_OPERATOR()::Check_AllPrimitivesAreClosed(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, UT_String& errormessage /* = UT_String("Polygons are not closed.") */)
-> bool
{
	auto primIt = GA_Iterator(geometry->getPrimitiveRange());
	for (primIt; !primIt.atEnd(); primIt.advance())
	{
		const auto currPrim = (GEO_PrimPoly*) geometry->getPrimitive(*primIt);
		if (currPrim->isClosed())
		{
			switch (errorlevel)
			{
			case NW_ERROR_LEVEL::Warning:
				{ this->addWarning(SOP_MESSAGE, errormessage.c_str()); }
				return false;

			case NW_ERROR_LEVEL::Error:
				{ this->addError(SOP_MESSAGE, errormessage.c_str()); }
				return false;
			}
		}
	}

	return true;
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____