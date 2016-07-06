/*
	Methods for working with parameters.

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means: NEVER!
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

template <typename NW_GA_RWHandleTypeT, NW_GA_AttributeClass attributeclass, GA_AttributeOwner attributetype>
NW_SOP_OPERATOR()::____find_attribute_of_type____(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, NW_GA_RWHandleTypeT& attributehandle, exint minsize /* = 1 */, exint maxsize /* = -1 */, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{
	// Get attribute reference based on type
	switch (attributeclass)
	{
	case GA_INTEGER_ATTRIBUTECLASS:
		attributeref = detail->findIntTuple(attributetype, attributename, minsize, maxsize);
		break;

	case GA_FLOAT_ATTRIBUTECLASS:
	case GA_VECTOR2_ATTRIBUTECLASS:
	case GA_VECTOR3_ATTRIBUTECLASS:
	case GA_VECTOR4_ATTRIBUTECLASS:
		attributeref = detail->findFloatTuple(attributetype, attributename, minsize, maxsize);
		break;

	case GA_STRING_ATTRIBUTECLASS:
		attributeref = detail->findStringTuple(attributetype, attributename, minsize, maxsize);
		break;
	}

	// Check attribute reference
	auto errorMessage = "\nRequired '" + attributename.toStdString() + "' attribute was not found.";

	if (attributeref.isInvalid()) 
	{
		switch (errorlevel)
		{
		case Warning:
			{ addWarning(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }		
			break;
		case Error:
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
			case Warning:
				{ addWarning(SOP_ERR_INVALID_ATTRIBUTE_NAME, errorMessage.c_str()); }		
				break;
			case Error:
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
{ return ____find_attribute_of_type____<GA_RWHandleI, GA_INTEGER_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleI, GA_INTEGER_ATTRIBUTECLASS, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleI, GA_INTEGER_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleI, GA_INTEGER_ATTRIBUTECLASS, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleR, GA_FLOAT_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleR, GA_FLOAT_ATTRIBUTECLASS, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleR, GA_FLOAT_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleR, GA_FLOAT_ATTRIBUTECLASS, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 1, 1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleS, GA_STRING_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 1, -1, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleS, GA_STRING_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 1, -1, errorlevel,time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleV2, GA_VECTOR2_ATTRIBUTECLASS, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, GA_VECTOR3_ATTRIBUTECLASS, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, GA_VECTOR4_ATTRIBUTECLASS, GA_ATTRIB_VERTEX>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleV2, GA_VECTOR2_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, GA_VECTOR3_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, GA_VECTOR4_ATTRIBUTECLASS, GA_ATTRIB_POINT>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleV2, GA_VECTOR2_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, GA_VECTOR3_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, GA_VECTOR4_ATTRIBUTECLASS, GA_ATTRIB_PRIMITIVE>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

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
{ return ____find_attribute_of_type____<GA_RWHandleV2, GA_VECTOR2_ATTRIBUTECLASS, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 2, 2, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV3, GA_VECTOR3_ATTRIBUTECLASS, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 3, 3, errorlevel, time); }

NW_SOP_OPERATOR()::Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel /* = NW_ERROR_LEVEL::None */, fpreal time /* = 0 */)
-> bool
{ return ____find_attribute_of_type____<GA_RWHandleV4, GA_VECTOR4_ATTRIBUTECLASS, GA_ATTRIB_DETAIL>(detail, attributename, attributeref, attributehandle, 4, 4, errorlevel, time); }

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