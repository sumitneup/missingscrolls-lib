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