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