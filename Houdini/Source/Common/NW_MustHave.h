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

#pragma once

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "Global_Configuration.h"

/* -----------------------------------------------------------------
DECLARATION                                                        |
----------------------------------------------------------------- */

namespace Nodeway
{
	class NW_MustHave
	{
	public:
		NW_MustHave() {};
		virtual ~NW_MustHave() {};

		// -------------------------- Information //

		virtual auto Tool_Author() -> string;
		virtual auto Tool_BirthDate() -> string;
		virtual auto Tool_AuthorEmailAdress() -> string;
		virtual auto Tool_AuthorSkypeName() -> string;
		virtual auto Tool_AuthorVimeoLink() -> string;
		virtual auto Tool_AuthorTwitterLink() -> string;
		virtual auto Tool_AuthorLinkedinLink() -> string;
		virtual auto Tool_AuthorOdforceName() -> string;
		virtual auto Tool_AuthorGithubLink() -> string;
		virtual auto Tool_ExplanationVideoLink() -> string;
		virtual auto Tool_ModifiedBy() -> string;		
	};
}