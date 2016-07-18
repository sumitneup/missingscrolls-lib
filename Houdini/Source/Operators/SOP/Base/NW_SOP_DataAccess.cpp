/*
	Methods for working with parameters.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means: NEVER!

	Methods starting and ending with '____' shouldn't be used anywhere outside of this file.
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

#include "NW_SOP_DataAccess.h"
#include "NW_SOP_ErrorChecking.cpp"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

GET_SOP_NAMESPACE()

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		NW_SOP_DATA_ACCESS_NAME

/* -----------------------------------------------------------------
IMPLEMENTATION                                                     |
----------------------------------------------------------------- */

/* --------------------------------- PARAMETERS ------------------------------------------------------------------ */

/// Read values from the interface <int> parameter

NW_SOP_OPERATOR()::Get_IntPRM(exint& val, const PRM_Template& parameter, exint parmindex, fpreal time /* = 0 */)
-> void
{ val = evalInt(parameter.getToken(), parmindex, time); }

NW_SOP_OPERATOR()::Get_IntPRM(exint& val, const PRM_Template& parameter, fpreal time /*= 0*/)
-> void
{ Get_IntPRM(val, parameter, 0, time); }

NW_SOP_OPERATOR()::Get_IntPRM(bool& val, const PRM_Template& parameter, fpreal time /*= 0*/)
-> void
{ val = evalInt(parameter.getToken(), 0, time); }

