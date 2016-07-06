/*
	This class must be inherited by any base class of any extension.

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

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "NW_MustHave.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

using namespace Nodeway;

/* -----------------------------------------------------------------
INFORMATION                                                        |
----------------------------------------------------------------- */

// Some information about tool for outside world
auto
NW_MustHave::Tool_Author()
-> string
{
	return NW;
}

auto
NW_MustHave::Tool_BirthDate()
-> string
{
	return "None";
}

auto
NW_MustHave::Tool_AuthorEmailAdress()
-> string
{
	return NW_EMAIL;
}

auto
NW_MustHave::Tool_AuthorSkypeName()
-> string
{
	return "None";
}
auto
NW_MustHave::Tool_AuthorVimeoLink()
-> string
{
	return NW_VIMEO;
}

auto
NW_MustHave::Tool_AuthorTwitterLink()
-> string
{
	return NW_TWITTER;
}

auto
NW_MustHave::Tool_AuthorLinkedinLink()
-> string
{
	return "None";
}

auto
NW_MustHave::Tool_AuthorOdforceName()
-> string
{
	return "None";
}

auto
NW_MustHave::Tool_AuthorGithubLink()
-> string
{
	return "None";
}

auto
NW_MustHave::Tool_ExplanationVideoLink()
-> string
{
	return "None";
}

auto
NW_MustHave::Tool_ModifiedBy()
-> string
{
	return "None";
}