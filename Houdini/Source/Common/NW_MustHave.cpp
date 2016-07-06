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