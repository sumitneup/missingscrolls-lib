/*
	updateParmsFlags() method macros.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
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
UPDATEPARMSFLAGS                                                   |
----------------------------------------------------------------- */

#define UPDATEPARMSFLAGS_DEFAULTS()\
auto changed = BASE_SOP_OPERATOR_NAME()::updateParmsFlags();\
currentTime = CHgetEvalTime();\
exint visibilityState;\
exint activeState;

#define GUIDE_ACTIVESTATE() static PRM_Template switchGuideActiveState[];
#define GUIDE_ACTIVESTATE_UPDATE(activitystate) for (auto parameter : switchGuideActiveState) changed |= this->setVisibleState(parameter.getToken(), activitystate);

#define PARAMETERS_VISIBILITYSTATE()\
private:\
static PRM_Template switchVisibilityState[];\
static PRM_Template switchInvertVisibilityState[];\
static PRM_Template switchButDontForceVisibilityState[];

#define PARAMETERS_VISIBLESTATE_UPDATE(visibilitystate)\
for (auto parameter : switchVisibilityState) changed |= this->setVisibleState(parameter.getToken(), visibilitystate);\
for (auto parameter : switchInvertVisibilityState) changed |= this->setVisibleState(parameter.getToken(), !visibilitystate);\
for (auto parameter : switchButDontForceVisibilityState) changed |= this->setVisibleState(parameter.getToken(), 0);