NW_SOP_OPERATOR()::Get_IntPRM(uint& val, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void 
{ val = evalInt(parameter.getToken(), 0, time); }

NW_SOP_OPERATOR()::Get_IntPRM(int& val, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void 
{ val = evalInt(parameter.getToken(), 0, time); }

/// Read values from the interface <float> parameter

NW_SOP_OPERATOR()::Get_FloatPRM(fpreal& val, const PRM_Template& parameter, exint parmindex, fpreal time /* = 0 */)
-> void
{ val = evalFloat(parameter.getToken(), parmindex, time); }

NW_SOP_OPERATOR()::Get_FloatPRM(fpreal& val, const PRM_Template& parameter, fpreal time /*= 0*/)
-> void
{ Get_FloatPRM(val, parameter, 0, time); }

NW_SOP_OPERATOR()::Get_DoublePRM(double& val, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void 
{ Get_FloatPRM(val, parameter, 0, time); }

/// Read values from the interface <vectorT> parameter

NW_SOP_OPERATOR()::Get_VectorPRM(UT_Vector2R& vector2, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{ vector2 = UT_Vector2R(evalFloat(parameter.getToken(), 0, time), evalFloat(parameter.getToken(), 1, time)); }

NW_SOP_OPERATOR()::Get_VectorPRM(UT_Vector3R& vector3, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{ vector3 = UT_Vector3R(evalFloat(parameter.getToken(), 0, time), evalFloat(parameter.getToken(), 1, time), evalFloat(parameter.getToken(), 2, time)); }

NW_SOP_OPERATOR()::Get_VectorPRM(UT_Vector4R& vector4, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{ vector4 = UT_Vector4R(evalFloat(parameter.getToken(), 0, time), evalFloat(parameter.getToken(), 1, time), evalFloat(parameter.getToken(), 2, time), evalFloat(parameter.getToken(), 3, time)); }

/// Read values from the interface <string> parameter

NW_SOP_OPERATOR()::Get_StringPRM(UT_String& str, const PRM_Template& parameter, exint parmindex, fpreal time /* = 0 */)
-> void
{ evalString(str, parameter.getToken(), parmindex, time); }

NW_SOP_OPERATOR()::Get_StringPRM(UT_String& str, const PRM_Template& parameter, fpreal time /*= 0*/)
-> void
{ Get_StringPRM(str, parameter, 0, time); }

/// Set values on the interface <int> parameter

NW_SOP_OPERATOR()::Set_IntPRM(exint& val, const PRM_Template& parameter, exint parmindex, fpreal time /* = 0 */)
-> void
{ setInt(parameter.getToken(), parmindex, time, val); }

NW_SOP_OPERATOR()::Set_IntPRM(exint& val, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{ Set_IntPRM(val, parameter, 0, time); }

/// Set values on the interface <float> parameter

NW_SOP_OPERATOR()::Set_FloatPRM(fpreal& val, const PRM_Template& parameter, exint parmindex, fpreal time /* = 0 */)
-> void
{ setFloat(parameter.getToken(), parmindex, time, val); }

NW_SOP_OPERATOR()::Set_FloatPRM(fpreal& val, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{ Set_FloatPRM(val, parameter, 0, time); }

/// Set values on the interface <vectorT> parameter

NW_SOP_OPERATOR()::Set_VectorPRM(UT_Vector2R& vector2, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{
	Set_FloatPRM(vector2.x(), parameter, 0, time);
	Set_FloatPRM(vector2.y(), parameter, 1, time);
}

NW_SOP_OPERATOR()::Set_VectorPRM(UT_Vector3R& vector3, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{
	Set_FloatPRM(vector3.x(), parameter, 0, time);
	Set_FloatPRM(vector3.y(), parameter, 1, time);
	Set_FloatPRM(vector3.z(), parameter, 2, time);
}

NW_SOP_OPERATOR()::Set_VectorPRM(UT_Vector4R& vector4, const PRM_Template& parameter, fpreal time /* = 0 */)
-> void
{
	Set_FloatPRM(vector4.x(), parameter, 0, time);
	Set_FloatPRM(vector4.y(), parameter, 1, time);
	Set_FloatPRM(vector4.z(), parameter, 2, time);
	Set_FloatPRM(vector4.w(), parameter, 3, time);
}

/// Set values on the interface <string> parameter

NW_SOP_OPERATOR()::Set_StringPRM(UT_String& str, const PRM_Template& parameter, exint parmindex, CH_StringMeaning meaning /* = CH_STRING_LITERAL */, fpreal time /* = 0 */)
-> void
{ setString(str, meaning, parameter.getToken(), parmindex, time); }

NW_SOP_OPERATOR()::Set_StringPRM(UT_String& str, const PRM_Template& parameter, CH_StringMeaning meaning /* = CH_STRING_LITERAL */, fpreal time /* = 0 */)
-> void
{ Set_StringPRM(str, parameter, 0, meaning, time); }

/* --------------------------------- ATTRIBUTES ------------------------------------------------------------------ */

template <typename NW_GA_RWHandleTypeT, NW_ATTRIBUTE_CLASS attributeclass, GA_AttributeOwner attributetype>
NW_SOP_OPERATOR()::____find_attribute_of_type____(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, NW_GA_RWHandleTypeT& attributehandle, exint minsize /* = 1 */, exint maxsize /* = -1 */, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// Get attribute reference based on type
	switch (attributeclass)
	{
		case NW_ATTRIBUTE_CLASS::Integer:
			{ attributeref = detail->findIntTuple(attributetype, attributename, minsize, maxsize); }
			break;

		case NW_ATTRIBUTE_CLASS::Float:
		case NW_ATTRIBUTE_CLASS::Vector2:
		case NW_ATTRIBUTE_CLASS::Vector3:
		case NW_ATTRIBUTE_CLASS::Vector4:
			{ attributeref = detail->findFloatTuple(attributetype, attributename, minsize, maxsize); }
			break;

		case NW_ATTRIBUTE_CLASS::String:
			{ attributeref = detail->findStringTuple(attributetype, attributename, minsize, maxsize); }
			break;
	}

	// Check attribute reference
	auto errorMessage = "\nRequired '" + attributename.toStdString() + "' attribute was not found.";

	if (attributeref.isInvalid()) 
	{
		switch (errorlevel)
		{
			case NW_ERROR_LEVEL::Warning:
				{ addWarning(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }		
				break;
			case NW_ERROR_LEVEL::Error:
				{ addError(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }
				break;		
		}

		return false;
	}
	else
	{
		// Get attribute handle
		attributehandle = NW_GA_RWHandleTypeT(attributeref.getAttribute());

		// Check attribute handle
		if (attributehandle.isInvalid())
		{
			errorMessage = "\nRequired '" + attributename.toStdString() + "' attribute was not found.";

			switch (errorlevel)
			{
				case NW_ERROR_LEVEL::Warning:
					{ addWarning(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }		
					break;
				case NW_ERROR_LEVEL::Error:
					{ addError(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }
					break;		
			}

			return false;
		}
	}

	return true;
}

// -------------------------- Find Integer Attributes // 

NW_SOP_OPERATOR()::Find_IntegerPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleI, NW_ATTRIBUTE_CLASS::Integer, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_IntegerPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_IntegerPrimitiveAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_IntegerVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleI, NW_ATTRIBUTE_CLASS::Integer, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_IntegerVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_IntegerVertexAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_IntegerPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleI, NW_ATTRIBUTE_CLASS::Integer, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_IntegerPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_IntegerPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_IntegerDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleI, NW_ATTRIBUTE_CLASS::Integer, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_IntegerDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_IntegerDetailAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find Float Attributes //

NW_SOP_OPERATOR()::Find_FloatPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleR, NW_ATTRIBUTE_CLASS::Float, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_FloatPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_FloatPrimitiveAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_FloatVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleR, NW_ATTRIBUTE_CLASS::Float, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_FloatVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_FloatVertexAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_FloatPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleR, NW_ATTRIBUTE_CLASS::Float, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_FloatPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_FloatPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_FloatDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleR, NW_ATTRIBUTE_CLASS::Float, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_FloatDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_FloatDetailAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find String Attributes //

NW_SOP_OPERATOR()::Find_StringPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleS, NW_ATTRIBUTE_CLASS::String, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, -1, errorlevel, time); }

NW_SOP_OPERATOR()::Find_StringPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_StringPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_StringPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleS, NW_ATTRIBUTE_CLASS::String, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, -1, errorlevel,time); }

NW_SOP_OPERATOR()::Find_StringPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_StringPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find Vector Vertex Attributes //

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV2, NW_ATTRIBUTE_CLASS::Vector2, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, NW_ATTRIBUTE_CLASS::Vector3, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, NW_ATTRIBUTE_CLASS::Vector4, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorVertexAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorVertexAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorVertexAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find Vector Point Attributes //

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV2, NW_ATTRIBUTE_CLASS::Vector2, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, NW_ATTRIBUTE_CLASS::Vector3, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, NW_ATTRIBUTE_CLASS::Vector4, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPointAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find Vector Primitive Attribute //	

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV2, NW_ATTRIBUTE_CLASS::Vector2, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, NW_ATTRIBUTE_CLASS::Vector3, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, NW_ATTRIBUTE_CLASS::Vector4, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPrimitiveAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPrimitiveAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorPrimitiveAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

// -------------------------- Find Vector Detail Attribute //

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV2, NW_ATTRIBUTE_CLASS::Vector2, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, NW_ATTRIBUTE_CLASS::Vector3, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, NW_ATTRIBUTE_CLASS::Vector4, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorDetailAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorDetailAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// First extract text specified in attribute parm field
	UT_String attributeName;
	Get_StringPRM(attributeName, parameter, time);
	auto success = Perform_StandardStringErrorChecking(attributeName, SOP_ERR_INVALID_ATTRIBUTE_NAME, false, false, true);

	if (success < UT_ERROR_WARNING) 
		return Find_VectorDetailAttribute(detail, attributeName, attributeref, attributehandle, errorlevel, time);

	return success;
}

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____