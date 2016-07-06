/*
	Common parameters code snippets that allows shorten parameters generation.

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
AUTHOR SECTION                                                     |
----------------------------------------------------------------- */

#define ____default_author_section_base____()\
static auto authorParm_Name = PRM_Name("author", "");\
static auto authorEmailAdressParm_Name = PRM_Name("authoremailadress", "");\
static auto authorTwitterLinkParm_Name = PRM_Name("authortwitterlink", "");\
static auto blank_Default = PRM_Default(0, "");\
auto author_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorParm_Name, &blank_Default);\
auto authorEmailAdress_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorEmailAdressParm_Name, &blank_Default);\
auto authorTwitterLink_Parameter = PRM_Template(PRM_LABEL, PRM_TYPE_NO_LABEL, 1, &authorTwitterLinkParm_Name, &blank_Default);

#define ____custom_author_section_base____(parmcount)\
__AUTHOR_SECTION_PRM(3 + parmcount)\
____default_author_section_base____()

// ready to use

#define __DEFAULT_AUTHOR_SECTION_PRM()\
namespace AUTHOR\
{\
____custom_author_section_base____(0)\
}

#define __CUSTOM_AUTHOR_SECTION_PRM(parmcount)\
namespace AUTHOR\
{\
____custom_author_section_base____(parmcount)\
}

/* -----------------------------------------------------------------
PARAMETERSLIST                                                     |
----------------------------------------------------------------- */

#define DEFAULT_AUTHOR_PARAMETERLIST()\
AUTHOR::authorSectionSwitcher_Parameter,\
AUTHOR::author_Parameter,\
AUTHOR::authorEmailAdress_Parameter,\
AUTHOR::authorTwitterLink_Parameter