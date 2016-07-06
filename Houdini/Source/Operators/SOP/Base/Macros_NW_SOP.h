/*
	Common helper macros for SOP.
	
	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- for NW_SOP_OPERATOR_NAME make it so it wouldn't require passing name
	  but make sure that we have something for inheriting also
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
NAMESPACE                                                          |
----------------------------------------------------------------- */

#define SOP_NAMESPACE_START()\
namespace Nodeway{\
namespace Operators{\
namespace SOP{

#define SOP_NAMESPACE_END									}}}

#define GET_SOP_NAMESPACE()									using namespace Nodeway::Operators::SOP;

/* -----------------------------------------------------------------
NAMES DEFAULTS                                                     |
----------------------------------------------------------------- */

#define NW_SOP_OPERATOR_NAME(operatorname)					____make_classname____(NW_SOP, operatorname)##_Operator
#define NW_SOP_OPERATOR_TITLE()								NW_SOP_OPERATOR_NAME(____unique_sop_title____)
#define NW_SOP_OPERATOR()									auto NW_SOP_OPERATOR_TITLE()	

#define SOP_OPERATOR_NAME(operatorname)						____make_classname____(SOP, operatorname)##_Operator
#define SOP_OPERATOR_TITLE()								SOP_OPERATOR_NAME(____unique_sop_title____)
#define SOP_OPERATOR()										auto SOP_OPERATOR_TITLE()

#define SOP_SELECTOR_NAME(operatorname, selectorname)		____make_classname____(SOP, operatorname)##_##selectorname##_Selector
#define SOP_SELECTOR_TITLE()								SOP_SELECTOR_NAME(____unique_sop_title____, selectorname)
#define SOP_SELECTOR(selectorname)							auto SOP_SELECTOR_TITLE()

#define SOP_PARMS_NAMESPACE_NAME(operatorname)				____make_parm_namespace____(SOP, operatorname)
#define SOP_PARMS_NAMESPACE_TITLE()							SOP_PARMS_NAMESPACE_NAME(____unique_sop_title____)
#define SOP_PARMS_NAMESPACE()								namespace SOP_PARMS_NAMESPACE_TITLE()

#define BASE_SOP_OPERATOR_NAME()							SOP_OPERATOR_NAME(____base_sop_title____)
#define BASE_SOP_OPERATOR()									auto BASE_SOP_OPERATOR_NAME()

//#define SOP_INHERITED_OPERATOR_NAME()