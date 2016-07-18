/*
	This is a place where you should specify common for all extensions include files.

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

#pragma once

/* -----------------------------------------------------------------
INCLUDES                                                           |
----------------------------------------------------------------- */

#include <BM/BM_ResourceManager.h>

#include <CH/CH_Manager.h>

#include <CL/CL_Clip.h>
#include <CL/CL_ClipIO.h>
#include <CL/CL_ClipReader.h>
#include <CL/CL_ClipWriter.h>

#include <DM/DM_SceneHook.h>
#include <DM/DM_GeoDetail.h>
#include <DM/DM_RenderTable.h>
#include <DM/DM_VPortAgent.h>
#include <DM/DM_EventTable.h>
#include <DM/DM_MouseHook.h>

#include <GA/GA_Types.h>
#include <GA/GA_Detail.h>
#include <GA/GA_ElementGroup.h>
#include <GA/GA_ElementWrangler.h>
#include <GA/GA_AttributeFilter.h>
#include <GA/GA_PrimitiveFamilyMask.h>
#include <GA/GA_AttributeRefMapDestHandle.h>
#include <GA/GA_AttributeDict.h>
#include <GA/GA_PrimitiveTypeId.h>
#include <GA/GA_PrimitiveTypes.h>
#include <GA/GA_PrimCompat.h>

#include <GU/GU_Prim.h>
#include <GU/GU_Curve.h>
#include <GU/GU_Align.h>
#include <GU/GU_Detail.h>

#include <GR/GR_Utils.h>
#include <GR/GR_GeoRender.h>
#include <GR/GR_Primitive.h>
#include <GR/GR_UserOption.h>
#include <GR/GR_PickRecord.h>
#include <GR/GR_OptionTable.h>
#include <GR/GR_DisplayOption.h>

#include <GEO/GEO_Curve.h>
#include <GEO/GEO_PrimType.h>
#include <GEO/GEO_PrimPoly.h>
#include <GEO/GEO_Primitive.h>
#include <GEO/GEO_IOTranslator.h>
#include <GEO/GEO_PrimTypeCompat.h>
#include <GEO/GEO_AttributeHandle.h>
#include <GEO/GEO_AttributeHandle.h>
#include <GEO/GEO_Closure.h>
#include <GEO/GEO_ConvertParms.h>

#include <GOP/GOP_AttribListParse.h>

#include <GUI/GUI_DisplayOption.h>
#include <GUI/GUI_PrimitiveHook.h>

#include <GT/GT_GEOPrimitive.h>
#include <GT/GT_PrimPolygonMesh.h>
#include <GT/GT_AttributeList.h>
#include <GT/GT_DANumeric.h>

#include <GU/GU_PrimPacked.h>
#include <GU/GU_PackedGeometry.h>
#include <GU/GU_EdgeUtils.h>

#include <GQ/GQ_Detail.h>

#include <SOP/SOP_HOM.h>
#include <HOM/HOM_Module.h>
#include <HOM/HOM_SopNode.h>
#include <HOM/HOM_Geometry.h>
#include <HOM/HOM_Vector3.h>
#include <HOM/HOM_Point.h>
#include <HOM/HOM_NodeType.h>
#include <HOM/HOM_ui.h>

#include <MSS/MSS_ReusableSelector.h>

#include <PRM/PRM_Parm.h>
#include <PRM/PRM_Error.h>
#include <PRM/PRM_Include.h>
#include <PRM/PRM_SpareData.h>
#include <PRM/PRM_ChoiceList.h>

#include <OP/OP_Input.h>
#include <OP/OP_Network.h>
#include <OP/OP_Director.h>
#include <OP/OP_Operator.h>
#include <OP/OP_OperatorTable.h>
#include <OP/OP_AutoLockInputs.h>

#include <RE/RE_Font.h>
#include <RE/RE_Render.h>
#include <RE/RE_Geometry.h>
#include <RE/RE_LightList.h>
#include <RE/RE_VertexArray.h>
#include <RE/RE_ShaderHandle.h>
#include <RE/RE_ElementArray.h>

#include <SOP/SOP_Node.h>

#include <SYS/SYS_Math.h>

#include <UI/UI_Event.h>

#include <UT/UT_Array.h>
#include <UT/UT_Assert.h>
#include <UT/UT_Vector.h>
#include <UT/UT_XMLNode.h>
#include <UT/UT_Vector3.h>
#include <UT/UT_IOTable.h>
#include <UT/UT_IStream.h>
#include <UT/UT_Interrupt.h>
#include <UT/UT_XMLDomParser.h>

#include <VM/VM_Math.h>

#include <vector>
#include <ostream>
//#include <iostream.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
//#include <fstream.h>
#include <memory>
#include <random>
#include <iomanip>

/* -----------------------------------------------------------------
USING                                                              |
----------------------------------------------------------------- */

using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::strlen;
using std::vector;
using std::string;
using std::to_string;
using std::unique_ptr;
using std::ostream;