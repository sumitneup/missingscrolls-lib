/*
	Common code snippets that allows to omit and ease generation of some common operator/selector parts.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!

	Macros starting and ending with '____' shouldn't be used anywhere outside of this file.
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- remove all SOP specific macros
	- leave only ones that can be used in more than one context
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
NAMES DEFAULTS                                                     |
----------------------------------------------------------------- */

#define ____make_classname____(extensiontype, extensionname) extensiontype##_##extensionname
#define ____make_parm_namespace____(extensiontype, extensionname) ____make_classname____(extensiontype, extensionname)##_PARAMETERS

/* -----------------------------------------------------------------
INPUT DEFAULTS                                                     |
----------------------------------------------------------------- */

#define DEFAULTINPUT_NAME							"WTF?"

/* -----------------------------------------------------------------
SETUP INFORMATION DEFAULTS                                         |
----------------------------------------------------------------- */

#define SETUP_INFORMATION_DEFAULTS_V1()\
this->Set_StringPRM(UT_String(this->Tool_Author() + " (" + this->Tool_BirthDate() + ")"), AUTHOR::author_Parameter);\
this->Set_StringPRM(UT_String("Email: " + this->Tool_AuthorEmailAdress()), AUTHOR::authorEmailAdress_Parameter);\
this->Set_StringPRM(UT_String("Twitter: " + this->Tool_AuthorTwitterLink()), AUTHOR::authorTwitterLink_Parameter);