/*
	Volumetric-Hierarchical Approximate Convex Decomposition.
	Based on https://github.com/kmammou/v-hacd

	IMPORTANT! ------------------------------------------
	DO NOT MODIFY THIS FILE.
	Doing so may break every extension that uses it as a base or utility.
	Modify it ONLY when you know what you are doing. That means NEVER!
	-----------------------------------------------------

	TODO! -----------------------------------------------
	- move Pull_IntPRM() and Pull_FloatPRM() to SOP_DataAccess and template them + add versions for <vector> and <string>
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

#include "SOP_VHACDEngine_Configuration.h"

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

using namespace VHACD;

/* -----------------------------------------------------------------
DEFINES															   |
----------------------------------------------------------------- */

#define ____unique_sop_title____		SOP_VHACDENGINE_NAME
#define VHACD_LOGGER_TITLE()			SOP_OPERATOR_TITLE()##_Logger
#define VHACD_CALLBACK_TITLE()			SOP_OPERATOR_TITLE()##_Callback

/* -----------------------------------------------------------------
LOGGER DECLARATION                                                 |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	class VHACD_LOGGER_TITLE() : public VHACD::IVHACD::IUserLogger
	{
	public:
		VHACD_LOGGER_TITLE()();
		~VHACD_LOGGER_TITLE()() override;

		auto Log(const char* const msg) -> void override;

		bool				_showMsg;
	};

	class VHACD_CALLBACK_TITLE() : public VHACD::IVHACD::IUserCallback
	{
	public:
		VHACD_CALLBACK_TITLE()( );
		~VHACD_CALLBACK_TITLE()() override;

		auto Update(const double overallProgress, const double stageProgress, const double operationProgress, const char* const stage, const char* const operation) -> void override;
		
		bool				_showOverallProgress;
		bool				_showStageProgress;
		bool				_showOperationProgress;

	private:
		HOM_Module&			_hou;
	};

SOP_NAMESPACE_END

/* -----------------------------------------------------------------
OPERATOR DECLARATION                                               |
----------------------------------------------------------------- */

SOP_NAMESPACE_START()

	SOP_OPERATOR_DECLARATION_ONE_OUTPUT_V1_START()

		DESCRIPTION_DECLARATION()
		PARAMETERS_VISIBILITYSTATE()

		private:			
			auto Pull_IntPRM(GU_Detail* geometry, const PRM_Template& parameter, bool interfaceonly = false, fpreal time = 0) -> exint;
			auto Pull_FloatPRM(GU_Detail* geometry, const PRM_Template& parameter, bool interfaceonly = false, fpreal time = 0) -> fpreal;
			auto Manage_SmallPolygons(UT_AutoInterrupt progress) -> bool;
			auto Setup_VHACD() -> void;
			auto Triangulate_Geometry(UT_AutoInterrupt progress) -> bool;
			auto Store_Data(UT_AutoInterrupt progress) -> bool;
			auto Generate_ConvexHulls(UT_AutoInterrupt progress) -> OP_ERROR;
			auto Draw_ConvexHull(GU_Detail* geometry, int hullid, IVHACD::ConvexHull hull, UT_AutoInterrupt progress) -> bool;		

			IVHACD::Parameters					_parametersVHACD;
			IVHACD*								_interfaceVHACD;
			vector<int>							_triangles;
			vector<float>						_points;

			GA_RWAttributeRef					_positionReference;
			GA_RWHandleV3						_positionHandle;			

			bool								_currentAllowParametersOverrideValueState;
			bool								_currentCollapseSmallPolygonsValueState;
			fpreal								_currentCollapseAreaValueState;
			bool								_currentShowReportValueState;
			int									_currentReportModeChoiceValueState;
			bool								_currentPreTriangulateValueState;

			VHACD_LOGGER_TITLE()				_loggerVHACD;
			VHACD_CALLBACK_TITLE()				_callbackVHACD;

	SOP_OPERATOR_DECLARATION_END____

SOP_NAMESPACE_END

/* -----------------------------------------------------------------
UNDEFINES                                                          |
----------------------------------------------------------------- */

#undef ____unique_sop_title____