/*
	Base class specific defaults
	
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

#include "../../../Common/NW_MustHave.h"

#include "../../Common/Macros_Selectors.h"

#include "../../Common/Macros_UpdateParmsFlags.h"
#include "../../Common/Macros_CookMyGuide.h"
#include "../../Common/Macros_CookMySop.h"

#include "../../Common/Macros_AttributePRM.h"
#include "../../Common/Macros_AttributeMenuPRM.h"
#include "../../Common/Macros_GroupMenuPRM.h"
#include "../../Common/Macros_ColorPRM.h"
#include "../../Common/Macros_VectorPRM.h"
#include "../../Common/Macros_FloatPRM.h"
#include "../../Common/Macros_IntegerPRM.h"
#include "../../Common/Macros_StringPRM.h"
#include "../../Common/Macros_TogglePRM.h"
#include "../../Common/Macros_ChoiceMenuPRM.h"
#include "../../Common/Macros_SeparatorPRM.h"
#include "../../Common/Macros_PrecisionPRM.h"
#include "../../Common/Macros_ErrorPRM.h"
#include "../../Common/Macros_SwitcherPRM.h"
#include "../../Common/Macros_CreateGroupPRM.h"
#include "../../Common/Macros_DescriptionPRM.h"
#include "../../Common/Macros_LabelPRM.h"

#include "../../Common/Macros_TitleSection.h"
#include "../../Common/Macros_AuthorSection.h"
#include "../../Common/Macros_GroupSection.h"

#include "Macros_NW_SOP.h"
#include "Macros_SOP_Declaration.h"
#include "Macros_SOP_Implementation.h"
#include "Macros_ParameterList.h"

/* -----------------------------------------------------------------
OPERATOR SPECIFIC DEFINES                                          |
----------------------------------------------------------------- */

// -------------------------- Defaults //

#define NW_SOP_NAME					GONodeway
#define NW_SOP_DATA_ACCESS_NAME		DataAccess
#define NW_SOP_ERRORCHECKING_NAME	ErrorChecking