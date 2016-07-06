/*
	This is a base abstract class for my SOP operators. 

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

#include "NW_SOP_DataAccess.h"

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____base_sop_title____ NW_SOP_NAME

/* -----------------------------------------------------------------
DECLARATION                                                        |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	class BASE_SOP_OPERATOR_NAME() : public NW_SOP_OPERATOR_NAME(NW_SOP_DATA_ACCESS_NAME)
	{
	protected:
		// -------------------------- Global Variables //

		// Use as default storage for error() from operations
		UT_ErrorSeverity wasSuccess;
		bool success;

		// Use as default storage for passing current time
		fpreal currentTime;

		// Use as default storage to check if some input is connected or NULL
		exint is0Connected;
		exint is1Connected;
		exint is2Connected;
		exint is3Connected;				

	public:
		BASE_SOP_OPERATOR_NAME() (OP_Network* network, const char* name, OP_Operator* op) : NW_SOP_OPERATOR_NAME(NW_SOP_DATA_ACCESS_NAME)(network, name, op) {};
		virtual ~BASE_SOP_OPERATOR_NAME() () override {};			

	protected:
			
		// -------------------------- Information //
			
		// Some information for people about you or anything you want to tell and should be visible on the operator interface
		virtual auto Setup_Information() -> void = 0;
	};

SOP_NAMESPACE_END