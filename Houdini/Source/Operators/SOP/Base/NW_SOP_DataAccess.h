/*
	Methods for accessing UI parameters and attributes.

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

#pragma once

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include "NW_SOP_ErrorChecking.h"

/* -----------------------------------------------------------------
DEFINES                                                            |
----------------------------------------------------------------- */

#define ____unique_sop_title____		NW_SOP_DATA_ACCESS_NAME

/* -----------------------------------------------------------------
DECLARATION                                                        |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	class NW_SOP_OPERATOR_TITLE() : public NW_SOP_OPERATOR_NAME(NW_SOP_ERRORCHECKING_NAME)
	{
	public:
		NW_SOP_OPERATOR_TITLE() (OP_Network* network, const char* name, OP_Operator* op) : NW_SOP_OPERATOR_NAME(NW_SOP_ERRORCHECKING_NAME)(network, name, op) {};
		virtual ~NW_SOP_OPERATOR_TITLE() () override {};

	private:

		// NW_GA_RWHandleTypeT should be of types <GA_RWHandleR, GA_RWHandleV2, GA_RWHandleV3, GA_RWHandleV4>
		// NW_GA_AttributeOwnerT should be limited to values of <enum GA_AttributeOwner>
		template <typename NW_GA_RWHandleTypeT, NW_GA_AttributeClass attributeclass, GA_AttributeOwner attributetype>
		auto ____find_attribute_of_type____(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, NW_GA_RWHandleTypeT& attributehandle, exint minsize = 1, exint maxsize = -1, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

	protected:
		
		/* --------------------------------- PARAMETERS ------------------------------------------------------------------ */

		/// Read values from the interface <int> parameter
		virtual auto Get_IntPRM(exint& val, const PRM_Template& parameter, exint parmindex, fpreal time = 0) -> void;
		virtual auto Get_IntPRM(exint& val, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Get_IntPRM(bool& val, const PRM_Template& parameter, fpreal time = 0) -> void;			
		virtual auto Get_IntPRM(uint& val, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Get_IntPRM(int& val, const PRM_Template& parameter, fpreal time = 0) -> void;		

		/// Read values from the interface <float> parameter
		virtual auto Get_FloatPRM(fpreal& val, const PRM_Template& parameter, exint parmindex, fpreal time = 0) -> void;
		virtual auto Get_FloatPRM(fpreal& val, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Get_DoublePRM(double& val, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Read values from the interface <vectorT> parameter
		virtual auto Get_VectorPRM(UT_Vector2R& vector2, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Get_VectorPRM(UT_Vector3R& vector3, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Get_VectorPRM(UT_Vector4R& vector4, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Read values from the interface <string> parameter
		virtual auto Get_StringPRM(UT_String& str, const PRM_Template& parameter, exint parmindex, fpreal time = 0) -> void;
		virtual auto Get_StringPRM(UT_String& str, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Set values on the interface <int> parameter
		virtual auto Set_IntPRM(exint& val, const PRM_Template& parameter, exint parmindex, fpreal time = 0) -> void;
		virtual auto Set_IntPRM(exint& val, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Set values on the interface <float> parameter
		virtual auto Set_FloatPRM(fpreal& val, const PRM_Template& parameter, exint parmindex, fpreal time = 0) -> void;
		virtual auto Set_FloatPRM(fpreal& val, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Set values on the interface <vectorT> parameter
		virtual auto Set_VectorPRM(UT_Vector2R& vector2, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Set_VectorPRM(UT_Vector3R& vector3, const PRM_Template& parameter, fpreal time = 0) -> void;
		virtual auto Set_VectorPRM(UT_Vector4R& vector4, const PRM_Template& parameter, fpreal time = 0) -> void;

		/// Set values on the interface <string> parameter
		virtual auto Set_StringPRM(UT_String& str, const PRM_Template& parameter, exint parmindex, CH_StringMeaning meaning = CH_STRING_LITERAL, fpreal time = 0) -> void;
		virtual auto Set_StringPRM(UT_String& str, const PRM_Template& parameter, CH_StringMeaning meaning = CH_STRING_LITERAL, fpreal time = 0) -> void;

		/* --------------------------------- ATTRIBUTES ------------------------------------------------------------------ */

		// Find <int> attributes
		virtual auto Find_IntegerVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_IntegerDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleI& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		// Find <float> attributes
		virtual auto Find_FloatVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_FloatDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleR& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		// Find <string> attributes
		virtual auto Find_StringPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_StringPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		virtual auto Find_StringPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_StringPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleS& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		// Find <vector> attributes
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorVertexAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPointAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorPrimitiveAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;

		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const UT_String& attributename, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV2& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV3& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
		virtual auto Find_VectorDetailAttribute(GU_Detail* detail, const PRM_Template& parameter, GA_RWAttributeRef& attributeref, GA_RWHandleV4& attributehandle, NW_ERROR_LEVEL errorlevel = NW_ERROR_LEVEL::None, fpreal time = 0) -> bool;
	};

SOP_NAMESPACE_END

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____