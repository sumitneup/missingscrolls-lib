/*
	Common helper macros for SOP.
	
	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- Move here all SOP specific macros.
	-----------------------------------------------------

	Author: 	Nodeway (2016)

	Email:		nodeway@hotmail.com
	Vimeo:		https://vimeo.com/nodeway
	Twitter:	https://twitter.com/nodeway
	Github:		https://github.com/nodeway
*/

#pragma once

/* -----------------------------------------------------------------
PARAMETERSLIST                                                     |
----------------------------------------------------------------- */

#define SOP_START_PARAMETERLIST()				PRM_Template SOP_OPERATOR_TITLE()::parametersList[] = {
#define ____SWITCH_VISIBILITY()					PRM_Template() }; PRM_Template SOP_OPERATOR_TITLE()::switchVisibilityState[] = {
#define ____SWITCH_INVERT_VISIBILITY()			PRM_Template() }; PRM_Template SOP_OPERATOR_TITLE()::switchInvertVisibilityState[] = {
#define ____SWITCH_BUTDONTFORCE_VISIBILITY()	PRM_Template() }; PRM_Template SOP_OPERATOR_TITLE()::switchButDontForceVisibilityState[] = {
#define ____SWITCH_GUIDE_ACTIVITY()				PRM_Template() }; PRM_Template SOP_OPERATOR_TITLE()::switchGuideActiveState[] = {
#define SOP_END_PARAMETERLIST()					PRM_Template() };