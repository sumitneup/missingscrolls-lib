/*
	Methods for working with error checking.

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
IMPLEMENTATION                                                     |
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

NW_SOP_OPERATOR()::Check_EnoughPrimitives(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredprimcount /* = 1 */, UT_String& errormessage /* = UT_String("") */)
-> bool
{	
	if (geometry->getPrimitiveRange().getEntries() < requiredprimcount) 
	{
		switch (errorlevel)
		{
		case NW_ERROR_LEVEL::Warning:
			{ this->addWarning(SOP_MESSAGE, errormessage == UT_String("")? UT_String("Not enough primitives."): errormessage.c_str()); }
			return false;

		case NW_ERROR_LEVEL::Error:
			{ this->addError(SOP_MESSAGE, errormessage == UT_String("")? UT_String("Not enough primitives."): errormessage.c_str()); }
			return false;
		}		
	}

	return true;
}

NW_SOP_OPERATOR()::Check_EnoughPoints(const GU_Detail* geometry, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::Warning */, exint requiredpointcount /* = 4 */, UT_String& errormessage /* = UT_String("") */) 
-> bool
{
	if (geometry->getPointRange().getEntries() < requiredpointcount)
	{
		switch (errorlevel)
		{
		case NW_ERROR_LEVEL::Warning:
			{ this->addWarning(SOP_MESSAGE, errormessage == UT_String("")? UT_String("Not enough points."): errormessage.c_str()); }
			return false;

		case NW_ERROR_LEVEL::Error:
			{ this->addError(SOP_MESSAGE, errormessage == UT_String("")? UT_String("Not enough points."): errormessage.c_str()); }
			return false;		
		}		
	}

	return true;
}

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