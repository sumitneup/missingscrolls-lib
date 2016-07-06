/*
	cookMyGuide1() and cookMyGuide2() method macros.

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
COOKMYGUIDE                                                        |
----------------------------------------------------------------- */

#define SOP_COOKMYGUIDE1() SOP_OPERATOR()::cookMyGuide1(OP_Context& context) -> OP_ERROR
#define SOP_COOKMYGUIDE2() SOP_OPERATOR()::cookMyGuide2(OP_Context& context) -> OP_ERROR

#define ____cookmyguide_defaults____(text)\
OP_AutoLockInputs autolock(this);\
this->wasSuccess = this->autolock.lock(context);\
if (this->wasSuccess >= UT_ERROR_ABORT) return error();\
auto progress = UT_AutoInterrupt(text);\
this->currentTime = context.getTime();

#define COOKMYGUIDE1_DEFAULTS()\
____cookmyguide_defaults____("Cooking Guide 1!")\
this->myGuide1->clearAndDestroy();

#define COOKMYGUIDE2_DEFAULTS()\
____cookmyguide_defaults____("Cooking Guide 2!")\
this->myGuide2->clearAndDestroy();