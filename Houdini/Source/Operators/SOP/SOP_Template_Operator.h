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

#include "SOP_Template_Configuration.h"

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		SOP_TEMPLATE_NAME

/* -----------------------------------------------------------------
DECLARATION                                                        |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	SOP_OPERATOR_DECLARATION_ONE_OUTPUT_V1_START()

		DESCRIPTION_DECLARATION()
		PARAMETERS_VISIBILITYSTATE()

		private:		

	SOP_OPERATOR_DECLARATION_END____

SOP_NAMESPACE_END

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____