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