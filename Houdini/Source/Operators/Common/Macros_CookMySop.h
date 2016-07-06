/*
	cookMySop() and cookMySopOutput() method macros.

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
COOKMYSOP                                                          |
----------------------------------------------------------------- */

#define COOKMYSOP_DEFAULTS()\
OP_AutoLockInputs autolock(this);\
wasSuccess = autolock.lock(context);\
if (wasSuccess >= UT_ERROR_ABORT) return error();\
auto progress = UT_AutoInterrupt("Cooking first output!");\
currentTime = context.getTime();	

#define COOKMYSOPOUTPUT_DEFAULTS()\
GU_DetailHandle result;\
this->gdp = new GU_Detail();\
result.allocateAndSet(this->gdp);\
auto progress = UT_AutoInterrupt("Cooking second output!");