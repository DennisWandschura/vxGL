/*
The MIT License(MIT)

Copyright(c) 2015 Dennis Wandschura

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/* WARNING: This file was automatically generated */
/* Do not edit. */

#include <vxGL/flextGL.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif

	typedef void(__stdcall *GLPROC)();

	void flextLoadOpenGLFunctions(void);

	static void open_libgl(void);
	static void close_libgl(void);
	static GLPROC get_proc(const char *proc);
	static void add_extension(const char* extension);

	int flextInit(void)
	{
		GLint minor, major;
		GLint num_extensions;
		int i;

		open_libgl();
		flextLoadOpenGLFunctions();
		close_libgl();

		glGetIntegerv(GL_MAJOR_VERSION, &major);
		glGetIntegerv(GL_MINOR_VERSION, &minor);

		if (10 * major + minor < 45) {
			fprintf(stderr, "Error: OpenGL version 4.5 not supported.\n");
			fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}


		/* --- Check for minimal version and profile --- */

		if (major * 10 + minor < 45) {
			fprintf(stderr, "Error: OpenGL version 4.5 not supported.\n");
			fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}


		/* --- Check for extensions --- */

		glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);

		for (i = 0; i < num_extensions; i++) {
			add_extension((const char*)glGetStringi(GL_EXTENSIONS, i));
		}

		if (!FLEXT_ARB_bindless_texture) {
			fprintf(stderr, "Error: OpenGL extension GL_ARB_bindless_texture not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_ARB_sparse_texture) {
			fprintf(stderr, "Error: OpenGL extension GL_ARB_sparse_texture not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_ARB_indirect_parameters) {
			fprintf(stderr, "Error: OpenGL extension GL_ARB_indirect_parameters not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_ARB_pipeline_statistics_query) {
			fprintf(stderr, "Error: OpenGL extension GL_ARB_pipeline_statistics_query not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_ARB_texture_non_power_of_two) {
			fprintf(stderr, "Error: OpenGL extension GL_ARB_texture_non_power_of_two not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_EXT_direct_state_access) {
			fprintf(stderr, "Error: OpenGL extension GL_EXT_direct_state_access not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_EXT_texture_compression_s3tc) {
			fprintf(stderr, "Error: OpenGL extension GL_EXT_texture_compression_s3tc not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}
		if (!FLEXT_EXT_texture_sRGB) {
			fprintf(stderr, "Error: OpenGL extension GL_EXT_texture_sRGB not supported.\n");
			fprintf(stderr, "       Try updating your graphics driver.\n");
			return GL_FALSE;
		}

		return GL_TRUE;
	}



	void flextLoadOpenGLFunctions(void)
	{
		/* --- Function pointer loading --- */


		/* GL_VERSION_1_2 */

		glpfDrawRangeElements = (PFNGLDRAWRANGEELEMENTS_PROC*)get_proc("glDrawRangeElements");
		glpfTexImage3D = (PFNGLTEXIMAGE3D_PROC*)get_proc("glTexImage3D");
		glpfTexSubImage3D = (PFNGLTEXSUBIMAGE3D_PROC*)get_proc("glTexSubImage3D");
		glpfCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3D_PROC*)get_proc("glCopyTexSubImage3D");


		/* GL_VERSION_1_3 */

		glpfActiveTexture = (PFNGLACTIVETEXTURE_PROC*)get_proc("glActiveTexture");
		glpfSampleCoverage = (PFNGLSAMPLECOVERAGE_PROC*)get_proc("glSampleCoverage");
		glpfCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3D_PROC*)get_proc("glCompressedTexImage3D");
		glpfCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2D_PROC*)get_proc("glCompressedTexImage2D");
		glpfCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1D_PROC*)get_proc("glCompressedTexImage1D");
		glpfCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC*)get_proc("glCompressedTexSubImage3D");
		glpfCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC*)get_proc("glCompressedTexSubImage2D");
		glpfCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC*)get_proc("glCompressedTexSubImage1D");
		glpfGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGE_PROC*)get_proc("glGetCompressedTexImage");


		/* GL_VERSION_1_4 */

		glpfBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATE_PROC*)get_proc("glBlendFuncSeparate");
		glpfMultiDrawArrays = (PFNGLMULTIDRAWARRAYS_PROC*)get_proc("glMultiDrawArrays");
		glpfMultiDrawElements = (PFNGLMULTIDRAWELEMENTS_PROC*)get_proc("glMultiDrawElements");
		glpfPointParameterf = (PFNGLPOINTPARAMETERF_PROC*)get_proc("glPointParameterf");
		glpfPointParameterfv = (PFNGLPOINTPARAMETERFV_PROC*)get_proc("glPointParameterfv");
		glpfPointParameteri = (PFNGLPOINTPARAMETERI_PROC*)get_proc("glPointParameteri");
		glpfPointParameteriv = (PFNGLPOINTPARAMETERIV_PROC*)get_proc("glPointParameteriv");
		glpfBlendColor = (PFNGLBLENDCOLOR_PROC*)get_proc("glBlendColor");
		glpfBlendEquation = (PFNGLBLENDEQUATION_PROC*)get_proc("glBlendEquation");


		/* GL_VERSION_1_5 */

		glpfGenQueries = (PFNGLGENQUERIES_PROC*)get_proc("glGenQueries");
		glpfDeleteQueries = (PFNGLDELETEQUERIES_PROC*)get_proc("glDeleteQueries");
		glpfIsQuery = (PFNGLISQUERY_PROC*)get_proc("glIsQuery");
		glpfBeginQuery = (PFNGLBEGINQUERY_PROC*)get_proc("glBeginQuery");
		glpfEndQuery = (PFNGLENDQUERY_PROC*)get_proc("glEndQuery");
		glpfGetQueryiv = (PFNGLGETQUERYIV_PROC*)get_proc("glGetQueryiv");
		glpfGetQueryObjectiv = (PFNGLGETQUERYOBJECTIV_PROC*)get_proc("glGetQueryObjectiv");
		glpfGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIV_PROC*)get_proc("glGetQueryObjectuiv");
		glpfBindBuffer = (PFNGLBINDBUFFER_PROC*)get_proc("glBindBuffer");
		glpfDeleteBuffers = (PFNGLDELETEBUFFERS_PROC*)get_proc("glDeleteBuffers");
		glpfGenBuffers = (PFNGLGENBUFFERS_PROC*)get_proc("glGenBuffers");
		glpfIsBuffer = (PFNGLISBUFFER_PROC*)get_proc("glIsBuffer");
		glpfBufferData = (PFNGLBUFFERDATA_PROC*)get_proc("glBufferData");
		glpfBufferSubData = (PFNGLBUFFERSUBDATA_PROC*)get_proc("glBufferSubData");
		glpfGetBufferSubData = (PFNGLGETBUFFERSUBDATA_PROC*)get_proc("glGetBufferSubData");
		glpfMapBuffer = (PFNGLMAPBUFFER_PROC*)get_proc("glMapBuffer");
		glpfUnmapBuffer = (PFNGLUNMAPBUFFER_PROC*)get_proc("glUnmapBuffer");
		glpfGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIV_PROC*)get_proc("glGetBufferParameteriv");
		glpfGetBufferPointerv = (PFNGLGETBUFFERPOINTERV_PROC*)get_proc("glGetBufferPointerv");


		/* GL_VERSION_2_0 */

		glpfBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATE_PROC*)get_proc("glBlendEquationSeparate");
		glpfDrawBuffers = (PFNGLDRAWBUFFERS_PROC*)get_proc("glDrawBuffers");
		glpfStencilOpSeparate = (PFNGLSTENCILOPSEPARATE_PROC*)get_proc("glStencilOpSeparate");
		glpfStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATE_PROC*)get_proc("glStencilFuncSeparate");
		glpfStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATE_PROC*)get_proc("glStencilMaskSeparate");
		glpfAttachShader = (PFNGLATTACHSHADER_PROC*)get_proc("glAttachShader");
		glpfBindAttribLocation = (PFNGLBINDATTRIBLOCATION_PROC*)get_proc("glBindAttribLocation");
		glpfCompileShader = (PFNGLCOMPILESHADER_PROC*)get_proc("glCompileShader");
		glpfCreateProgram = (PFNGLCREATEPROGRAM_PROC*)get_proc("glCreateProgram");
		glpfCreateShader = (PFNGLCREATESHADER_PROC*)get_proc("glCreateShader");
		glpfDeleteProgram = (PFNGLDELETEPROGRAM_PROC*)get_proc("glDeleteProgram");
		glpfDeleteShader = (PFNGLDELETESHADER_PROC*)get_proc("glDeleteShader");
		glpfDetachShader = (PFNGLDETACHSHADER_PROC*)get_proc("glDetachShader");
		glpfDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAY_PROC*)get_proc("glDisableVertexAttribArray");
		glpfEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAY_PROC*)get_proc("glEnableVertexAttribArray");
		glpfGetActiveAttrib = (PFNGLGETACTIVEATTRIB_PROC*)get_proc("glGetActiveAttrib");
		glpfGetActiveUniform = (PFNGLGETACTIVEUNIFORM_PROC*)get_proc("glGetActiveUniform");
		glpfGetAttachedShaders = (PFNGLGETATTACHEDSHADERS_PROC*)get_proc("glGetAttachedShaders");
		glpfGetAttribLocation = (PFNGLGETATTRIBLOCATION_PROC*)get_proc("glGetAttribLocation");
		glpfGetProgramiv = (PFNGLGETPROGRAMIV_PROC*)get_proc("glGetProgramiv");
		glpfGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOG_PROC*)get_proc("glGetProgramInfoLog");
		glpfGetShaderiv = (PFNGLGETSHADERIV_PROC*)get_proc("glGetShaderiv");
		glpfGetShaderInfoLog = (PFNGLGETSHADERINFOLOG_PROC*)get_proc("glGetShaderInfoLog");
		glpfGetShaderSource = (PFNGLGETSHADERSOURCE_PROC*)get_proc("glGetShaderSource");
		glpfGetUniformLocation = (PFNGLGETUNIFORMLOCATION_PROC*)get_proc("glGetUniformLocation");
		glpfGetUniformfv = (PFNGLGETUNIFORMFV_PROC*)get_proc("glGetUniformfv");
		glpfGetUniformiv = (PFNGLGETUNIFORMIV_PROC*)get_proc("glGetUniformiv");
		glpfGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDV_PROC*)get_proc("glGetVertexAttribdv");
		glpfGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFV_PROC*)get_proc("glGetVertexAttribfv");
		glpfGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIV_PROC*)get_proc("glGetVertexAttribiv");
		glpfGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERV_PROC*)get_proc("glGetVertexAttribPointerv");
		glpfIsProgram = (PFNGLISPROGRAM_PROC*)get_proc("glIsProgram");
		glpfIsShader = (PFNGLISSHADER_PROC*)get_proc("glIsShader");
		glpfLinkProgram = (PFNGLLINKPROGRAM_PROC*)get_proc("glLinkProgram");
		glpfShaderSource = (PFNGLSHADERSOURCE_PROC*)get_proc("glShaderSource");
		glpfUseProgram = (PFNGLUSEPROGRAM_PROC*)get_proc("glUseProgram");
		glpfUniform1f = (PFNGLUNIFORM1F_PROC*)get_proc("glUniform1f");
		glpfUniform2f = (PFNGLUNIFORM2F_PROC*)get_proc("glUniform2f");
		glpfUniform3f = (PFNGLUNIFORM3F_PROC*)get_proc("glUniform3f");
		glpfUniform4f = (PFNGLUNIFORM4F_PROC*)get_proc("glUniform4f");
		glpfUniform1i = (PFNGLUNIFORM1I_PROC*)get_proc("glUniform1i");
		glpfUniform2i = (PFNGLUNIFORM2I_PROC*)get_proc("glUniform2i");
		glpfUniform3i = (PFNGLUNIFORM3I_PROC*)get_proc("glUniform3i");
		glpfUniform4i = (PFNGLUNIFORM4I_PROC*)get_proc("glUniform4i");
		glpfUniform1fv = (PFNGLUNIFORM1FV_PROC*)get_proc("glUniform1fv");
		glpfUniform2fv = (PFNGLUNIFORM2FV_PROC*)get_proc("glUniform2fv");
		glpfUniform3fv = (PFNGLUNIFORM3FV_PROC*)get_proc("glUniform3fv");
		glpfUniform4fv = (PFNGLUNIFORM4FV_PROC*)get_proc("glUniform4fv");
		glpfUniform1iv = (PFNGLUNIFORM1IV_PROC*)get_proc("glUniform1iv");
		glpfUniform2iv = (PFNGLUNIFORM2IV_PROC*)get_proc("glUniform2iv");
		glpfUniform3iv = (PFNGLUNIFORM3IV_PROC*)get_proc("glUniform3iv");
		glpfUniform4iv = (PFNGLUNIFORM4IV_PROC*)get_proc("glUniform4iv");
		glpfUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FV_PROC*)get_proc("glUniformMatrix2fv");
		glpfUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FV_PROC*)get_proc("glUniformMatrix3fv");
		glpfUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FV_PROC*)get_proc("glUniformMatrix4fv");
		glpfValidateProgram = (PFNGLVALIDATEPROGRAM_PROC*)get_proc("glValidateProgram");
		glpfVertexAttrib1d = (PFNGLVERTEXATTRIB1D_PROC*)get_proc("glVertexAttrib1d");
		glpfVertexAttrib1dv = (PFNGLVERTEXATTRIB1DV_PROC*)get_proc("glVertexAttrib1dv");
		glpfVertexAttrib1f = (PFNGLVERTEXATTRIB1F_PROC*)get_proc("glVertexAttrib1f");
		glpfVertexAttrib1fv = (PFNGLVERTEXATTRIB1FV_PROC*)get_proc("glVertexAttrib1fv");
		glpfVertexAttrib1s = (PFNGLVERTEXATTRIB1S_PROC*)get_proc("glVertexAttrib1s");
		glpfVertexAttrib1sv = (PFNGLVERTEXATTRIB1SV_PROC*)get_proc("glVertexAttrib1sv");
		glpfVertexAttrib2d = (PFNGLVERTEXATTRIB2D_PROC*)get_proc("glVertexAttrib2d");
		glpfVertexAttrib2dv = (PFNGLVERTEXATTRIB2DV_PROC*)get_proc("glVertexAttrib2dv");
		glpfVertexAttrib2f = (PFNGLVERTEXATTRIB2F_PROC*)get_proc("glVertexAttrib2f");
		glpfVertexAttrib2fv = (PFNGLVERTEXATTRIB2FV_PROC*)get_proc("glVertexAttrib2fv");
		glpfVertexAttrib2s = (PFNGLVERTEXATTRIB2S_PROC*)get_proc("glVertexAttrib2s");
		glpfVertexAttrib2sv = (PFNGLVERTEXATTRIB2SV_PROC*)get_proc("glVertexAttrib2sv");
		glpfVertexAttrib3d = (PFNGLVERTEXATTRIB3D_PROC*)get_proc("glVertexAttrib3d");
		glpfVertexAttrib3dv = (PFNGLVERTEXATTRIB3DV_PROC*)get_proc("glVertexAttrib3dv");
		glpfVertexAttrib3f = (PFNGLVERTEXATTRIB3F_PROC*)get_proc("glVertexAttrib3f");
		glpfVertexAttrib3fv = (PFNGLVERTEXATTRIB3FV_PROC*)get_proc("glVertexAttrib3fv");
		glpfVertexAttrib3s = (PFNGLVERTEXATTRIB3S_PROC*)get_proc("glVertexAttrib3s");
		glpfVertexAttrib3sv = (PFNGLVERTEXATTRIB3SV_PROC*)get_proc("glVertexAttrib3sv");
		glpfVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBV_PROC*)get_proc("glVertexAttrib4Nbv");
		glpfVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIV_PROC*)get_proc("glVertexAttrib4Niv");
		glpfVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSV_PROC*)get_proc("glVertexAttrib4Nsv");
		glpfVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUB_PROC*)get_proc("glVertexAttrib4Nub");
		glpfVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBV_PROC*)get_proc("glVertexAttrib4Nubv");
		glpfVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIV_PROC*)get_proc("glVertexAttrib4Nuiv");
		glpfVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSV_PROC*)get_proc("glVertexAttrib4Nusv");
		glpfVertexAttrib4bv = (PFNGLVERTEXATTRIB4BV_PROC*)get_proc("glVertexAttrib4bv");
		glpfVertexAttrib4d = (PFNGLVERTEXATTRIB4D_PROC*)get_proc("glVertexAttrib4d");
		glpfVertexAttrib4dv = (PFNGLVERTEXATTRIB4DV_PROC*)get_proc("glVertexAttrib4dv");
		glpfVertexAttrib4f = (PFNGLVERTEXATTRIB4F_PROC*)get_proc("glVertexAttrib4f");
		glpfVertexAttrib4fv = (PFNGLVERTEXATTRIB4FV_PROC*)get_proc("glVertexAttrib4fv");
		glpfVertexAttrib4iv = (PFNGLVERTEXATTRIB4IV_PROC*)get_proc("glVertexAttrib4iv");
		glpfVertexAttrib4s = (PFNGLVERTEXATTRIB4S_PROC*)get_proc("glVertexAttrib4s");
		glpfVertexAttrib4sv = (PFNGLVERTEXATTRIB4SV_PROC*)get_proc("glVertexAttrib4sv");
		glpfVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBV_PROC*)get_proc("glVertexAttrib4ubv");
		glpfVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIV_PROC*)get_proc("glVertexAttrib4uiv");
		glpfVertexAttrib4usv = (PFNGLVERTEXATTRIB4USV_PROC*)get_proc("glVertexAttrib4usv");
		glpfVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTER_PROC*)get_proc("glVertexAttribPointer");


		/* GL_VERSION_2_1 */

		glpfUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FV_PROC*)get_proc("glUniformMatrix2x3fv");
		glpfUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FV_PROC*)get_proc("glUniformMatrix3x2fv");
		glpfUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FV_PROC*)get_proc("glUniformMatrix2x4fv");
		glpfUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FV_PROC*)get_proc("glUniformMatrix4x2fv");
		glpfUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FV_PROC*)get_proc("glUniformMatrix3x4fv");
		glpfUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FV_PROC*)get_proc("glUniformMatrix4x3fv");


		/* GL_VERSION_3_0 */

		glpfColorMaski = (PFNGLCOLORMASKI_PROC*)get_proc("glColorMaski");
		glpfGetBooleani_v = (PFNGLGETBOOLEANI_V_PROC*)get_proc("glGetBooleani_v");
		glpfGetIntegeri_v = (PFNGLGETINTEGERI_V_PROC*)get_proc("glGetIntegeri_v");
		glpfEnablei = (PFNGLENABLEI_PROC*)get_proc("glEnablei");
		glpfDisablei = (PFNGLDISABLEI_PROC*)get_proc("glDisablei");
		glpfIsEnabledi = (PFNGLISENABLEDI_PROC*)get_proc("glIsEnabledi");
		glpfBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACK_PROC*)get_proc("glBeginTransformFeedback");
		glpfEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACK_PROC*)get_proc("glEndTransformFeedback");
		glpfBindBufferRange = (PFNGLBINDBUFFERRANGE_PROC*)get_proc("glBindBufferRange");
		glpfBindBufferBase = (PFNGLBINDBUFFERBASE_PROC*)get_proc("glBindBufferBase");
		glpfTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGS_PROC*)get_proc("glTransformFeedbackVaryings");
		glpfGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYING_PROC*)get_proc("glGetTransformFeedbackVarying");
		glpfClampColor = (PFNGLCLAMPCOLOR_PROC*)get_proc("glClampColor");
		glpfBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDER_PROC*)get_proc("glBeginConditionalRender");
		glpfEndConditionalRender = (PFNGLENDCONDITIONALRENDER_PROC*)get_proc("glEndConditionalRender");
		glpfVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTER_PROC*)get_proc("glVertexAttribIPointer");
		glpfGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIV_PROC*)get_proc("glGetVertexAttribIiv");
		glpfGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIV_PROC*)get_proc("glGetVertexAttribIuiv");
		glpfVertexAttribI1i = (PFNGLVERTEXATTRIBI1I_PROC*)get_proc("glVertexAttribI1i");
		glpfVertexAttribI2i = (PFNGLVERTEXATTRIBI2I_PROC*)get_proc("glVertexAttribI2i");
		glpfVertexAttribI3i = (PFNGLVERTEXATTRIBI3I_PROC*)get_proc("glVertexAttribI3i");
		glpfVertexAttribI4i = (PFNGLVERTEXATTRIBI4I_PROC*)get_proc("glVertexAttribI4i");
		glpfVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UI_PROC*)get_proc("glVertexAttribI1ui");
		glpfVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UI_PROC*)get_proc("glVertexAttribI2ui");
		glpfVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UI_PROC*)get_proc("glVertexAttribI3ui");
		glpfVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UI_PROC*)get_proc("glVertexAttribI4ui");
		glpfVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IV_PROC*)get_proc("glVertexAttribI1iv");
		glpfVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IV_PROC*)get_proc("glVertexAttribI2iv");
		glpfVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IV_PROC*)get_proc("glVertexAttribI3iv");
		glpfVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IV_PROC*)get_proc("glVertexAttribI4iv");
		glpfVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIV_PROC*)get_proc("glVertexAttribI1uiv");
		glpfVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIV_PROC*)get_proc("glVertexAttribI2uiv");
		glpfVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIV_PROC*)get_proc("glVertexAttribI3uiv");
		glpfVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIV_PROC*)get_proc("glVertexAttribI4uiv");
		glpfVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BV_PROC*)get_proc("glVertexAttribI4bv");
		glpfVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SV_PROC*)get_proc("glVertexAttribI4sv");
		glpfVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBV_PROC*)get_proc("glVertexAttribI4ubv");
		glpfVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USV_PROC*)get_proc("glVertexAttribI4usv");
		glpfGetUniformuiv = (PFNGLGETUNIFORMUIV_PROC*)get_proc("glGetUniformuiv");
		glpfBindFragDataLocation = (PFNGLBINDFRAGDATALOCATION_PROC*)get_proc("glBindFragDataLocation");
		glpfGetFragDataLocation = (PFNGLGETFRAGDATALOCATION_PROC*)get_proc("glGetFragDataLocation");
		glpfUniform1ui = (PFNGLUNIFORM1UI_PROC*)get_proc("glUniform1ui");
		glpfUniform2ui = (PFNGLUNIFORM2UI_PROC*)get_proc("glUniform2ui");
		glpfUniform3ui = (PFNGLUNIFORM3UI_PROC*)get_proc("glUniform3ui");
		glpfUniform4ui = (PFNGLUNIFORM4UI_PROC*)get_proc("glUniform4ui");
		glpfUniform1uiv = (PFNGLUNIFORM1UIV_PROC*)get_proc("glUniform1uiv");
		glpfUniform2uiv = (PFNGLUNIFORM2UIV_PROC*)get_proc("glUniform2uiv");
		glpfUniform3uiv = (PFNGLUNIFORM3UIV_PROC*)get_proc("glUniform3uiv");
		glpfUniform4uiv = (PFNGLUNIFORM4UIV_PROC*)get_proc("glUniform4uiv");
		glpfTexParameterIiv = (PFNGLTEXPARAMETERIIV_PROC*)get_proc("glTexParameterIiv");
		glpfTexParameterIuiv = (PFNGLTEXPARAMETERIUIV_PROC*)get_proc("glTexParameterIuiv");
		glpfGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIV_PROC*)get_proc("glGetTexParameterIiv");
		glpfGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIV_PROC*)get_proc("glGetTexParameterIuiv");
		glpfClearBufferiv = (PFNGLCLEARBUFFERIV_PROC*)get_proc("glClearBufferiv");
		glpfClearBufferuiv = (PFNGLCLEARBUFFERUIV_PROC*)get_proc("glClearBufferuiv");
		glpfClearBufferfv = (PFNGLCLEARBUFFERFV_PROC*)get_proc("glClearBufferfv");
		glpfClearBufferfi = (PFNGLCLEARBUFFERFI_PROC*)get_proc("glClearBufferfi");
		glpfGetStringi = (PFNGLGETSTRINGI_PROC*)get_proc("glGetStringi");
		glpfIsRenderbuffer = (PFNGLISRENDERBUFFER_PROC*)get_proc("glIsRenderbuffer");
		glpfBindRenderbuffer = (PFNGLBINDRENDERBUFFER_PROC*)get_proc("glBindRenderbuffer");
		glpfDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERS_PROC*)get_proc("glDeleteRenderbuffers");
		glpfGenRenderbuffers = (PFNGLGENRENDERBUFFERS_PROC*)get_proc("glGenRenderbuffers");
		glpfRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGE_PROC*)get_proc("glRenderbufferStorage");
		glpfGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIV_PROC*)get_proc("glGetRenderbufferParameteriv");
		glpfIsFramebuffer = (PFNGLISFRAMEBUFFER_PROC*)get_proc("glIsFramebuffer");
		glpfBindFramebuffer = (PFNGLBINDFRAMEBUFFER_PROC*)get_proc("glBindFramebuffer");
		glpfDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERS_PROC*)get_proc("glDeleteFramebuffers");
		glpfGenFramebuffers = (PFNGLGENFRAMEBUFFERS_PROC*)get_proc("glGenFramebuffers");
		glpfCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUS_PROC*)get_proc("glCheckFramebufferStatus");
		glpfFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1D_PROC*)get_proc("glFramebufferTexture1D");
		glpfFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2D_PROC*)get_proc("glFramebufferTexture2D");
		glpfFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3D_PROC*)get_proc("glFramebufferTexture3D");
		glpfFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFER_PROC*)get_proc("glFramebufferRenderbuffer");
		glpfGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC*)get_proc("glGetFramebufferAttachmentParameteriv");
		glpfGenerateMipmap = (PFNGLGENERATEMIPMAP_PROC*)get_proc("glGenerateMipmap");
		glpfBlitFramebuffer = (PFNGLBLITFRAMEBUFFER_PROC*)get_proc("glBlitFramebuffer");
		glpfRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC*)get_proc("glRenderbufferStorageMultisample");
		glpfFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYER_PROC*)get_proc("glFramebufferTextureLayer");
		glpfMapBufferRange = (PFNGLMAPBUFFERRANGE_PROC*)get_proc("glMapBufferRange");
		glpfFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGE_PROC*)get_proc("glFlushMappedBufferRange");
		glpfBindVertexArray = (PFNGLBINDVERTEXARRAY_PROC*)get_proc("glBindVertexArray");
		glpfDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYS_PROC*)get_proc("glDeleteVertexArrays");
		glpfGenVertexArrays = (PFNGLGENVERTEXARRAYS_PROC*)get_proc("glGenVertexArrays");
		glpfIsVertexArray = (PFNGLISVERTEXARRAY_PROC*)get_proc("glIsVertexArray");


		/* GL_VERSION_3_1 */

		glpfDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCED_PROC*)get_proc("glDrawArraysInstanced");
		glpfDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCED_PROC*)get_proc("glDrawElementsInstanced");
		glpfTexBuffer = (PFNGLTEXBUFFER_PROC*)get_proc("glTexBuffer");
		glpfPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEX_PROC*)get_proc("glPrimitiveRestartIndex");
		glpfCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATA_PROC*)get_proc("glCopyBufferSubData");
		glpfGetUniformIndices = (PFNGLGETUNIFORMINDICES_PROC*)get_proc("glGetUniformIndices");
		glpfGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIV_PROC*)get_proc("glGetActiveUniformsiv");
		glpfGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAME_PROC*)get_proc("glGetActiveUniformName");
		glpfGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEX_PROC*)get_proc("glGetUniformBlockIndex");
		glpfGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIV_PROC*)get_proc("glGetActiveUniformBlockiv");
		glpfGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC*)get_proc("glGetActiveUniformBlockName");
		glpfUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDING_PROC*)get_proc("glUniformBlockBinding");


		/* GL_VERSION_3_2 */

		glpfDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEX_PROC*)get_proc("glDrawElementsBaseVertex");
		glpfDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEX_PROC*)get_proc("glDrawRangeElementsBaseVertex");
		glpfDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX_PROC*)get_proc("glDrawElementsInstancedBaseVertex");
		glpfMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEX_PROC*)get_proc("glMultiDrawElementsBaseVertex");
		glpfProvokingVertex = (PFNGLPROVOKINGVERTEX_PROC*)get_proc("glProvokingVertex");
		glpfFenceSync = (PFNGLFENCESYNC_PROC*)get_proc("glFenceSync");
		glpfIsSync = (PFNGLISSYNC_PROC*)get_proc("glIsSync");
		glpfDeleteSync = (PFNGLDELETESYNC_PROC*)get_proc("glDeleteSync");
		glpfClientWaitSync = (PFNGLCLIENTWAITSYNC_PROC*)get_proc("glClientWaitSync");
		glpfWaitSync = (PFNGLWAITSYNC_PROC*)get_proc("glWaitSync");
		glpfGetInteger64v = (PFNGLGETINTEGER64V_PROC*)get_proc("glGetInteger64v");
		glpfGetSynciv = (PFNGLGETSYNCIV_PROC*)get_proc("glGetSynciv");
		glpfGetInteger64i_v = (PFNGLGETINTEGER64I_V_PROC*)get_proc("glGetInteger64i_v");
		glpfGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64V_PROC*)get_proc("glGetBufferParameteri64v");
		glpfFramebufferTexture = (PFNGLFRAMEBUFFERTEXTURE_PROC*)get_proc("glFramebufferTexture");
		glpfTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLE_PROC*)get_proc("glTexImage2DMultisample");
		glpfTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLE_PROC*)get_proc("glTexImage3DMultisample");
		glpfGetMultisamplefv = (PFNGLGETMULTISAMPLEFV_PROC*)get_proc("glGetMultisamplefv");
		glpfSampleMaski = (PFNGLSAMPLEMASKI_PROC*)get_proc("glSampleMaski");


		/* GL_VERSION_3_3 */

		glpfBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXED_PROC*)get_proc("glBindFragDataLocationIndexed");
		glpfGetFragDataIndex = (PFNGLGETFRAGDATAINDEX_PROC*)get_proc("glGetFragDataIndex");
		glpfGenSamplers = (PFNGLGENSAMPLERS_PROC*)get_proc("glGenSamplers");
		glpfDeleteSamplers = (PFNGLDELETESAMPLERS_PROC*)get_proc("glDeleteSamplers");
		glpfIsSampler = (PFNGLISSAMPLER_PROC*)get_proc("glIsSampler");
		glpfBindSampler = (PFNGLBINDSAMPLER_PROC*)get_proc("glBindSampler");
		glpfSamplerParameteri = (PFNGLSAMPLERPARAMETERI_PROC*)get_proc("glSamplerParameteri");
		glpfSamplerParameteriv = (PFNGLSAMPLERPARAMETERIV_PROC*)get_proc("glSamplerParameteriv");
		glpfSamplerParameterf = (PFNGLSAMPLERPARAMETERF_PROC*)get_proc("glSamplerParameterf");
		glpfSamplerParameterfv = (PFNGLSAMPLERPARAMETERFV_PROC*)get_proc("glSamplerParameterfv");
		glpfSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIV_PROC*)get_proc("glSamplerParameterIiv");
		glpfSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIV_PROC*)get_proc("glSamplerParameterIuiv");
		glpfGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIV_PROC*)get_proc("glGetSamplerParameteriv");
		glpfGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIV_PROC*)get_proc("glGetSamplerParameterIiv");
		glpfGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFV_PROC*)get_proc("glGetSamplerParameterfv");
		glpfGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIV_PROC*)get_proc("glGetSamplerParameterIuiv");
		glpfQueryCounter = (PFNGLQUERYCOUNTER_PROC*)get_proc("glQueryCounter");
		glpfGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64V_PROC*)get_proc("glGetQueryObjecti64v");
		glpfGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64V_PROC*)get_proc("glGetQueryObjectui64v");
		glpfVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISOR_PROC*)get_proc("glVertexAttribDivisor");
		glpfVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UI_PROC*)get_proc("glVertexAttribP1ui");
		glpfVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIV_PROC*)get_proc("glVertexAttribP1uiv");
		glpfVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UI_PROC*)get_proc("glVertexAttribP2ui");
		glpfVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIV_PROC*)get_proc("glVertexAttribP2uiv");
		glpfVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UI_PROC*)get_proc("glVertexAttribP3ui");
		glpfVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIV_PROC*)get_proc("glVertexAttribP3uiv");
		glpfVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UI_PROC*)get_proc("glVertexAttribP4ui");
		glpfVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIV_PROC*)get_proc("glVertexAttribP4uiv");


		/* GL_VERSION_4_0 */

		glpfMinSampleShading = (PFNGLMINSAMPLESHADING_PROC*)get_proc("glMinSampleShading");
		glpfBlendEquationi = (PFNGLBLENDEQUATIONI_PROC*)get_proc("glBlendEquationi");
		glpfBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEI_PROC*)get_proc("glBlendEquationSeparatei");
		glpfBlendFunci = (PFNGLBLENDFUNCI_PROC*)get_proc("glBlendFunci");
		glpfBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEI_PROC*)get_proc("glBlendFuncSeparatei");
		glpfDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECT_PROC*)get_proc("glDrawArraysIndirect");
		glpfDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECT_PROC*)get_proc("glDrawElementsIndirect");
		glpfUniform1d = (PFNGLUNIFORM1D_PROC*)get_proc("glUniform1d");
		glpfUniform2d = (PFNGLUNIFORM2D_PROC*)get_proc("glUniform2d");
		glpfUniform3d = (PFNGLUNIFORM3D_PROC*)get_proc("glUniform3d");
		glpfUniform4d = (PFNGLUNIFORM4D_PROC*)get_proc("glUniform4d");
		glpfUniform1dv = (PFNGLUNIFORM1DV_PROC*)get_proc("glUniform1dv");
		glpfUniform2dv = (PFNGLUNIFORM2DV_PROC*)get_proc("glUniform2dv");
		glpfUniform3dv = (PFNGLUNIFORM3DV_PROC*)get_proc("glUniform3dv");
		glpfUniform4dv = (PFNGLUNIFORM4DV_PROC*)get_proc("glUniform4dv");
		glpfUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DV_PROC*)get_proc("glUniformMatrix2dv");
		glpfUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DV_PROC*)get_proc("glUniformMatrix3dv");
		glpfUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DV_PROC*)get_proc("glUniformMatrix4dv");
		glpfUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DV_PROC*)get_proc("glUniformMatrix2x3dv");
		glpfUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DV_PROC*)get_proc("glUniformMatrix2x4dv");
		glpfUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DV_PROC*)get_proc("glUniformMatrix3x2dv");
		glpfUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DV_PROC*)get_proc("glUniformMatrix3x4dv");
		glpfUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DV_PROC*)get_proc("glUniformMatrix4x2dv");
		glpfUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DV_PROC*)get_proc("glUniformMatrix4x3dv");
		glpfGetUniformdv = (PFNGLGETUNIFORMDV_PROC*)get_proc("glGetUniformdv");
		glpfGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATION_PROC*)get_proc("glGetSubroutineUniformLocation");
		glpfGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEX_PROC*)get_proc("glGetSubroutineIndex");
		glpfGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIV_PROC*)get_proc("glGetActiveSubroutineUniformiv");
		glpfGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAME_PROC*)get_proc("glGetActiveSubroutineUniformName");
		glpfGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAME_PROC*)get_proc("glGetActiveSubroutineName");
		glpfUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIV_PROC*)get_proc("glUniformSubroutinesuiv");
		glpfGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIV_PROC*)get_proc("glGetUniformSubroutineuiv");
		glpfGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIV_PROC*)get_proc("glGetProgramStageiv");
		glpfPatchParameteri = (PFNGLPATCHPARAMETERI_PROC*)get_proc("glPatchParameteri");
		glpfPatchParameterfv = (PFNGLPATCHPARAMETERFV_PROC*)get_proc("glPatchParameterfv");
		glpfBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACK_PROC*)get_proc("glBindTransformFeedback");
		glpfDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKS_PROC*)get_proc("glDeleteTransformFeedbacks");
		glpfGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKS_PROC*)get_proc("glGenTransformFeedbacks");
		glpfIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACK_PROC*)get_proc("glIsTransformFeedback");
		glpfPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACK_PROC*)get_proc("glPauseTransformFeedback");
		glpfResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACK_PROC*)get_proc("glResumeTransformFeedback");
		glpfDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACK_PROC*)get_proc("glDrawTransformFeedback");
		glpfDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAM_PROC*)get_proc("glDrawTransformFeedbackStream");
		glpfBeginQueryIndexed = (PFNGLBEGINQUERYINDEXED_PROC*)get_proc("glBeginQueryIndexed");
		glpfEndQueryIndexed = (PFNGLENDQUERYINDEXED_PROC*)get_proc("glEndQueryIndexed");
		glpfGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIV_PROC*)get_proc("glGetQueryIndexediv");


		/* GL_VERSION_4_1 */

		glpfReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILER_PROC*)get_proc("glReleaseShaderCompiler");
		glpfShaderBinary = (PFNGLSHADERBINARY_PROC*)get_proc("glShaderBinary");
		glpfGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMAT_PROC*)get_proc("glGetShaderPrecisionFormat");
		glpfDepthRangef = (PFNGLDEPTHRANGEF_PROC*)get_proc("glDepthRangef");
		glpfClearDepthf = (PFNGLCLEARDEPTHF_PROC*)get_proc("glClearDepthf");
		glpfGetProgramBinary = (PFNGLGETPROGRAMBINARY_PROC*)get_proc("glGetProgramBinary");
		glpfProgramBinary = (PFNGLPROGRAMBINARY_PROC*)get_proc("glProgramBinary");
		glpfProgramParameteri = (PFNGLPROGRAMPARAMETERI_PROC*)get_proc("glProgramParameteri");
		glpfUseProgramStages = (PFNGLUSEPROGRAMSTAGES_PROC*)get_proc("glUseProgramStages");
		glpfActiveShaderProgram = (PFNGLACTIVESHADERPROGRAM_PROC*)get_proc("glActiveShaderProgram");
		glpfCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMV_PROC*)get_proc("glCreateShaderProgramv");
		glpfBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINE_PROC*)get_proc("glBindProgramPipeline");
		glpfDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINES_PROC*)get_proc("glDeleteProgramPipelines");
		glpfGenProgramPipelines = (PFNGLGENPROGRAMPIPELINES_PROC*)get_proc("glGenProgramPipelines");
		glpfIsProgramPipeline = (PFNGLISPROGRAMPIPELINE_PROC*)get_proc("glIsProgramPipeline");
		glpfGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIV_PROC*)get_proc("glGetProgramPipelineiv");
		glpfProgramUniform1i = (PFNGLPROGRAMUNIFORM1I_PROC*)get_proc("glProgramUniform1i");
		glpfProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IV_PROC*)get_proc("glProgramUniform1iv");
		glpfProgramUniform1f = (PFNGLPROGRAMUNIFORM1F_PROC*)get_proc("glProgramUniform1f");
		glpfProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FV_PROC*)get_proc("glProgramUniform1fv");
		glpfProgramUniform1d = (PFNGLPROGRAMUNIFORM1D_PROC*)get_proc("glProgramUniform1d");
		glpfProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DV_PROC*)get_proc("glProgramUniform1dv");
		glpfProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UI_PROC*)get_proc("glProgramUniform1ui");
		glpfProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIV_PROC*)get_proc("glProgramUniform1uiv");
		glpfProgramUniform2i = (PFNGLPROGRAMUNIFORM2I_PROC*)get_proc("glProgramUniform2i");
		glpfProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IV_PROC*)get_proc("glProgramUniform2iv");
		glpfProgramUniform2f = (PFNGLPROGRAMUNIFORM2F_PROC*)get_proc("glProgramUniform2f");
		glpfProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FV_PROC*)get_proc("glProgramUniform2fv");
		glpfProgramUniform2d = (PFNGLPROGRAMUNIFORM2D_PROC*)get_proc("glProgramUniform2d");
		glpfProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DV_PROC*)get_proc("glProgramUniform2dv");
		glpfProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UI_PROC*)get_proc("glProgramUniform2ui");
		glpfProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIV_PROC*)get_proc("glProgramUniform2uiv");
		glpfProgramUniform3i = (PFNGLPROGRAMUNIFORM3I_PROC*)get_proc("glProgramUniform3i");
		glpfProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IV_PROC*)get_proc("glProgramUniform3iv");
		glpfProgramUniform3f = (PFNGLPROGRAMUNIFORM3F_PROC*)get_proc("glProgramUniform3f");
		glpfProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FV_PROC*)get_proc("glProgramUniform3fv");
		glpfProgramUniform3d = (PFNGLPROGRAMUNIFORM3D_PROC*)get_proc("glProgramUniform3d");
		glpfProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DV_PROC*)get_proc("glProgramUniform3dv");
		glpfProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UI_PROC*)get_proc("glProgramUniform3ui");
		glpfProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIV_PROC*)get_proc("glProgramUniform3uiv");
		glpfProgramUniform4i = (PFNGLPROGRAMUNIFORM4I_PROC*)get_proc("glProgramUniform4i");
		glpfProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IV_PROC*)get_proc("glProgramUniform4iv");
		glpfProgramUniform4f = (PFNGLPROGRAMUNIFORM4F_PROC*)get_proc("glProgramUniform4f");
		glpfProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FV_PROC*)get_proc("glProgramUniform4fv");
		glpfProgramUniform4d = (PFNGLPROGRAMUNIFORM4D_PROC*)get_proc("glProgramUniform4d");
		glpfProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DV_PROC*)get_proc("glProgramUniform4dv");
		glpfProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UI_PROC*)get_proc("glProgramUniform4ui");
		glpfProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIV_PROC*)get_proc("glProgramUniform4uiv");
		glpfProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FV_PROC*)get_proc("glProgramUniformMatrix2fv");
		glpfProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FV_PROC*)get_proc("glProgramUniformMatrix3fv");
		glpfProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FV_PROC*)get_proc("glProgramUniformMatrix4fv");
		glpfProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DV_PROC*)get_proc("glProgramUniformMatrix2dv");
		glpfProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DV_PROC*)get_proc("glProgramUniformMatrix3dv");
		glpfProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DV_PROC*)get_proc("glProgramUniformMatrix4dv");
		glpfProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FV_PROC*)get_proc("glProgramUniformMatrix2x3fv");
		glpfProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FV_PROC*)get_proc("glProgramUniformMatrix3x2fv");
		glpfProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FV_PROC*)get_proc("glProgramUniformMatrix2x4fv");
		glpfProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FV_PROC*)get_proc("glProgramUniformMatrix4x2fv");
		glpfProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FV_PROC*)get_proc("glProgramUniformMatrix3x4fv");
		glpfProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FV_PROC*)get_proc("glProgramUniformMatrix4x3fv");
		glpfProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DV_PROC*)get_proc("glProgramUniformMatrix2x3dv");
		glpfProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DV_PROC*)get_proc("glProgramUniformMatrix3x2dv");
		glpfProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DV_PROC*)get_proc("glProgramUniformMatrix2x4dv");
		glpfProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DV_PROC*)get_proc("glProgramUniformMatrix4x2dv");
		glpfProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DV_PROC*)get_proc("glProgramUniformMatrix3x4dv");
		glpfProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DV_PROC*)get_proc("glProgramUniformMatrix4x3dv");
		glpfValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINE_PROC*)get_proc("glValidateProgramPipeline");
		glpfGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOG_PROC*)get_proc("glGetProgramPipelineInfoLog");
		glpfVertexAttribL1d = (PFNGLVERTEXATTRIBL1D_PROC*)get_proc("glVertexAttribL1d");
		glpfVertexAttribL2d = (PFNGLVERTEXATTRIBL2D_PROC*)get_proc("glVertexAttribL2d");
		glpfVertexAttribL3d = (PFNGLVERTEXATTRIBL3D_PROC*)get_proc("glVertexAttribL3d");
		glpfVertexAttribL4d = (PFNGLVERTEXATTRIBL4D_PROC*)get_proc("glVertexAttribL4d");
		glpfVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DV_PROC*)get_proc("glVertexAttribL1dv");
		glpfVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DV_PROC*)get_proc("glVertexAttribL2dv");
		glpfVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DV_PROC*)get_proc("glVertexAttribL3dv");
		glpfVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DV_PROC*)get_proc("glVertexAttribL4dv");
		glpfVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTER_PROC*)get_proc("glVertexAttribLPointer");
		glpfGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDV_PROC*)get_proc("glGetVertexAttribLdv");
		glpfViewportArrayv = (PFNGLVIEWPORTARRAYV_PROC*)get_proc("glViewportArrayv");
		glpfViewportIndexedf = (PFNGLVIEWPORTINDEXEDF_PROC*)get_proc("glViewportIndexedf");
		glpfViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFV_PROC*)get_proc("glViewportIndexedfv");
		glpfScissorArrayv = (PFNGLSCISSORARRAYV_PROC*)get_proc("glScissorArrayv");
		glpfScissorIndexed = (PFNGLSCISSORINDEXED_PROC*)get_proc("glScissorIndexed");
		glpfScissorIndexedv = (PFNGLSCISSORINDEXEDV_PROC*)get_proc("glScissorIndexedv");
		glpfDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYV_PROC*)get_proc("glDepthRangeArrayv");
		glpfDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXED_PROC*)get_proc("glDepthRangeIndexed");
		glpfGetFloati_v = (PFNGLGETFLOATI_V_PROC*)get_proc("glGetFloati_v");
		glpfGetDoublei_v = (PFNGLGETDOUBLEI_V_PROC*)get_proc("glGetDoublei_v");


		/* GL_VERSION_4_2 */

		glpfDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCE_PROC*)get_proc("glDrawArraysInstancedBaseInstance");
		glpfDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCE_PROC*)get_proc("glDrawElementsInstancedBaseInstance");
		glpfDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE_PROC*)get_proc("glDrawElementsInstancedBaseVertexBaseInstance");
		glpfGetInternalformativ = (PFNGLGETINTERNALFORMATIV_PROC*)get_proc("glGetInternalformativ");
		glpfGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIV_PROC*)get_proc("glGetActiveAtomicCounterBufferiv");
		glpfBindImageTexture = (PFNGLBINDIMAGETEXTURE_PROC*)get_proc("glBindImageTexture");
		glpfMemoryBarrier = (PFNGLMEMORYBARRIER_PROC*)get_proc("glMemoryBarrier");
		glpfTexStorage1D = (PFNGLTEXSTORAGE1D_PROC*)get_proc("glTexStorage1D");
		glpfTexStorage2D = (PFNGLTEXSTORAGE2D_PROC*)get_proc("glTexStorage2D");
		glpfTexStorage3D = (PFNGLTEXSTORAGE3D_PROC*)get_proc("glTexStorage3D");
		glpfDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCED_PROC*)get_proc("glDrawTransformFeedbackInstanced");
		glpfDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED_PROC*)get_proc("glDrawTransformFeedbackStreamInstanced");


		/* GL_VERSION_4_3 */

		glpfClearBufferData = (PFNGLCLEARBUFFERDATA_PROC*)get_proc("glClearBufferData");
		glpfClearBufferSubData = (PFNGLCLEARBUFFERSUBDATA_PROC*)get_proc("glClearBufferSubData");
		glpfDispatchCompute = (PFNGLDISPATCHCOMPUTE_PROC*)get_proc("glDispatchCompute");
		glpfDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECT_PROC*)get_proc("glDispatchComputeIndirect");
		glpfCopyImageSubData = (PFNGLCOPYIMAGESUBDATA_PROC*)get_proc("glCopyImageSubData");
		glpfFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERI_PROC*)get_proc("glFramebufferParameteri");
		glpfGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIV_PROC*)get_proc("glGetFramebufferParameteriv");
		glpfGetInternalformati64v = (PFNGLGETINTERNALFORMATI64V_PROC*)get_proc("glGetInternalformati64v");
		glpfInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGE_PROC*)get_proc("glInvalidateTexSubImage");
		glpfInvalidateTexImage = (PFNGLINVALIDATETEXIMAGE_PROC*)get_proc("glInvalidateTexImage");
		glpfInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATA_PROC*)get_proc("glInvalidateBufferSubData");
		glpfInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATA_PROC*)get_proc("glInvalidateBufferData");
		glpfInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFER_PROC*)get_proc("glInvalidateFramebuffer");
		glpfInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFER_PROC*)get_proc("glInvalidateSubFramebuffer");
		glpfMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECT_PROC*)get_proc("glMultiDrawArraysIndirect");
		glpfMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECT_PROC*)get_proc("glMultiDrawElementsIndirect");
		glpfGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIV_PROC*)get_proc("glGetProgramInterfaceiv");
		glpfGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEX_PROC*)get_proc("glGetProgramResourceIndex");
		glpfGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAME_PROC*)get_proc("glGetProgramResourceName");
		glpfGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIV_PROC*)get_proc("glGetProgramResourceiv");
		glpfGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATION_PROC*)get_proc("glGetProgramResourceLocation");
		glpfGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEX_PROC*)get_proc("glGetProgramResourceLocationIndex");
		glpfShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDING_PROC*)get_proc("glShaderStorageBlockBinding");
		glpfTexBufferRange = (PFNGLTEXBUFFERRANGE_PROC*)get_proc("glTexBufferRange");
		glpfTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLE_PROC*)get_proc("glTexStorage2DMultisample");
		glpfTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLE_PROC*)get_proc("glTexStorage3DMultisample");
		glpfTextureView = (PFNGLTEXTUREVIEW_PROC*)get_proc("glTextureView");
		glpfBindVertexBuffer = (PFNGLBINDVERTEXBUFFER_PROC*)get_proc("glBindVertexBuffer");
		glpfVertexAttribFormat = (PFNGLVERTEXATTRIBFORMAT_PROC*)get_proc("glVertexAttribFormat");
		glpfVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMAT_PROC*)get_proc("glVertexAttribIFormat");
		glpfVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMAT_PROC*)get_proc("glVertexAttribLFormat");
		glpfVertexAttribBinding = (PFNGLVERTEXATTRIBBINDING_PROC*)get_proc("glVertexAttribBinding");
		glpfVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISOR_PROC*)get_proc("glVertexBindingDivisor");
		glpfDebugMessageControl = (PFNGLDEBUGMESSAGECONTROL_PROC*)get_proc("glDebugMessageControl");
		glpfDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERT_PROC*)get_proc("glDebugMessageInsert");
		glpfDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACK_PROC*)get_proc("glDebugMessageCallback");
		glpfGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOG_PROC*)get_proc("glGetDebugMessageLog");
		glpfPushDebugGroup = (PFNGLPUSHDEBUGGROUP_PROC*)get_proc("glPushDebugGroup");
		glpfPopDebugGroup = (PFNGLPOPDEBUGGROUP_PROC*)get_proc("glPopDebugGroup");
		glpfObjectLabel = (PFNGLOBJECTLABEL_PROC*)get_proc("glObjectLabel");
		glpfGetObjectLabel = (PFNGLGETOBJECTLABEL_PROC*)get_proc("glGetObjectLabel");
		glpfObjectPtrLabel = (PFNGLOBJECTPTRLABEL_PROC*)get_proc("glObjectPtrLabel");
		glpfGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABEL_PROC*)get_proc("glGetObjectPtrLabel");
		glpfGetPointerv = (PFNGLGETPOINTERV_PROC*)get_proc("glGetPointerv");


		/* GL_VERSION_4_4 */

		glpfBufferStorage = (PFNGLBUFFERSTORAGE_PROC*)get_proc("glBufferStorage");
		glpfClearTexImage = (PFNGLCLEARTEXIMAGE_PROC*)get_proc("glClearTexImage");
		glpfClearTexSubImage = (PFNGLCLEARTEXSUBIMAGE_PROC*)get_proc("glClearTexSubImage");
		glpfBindBuffersBase = (PFNGLBINDBUFFERSBASE_PROC*)get_proc("glBindBuffersBase");
		glpfBindBuffersRange = (PFNGLBINDBUFFERSRANGE_PROC*)get_proc("glBindBuffersRange");
		glpfBindTextures = (PFNGLBINDTEXTURES_PROC*)get_proc("glBindTextures");
		glpfBindSamplers = (PFNGLBINDSAMPLERS_PROC*)get_proc("glBindSamplers");
		glpfBindImageTextures = (PFNGLBINDIMAGETEXTURES_PROC*)get_proc("glBindImageTextures");
		glpfBindVertexBuffers = (PFNGLBINDVERTEXBUFFERS_PROC*)get_proc("glBindVertexBuffers");


		/* GL_VERSION_4_5 */

		glpfClipControl = (PFNGLCLIPCONTROL_PROC*)get_proc("glClipControl");
		glpfCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKS_PROC*)get_proc("glCreateTransformFeedbacks");
		glpfTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASE_PROC*)get_proc("glTransformFeedbackBufferBase");
		glpfTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGE_PROC*)get_proc("glTransformFeedbackBufferRange");
		glpfGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIV_PROC*)get_proc("glGetTransformFeedbackiv");
		glpfGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_V_PROC*)get_proc("glGetTransformFeedbacki_v");
		glpfGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_V_PROC*)get_proc("glGetTransformFeedbacki64_v");
		glpfCreateBuffers = (PFNGLCREATEBUFFERS_PROC*)get_proc("glCreateBuffers");
		glpfNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGE_PROC*)get_proc("glNamedBufferStorage");
		glpfNamedBufferData = (PFNGLNAMEDBUFFERDATA_PROC*)get_proc("glNamedBufferData");
		glpfNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATA_PROC*)get_proc("glNamedBufferSubData");
		glpfCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATA_PROC*)get_proc("glCopyNamedBufferSubData");
		glpfClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATA_PROC*)get_proc("glClearNamedBufferData");
		glpfClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATA_PROC*)get_proc("glClearNamedBufferSubData");
		glpfMapNamedBuffer = (PFNGLMAPNAMEDBUFFER_PROC*)get_proc("glMapNamedBuffer");
		glpfMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGE_PROC*)get_proc("glMapNamedBufferRange");
		glpfUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFER_PROC*)get_proc("glUnmapNamedBuffer");
		glpfFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGE_PROC*)get_proc("glFlushMappedNamedBufferRange");
		glpfGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIV_PROC*)get_proc("glGetNamedBufferParameteriv");
		glpfGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64V_PROC*)get_proc("glGetNamedBufferParameteri64v");
		glpfGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERV_PROC*)get_proc("glGetNamedBufferPointerv");
		glpfGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATA_PROC*)get_proc("glGetNamedBufferSubData");
		glpfCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERS_PROC*)get_proc("glCreateFramebuffers");
		glpfNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFER_PROC*)get_proc("glNamedFramebufferRenderbuffer");
		glpfNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERI_PROC*)get_proc("glNamedFramebufferParameteri");
		glpfNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTURE_PROC*)get_proc("glNamedFramebufferTexture");
		glpfNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYER_PROC*)get_proc("glNamedFramebufferTextureLayer");
		glpfNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFER_PROC*)get_proc("glNamedFramebufferDrawBuffer");
		glpfNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERS_PROC*)get_proc("glNamedFramebufferDrawBuffers");
		glpfNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFER_PROC*)get_proc("glNamedFramebufferReadBuffer");
		glpfInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATA_PROC*)get_proc("glInvalidateNamedFramebufferData");
		glpfInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATA_PROC*)get_proc("glInvalidateNamedFramebufferSubData");
		glpfClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIV_PROC*)get_proc("glClearNamedFramebufferiv");
		glpfClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIV_PROC*)get_proc("glClearNamedFramebufferuiv");
		glpfClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFV_PROC*)get_proc("glClearNamedFramebufferfv");
		glpfClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFI_PROC*)get_proc("glClearNamedFramebufferfi");
		glpfBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFER_PROC*)get_proc("glBlitNamedFramebuffer");
		glpfCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUS_PROC*)get_proc("glCheckNamedFramebufferStatus");
		glpfGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIV_PROC*)get_proc("glGetNamedFramebufferParameteriv");
		glpfGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV_PROC*)get_proc("glGetNamedFramebufferAttachmentParameteriv");
		glpfCreateRenderbuffers = (PFNGLCREATERENDERBUFFERS_PROC*)get_proc("glCreateRenderbuffers");
		glpfNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGE_PROC*)get_proc("glNamedRenderbufferStorage");
		glpfNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE_PROC*)get_proc("glNamedRenderbufferStorageMultisample");
		glpfGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIV_PROC*)get_proc("glGetNamedRenderbufferParameteriv");
		glpfCreateTextures = (PFNGLCREATETEXTURES_PROC*)get_proc("glCreateTextures");
		glpfTextureBuffer = (PFNGLTEXTUREBUFFER_PROC*)get_proc("glTextureBuffer");
		glpfTextureBufferRange = (PFNGLTEXTUREBUFFERRANGE_PROC*)get_proc("glTextureBufferRange");
		glpfTextureStorage1D = (PFNGLTEXTURESTORAGE1D_PROC*)get_proc("glTextureStorage1D");
		glpfTextureStorage2D = (PFNGLTEXTURESTORAGE2D_PROC*)get_proc("glTextureStorage2D");
		glpfTextureStorage3D = (PFNGLTEXTURESTORAGE3D_PROC*)get_proc("glTextureStorage3D");
		glpfTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLE_PROC*)get_proc("glTextureStorage2DMultisample");
		glpfTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLE_PROC*)get_proc("glTextureStorage3DMultisample");
		glpfTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1D_PROC*)get_proc("glTextureSubImage1D");
		glpfTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2D_PROC*)get_proc("glTextureSubImage2D");
		glpfTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3D_PROC*)get_proc("glTextureSubImage3D");
		glpfCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1D_PROC*)get_proc("glCompressedTextureSubImage1D");
		glpfCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2D_PROC*)get_proc("glCompressedTextureSubImage2D");
		glpfCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3D_PROC*)get_proc("glCompressedTextureSubImage3D");
		glpfCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1D_PROC*)get_proc("glCopyTextureSubImage1D");
		glpfCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2D_PROC*)get_proc("glCopyTextureSubImage2D");
		glpfCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3D_PROC*)get_proc("glCopyTextureSubImage3D");
		glpfTextureParameterf = (PFNGLTEXTUREPARAMETERF_PROC*)get_proc("glTextureParameterf");
		glpfTextureParameterfv = (PFNGLTEXTUREPARAMETERFV_PROC*)get_proc("glTextureParameterfv");
		glpfTextureParameteri = (PFNGLTEXTUREPARAMETERI_PROC*)get_proc("glTextureParameteri");
		glpfTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIV_PROC*)get_proc("glTextureParameterIiv");
		glpfTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIV_PROC*)get_proc("glTextureParameterIuiv");
		glpfTextureParameteriv = (PFNGLTEXTUREPARAMETERIV_PROC*)get_proc("glTextureParameteriv");
		glpfGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAP_PROC*)get_proc("glGenerateTextureMipmap");
		glpfBindTextureUnit = (PFNGLBINDTEXTUREUNIT_PROC*)get_proc("glBindTextureUnit");
		glpfGetTextureImage = (PFNGLGETTEXTUREIMAGE_PROC*)get_proc("glGetTextureImage");
		glpfGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGE_PROC*)get_proc("glGetCompressedTextureImage");
		glpfGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFV_PROC*)get_proc("glGetTextureLevelParameterfv");
		glpfGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIV_PROC*)get_proc("glGetTextureLevelParameteriv");
		glpfGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFV_PROC*)get_proc("glGetTextureParameterfv");
		glpfGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIV_PROC*)get_proc("glGetTextureParameterIiv");
		glpfGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIV_PROC*)get_proc("glGetTextureParameterIuiv");
		glpfGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIV_PROC*)get_proc("glGetTextureParameteriv");
		glpfCreateVertexArrays = (PFNGLCREATEVERTEXARRAYS_PROC*)get_proc("glCreateVertexArrays");
		glpfDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIB_PROC*)get_proc("glDisableVertexArrayAttrib");
		glpfEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIB_PROC*)get_proc("glEnableVertexArrayAttrib");
		glpfVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFER_PROC*)get_proc("glVertexArrayElementBuffer");
		glpfVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFER_PROC*)get_proc("glVertexArrayVertexBuffer");
		glpfVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERS_PROC*)get_proc("glVertexArrayVertexBuffers");
		glpfVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDING_PROC*)get_proc("glVertexArrayAttribBinding");
		glpfVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMAT_PROC*)get_proc("glVertexArrayAttribFormat");
		glpfVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMAT_PROC*)get_proc("glVertexArrayAttribIFormat");
		glpfVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMAT_PROC*)get_proc("glVertexArrayAttribLFormat");
		glpfVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISOR_PROC*)get_proc("glVertexArrayBindingDivisor");
		glpfGetVertexArrayiv = (PFNGLGETVERTEXARRAYIV_PROC*)get_proc("glGetVertexArrayiv");
		glpfGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIV_PROC*)get_proc("glGetVertexArrayIndexediv");
		glpfGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IV_PROC*)get_proc("glGetVertexArrayIndexed64iv");
		glpfCreateSamplers = (PFNGLCREATESAMPLERS_PROC*)get_proc("glCreateSamplers");
		glpfCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINES_PROC*)get_proc("glCreateProgramPipelines");
		glpfCreateQueries = (PFNGLCREATEQUERIES_PROC*)get_proc("glCreateQueries");
		glpfGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64V_PROC*)get_proc("glGetQueryBufferObjecti64v");
		glpfGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIV_PROC*)get_proc("glGetQueryBufferObjectiv");
		glpfGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64V_PROC*)get_proc("glGetQueryBufferObjectui64v");
		glpfGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIV_PROC*)get_proc("glGetQueryBufferObjectuiv");
		glpfMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGION_PROC*)get_proc("glMemoryBarrierByRegion");
		glpfGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGE_PROC*)get_proc("glGetTextureSubImage");
		glpfGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGE_PROC*)get_proc("glGetCompressedTextureSubImage");
		glpfGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUS_PROC*)get_proc("glGetGraphicsResetStatus");
		glpfGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGE_PROC*)get_proc("glGetnCompressedTexImage");
		glpfGetnTexImage = (PFNGLGETNTEXIMAGE_PROC*)get_proc("glGetnTexImage");
		glpfGetnUniformdv = (PFNGLGETNUNIFORMDV_PROC*)get_proc("glGetnUniformdv");
		glpfGetnUniformfv = (PFNGLGETNUNIFORMFV_PROC*)get_proc("glGetnUniformfv");
		glpfGetnUniformiv = (PFNGLGETNUNIFORMIV_PROC*)get_proc("glGetnUniformiv");
		glpfGetnUniformuiv = (PFNGLGETNUNIFORMUIV_PROC*)get_proc("glGetnUniformuiv");
		glpfReadnPixels = (PFNGLREADNPIXELS_PROC*)get_proc("glReadnPixels");
		glpfTextureBarrier = (PFNGLTEXTUREBARRIER_PROC*)get_proc("glTextureBarrier");


		/* GL_ARB_bindless_texture */

		glpfGetTextureHandleARB = (PFNGLGETTEXTUREHANDLEARB_PROC*)get_proc("glGetTextureHandleARB");
		glpfGetTextureSamplerHandleARB = (PFNGLGETTEXTURESAMPLERHANDLEARB_PROC*)get_proc("glGetTextureSamplerHandleARB");
		glpfMakeTextureHandleResidentARB = (PFNGLMAKETEXTUREHANDLERESIDENTARB_PROC*)get_proc("glMakeTextureHandleResidentARB");
		glpfMakeTextureHandleNonResidentARB = (PFNGLMAKETEXTUREHANDLENONRESIDENTARB_PROC*)get_proc("glMakeTextureHandleNonResidentARB");
		glpfGetImageHandleARB = (PFNGLGETIMAGEHANDLEARB_PROC*)get_proc("glGetImageHandleARB");
		glpfMakeImageHandleResidentARB = (PFNGLMAKEIMAGEHANDLERESIDENTARB_PROC*)get_proc("glMakeImageHandleResidentARB");
		glpfMakeImageHandleNonResidentARB = (PFNGLMAKEIMAGEHANDLENONRESIDENTARB_PROC*)get_proc("glMakeImageHandleNonResidentARB");
		glpfUniformHandleui64ARB = (PFNGLUNIFORMHANDLEUI64ARB_PROC*)get_proc("glUniformHandleui64ARB");
		glpfUniformHandleui64vARB = (PFNGLUNIFORMHANDLEUI64VARB_PROC*)get_proc("glUniformHandleui64vARB");
		glpfProgramUniformHandleui64ARB = (PFNGLPROGRAMUNIFORMHANDLEUI64ARB_PROC*)get_proc("glProgramUniformHandleui64ARB");
		glpfProgramUniformHandleui64vARB = (PFNGLPROGRAMUNIFORMHANDLEUI64VARB_PROC*)get_proc("glProgramUniformHandleui64vARB");
		glpfIsTextureHandleResidentARB = (PFNGLISTEXTUREHANDLERESIDENTARB_PROC*)get_proc("glIsTextureHandleResidentARB");
		glpfIsImageHandleResidentARB = (PFNGLISIMAGEHANDLERESIDENTARB_PROC*)get_proc("glIsImageHandleResidentARB");
		glpfVertexAttribL1ui64ARB = (PFNGLVERTEXATTRIBL1UI64ARB_PROC*)get_proc("glVertexAttribL1ui64ARB");
		glpfVertexAttribL1ui64vARB = (PFNGLVERTEXATTRIBL1UI64VARB_PROC*)get_proc("glVertexAttribL1ui64vARB");
		glpfGetVertexAttribLui64vARB = (PFNGLGETVERTEXATTRIBLUI64VARB_PROC*)get_proc("glGetVertexAttribLui64vARB");


		/* GL_ARB_sparse_texture */

		glpfTexPageCommitmentARB = (PFNGLTEXPAGECOMMITMENTARB_PROC*)get_proc("glTexPageCommitmentARB");


		/* GL_ARB_indirect_parameters */

		glpfMultiDrawArraysIndirectCountARB = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARB_PROC*)get_proc("glMultiDrawArraysIndirectCountARB");
		glpfMultiDrawElementsIndirectCountARB = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARB_PROC*)get_proc("glMultiDrawElementsIndirectCountARB");


		/* GL_ARB_pipeline_statistics_query */



		/* GL_ARB_texture_non_power_of_two */



		/* GL_EXT_direct_state_access */

		glpfMatrixLoadfEXT = (PFNGLMATRIXLOADFEXT_PROC*)get_proc("glMatrixLoadfEXT");
		glpfMatrixLoaddEXT = (PFNGLMATRIXLOADDEXT_PROC*)get_proc("glMatrixLoaddEXT");
		glpfMatrixMultfEXT = (PFNGLMATRIXMULTFEXT_PROC*)get_proc("glMatrixMultfEXT");
		glpfMatrixMultdEXT = (PFNGLMATRIXMULTDEXT_PROC*)get_proc("glMatrixMultdEXT");
		glpfMatrixLoadIdentityEXT = (PFNGLMATRIXLOADIDENTITYEXT_PROC*)get_proc("glMatrixLoadIdentityEXT");
		glpfMatrixRotatefEXT = (PFNGLMATRIXROTATEFEXT_PROC*)get_proc("glMatrixRotatefEXT");
		glpfMatrixRotatedEXT = (PFNGLMATRIXROTATEDEXT_PROC*)get_proc("glMatrixRotatedEXT");
		glpfMatrixScalefEXT = (PFNGLMATRIXSCALEFEXT_PROC*)get_proc("glMatrixScalefEXT");
		glpfMatrixScaledEXT = (PFNGLMATRIXSCALEDEXT_PROC*)get_proc("glMatrixScaledEXT");
		glpfMatrixTranslatefEXT = (PFNGLMATRIXTRANSLATEFEXT_PROC*)get_proc("glMatrixTranslatefEXT");
		glpfMatrixTranslatedEXT = (PFNGLMATRIXTRANSLATEDEXT_PROC*)get_proc("glMatrixTranslatedEXT");
		glpfMatrixFrustumEXT = (PFNGLMATRIXFRUSTUMEXT_PROC*)get_proc("glMatrixFrustumEXT");
		glpfMatrixOrthoEXT = (PFNGLMATRIXORTHOEXT_PROC*)get_proc("glMatrixOrthoEXT");
		glpfMatrixPopEXT = (PFNGLMATRIXPOPEXT_PROC*)get_proc("glMatrixPopEXT");
		glpfMatrixPushEXT = (PFNGLMATRIXPUSHEXT_PROC*)get_proc("glMatrixPushEXT");
		glpfClientAttribDefaultEXT = (PFNGLCLIENTATTRIBDEFAULTEXT_PROC*)get_proc("glClientAttribDefaultEXT");
		glpfPushClientAttribDefaultEXT = (PFNGLPUSHCLIENTATTRIBDEFAULTEXT_PROC*)get_proc("glPushClientAttribDefaultEXT");
		glpfTextureParameterfEXT = (PFNGLTEXTUREPARAMETERFEXT_PROC*)get_proc("glTextureParameterfEXT");
		glpfTextureParameterfvEXT = (PFNGLTEXTUREPARAMETERFVEXT_PROC*)get_proc("glTextureParameterfvEXT");
		glpfTextureParameteriEXT = (PFNGLTEXTUREPARAMETERIEXT_PROC*)get_proc("glTextureParameteriEXT");
		glpfTextureParameterivEXT = (PFNGLTEXTUREPARAMETERIVEXT_PROC*)get_proc("glTextureParameterivEXT");
		glpfTextureImage1DEXT = (PFNGLTEXTUREIMAGE1DEXT_PROC*)get_proc("glTextureImage1DEXT");
		glpfTextureImage2DEXT = (PFNGLTEXTUREIMAGE2DEXT_PROC*)get_proc("glTextureImage2DEXT");
		glpfTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXT_PROC*)get_proc("glTextureSubImage1DEXT");
		glpfTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXT_PROC*)get_proc("glTextureSubImage2DEXT");
		glpfCopyTextureImage1DEXT = (PFNGLCOPYTEXTUREIMAGE1DEXT_PROC*)get_proc("glCopyTextureImage1DEXT");
		glpfCopyTextureImage2DEXT = (PFNGLCOPYTEXTUREIMAGE2DEXT_PROC*)get_proc("glCopyTextureImage2DEXT");
		glpfCopyTextureSubImage1DEXT = (PFNGLCOPYTEXTURESUBIMAGE1DEXT_PROC*)get_proc("glCopyTextureSubImage1DEXT");
		glpfCopyTextureSubImage2DEXT = (PFNGLCOPYTEXTURESUBIMAGE2DEXT_PROC*)get_proc("glCopyTextureSubImage2DEXT");
		glpfGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXT_PROC*)get_proc("glGetTextureImageEXT");
		glpfGetTextureParameterfvEXT = (PFNGLGETTEXTUREPARAMETERFVEXT_PROC*)get_proc("glGetTextureParameterfvEXT");
		glpfGetTextureParameterivEXT = (PFNGLGETTEXTUREPARAMETERIVEXT_PROC*)get_proc("glGetTextureParameterivEXT");
		glpfGetTextureLevelParameterfvEXT = (PFNGLGETTEXTURELEVELPARAMETERFVEXT_PROC*)get_proc("glGetTextureLevelParameterfvEXT");
		glpfGetTextureLevelParameterivEXT = (PFNGLGETTEXTURELEVELPARAMETERIVEXT_PROC*)get_proc("glGetTextureLevelParameterivEXT");
		glpfTextureImage3DEXT = (PFNGLTEXTUREIMAGE3DEXT_PROC*)get_proc("glTextureImage3DEXT");
		glpfTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXT_PROC*)get_proc("glTextureSubImage3DEXT");
		glpfCopyTextureSubImage3DEXT = (PFNGLCOPYTEXTURESUBIMAGE3DEXT_PROC*)get_proc("glCopyTextureSubImage3DEXT");
		glpfBindMultiTextureEXT = (PFNGLBINDMULTITEXTUREEXT_PROC*)get_proc("glBindMultiTextureEXT");
		glpfMultiTexCoordPointerEXT = (PFNGLMULTITEXCOORDPOINTEREXT_PROC*)get_proc("glMultiTexCoordPointerEXT");
		glpfMultiTexEnvfEXT = (PFNGLMULTITEXENVFEXT_PROC*)get_proc("glMultiTexEnvfEXT");
		glpfMultiTexEnvfvEXT = (PFNGLMULTITEXENVFVEXT_PROC*)get_proc("glMultiTexEnvfvEXT");
		glpfMultiTexEnviEXT = (PFNGLMULTITEXENVIEXT_PROC*)get_proc("glMultiTexEnviEXT");
		glpfMultiTexEnvivEXT = (PFNGLMULTITEXENVIVEXT_PROC*)get_proc("glMultiTexEnvivEXT");
		glpfMultiTexGendEXT = (PFNGLMULTITEXGENDEXT_PROC*)get_proc("glMultiTexGendEXT");
		glpfMultiTexGendvEXT = (PFNGLMULTITEXGENDVEXT_PROC*)get_proc("glMultiTexGendvEXT");
		glpfMultiTexGenfEXT = (PFNGLMULTITEXGENFEXT_PROC*)get_proc("glMultiTexGenfEXT");
		glpfMultiTexGenfvEXT = (PFNGLMULTITEXGENFVEXT_PROC*)get_proc("glMultiTexGenfvEXT");
		glpfMultiTexGeniEXT = (PFNGLMULTITEXGENIEXT_PROC*)get_proc("glMultiTexGeniEXT");
		glpfMultiTexGenivEXT = (PFNGLMULTITEXGENIVEXT_PROC*)get_proc("glMultiTexGenivEXT");
		glpfGetMultiTexEnvfvEXT = (PFNGLGETMULTITEXENVFVEXT_PROC*)get_proc("glGetMultiTexEnvfvEXT");
		glpfGetMultiTexEnvivEXT = (PFNGLGETMULTITEXENVIVEXT_PROC*)get_proc("glGetMultiTexEnvivEXT");
		glpfGetMultiTexGendvEXT = (PFNGLGETMULTITEXGENDVEXT_PROC*)get_proc("glGetMultiTexGendvEXT");
		glpfGetMultiTexGenfvEXT = (PFNGLGETMULTITEXGENFVEXT_PROC*)get_proc("glGetMultiTexGenfvEXT");
		glpfGetMultiTexGenivEXT = (PFNGLGETMULTITEXGENIVEXT_PROC*)get_proc("glGetMultiTexGenivEXT");
		glpfMultiTexParameteriEXT = (PFNGLMULTITEXPARAMETERIEXT_PROC*)get_proc("glMultiTexParameteriEXT");
		glpfMultiTexParameterivEXT = (PFNGLMULTITEXPARAMETERIVEXT_PROC*)get_proc("glMultiTexParameterivEXT");
		glpfMultiTexParameterfEXT = (PFNGLMULTITEXPARAMETERFEXT_PROC*)get_proc("glMultiTexParameterfEXT");
		glpfMultiTexParameterfvEXT = (PFNGLMULTITEXPARAMETERFVEXT_PROC*)get_proc("glMultiTexParameterfvEXT");
		glpfMultiTexImage1DEXT = (PFNGLMULTITEXIMAGE1DEXT_PROC*)get_proc("glMultiTexImage1DEXT");
		glpfMultiTexImage2DEXT = (PFNGLMULTITEXIMAGE2DEXT_PROC*)get_proc("glMultiTexImage2DEXT");
		glpfMultiTexSubImage1DEXT = (PFNGLMULTITEXSUBIMAGE1DEXT_PROC*)get_proc("glMultiTexSubImage1DEXT");
		glpfMultiTexSubImage2DEXT = (PFNGLMULTITEXSUBIMAGE2DEXT_PROC*)get_proc("glMultiTexSubImage2DEXT");
		glpfCopyMultiTexImage1DEXT = (PFNGLCOPYMULTITEXIMAGE1DEXT_PROC*)get_proc("glCopyMultiTexImage1DEXT");
		glpfCopyMultiTexImage2DEXT = (PFNGLCOPYMULTITEXIMAGE2DEXT_PROC*)get_proc("glCopyMultiTexImage2DEXT");
		glpfCopyMultiTexSubImage1DEXT = (PFNGLCOPYMULTITEXSUBIMAGE1DEXT_PROC*)get_proc("glCopyMultiTexSubImage1DEXT");
		glpfCopyMultiTexSubImage2DEXT = (PFNGLCOPYMULTITEXSUBIMAGE2DEXT_PROC*)get_proc("glCopyMultiTexSubImage2DEXT");
		glpfGetMultiTexImageEXT = (PFNGLGETMULTITEXIMAGEEXT_PROC*)get_proc("glGetMultiTexImageEXT");
		glpfGetMultiTexParameterfvEXT = (PFNGLGETMULTITEXPARAMETERFVEXT_PROC*)get_proc("glGetMultiTexParameterfvEXT");
		glpfGetMultiTexParameterivEXT = (PFNGLGETMULTITEXPARAMETERIVEXT_PROC*)get_proc("glGetMultiTexParameterivEXT");
		glpfGetMultiTexLevelParameterfvEXT = (PFNGLGETMULTITEXLEVELPARAMETERFVEXT_PROC*)get_proc("glGetMultiTexLevelParameterfvEXT");
		glpfGetMultiTexLevelParameterivEXT = (PFNGLGETMULTITEXLEVELPARAMETERIVEXT_PROC*)get_proc("glGetMultiTexLevelParameterivEXT");
		glpfMultiTexImage3DEXT = (PFNGLMULTITEXIMAGE3DEXT_PROC*)get_proc("glMultiTexImage3DEXT");
		glpfMultiTexSubImage3DEXT = (PFNGLMULTITEXSUBIMAGE3DEXT_PROC*)get_proc("glMultiTexSubImage3DEXT");
		glpfCopyMultiTexSubImage3DEXT = (PFNGLCOPYMULTITEXSUBIMAGE3DEXT_PROC*)get_proc("glCopyMultiTexSubImage3DEXT");
		glpfEnableClientStateIndexedEXT = (PFNGLENABLECLIENTSTATEINDEXEDEXT_PROC*)get_proc("glEnableClientStateIndexedEXT");
		glpfDisableClientStateIndexedEXT = (PFNGLDISABLECLIENTSTATEINDEXEDEXT_PROC*)get_proc("glDisableClientStateIndexedEXT");
		glpfGetFloatIndexedvEXT = (PFNGLGETFLOATINDEXEDVEXT_PROC*)get_proc("glGetFloatIndexedvEXT");
		glpfGetDoubleIndexedvEXT = (PFNGLGETDOUBLEINDEXEDVEXT_PROC*)get_proc("glGetDoubleIndexedvEXT");
		glpfGetPointerIndexedvEXT = (PFNGLGETPOINTERINDEXEDVEXT_PROC*)get_proc("glGetPointerIndexedvEXT");
		glpfEnableIndexedEXT = (PFNGLENABLEINDEXEDEXT_PROC*)get_proc("glEnableIndexedEXT");
		glpfDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXT_PROC*)get_proc("glDisableIndexedEXT");
		glpfIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXT_PROC*)get_proc("glIsEnabledIndexedEXT");
		glpfGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXT_PROC*)get_proc("glGetIntegerIndexedvEXT");
		glpfGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXT_PROC*)get_proc("glGetBooleanIndexedvEXT");
		glpfCompressedTextureImage3DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXT_PROC*)get_proc("glCompressedTextureImage3DEXT");
		glpfCompressedTextureImage2DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXT_PROC*)get_proc("glCompressedTextureImage2DEXT");
		glpfCompressedTextureImage1DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXT_PROC*)get_proc("glCompressedTextureImage1DEXT");
		glpfCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXT_PROC*)get_proc("glCompressedTextureSubImage3DEXT");
		glpfCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXT_PROC*)get_proc("glCompressedTextureSubImage2DEXT");
		glpfCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXT_PROC*)get_proc("glCompressedTextureSubImage1DEXT");
		glpfGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXT_PROC*)get_proc("glGetCompressedTextureImageEXT");
		glpfCompressedMultiTexImage3DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXT_PROC*)get_proc("glCompressedMultiTexImage3DEXT");
		glpfCompressedMultiTexImage2DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXT_PROC*)get_proc("glCompressedMultiTexImage2DEXT");
		glpfCompressedMultiTexImage1DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXT_PROC*)get_proc("glCompressedMultiTexImage1DEXT");
		glpfCompressedMultiTexSubImage3DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXT_PROC*)get_proc("glCompressedMultiTexSubImage3DEXT");
		glpfCompressedMultiTexSubImage2DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXT_PROC*)get_proc("glCompressedMultiTexSubImage2DEXT");
		glpfCompressedMultiTexSubImage1DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXT_PROC*)get_proc("glCompressedMultiTexSubImage1DEXT");
		glpfGetCompressedMultiTexImageEXT = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXT_PROC*)get_proc("glGetCompressedMultiTexImageEXT");
		glpfMatrixLoadTransposefEXT = (PFNGLMATRIXLOADTRANSPOSEFEXT_PROC*)get_proc("glMatrixLoadTransposefEXT");
		glpfMatrixLoadTransposedEXT = (PFNGLMATRIXLOADTRANSPOSEDEXT_PROC*)get_proc("glMatrixLoadTransposedEXT");
		glpfMatrixMultTransposefEXT = (PFNGLMATRIXMULTTRANSPOSEFEXT_PROC*)get_proc("glMatrixMultTransposefEXT");
		glpfMatrixMultTransposedEXT = (PFNGLMATRIXMULTTRANSPOSEDEXT_PROC*)get_proc("glMatrixMultTransposedEXT");
		glpfNamedBufferDataEXT = (PFNGLNAMEDBUFFERDATAEXT_PROC*)get_proc("glNamedBufferDataEXT");
		glpfNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXT_PROC*)get_proc("glNamedBufferSubDataEXT");
		glpfMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXT_PROC*)get_proc("glMapNamedBufferEXT");
		glpfUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXT_PROC*)get_proc("glUnmapNamedBufferEXT");
		glpfGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXT_PROC*)get_proc("glGetNamedBufferParameterivEXT");
		glpfGetNamedBufferPointervEXT = (PFNGLGETNAMEDBUFFERPOINTERVEXT_PROC*)get_proc("glGetNamedBufferPointervEXT");
		glpfGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXT_PROC*)get_proc("glGetNamedBufferSubDataEXT");
		glpfProgramUniform1fEXT = (PFNGLPROGRAMUNIFORM1FEXT_PROC*)get_proc("glProgramUniform1fEXT");
		glpfProgramUniform2fEXT = (PFNGLPROGRAMUNIFORM2FEXT_PROC*)get_proc("glProgramUniform2fEXT");
		glpfProgramUniform3fEXT = (PFNGLPROGRAMUNIFORM3FEXT_PROC*)get_proc("glProgramUniform3fEXT");
		glpfProgramUniform4fEXT = (PFNGLPROGRAMUNIFORM4FEXT_PROC*)get_proc("glProgramUniform4fEXT");
		glpfProgramUniform1iEXT = (PFNGLPROGRAMUNIFORM1IEXT_PROC*)get_proc("glProgramUniform1iEXT");
		glpfProgramUniform2iEXT = (PFNGLPROGRAMUNIFORM2IEXT_PROC*)get_proc("glProgramUniform2iEXT");
		glpfProgramUniform3iEXT = (PFNGLPROGRAMUNIFORM3IEXT_PROC*)get_proc("glProgramUniform3iEXT");
		glpfProgramUniform4iEXT = (PFNGLPROGRAMUNIFORM4IEXT_PROC*)get_proc("glProgramUniform4iEXT");
		glpfProgramUniform1fvEXT = (PFNGLPROGRAMUNIFORM1FVEXT_PROC*)get_proc("glProgramUniform1fvEXT");
		glpfProgramUniform2fvEXT = (PFNGLPROGRAMUNIFORM2FVEXT_PROC*)get_proc("glProgramUniform2fvEXT");
		glpfProgramUniform3fvEXT = (PFNGLPROGRAMUNIFORM3FVEXT_PROC*)get_proc("glProgramUniform3fvEXT");
		glpfProgramUniform4fvEXT = (PFNGLPROGRAMUNIFORM4FVEXT_PROC*)get_proc("glProgramUniform4fvEXT");
		glpfProgramUniform1ivEXT = (PFNGLPROGRAMUNIFORM1IVEXT_PROC*)get_proc("glProgramUniform1ivEXT");
		glpfProgramUniform2ivEXT = (PFNGLPROGRAMUNIFORM2IVEXT_PROC*)get_proc("glProgramUniform2ivEXT");
		glpfProgramUniform3ivEXT = (PFNGLPROGRAMUNIFORM3IVEXT_PROC*)get_proc("glProgramUniform3ivEXT");
		glpfProgramUniform4ivEXT = (PFNGLPROGRAMUNIFORM4IVEXT_PROC*)get_proc("glProgramUniform4ivEXT");
		glpfProgramUniformMatrix2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2FVEXT_PROC*)get_proc("glProgramUniformMatrix2fvEXT");
		glpfProgramUniformMatrix3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3FVEXT_PROC*)get_proc("glProgramUniformMatrix3fvEXT");
		glpfProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXT_PROC*)get_proc("glProgramUniformMatrix4fvEXT");
		glpfProgramUniformMatrix2x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXT_PROC*)get_proc("glProgramUniformMatrix2x3fvEXT");
		glpfProgramUniformMatrix3x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXT_PROC*)get_proc("glProgramUniformMatrix3x2fvEXT");
		glpfProgramUniformMatrix2x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXT_PROC*)get_proc("glProgramUniformMatrix2x4fvEXT");
		glpfProgramUniformMatrix4x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXT_PROC*)get_proc("glProgramUniformMatrix4x2fvEXT");
		glpfProgramUniformMatrix3x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXT_PROC*)get_proc("glProgramUniformMatrix3x4fvEXT");
		glpfProgramUniformMatrix4x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXT_PROC*)get_proc("glProgramUniformMatrix4x3fvEXT");
		glpfTextureBufferEXT = (PFNGLTEXTUREBUFFEREXT_PROC*)get_proc("glTextureBufferEXT");
		glpfMultiTexBufferEXT = (PFNGLMULTITEXBUFFEREXT_PROC*)get_proc("glMultiTexBufferEXT");
		glpfTextureParameterIivEXT = (PFNGLTEXTUREPARAMETERIIVEXT_PROC*)get_proc("glTextureParameterIivEXT");
		glpfTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXT_PROC*)get_proc("glTextureParameterIuivEXT");
		glpfGetTextureParameterIivEXT = (PFNGLGETTEXTUREPARAMETERIIVEXT_PROC*)get_proc("glGetTextureParameterIivEXT");
		glpfGetTextureParameterIuivEXT = (PFNGLGETTEXTUREPARAMETERIUIVEXT_PROC*)get_proc("glGetTextureParameterIuivEXT");
		glpfMultiTexParameterIivEXT = (PFNGLMULTITEXPARAMETERIIVEXT_PROC*)get_proc("glMultiTexParameterIivEXT");
		glpfMultiTexParameterIuivEXT = (PFNGLMULTITEXPARAMETERIUIVEXT_PROC*)get_proc("glMultiTexParameterIuivEXT");
		glpfGetMultiTexParameterIivEXT = (PFNGLGETMULTITEXPARAMETERIIVEXT_PROC*)get_proc("glGetMultiTexParameterIivEXT");
		glpfGetMultiTexParameterIuivEXT = (PFNGLGETMULTITEXPARAMETERIUIVEXT_PROC*)get_proc("glGetMultiTexParameterIuivEXT");
		glpfProgramUniform1uiEXT = (PFNGLPROGRAMUNIFORM1UIEXT_PROC*)get_proc("glProgramUniform1uiEXT");
		glpfProgramUniform2uiEXT = (PFNGLPROGRAMUNIFORM2UIEXT_PROC*)get_proc("glProgramUniform2uiEXT");
		glpfProgramUniform3uiEXT = (PFNGLPROGRAMUNIFORM3UIEXT_PROC*)get_proc("glProgramUniform3uiEXT");
		glpfProgramUniform4uiEXT = (PFNGLPROGRAMUNIFORM4UIEXT_PROC*)get_proc("glProgramUniform4uiEXT");
		glpfProgramUniform1uivEXT = (PFNGLPROGRAMUNIFORM1UIVEXT_PROC*)get_proc("glProgramUniform1uivEXT");
		glpfProgramUniform2uivEXT = (PFNGLPROGRAMUNIFORM2UIVEXT_PROC*)get_proc("glProgramUniform2uivEXT");
		glpfProgramUniform3uivEXT = (PFNGLPROGRAMUNIFORM3UIVEXT_PROC*)get_proc("glProgramUniform3uivEXT");
		glpfProgramUniform4uivEXT = (PFNGLPROGRAMUNIFORM4UIVEXT_PROC*)get_proc("glProgramUniform4uivEXT");
		glpfNamedProgramLocalParameters4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXT_PROC*)get_proc("glNamedProgramLocalParameters4fvEXT");
		glpfNamedProgramLocalParameterI4iEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXT_PROC*)get_proc("glNamedProgramLocalParameterI4iEXT");
		glpfNamedProgramLocalParameterI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXT_PROC*)get_proc("glNamedProgramLocalParameterI4ivEXT");
		glpfNamedProgramLocalParametersI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT_PROC*)get_proc("glNamedProgramLocalParametersI4ivEXT");
		glpfNamedProgramLocalParameterI4uiEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXT_PROC*)get_proc("glNamedProgramLocalParameterI4uiEXT");
		glpfNamedProgramLocalParameterI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT_PROC*)get_proc("glNamedProgramLocalParameterI4uivEXT");
		glpfNamedProgramLocalParametersI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT_PROC*)get_proc("glNamedProgramLocalParametersI4uivEXT");
		glpfGetNamedProgramLocalParameterIivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT_PROC*)get_proc("glGetNamedProgramLocalParameterIivEXT");
		glpfGetNamedProgramLocalParameterIuivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT_PROC*)get_proc("glGetNamedProgramLocalParameterIuivEXT");
		glpfEnableClientStateiEXT = (PFNGLENABLECLIENTSTATEIEXT_PROC*)get_proc("glEnableClientStateiEXT");
		glpfDisableClientStateiEXT = (PFNGLDISABLECLIENTSTATEIEXT_PROC*)get_proc("glDisableClientStateiEXT");
		glpfGetFloati_vEXT = (PFNGLGETFLOATI_VEXT_PROC*)get_proc("glGetFloati_vEXT");
		glpfGetDoublei_vEXT = (PFNGLGETDOUBLEI_VEXT_PROC*)get_proc("glGetDoublei_vEXT");
		glpfGetPointeri_vEXT = (PFNGLGETPOINTERI_VEXT_PROC*)get_proc("glGetPointeri_vEXT");
		glpfNamedProgramStringEXT = (PFNGLNAMEDPROGRAMSTRINGEXT_PROC*)get_proc("glNamedProgramStringEXT");
		glpfNamedProgramLocalParameter4dEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXT_PROC*)get_proc("glNamedProgramLocalParameter4dEXT");
		glpfNamedProgramLocalParameter4dvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXT_PROC*)get_proc("glNamedProgramLocalParameter4dvEXT");
		glpfNamedProgramLocalParameter4fEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXT_PROC*)get_proc("glNamedProgramLocalParameter4fEXT");
		glpfNamedProgramLocalParameter4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXT_PROC*)get_proc("glNamedProgramLocalParameter4fvEXT");
		glpfGetNamedProgramLocalParameterdvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXT_PROC*)get_proc("glGetNamedProgramLocalParameterdvEXT");
		glpfGetNamedProgramLocalParameterfvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXT_PROC*)get_proc("glGetNamedProgramLocalParameterfvEXT");
		glpfGetNamedProgramivEXT = (PFNGLGETNAMEDPROGRAMIVEXT_PROC*)get_proc("glGetNamedProgramivEXT");
		glpfGetNamedProgramStringEXT = (PFNGLGETNAMEDPROGRAMSTRINGEXT_PROC*)get_proc("glGetNamedProgramStringEXT");
		glpfNamedRenderbufferStorageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEEXT_PROC*)get_proc("glNamedRenderbufferStorageEXT");
		glpfGetNamedRenderbufferParameterivEXT = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXT_PROC*)get_proc("glGetNamedRenderbufferParameterivEXT");
		glpfNamedRenderbufferStorageMultisampleEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT_PROC*)get_proc("glNamedRenderbufferStorageMultisampleEXT");
		glpfNamedRenderbufferStorageMultisampleCoverageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT_PROC*)get_proc("glNamedRenderbufferStorageMultisampleCoverageEXT");
		glpfCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXT_PROC*)get_proc("glCheckNamedFramebufferStatusEXT");
		glpfNamedFramebufferTexture1DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXT_PROC*)get_proc("glNamedFramebufferTexture1DEXT");
		glpfNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXT_PROC*)get_proc("glNamedFramebufferTexture2DEXT");
		glpfNamedFramebufferTexture3DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXT_PROC*)get_proc("glNamedFramebufferTexture3DEXT");
		glpfNamedFramebufferRenderbufferEXT = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXT_PROC*)get_proc("glNamedFramebufferRenderbufferEXT");
		glpfGetNamedFramebufferAttachmentParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT_PROC*)get_proc("glGetNamedFramebufferAttachmentParameterivEXT");
		glpfGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXT_PROC*)get_proc("glGenerateTextureMipmapEXT");
		glpfGenerateMultiTexMipmapEXT = (PFNGLGENERATEMULTITEXMIPMAPEXT_PROC*)get_proc("glGenerateMultiTexMipmapEXT");
		glpfFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXT_PROC*)get_proc("glFramebufferDrawBufferEXT");
		glpfFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXT_PROC*)get_proc("glFramebufferDrawBuffersEXT");
		glpfFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXT_PROC*)get_proc("glFramebufferReadBufferEXT");
		glpfGetFramebufferParameterivEXT = (PFNGLGETFRAMEBUFFERPARAMETERIVEXT_PROC*)get_proc("glGetFramebufferParameterivEXT");
		glpfNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXT_PROC*)get_proc("glNamedCopyBufferSubDataEXT");
		glpfNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXT_PROC*)get_proc("glNamedFramebufferTextureEXT");
		glpfNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXT_PROC*)get_proc("glNamedFramebufferTextureLayerEXT");
		glpfNamedFramebufferTextureFaceEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXT_PROC*)get_proc("glNamedFramebufferTextureFaceEXT");
		glpfTextureRenderbufferEXT = (PFNGLTEXTURERENDERBUFFEREXT_PROC*)get_proc("glTextureRenderbufferEXT");
		glpfMultiTexRenderbufferEXT = (PFNGLMULTITEXRENDERBUFFEREXT_PROC*)get_proc("glMultiTexRenderbufferEXT");
		glpfVertexArrayVertexOffsetEXT = (PFNGLVERTEXARRAYVERTEXOFFSETEXT_PROC*)get_proc("glVertexArrayVertexOffsetEXT");
		glpfVertexArrayColorOffsetEXT = (PFNGLVERTEXARRAYCOLOROFFSETEXT_PROC*)get_proc("glVertexArrayColorOffsetEXT");
		glpfVertexArrayEdgeFlagOffsetEXT = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXT_PROC*)get_proc("glVertexArrayEdgeFlagOffsetEXT");
		glpfVertexArrayIndexOffsetEXT = (PFNGLVERTEXARRAYINDEXOFFSETEXT_PROC*)get_proc("glVertexArrayIndexOffsetEXT");
		glpfVertexArrayNormalOffsetEXT = (PFNGLVERTEXARRAYNORMALOFFSETEXT_PROC*)get_proc("glVertexArrayNormalOffsetEXT");
		glpfVertexArrayTexCoordOffsetEXT = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXT_PROC*)get_proc("glVertexArrayTexCoordOffsetEXT");
		glpfVertexArrayMultiTexCoordOffsetEXT = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXT_PROC*)get_proc("glVertexArrayMultiTexCoordOffsetEXT");
		glpfVertexArrayFogCoordOffsetEXT = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXT_PROC*)get_proc("glVertexArrayFogCoordOffsetEXT");
		glpfVertexArraySecondaryColorOffsetEXT = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXT_PROC*)get_proc("glVertexArraySecondaryColorOffsetEXT");
		glpfVertexArrayVertexAttribOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXT_PROC*)get_proc("glVertexArrayVertexAttribOffsetEXT");
		glpfVertexArrayVertexAttribIOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXT_PROC*)get_proc("glVertexArrayVertexAttribIOffsetEXT");
		glpfEnableVertexArrayEXT = (PFNGLENABLEVERTEXARRAYEXT_PROC*)get_proc("glEnableVertexArrayEXT");
		glpfDisableVertexArrayEXT = (PFNGLDISABLEVERTEXARRAYEXT_PROC*)get_proc("glDisableVertexArrayEXT");
		glpfEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXT_PROC*)get_proc("glEnableVertexArrayAttribEXT");
		glpfDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXT_PROC*)get_proc("glDisableVertexArrayAttribEXT");
		glpfGetVertexArrayIntegervEXT = (PFNGLGETVERTEXARRAYINTEGERVEXT_PROC*)get_proc("glGetVertexArrayIntegervEXT");
		glpfGetVertexArrayPointervEXT = (PFNGLGETVERTEXARRAYPOINTERVEXT_PROC*)get_proc("glGetVertexArrayPointervEXT");
		glpfGetVertexArrayIntegeri_vEXT = (PFNGLGETVERTEXARRAYINTEGERI_VEXT_PROC*)get_proc("glGetVertexArrayIntegeri_vEXT");
		glpfGetVertexArrayPointeri_vEXT = (PFNGLGETVERTEXARRAYPOINTERI_VEXT_PROC*)get_proc("glGetVertexArrayPointeri_vEXT");
		glpfMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXT_PROC*)get_proc("glMapNamedBufferRangeEXT");
		glpfFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXT_PROC*)get_proc("glFlushMappedNamedBufferRangeEXT");
		glpfNamedBufferStorageEXT = (PFNGLNAMEDBUFFERSTORAGEEXT_PROC*)get_proc("glNamedBufferStorageEXT");
		glpfClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXT_PROC*)get_proc("glClearNamedBufferDataEXT");
		glpfClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXT_PROC*)get_proc("glClearNamedBufferSubDataEXT");
		glpfNamedFramebufferParameteriEXT = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXT_PROC*)get_proc("glNamedFramebufferParameteriEXT");
		glpfGetNamedFramebufferParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXT_PROC*)get_proc("glGetNamedFramebufferParameterivEXT");
		glpfProgramUniform1dEXT = (PFNGLPROGRAMUNIFORM1DEXT_PROC*)get_proc("glProgramUniform1dEXT");
		glpfProgramUniform2dEXT = (PFNGLPROGRAMUNIFORM2DEXT_PROC*)get_proc("glProgramUniform2dEXT");
		glpfProgramUniform3dEXT = (PFNGLPROGRAMUNIFORM3DEXT_PROC*)get_proc("glProgramUniform3dEXT");
		glpfProgramUniform4dEXT = (PFNGLPROGRAMUNIFORM4DEXT_PROC*)get_proc("glProgramUniform4dEXT");
		glpfProgramUniform1dvEXT = (PFNGLPROGRAMUNIFORM1DVEXT_PROC*)get_proc("glProgramUniform1dvEXT");
		glpfProgramUniform2dvEXT = (PFNGLPROGRAMUNIFORM2DVEXT_PROC*)get_proc("glProgramUniform2dvEXT");
		glpfProgramUniform3dvEXT = (PFNGLPROGRAMUNIFORM3DVEXT_PROC*)get_proc("glProgramUniform3dvEXT");
		glpfProgramUniform4dvEXT = (PFNGLPROGRAMUNIFORM4DVEXT_PROC*)get_proc("glProgramUniform4dvEXT");
		glpfProgramUniformMatrix2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2DVEXT_PROC*)get_proc("glProgramUniformMatrix2dvEXT");
		glpfProgramUniformMatrix3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3DVEXT_PROC*)get_proc("glProgramUniformMatrix3dvEXT");
		glpfProgramUniformMatrix4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4DVEXT_PROC*)get_proc("glProgramUniformMatrix4dvEXT");
		glpfProgramUniformMatrix2x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXT_PROC*)get_proc("glProgramUniformMatrix2x3dvEXT");
		glpfProgramUniformMatrix2x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXT_PROC*)get_proc("glProgramUniformMatrix2x4dvEXT");
		glpfProgramUniformMatrix3x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXT_PROC*)get_proc("glProgramUniformMatrix3x2dvEXT");
		glpfProgramUniformMatrix3x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXT_PROC*)get_proc("glProgramUniformMatrix3x4dvEXT");
		glpfProgramUniformMatrix4x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXT_PROC*)get_proc("glProgramUniformMatrix4x2dvEXT");
		glpfProgramUniformMatrix4x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXT_PROC*)get_proc("glProgramUniformMatrix4x3dvEXT");
		glpfTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXT_PROC*)get_proc("glTextureBufferRangeEXT");
		glpfTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXT_PROC*)get_proc("glTextureStorage1DEXT");
		glpfTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXT_PROC*)get_proc("glTextureStorage2DEXT");
		glpfTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXT_PROC*)get_proc("glTextureStorage3DEXT");
		glpfTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXT_PROC*)get_proc("glTextureStorage2DMultisampleEXT");
		glpfTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXT_PROC*)get_proc("glTextureStorage3DMultisampleEXT");
		glpfVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXT_PROC*)get_proc("glVertexArrayBindVertexBufferEXT");
		glpfVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXT_PROC*)get_proc("glVertexArrayVertexAttribFormatEXT");
		glpfVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXT_PROC*)get_proc("glVertexArrayVertexAttribIFormatEXT");
		glpfVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXT_PROC*)get_proc("glVertexArrayVertexAttribLFormatEXT");
		glpfVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXT_PROC*)get_proc("glVertexArrayVertexAttribBindingEXT");
		glpfVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXT_PROC*)get_proc("glVertexArrayVertexBindingDivisorEXT");
		glpfVertexArrayVertexAttribLOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXT_PROC*)get_proc("glVertexArrayVertexAttribLOffsetEXT");
		glpfTexturePageCommitmentEXT = (PFNGLTEXTUREPAGECOMMITMENTEXT_PROC*)get_proc("glTexturePageCommitmentEXT");
		glpfVertexArrayVertexAttribDivisorEXT = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXT_PROC*)get_proc("glVertexArrayVertexAttribDivisorEXT");


		/* GL_EXT_texture_compression_s3tc */



		/* GL_EXT_texture_sRGB */



		/* GL_ARB_shader_draw_parameters */



		/* GL_ARB_map_buffer_alignment */



		/* GL_NV_bindless_multi_draw_indirect */

		glpfMultiDrawArraysIndirectBindlessNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNV_PROC*)get_proc("glMultiDrawArraysIndirectBindlessNV");
		glpfMultiDrawElementsIndirectBindlessNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNV_PROC*)get_proc("glMultiDrawElementsIndirectBindlessNV");


		/* GL_NVX_gpu_memory_info */



		/* GL_NV_command_list */

		glpfCreateStatesNV = (PFNGLCREATESTATESNV_PROC*)get_proc("glCreateStatesNV");
		glpfDeleteStatesNV = (PFNGLDELETESTATESNV_PROC*)get_proc("glDeleteStatesNV");
		glpfIsStateNV = (PFNGLISSTATENV_PROC*)get_proc("glIsStateNV");
		glpfStateCaptureNV = (PFNGLSTATECAPTURENV_PROC*)get_proc("glStateCaptureNV");
		glpfGetCommandHeaderNV = (PFNGLGETCOMMANDHEADERNV_PROC*)get_proc("glGetCommandHeaderNV");
		glpfGetStageIndexNV = (PFNGLGETSTAGEINDEXNV_PROC*)get_proc("glGetStageIndexNV");
		glpfDrawCommandsNV = (PFNGLDRAWCOMMANDSNV_PROC*)get_proc("glDrawCommandsNV");
		glpfDrawCommandsAddressNV = (PFNGLDRAWCOMMANDSADDRESSNV_PROC*)get_proc("glDrawCommandsAddressNV");
		glpfDrawCommandsStatesNV = (PFNGLDRAWCOMMANDSSTATESNV_PROC*)get_proc("glDrawCommandsStatesNV");
		glpfDrawCommandsStatesAddressNV = (PFNGLDRAWCOMMANDSSTATESADDRESSNV_PROC*)get_proc("glDrawCommandsStatesAddressNV");
		glpfCreateCommandListsNV = (PFNGLCREATECOMMANDLISTSNV_PROC*)get_proc("glCreateCommandListsNV");
		glpfDeleteCommandListsNV = (PFNGLDELETECOMMANDLISTSNV_PROC*)get_proc("glDeleteCommandListsNV");
		glpfIsCommandListNV = (PFNGLISCOMMANDLISTNV_PROC*)get_proc("glIsCommandListNV");
		glpfListDrawCommandsStatesClientNV = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNV_PROC*)get_proc("glListDrawCommandsStatesClientNV");
		glpfCommandListSegmentsNV = (PFNGLCOMMANDLISTSEGMENTSNV_PROC*)get_proc("glCommandListSegmentsNV");
		glpfCompileCommandListNV = (PFNGLCOMPILECOMMANDLISTNV_PROC*)get_proc("glCompileCommandListNV");
		glpfCallCommandListNV = (PFNGLCALLCOMMANDLISTNV_PROC*)get_proc("glCallCommandListNV");


		/* GL_NV_uniform_buffer_unified_memory */



		/* GL_NV_vertex_buffer_unified_memory */

		glpfBufferAddressRangeNV = (PFNGLBUFFERADDRESSRANGENV_PROC*)get_proc("glBufferAddressRangeNV");
		glpfVertexFormatNV = (PFNGLVERTEXFORMATNV_PROC*)get_proc("glVertexFormatNV");
		glpfNormalFormatNV = (PFNGLNORMALFORMATNV_PROC*)get_proc("glNormalFormatNV");
		glpfColorFormatNV = (PFNGLCOLORFORMATNV_PROC*)get_proc("glColorFormatNV");
		glpfIndexFormatNV = (PFNGLINDEXFORMATNV_PROC*)get_proc("glIndexFormatNV");
		glpfTexCoordFormatNV = (PFNGLTEXCOORDFORMATNV_PROC*)get_proc("glTexCoordFormatNV");
		glpfEdgeFlagFormatNV = (PFNGLEDGEFLAGFORMATNV_PROC*)get_proc("glEdgeFlagFormatNV");
		glpfSecondaryColorFormatNV = (PFNGLSECONDARYCOLORFORMATNV_PROC*)get_proc("glSecondaryColorFormatNV");
		glpfFogCoordFormatNV = (PFNGLFOGCOORDFORMATNV_PROC*)get_proc("glFogCoordFormatNV");
		glpfVertexAttribFormatNV = (PFNGLVERTEXATTRIBFORMATNV_PROC*)get_proc("glVertexAttribFormatNV");
		glpfVertexAttribIFormatNV = (PFNGLVERTEXATTRIBIFORMATNV_PROC*)get_proc("glVertexAttribIFormatNV");
		glpfGetIntegerui64i_vNV = (PFNGLGETINTEGERUI64I_VNV_PROC*)get_proc("glGetIntegerui64i_vNV");


		/* GL_NV_shader_buffer_load */

		glpfMakeBufferResidentNV = (PFNGLMAKEBUFFERRESIDENTNV_PROC*)get_proc("glMakeBufferResidentNV");
		glpfMakeBufferNonResidentNV = (PFNGLMAKEBUFFERNONRESIDENTNV_PROC*)get_proc("glMakeBufferNonResidentNV");
		glpfIsBufferResidentNV = (PFNGLISBUFFERRESIDENTNV_PROC*)get_proc("glIsBufferResidentNV");
		glpfMakeNamedBufferResidentNV = (PFNGLMAKENAMEDBUFFERRESIDENTNV_PROC*)get_proc("glMakeNamedBufferResidentNV");
		glpfMakeNamedBufferNonResidentNV = (PFNGLMAKENAMEDBUFFERNONRESIDENTNV_PROC*)get_proc("glMakeNamedBufferNonResidentNV");
		glpfIsNamedBufferResidentNV = (PFNGLISNAMEDBUFFERRESIDENTNV_PROC*)get_proc("glIsNamedBufferResidentNV");
		glpfGetBufferParameterui64vNV = (PFNGLGETBUFFERPARAMETERUI64VNV_PROC*)get_proc("glGetBufferParameterui64vNV");
		glpfGetNamedBufferParameterui64vNV = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNV_PROC*)get_proc("glGetNamedBufferParameterui64vNV");
		glpfGetIntegerui64vNV = (PFNGLGETINTEGERUI64VNV_PROC*)get_proc("glGetIntegerui64vNV");
		glpfUniformui64NV = (PFNGLUNIFORMUI64NV_PROC*)get_proc("glUniformui64NV");
		glpfUniformui64vNV = (PFNGLUNIFORMUI64VNV_PROC*)get_proc("glUniformui64vNV");
		glpfGetUniformui64vNV = (PFNGLGETUNIFORMUI64VNV_PROC*)get_proc("glGetUniformui64vNV");
		glpfProgramUniformui64NV = (PFNGLPROGRAMUNIFORMUI64NV_PROC*)get_proc("glProgramUniformui64NV");
		glpfProgramUniformui64vNV = (PFNGLPROGRAMUNIFORMUI64VNV_PROC*)get_proc("glProgramUniformui64vNV");


	}

	/* ----------------------- Extension flag definitions ---------------------- */
	int FLEXT_ARB_bindless_texture = GL_FALSE;
	int FLEXT_ARB_sparse_texture = GL_FALSE;
	int FLEXT_ARB_indirect_parameters = GL_FALSE;
	int FLEXT_ARB_pipeline_statistics_query = GL_FALSE;
	int FLEXT_ARB_texture_non_power_of_two = GL_FALSE;
	int FLEXT_EXT_direct_state_access = GL_FALSE;
	int FLEXT_EXT_texture_compression_s3tc = GL_FALSE;
	int FLEXT_EXT_texture_sRGB = GL_FALSE;
	int FLEXT_ARB_shader_draw_parameters = GL_FALSE;
	int FLEXT_ARB_map_buffer_alignment = GL_FALSE;
	int FLEXT_NV_bindless_multi_draw_indirect = GL_FALSE;
	int FLEXT_NVX_gpu_memory_info = GL_FALSE;
	int FLEXT_NV_command_list = GL_FALSE;
	int FLEXT_NV_uniform_buffer_unified_memory = GL_FALSE;
	int FLEXT_NV_vertex_buffer_unified_memory = GL_FALSE;
	int FLEXT_NV_shader_buffer_load = GL_FALSE;

	/* ---------------------- Function pointer definitions --------------------- */

	/* GL_VERSION_1_2 */

	PFNGLDRAWRANGEELEMENTS_PROC* glpfDrawRangeElements = NULL;
	PFNGLTEXIMAGE3D_PROC* glpfTexImage3D = NULL;
	PFNGLTEXSUBIMAGE3D_PROC* glpfTexSubImage3D = NULL;
	PFNGLCOPYTEXSUBIMAGE3D_PROC* glpfCopyTexSubImage3D = NULL;

	/* GL_VERSION_1_3 */

	PFNGLACTIVETEXTURE_PROC* glpfActiveTexture = NULL;
	PFNGLSAMPLECOVERAGE_PROC* glpfSampleCoverage = NULL;
	PFNGLCOMPRESSEDTEXIMAGE3D_PROC* glpfCompressedTexImage3D = NULL;
	PFNGLCOMPRESSEDTEXIMAGE2D_PROC* glpfCompressedTexImage2D = NULL;
	PFNGLCOMPRESSEDTEXIMAGE1D_PROC* glpfCompressedTexImage1D = NULL;
	PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC* glpfCompressedTexSubImage3D = NULL;
	PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC* glpfCompressedTexSubImage2D = NULL;
	PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC* glpfCompressedTexSubImage1D = NULL;
	PFNGLGETCOMPRESSEDTEXIMAGE_PROC* glpfGetCompressedTexImage = NULL;

	/* GL_VERSION_1_4 */

	PFNGLBLENDFUNCSEPARATE_PROC* glpfBlendFuncSeparate = NULL;
	PFNGLMULTIDRAWARRAYS_PROC* glpfMultiDrawArrays = NULL;
	PFNGLMULTIDRAWELEMENTS_PROC* glpfMultiDrawElements = NULL;
	PFNGLPOINTPARAMETERF_PROC* glpfPointParameterf = NULL;
	PFNGLPOINTPARAMETERFV_PROC* glpfPointParameterfv = NULL;
	PFNGLPOINTPARAMETERI_PROC* glpfPointParameteri = NULL;
	PFNGLPOINTPARAMETERIV_PROC* glpfPointParameteriv = NULL;
	PFNGLBLENDCOLOR_PROC* glpfBlendColor = NULL;
	PFNGLBLENDEQUATION_PROC* glpfBlendEquation = NULL;

	/* GL_VERSION_1_5 */

	PFNGLGENQUERIES_PROC* glpfGenQueries = NULL;
	PFNGLDELETEQUERIES_PROC* glpfDeleteQueries = NULL;
	PFNGLISQUERY_PROC* glpfIsQuery = NULL;
	PFNGLBEGINQUERY_PROC* glpfBeginQuery = NULL;
	PFNGLENDQUERY_PROC* glpfEndQuery = NULL;
	PFNGLGETQUERYIV_PROC* glpfGetQueryiv = NULL;
	PFNGLGETQUERYOBJECTIV_PROC* glpfGetQueryObjectiv = NULL;
	PFNGLGETQUERYOBJECTUIV_PROC* glpfGetQueryObjectuiv = NULL;
	PFNGLBINDBUFFER_PROC* glpfBindBuffer = NULL;
	PFNGLDELETEBUFFERS_PROC* glpfDeleteBuffers = NULL;
	PFNGLGENBUFFERS_PROC* glpfGenBuffers = NULL;
	PFNGLISBUFFER_PROC* glpfIsBuffer = NULL;
	PFNGLBUFFERDATA_PROC* glpfBufferData = NULL;
	PFNGLBUFFERSUBDATA_PROC* glpfBufferSubData = NULL;
	PFNGLGETBUFFERSUBDATA_PROC* glpfGetBufferSubData = NULL;
	PFNGLMAPBUFFER_PROC* glpfMapBuffer = NULL;
	PFNGLUNMAPBUFFER_PROC* glpfUnmapBuffer = NULL;
	PFNGLGETBUFFERPARAMETERIV_PROC* glpfGetBufferParameteriv = NULL;
	PFNGLGETBUFFERPOINTERV_PROC* glpfGetBufferPointerv = NULL;

	/* GL_VERSION_2_0 */

	PFNGLBLENDEQUATIONSEPARATE_PROC* glpfBlendEquationSeparate = NULL;
	PFNGLDRAWBUFFERS_PROC* glpfDrawBuffers = NULL;
	PFNGLSTENCILOPSEPARATE_PROC* glpfStencilOpSeparate = NULL;
	PFNGLSTENCILFUNCSEPARATE_PROC* glpfStencilFuncSeparate = NULL;
	PFNGLSTENCILMASKSEPARATE_PROC* glpfStencilMaskSeparate = NULL;
	PFNGLATTACHSHADER_PROC* glpfAttachShader = NULL;
	PFNGLBINDATTRIBLOCATION_PROC* glpfBindAttribLocation = NULL;
	PFNGLCOMPILESHADER_PROC* glpfCompileShader = NULL;
	PFNGLCREATEPROGRAM_PROC* glpfCreateProgram = NULL;
	PFNGLCREATESHADER_PROC* glpfCreateShader = NULL;
	PFNGLDELETEPROGRAM_PROC* glpfDeleteProgram = NULL;
	PFNGLDELETESHADER_PROC* glpfDeleteShader = NULL;
	PFNGLDETACHSHADER_PROC* glpfDetachShader = NULL;
	PFNGLDISABLEVERTEXATTRIBARRAY_PROC* glpfDisableVertexAttribArray = NULL;
	PFNGLENABLEVERTEXATTRIBARRAY_PROC* glpfEnableVertexAttribArray = NULL;
	PFNGLGETACTIVEATTRIB_PROC* glpfGetActiveAttrib = NULL;
	PFNGLGETACTIVEUNIFORM_PROC* glpfGetActiveUniform = NULL;
	PFNGLGETATTACHEDSHADERS_PROC* glpfGetAttachedShaders = NULL;
	PFNGLGETATTRIBLOCATION_PROC* glpfGetAttribLocation = NULL;
	PFNGLGETPROGRAMIV_PROC* glpfGetProgramiv = NULL;
	PFNGLGETPROGRAMINFOLOG_PROC* glpfGetProgramInfoLog = NULL;
	PFNGLGETSHADERIV_PROC* glpfGetShaderiv = NULL;
	PFNGLGETSHADERINFOLOG_PROC* glpfGetShaderInfoLog = NULL;
	PFNGLGETSHADERSOURCE_PROC* glpfGetShaderSource = NULL;
	PFNGLGETUNIFORMLOCATION_PROC* glpfGetUniformLocation = NULL;
	PFNGLGETUNIFORMFV_PROC* glpfGetUniformfv = NULL;
	PFNGLGETUNIFORMIV_PROC* glpfGetUniformiv = NULL;
	PFNGLGETVERTEXATTRIBDV_PROC* glpfGetVertexAttribdv = NULL;
	PFNGLGETVERTEXATTRIBFV_PROC* glpfGetVertexAttribfv = NULL;
	PFNGLGETVERTEXATTRIBIV_PROC* glpfGetVertexAttribiv = NULL;
	PFNGLGETVERTEXATTRIBPOINTERV_PROC* glpfGetVertexAttribPointerv = NULL;
	PFNGLISPROGRAM_PROC* glpfIsProgram = NULL;
	PFNGLISSHADER_PROC* glpfIsShader = NULL;
	PFNGLLINKPROGRAM_PROC* glpfLinkProgram = NULL;
	PFNGLSHADERSOURCE_PROC* glpfShaderSource = NULL;
	PFNGLUSEPROGRAM_PROC* glpfUseProgram = NULL;
	PFNGLUNIFORM1F_PROC* glpfUniform1f = NULL;
	PFNGLUNIFORM2F_PROC* glpfUniform2f = NULL;
	PFNGLUNIFORM3F_PROC* glpfUniform3f = NULL;
	PFNGLUNIFORM4F_PROC* glpfUniform4f = NULL;
	PFNGLUNIFORM1I_PROC* glpfUniform1i = NULL;
	PFNGLUNIFORM2I_PROC* glpfUniform2i = NULL;
	PFNGLUNIFORM3I_PROC* glpfUniform3i = NULL;
	PFNGLUNIFORM4I_PROC* glpfUniform4i = NULL;
	PFNGLUNIFORM1FV_PROC* glpfUniform1fv = NULL;
	PFNGLUNIFORM2FV_PROC* glpfUniform2fv = NULL;
	PFNGLUNIFORM3FV_PROC* glpfUniform3fv = NULL;
	PFNGLUNIFORM4FV_PROC* glpfUniform4fv = NULL;
	PFNGLUNIFORM1IV_PROC* glpfUniform1iv = NULL;
	PFNGLUNIFORM2IV_PROC* glpfUniform2iv = NULL;
	PFNGLUNIFORM3IV_PROC* glpfUniform3iv = NULL;
	PFNGLUNIFORM4IV_PROC* glpfUniform4iv = NULL;
	PFNGLUNIFORMMATRIX2FV_PROC* glpfUniformMatrix2fv = NULL;
	PFNGLUNIFORMMATRIX3FV_PROC* glpfUniformMatrix3fv = NULL;
	PFNGLUNIFORMMATRIX4FV_PROC* glpfUniformMatrix4fv = NULL;
	PFNGLVALIDATEPROGRAM_PROC* glpfValidateProgram = NULL;
	PFNGLVERTEXATTRIB1D_PROC* glpfVertexAttrib1d = NULL;
	PFNGLVERTEXATTRIB1DV_PROC* glpfVertexAttrib1dv = NULL;
	PFNGLVERTEXATTRIB1F_PROC* glpfVertexAttrib1f = NULL;
	PFNGLVERTEXATTRIB1FV_PROC* glpfVertexAttrib1fv = NULL;
	PFNGLVERTEXATTRIB1S_PROC* glpfVertexAttrib1s = NULL;
	PFNGLVERTEXATTRIB1SV_PROC* glpfVertexAttrib1sv = NULL;
	PFNGLVERTEXATTRIB2D_PROC* glpfVertexAttrib2d = NULL;
	PFNGLVERTEXATTRIB2DV_PROC* glpfVertexAttrib2dv = NULL;
	PFNGLVERTEXATTRIB2F_PROC* glpfVertexAttrib2f = NULL;
	PFNGLVERTEXATTRIB2FV_PROC* glpfVertexAttrib2fv = NULL;
	PFNGLVERTEXATTRIB2S_PROC* glpfVertexAttrib2s = NULL;
	PFNGLVERTEXATTRIB2SV_PROC* glpfVertexAttrib2sv = NULL;
	PFNGLVERTEXATTRIB3D_PROC* glpfVertexAttrib3d = NULL;
	PFNGLVERTEXATTRIB3DV_PROC* glpfVertexAttrib3dv = NULL;
	PFNGLVERTEXATTRIB3F_PROC* glpfVertexAttrib3f = NULL;
	PFNGLVERTEXATTRIB3FV_PROC* glpfVertexAttrib3fv = NULL;
	PFNGLVERTEXATTRIB3S_PROC* glpfVertexAttrib3s = NULL;
	PFNGLVERTEXATTRIB3SV_PROC* glpfVertexAttrib3sv = NULL;
	PFNGLVERTEXATTRIB4NBV_PROC* glpfVertexAttrib4Nbv = NULL;
	PFNGLVERTEXATTRIB4NIV_PROC* glpfVertexAttrib4Niv = NULL;
	PFNGLVERTEXATTRIB4NSV_PROC* glpfVertexAttrib4Nsv = NULL;
	PFNGLVERTEXATTRIB4NUB_PROC* glpfVertexAttrib4Nub = NULL;
	PFNGLVERTEXATTRIB4NUBV_PROC* glpfVertexAttrib4Nubv = NULL;
	PFNGLVERTEXATTRIB4NUIV_PROC* glpfVertexAttrib4Nuiv = NULL;
	PFNGLVERTEXATTRIB4NUSV_PROC* glpfVertexAttrib4Nusv = NULL;
	PFNGLVERTEXATTRIB4BV_PROC* glpfVertexAttrib4bv = NULL;
	PFNGLVERTEXATTRIB4D_PROC* glpfVertexAttrib4d = NULL;
	PFNGLVERTEXATTRIB4DV_PROC* glpfVertexAttrib4dv = NULL;
	PFNGLVERTEXATTRIB4F_PROC* glpfVertexAttrib4f = NULL;
	PFNGLVERTEXATTRIB4FV_PROC* glpfVertexAttrib4fv = NULL;
	PFNGLVERTEXATTRIB4IV_PROC* glpfVertexAttrib4iv = NULL;
	PFNGLVERTEXATTRIB4S_PROC* glpfVertexAttrib4s = NULL;
	PFNGLVERTEXATTRIB4SV_PROC* glpfVertexAttrib4sv = NULL;
	PFNGLVERTEXATTRIB4UBV_PROC* glpfVertexAttrib4ubv = NULL;
	PFNGLVERTEXATTRIB4UIV_PROC* glpfVertexAttrib4uiv = NULL;
	PFNGLVERTEXATTRIB4USV_PROC* glpfVertexAttrib4usv = NULL;
	PFNGLVERTEXATTRIBPOINTER_PROC* glpfVertexAttribPointer = NULL;

	/* GL_VERSION_2_1 */

	PFNGLUNIFORMMATRIX2X3FV_PROC* glpfUniformMatrix2x3fv = NULL;
	PFNGLUNIFORMMATRIX3X2FV_PROC* glpfUniformMatrix3x2fv = NULL;
	PFNGLUNIFORMMATRIX2X4FV_PROC* glpfUniformMatrix2x4fv = NULL;
	PFNGLUNIFORMMATRIX4X2FV_PROC* glpfUniformMatrix4x2fv = NULL;
	PFNGLUNIFORMMATRIX3X4FV_PROC* glpfUniformMatrix3x4fv = NULL;
	PFNGLUNIFORMMATRIX4X3FV_PROC* glpfUniformMatrix4x3fv = NULL;

	/* GL_VERSION_3_0 */

	PFNGLCOLORMASKI_PROC* glpfColorMaski = NULL;
	PFNGLGETBOOLEANI_V_PROC* glpfGetBooleani_v = NULL;
	PFNGLGETINTEGERI_V_PROC* glpfGetIntegeri_v = NULL;
	PFNGLENABLEI_PROC* glpfEnablei = NULL;
	PFNGLDISABLEI_PROC* glpfDisablei = NULL;
	PFNGLISENABLEDI_PROC* glpfIsEnabledi = NULL;
	PFNGLBEGINTRANSFORMFEEDBACK_PROC* glpfBeginTransformFeedback = NULL;
	PFNGLENDTRANSFORMFEEDBACK_PROC* glpfEndTransformFeedback = NULL;
	PFNGLBINDBUFFERRANGE_PROC* glpfBindBufferRange = NULL;
	PFNGLBINDBUFFERBASE_PROC* glpfBindBufferBase = NULL;
	PFNGLTRANSFORMFEEDBACKVARYINGS_PROC* glpfTransformFeedbackVaryings = NULL;
	PFNGLGETTRANSFORMFEEDBACKVARYING_PROC* glpfGetTransformFeedbackVarying = NULL;
	PFNGLCLAMPCOLOR_PROC* glpfClampColor = NULL;
	PFNGLBEGINCONDITIONALRENDER_PROC* glpfBeginConditionalRender = NULL;
	PFNGLENDCONDITIONALRENDER_PROC* glpfEndConditionalRender = NULL;
	PFNGLVERTEXATTRIBIPOINTER_PROC* glpfVertexAttribIPointer = NULL;
	PFNGLGETVERTEXATTRIBIIV_PROC* glpfGetVertexAttribIiv = NULL;
	PFNGLGETVERTEXATTRIBIUIV_PROC* glpfGetVertexAttribIuiv = NULL;
	PFNGLVERTEXATTRIBI1I_PROC* glpfVertexAttribI1i = NULL;
	PFNGLVERTEXATTRIBI2I_PROC* glpfVertexAttribI2i = NULL;
	PFNGLVERTEXATTRIBI3I_PROC* glpfVertexAttribI3i = NULL;
	PFNGLVERTEXATTRIBI4I_PROC* glpfVertexAttribI4i = NULL;
	PFNGLVERTEXATTRIBI1UI_PROC* glpfVertexAttribI1ui = NULL;
	PFNGLVERTEXATTRIBI2UI_PROC* glpfVertexAttribI2ui = NULL;
	PFNGLVERTEXATTRIBI3UI_PROC* glpfVertexAttribI3ui = NULL;
	PFNGLVERTEXATTRIBI4UI_PROC* glpfVertexAttribI4ui = NULL;
	PFNGLVERTEXATTRIBI1IV_PROC* glpfVertexAttribI1iv = NULL;
	PFNGLVERTEXATTRIBI2IV_PROC* glpfVertexAttribI2iv = NULL;
	PFNGLVERTEXATTRIBI3IV_PROC* glpfVertexAttribI3iv = NULL;
	PFNGLVERTEXATTRIBI4IV_PROC* glpfVertexAttribI4iv = NULL;
	PFNGLVERTEXATTRIBI1UIV_PROC* glpfVertexAttribI1uiv = NULL;
	PFNGLVERTEXATTRIBI2UIV_PROC* glpfVertexAttribI2uiv = NULL;
	PFNGLVERTEXATTRIBI3UIV_PROC* glpfVertexAttribI3uiv = NULL;
	PFNGLVERTEXATTRIBI4UIV_PROC* glpfVertexAttribI4uiv = NULL;
	PFNGLVERTEXATTRIBI4BV_PROC* glpfVertexAttribI4bv = NULL;
	PFNGLVERTEXATTRIBI4SV_PROC* glpfVertexAttribI4sv = NULL;
	PFNGLVERTEXATTRIBI4UBV_PROC* glpfVertexAttribI4ubv = NULL;
	PFNGLVERTEXATTRIBI4USV_PROC* glpfVertexAttribI4usv = NULL;
	PFNGLGETUNIFORMUIV_PROC* glpfGetUniformuiv = NULL;
	PFNGLBINDFRAGDATALOCATION_PROC* glpfBindFragDataLocation = NULL;
	PFNGLGETFRAGDATALOCATION_PROC* glpfGetFragDataLocation = NULL;
	PFNGLUNIFORM1UI_PROC* glpfUniform1ui = NULL;
	PFNGLUNIFORM2UI_PROC* glpfUniform2ui = NULL;
	PFNGLUNIFORM3UI_PROC* glpfUniform3ui = NULL;
	PFNGLUNIFORM4UI_PROC* glpfUniform4ui = NULL;
	PFNGLUNIFORM1UIV_PROC* glpfUniform1uiv = NULL;
	PFNGLUNIFORM2UIV_PROC* glpfUniform2uiv = NULL;
	PFNGLUNIFORM3UIV_PROC* glpfUniform3uiv = NULL;
	PFNGLUNIFORM4UIV_PROC* glpfUniform4uiv = NULL;
	PFNGLTEXPARAMETERIIV_PROC* glpfTexParameterIiv = NULL;
	PFNGLTEXPARAMETERIUIV_PROC* glpfTexParameterIuiv = NULL;
	PFNGLGETTEXPARAMETERIIV_PROC* glpfGetTexParameterIiv = NULL;
	PFNGLGETTEXPARAMETERIUIV_PROC* glpfGetTexParameterIuiv = NULL;
	PFNGLCLEARBUFFERIV_PROC* glpfClearBufferiv = NULL;
	PFNGLCLEARBUFFERUIV_PROC* glpfClearBufferuiv = NULL;
	PFNGLCLEARBUFFERFV_PROC* glpfClearBufferfv = NULL;
	PFNGLCLEARBUFFERFI_PROC* glpfClearBufferfi = NULL;
	PFNGLGETSTRINGI_PROC* glpfGetStringi = NULL;
	PFNGLISRENDERBUFFER_PROC* glpfIsRenderbuffer = NULL;
	PFNGLBINDRENDERBUFFER_PROC* glpfBindRenderbuffer = NULL;
	PFNGLDELETERENDERBUFFERS_PROC* glpfDeleteRenderbuffers = NULL;
	PFNGLGENRENDERBUFFERS_PROC* glpfGenRenderbuffers = NULL;
	PFNGLRENDERBUFFERSTORAGE_PROC* glpfRenderbufferStorage = NULL;
	PFNGLGETRENDERBUFFERPARAMETERIV_PROC* glpfGetRenderbufferParameteriv = NULL;
	PFNGLISFRAMEBUFFER_PROC* glpfIsFramebuffer = NULL;
	PFNGLBINDFRAMEBUFFER_PROC* glpfBindFramebuffer = NULL;
	PFNGLDELETEFRAMEBUFFERS_PROC* glpfDeleteFramebuffers = NULL;
	PFNGLGENFRAMEBUFFERS_PROC* glpfGenFramebuffers = NULL;
	PFNGLCHECKFRAMEBUFFERSTATUS_PROC* glpfCheckFramebufferStatus = NULL;
	PFNGLFRAMEBUFFERTEXTURE1D_PROC* glpfFramebufferTexture1D = NULL;
	PFNGLFRAMEBUFFERTEXTURE2D_PROC* glpfFramebufferTexture2D = NULL;
	PFNGLFRAMEBUFFERTEXTURE3D_PROC* glpfFramebufferTexture3D = NULL;
	PFNGLFRAMEBUFFERRENDERBUFFER_PROC* glpfFramebufferRenderbuffer = NULL;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC* glpfGetFramebufferAttachmentParameteriv = NULL;
	PFNGLGENERATEMIPMAP_PROC* glpfGenerateMipmap = NULL;
	PFNGLBLITFRAMEBUFFER_PROC* glpfBlitFramebuffer = NULL;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC* glpfRenderbufferStorageMultisample = NULL;
	PFNGLFRAMEBUFFERTEXTURELAYER_PROC* glpfFramebufferTextureLayer = NULL;
	PFNGLMAPBUFFERRANGE_PROC* glpfMapBufferRange = NULL;
	PFNGLFLUSHMAPPEDBUFFERRANGE_PROC* glpfFlushMappedBufferRange = NULL;
	PFNGLBINDVERTEXARRAY_PROC* glpfBindVertexArray = NULL;
	PFNGLDELETEVERTEXARRAYS_PROC* glpfDeleteVertexArrays = NULL;
	PFNGLGENVERTEXARRAYS_PROC* glpfGenVertexArrays = NULL;
	PFNGLISVERTEXARRAY_PROC* glpfIsVertexArray = NULL;

	/* GL_VERSION_3_1 */

	PFNGLDRAWARRAYSINSTANCED_PROC* glpfDrawArraysInstanced = NULL;
	PFNGLDRAWELEMENTSINSTANCED_PROC* glpfDrawElementsInstanced = NULL;
	PFNGLTEXBUFFER_PROC* glpfTexBuffer = NULL;
	PFNGLPRIMITIVERESTARTINDEX_PROC* glpfPrimitiveRestartIndex = NULL;
	PFNGLCOPYBUFFERSUBDATA_PROC* glpfCopyBufferSubData = NULL;
	PFNGLGETUNIFORMINDICES_PROC* glpfGetUniformIndices = NULL;
	PFNGLGETACTIVEUNIFORMSIV_PROC* glpfGetActiveUniformsiv = NULL;
	PFNGLGETACTIVEUNIFORMNAME_PROC* glpfGetActiveUniformName = NULL;
	PFNGLGETUNIFORMBLOCKINDEX_PROC* glpfGetUniformBlockIndex = NULL;
	PFNGLGETACTIVEUNIFORMBLOCKIV_PROC* glpfGetActiveUniformBlockiv = NULL;
	PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC* glpfGetActiveUniformBlockName = NULL;
	PFNGLUNIFORMBLOCKBINDING_PROC* glpfUniformBlockBinding = NULL;

	/* GL_VERSION_3_2 */

	PFNGLDRAWELEMENTSBASEVERTEX_PROC* glpfDrawElementsBaseVertex = NULL;
	PFNGLDRAWRANGEELEMENTSBASEVERTEX_PROC* glpfDrawRangeElementsBaseVertex = NULL;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX_PROC* glpfDrawElementsInstancedBaseVertex = NULL;
	PFNGLMULTIDRAWELEMENTSBASEVERTEX_PROC* glpfMultiDrawElementsBaseVertex = NULL;
	PFNGLPROVOKINGVERTEX_PROC* glpfProvokingVertex = NULL;
	PFNGLFENCESYNC_PROC* glpfFenceSync = NULL;
	PFNGLISSYNC_PROC* glpfIsSync = NULL;
	PFNGLDELETESYNC_PROC* glpfDeleteSync = NULL;
	PFNGLCLIENTWAITSYNC_PROC* glpfClientWaitSync = NULL;
	PFNGLWAITSYNC_PROC* glpfWaitSync = NULL;
	PFNGLGETINTEGER64V_PROC* glpfGetInteger64v = NULL;
	PFNGLGETSYNCIV_PROC* glpfGetSynciv = NULL;
	PFNGLGETINTEGER64I_V_PROC* glpfGetInteger64i_v = NULL;
	PFNGLGETBUFFERPARAMETERI64V_PROC* glpfGetBufferParameteri64v = NULL;
	PFNGLFRAMEBUFFERTEXTURE_PROC* glpfFramebufferTexture = NULL;
	PFNGLTEXIMAGE2DMULTISAMPLE_PROC* glpfTexImage2DMultisample = NULL;
	PFNGLTEXIMAGE3DMULTISAMPLE_PROC* glpfTexImage3DMultisample = NULL;
	PFNGLGETMULTISAMPLEFV_PROC* glpfGetMultisamplefv = NULL;
	PFNGLSAMPLEMASKI_PROC* glpfSampleMaski = NULL;

	/* GL_VERSION_3_3 */

	PFNGLBINDFRAGDATALOCATIONINDEXED_PROC* glpfBindFragDataLocationIndexed = NULL;
	PFNGLGETFRAGDATAINDEX_PROC* glpfGetFragDataIndex = NULL;
	PFNGLGENSAMPLERS_PROC* glpfGenSamplers = NULL;
	PFNGLDELETESAMPLERS_PROC* glpfDeleteSamplers = NULL;
	PFNGLISSAMPLER_PROC* glpfIsSampler = NULL;
	PFNGLBINDSAMPLER_PROC* glpfBindSampler = NULL;
	PFNGLSAMPLERPARAMETERI_PROC* glpfSamplerParameteri = NULL;
	PFNGLSAMPLERPARAMETERIV_PROC* glpfSamplerParameteriv = NULL;
	PFNGLSAMPLERPARAMETERF_PROC* glpfSamplerParameterf = NULL;
	PFNGLSAMPLERPARAMETERFV_PROC* glpfSamplerParameterfv = NULL;
	PFNGLSAMPLERPARAMETERIIV_PROC* glpfSamplerParameterIiv = NULL;
	PFNGLSAMPLERPARAMETERIUIV_PROC* glpfSamplerParameterIuiv = NULL;
	PFNGLGETSAMPLERPARAMETERIV_PROC* glpfGetSamplerParameteriv = NULL;
	PFNGLGETSAMPLERPARAMETERIIV_PROC* glpfGetSamplerParameterIiv = NULL;
	PFNGLGETSAMPLERPARAMETERFV_PROC* glpfGetSamplerParameterfv = NULL;
	PFNGLGETSAMPLERPARAMETERIUIV_PROC* glpfGetSamplerParameterIuiv = NULL;
	PFNGLQUERYCOUNTER_PROC* glpfQueryCounter = NULL;
	PFNGLGETQUERYOBJECTI64V_PROC* glpfGetQueryObjecti64v = NULL;
	PFNGLGETQUERYOBJECTUI64V_PROC* glpfGetQueryObjectui64v = NULL;
	PFNGLVERTEXATTRIBDIVISOR_PROC* glpfVertexAttribDivisor = NULL;
	PFNGLVERTEXATTRIBP1UI_PROC* glpfVertexAttribP1ui = NULL;
	PFNGLVERTEXATTRIBP1UIV_PROC* glpfVertexAttribP1uiv = NULL;
	PFNGLVERTEXATTRIBP2UI_PROC* glpfVertexAttribP2ui = NULL;
	PFNGLVERTEXATTRIBP2UIV_PROC* glpfVertexAttribP2uiv = NULL;
	PFNGLVERTEXATTRIBP3UI_PROC* glpfVertexAttribP3ui = NULL;
	PFNGLVERTEXATTRIBP3UIV_PROC* glpfVertexAttribP3uiv = NULL;
	PFNGLVERTEXATTRIBP4UI_PROC* glpfVertexAttribP4ui = NULL;
	PFNGLVERTEXATTRIBP4UIV_PROC* glpfVertexAttribP4uiv = NULL;

	/* GL_VERSION_4_0 */

	PFNGLMINSAMPLESHADING_PROC* glpfMinSampleShading = NULL;
	PFNGLBLENDEQUATIONI_PROC* glpfBlendEquationi = NULL;
	PFNGLBLENDEQUATIONSEPARATEI_PROC* glpfBlendEquationSeparatei = NULL;
	PFNGLBLENDFUNCI_PROC* glpfBlendFunci = NULL;
	PFNGLBLENDFUNCSEPARATEI_PROC* glpfBlendFuncSeparatei = NULL;
	PFNGLDRAWARRAYSINDIRECT_PROC* glpfDrawArraysIndirect = NULL;
	PFNGLDRAWELEMENTSINDIRECT_PROC* glpfDrawElementsIndirect = NULL;
	PFNGLUNIFORM1D_PROC* glpfUniform1d = NULL;
	PFNGLUNIFORM2D_PROC* glpfUniform2d = NULL;
	PFNGLUNIFORM3D_PROC* glpfUniform3d = NULL;
	PFNGLUNIFORM4D_PROC* glpfUniform4d = NULL;
	PFNGLUNIFORM1DV_PROC* glpfUniform1dv = NULL;
	PFNGLUNIFORM2DV_PROC* glpfUniform2dv = NULL;
	PFNGLUNIFORM3DV_PROC* glpfUniform3dv = NULL;
	PFNGLUNIFORM4DV_PROC* glpfUniform4dv = NULL;
	PFNGLUNIFORMMATRIX2DV_PROC* glpfUniformMatrix2dv = NULL;
	PFNGLUNIFORMMATRIX3DV_PROC* glpfUniformMatrix3dv = NULL;
	PFNGLUNIFORMMATRIX4DV_PROC* glpfUniformMatrix4dv = NULL;
	PFNGLUNIFORMMATRIX2X3DV_PROC* glpfUniformMatrix2x3dv = NULL;
	PFNGLUNIFORMMATRIX2X4DV_PROC* glpfUniformMatrix2x4dv = NULL;
	PFNGLUNIFORMMATRIX3X2DV_PROC* glpfUniformMatrix3x2dv = NULL;
	PFNGLUNIFORMMATRIX3X4DV_PROC* glpfUniformMatrix3x4dv = NULL;
	PFNGLUNIFORMMATRIX4X2DV_PROC* glpfUniformMatrix4x2dv = NULL;
	PFNGLUNIFORMMATRIX4X3DV_PROC* glpfUniformMatrix4x3dv = NULL;
	PFNGLGETUNIFORMDV_PROC* glpfGetUniformdv = NULL;
	PFNGLGETSUBROUTINEUNIFORMLOCATION_PROC* glpfGetSubroutineUniformLocation = NULL;
	PFNGLGETSUBROUTINEINDEX_PROC* glpfGetSubroutineIndex = NULL;
	PFNGLGETACTIVESUBROUTINEUNIFORMIV_PROC* glpfGetActiveSubroutineUniformiv = NULL;
	PFNGLGETACTIVESUBROUTINEUNIFORMNAME_PROC* glpfGetActiveSubroutineUniformName = NULL;
	PFNGLGETACTIVESUBROUTINENAME_PROC* glpfGetActiveSubroutineName = NULL;
	PFNGLUNIFORMSUBROUTINESUIV_PROC* glpfUniformSubroutinesuiv = NULL;
	PFNGLGETUNIFORMSUBROUTINEUIV_PROC* glpfGetUniformSubroutineuiv = NULL;
	PFNGLGETPROGRAMSTAGEIV_PROC* glpfGetProgramStageiv = NULL;
	PFNGLPATCHPARAMETERI_PROC* glpfPatchParameteri = NULL;
	PFNGLPATCHPARAMETERFV_PROC* glpfPatchParameterfv = NULL;
	PFNGLBINDTRANSFORMFEEDBACK_PROC* glpfBindTransformFeedback = NULL;
	PFNGLDELETETRANSFORMFEEDBACKS_PROC* glpfDeleteTransformFeedbacks = NULL;
	PFNGLGENTRANSFORMFEEDBACKS_PROC* glpfGenTransformFeedbacks = NULL;
	PFNGLISTRANSFORMFEEDBACK_PROC* glpfIsTransformFeedback = NULL;
	PFNGLPAUSETRANSFORMFEEDBACK_PROC* glpfPauseTransformFeedback = NULL;
	PFNGLRESUMETRANSFORMFEEDBACK_PROC* glpfResumeTransformFeedback = NULL;
	PFNGLDRAWTRANSFORMFEEDBACK_PROC* glpfDrawTransformFeedback = NULL;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAM_PROC* glpfDrawTransformFeedbackStream = NULL;
	PFNGLBEGINQUERYINDEXED_PROC* glpfBeginQueryIndexed = NULL;
	PFNGLENDQUERYINDEXED_PROC* glpfEndQueryIndexed = NULL;
	PFNGLGETQUERYINDEXEDIV_PROC* glpfGetQueryIndexediv = NULL;

	/* GL_VERSION_4_1 */

	PFNGLRELEASESHADERCOMPILER_PROC* glpfReleaseShaderCompiler = NULL;
	PFNGLSHADERBINARY_PROC* glpfShaderBinary = NULL;
	PFNGLGETSHADERPRECISIONFORMAT_PROC* glpfGetShaderPrecisionFormat = NULL;
	PFNGLDEPTHRANGEF_PROC* glpfDepthRangef = NULL;
	PFNGLCLEARDEPTHF_PROC* glpfClearDepthf = NULL;
	PFNGLGETPROGRAMBINARY_PROC* glpfGetProgramBinary = NULL;
	PFNGLPROGRAMBINARY_PROC* glpfProgramBinary = NULL;
	PFNGLPROGRAMPARAMETERI_PROC* glpfProgramParameteri = NULL;
	PFNGLUSEPROGRAMSTAGES_PROC* glpfUseProgramStages = NULL;
	PFNGLACTIVESHADERPROGRAM_PROC* glpfActiveShaderProgram = NULL;
	PFNGLCREATESHADERPROGRAMV_PROC* glpfCreateShaderProgramv = NULL;
	PFNGLBINDPROGRAMPIPELINE_PROC* glpfBindProgramPipeline = NULL;
	PFNGLDELETEPROGRAMPIPELINES_PROC* glpfDeleteProgramPipelines = NULL;
	PFNGLGENPROGRAMPIPELINES_PROC* glpfGenProgramPipelines = NULL;
	PFNGLISPROGRAMPIPELINE_PROC* glpfIsProgramPipeline = NULL;
	PFNGLGETPROGRAMPIPELINEIV_PROC* glpfGetProgramPipelineiv = NULL;
	PFNGLPROGRAMUNIFORM1I_PROC* glpfProgramUniform1i = NULL;
	PFNGLPROGRAMUNIFORM1IV_PROC* glpfProgramUniform1iv = NULL;
	PFNGLPROGRAMUNIFORM1F_PROC* glpfProgramUniform1f = NULL;
	PFNGLPROGRAMUNIFORM1FV_PROC* glpfProgramUniform1fv = NULL;
	PFNGLPROGRAMUNIFORM1D_PROC* glpfProgramUniform1d = NULL;
	PFNGLPROGRAMUNIFORM1DV_PROC* glpfProgramUniform1dv = NULL;
	PFNGLPROGRAMUNIFORM1UI_PROC* glpfProgramUniform1ui = NULL;
	PFNGLPROGRAMUNIFORM1UIV_PROC* glpfProgramUniform1uiv = NULL;
	PFNGLPROGRAMUNIFORM2I_PROC* glpfProgramUniform2i = NULL;
	PFNGLPROGRAMUNIFORM2IV_PROC* glpfProgramUniform2iv = NULL;
	PFNGLPROGRAMUNIFORM2F_PROC* glpfProgramUniform2f = NULL;
	PFNGLPROGRAMUNIFORM2FV_PROC* glpfProgramUniform2fv = NULL;
	PFNGLPROGRAMUNIFORM2D_PROC* glpfProgramUniform2d = NULL;
	PFNGLPROGRAMUNIFORM2DV_PROC* glpfProgramUniform2dv = NULL;
	PFNGLPROGRAMUNIFORM2UI_PROC* glpfProgramUniform2ui = NULL;
	PFNGLPROGRAMUNIFORM2UIV_PROC* glpfProgramUniform2uiv = NULL;
	PFNGLPROGRAMUNIFORM3I_PROC* glpfProgramUniform3i = NULL;
	PFNGLPROGRAMUNIFORM3IV_PROC* glpfProgramUniform3iv = NULL;
	PFNGLPROGRAMUNIFORM3F_PROC* glpfProgramUniform3f = NULL;
	PFNGLPROGRAMUNIFORM3FV_PROC* glpfProgramUniform3fv = NULL;
	PFNGLPROGRAMUNIFORM3D_PROC* glpfProgramUniform3d = NULL;
	PFNGLPROGRAMUNIFORM3DV_PROC* glpfProgramUniform3dv = NULL;
	PFNGLPROGRAMUNIFORM3UI_PROC* glpfProgramUniform3ui = NULL;
	PFNGLPROGRAMUNIFORM3UIV_PROC* glpfProgramUniform3uiv = NULL;
	PFNGLPROGRAMUNIFORM4I_PROC* glpfProgramUniform4i = NULL;
	PFNGLPROGRAMUNIFORM4IV_PROC* glpfProgramUniform4iv = NULL;
	PFNGLPROGRAMUNIFORM4F_PROC* glpfProgramUniform4f = NULL;
	PFNGLPROGRAMUNIFORM4FV_PROC* glpfProgramUniform4fv = NULL;
	PFNGLPROGRAMUNIFORM4D_PROC* glpfProgramUniform4d = NULL;
	PFNGLPROGRAMUNIFORM4DV_PROC* glpfProgramUniform4dv = NULL;
	PFNGLPROGRAMUNIFORM4UI_PROC* glpfProgramUniform4ui = NULL;
	PFNGLPROGRAMUNIFORM4UIV_PROC* glpfProgramUniform4uiv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2FV_PROC* glpfProgramUniformMatrix2fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3FV_PROC* glpfProgramUniformMatrix3fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4FV_PROC* glpfProgramUniformMatrix4fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2DV_PROC* glpfProgramUniformMatrix2dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3DV_PROC* glpfProgramUniformMatrix3dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4DV_PROC* glpfProgramUniformMatrix4dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X3FV_PROC* glpfProgramUniformMatrix2x3fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X2FV_PROC* glpfProgramUniformMatrix3x2fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X4FV_PROC* glpfProgramUniformMatrix2x4fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X2FV_PROC* glpfProgramUniformMatrix4x2fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X4FV_PROC* glpfProgramUniformMatrix3x4fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X3FV_PROC* glpfProgramUniformMatrix4x3fv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X3DV_PROC* glpfProgramUniformMatrix2x3dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X2DV_PROC* glpfProgramUniformMatrix3x2dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X4DV_PROC* glpfProgramUniformMatrix2x4dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X2DV_PROC* glpfProgramUniformMatrix4x2dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X4DV_PROC* glpfProgramUniformMatrix3x4dv = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X3DV_PROC* glpfProgramUniformMatrix4x3dv = NULL;
	PFNGLVALIDATEPROGRAMPIPELINE_PROC* glpfValidateProgramPipeline = NULL;
	PFNGLGETPROGRAMPIPELINEINFOLOG_PROC* glpfGetProgramPipelineInfoLog = NULL;
	PFNGLVERTEXATTRIBL1D_PROC* glpfVertexAttribL1d = NULL;
	PFNGLVERTEXATTRIBL2D_PROC* glpfVertexAttribL2d = NULL;
	PFNGLVERTEXATTRIBL3D_PROC* glpfVertexAttribL3d = NULL;
	PFNGLVERTEXATTRIBL4D_PROC* glpfVertexAttribL4d = NULL;
	PFNGLVERTEXATTRIBL1DV_PROC* glpfVertexAttribL1dv = NULL;
	PFNGLVERTEXATTRIBL2DV_PROC* glpfVertexAttribL2dv = NULL;
	PFNGLVERTEXATTRIBL3DV_PROC* glpfVertexAttribL3dv = NULL;
	PFNGLVERTEXATTRIBL4DV_PROC* glpfVertexAttribL4dv = NULL;
	PFNGLVERTEXATTRIBLPOINTER_PROC* glpfVertexAttribLPointer = NULL;
	PFNGLGETVERTEXATTRIBLDV_PROC* glpfGetVertexAttribLdv = NULL;
	PFNGLVIEWPORTARRAYV_PROC* glpfViewportArrayv = NULL;
	PFNGLVIEWPORTINDEXEDF_PROC* glpfViewportIndexedf = NULL;
	PFNGLVIEWPORTINDEXEDFV_PROC* glpfViewportIndexedfv = NULL;
	PFNGLSCISSORARRAYV_PROC* glpfScissorArrayv = NULL;
	PFNGLSCISSORINDEXED_PROC* glpfScissorIndexed = NULL;
	PFNGLSCISSORINDEXEDV_PROC* glpfScissorIndexedv = NULL;
	PFNGLDEPTHRANGEARRAYV_PROC* glpfDepthRangeArrayv = NULL;
	PFNGLDEPTHRANGEINDEXED_PROC* glpfDepthRangeIndexed = NULL;
	PFNGLGETFLOATI_V_PROC* glpfGetFloati_v = NULL;
	PFNGLGETDOUBLEI_V_PROC* glpfGetDoublei_v = NULL;

	/* GL_VERSION_4_2 */

	PFNGLDRAWARRAYSINSTANCEDBASEINSTANCE_PROC* glpfDrawArraysInstancedBaseInstance = NULL;
	PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCE_PROC* glpfDrawElementsInstancedBaseInstance = NULL;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE_PROC* glpfDrawElementsInstancedBaseVertexBaseInstance = NULL;
	PFNGLGETINTERNALFORMATIV_PROC* glpfGetInternalformativ = NULL;
	PFNGLGETACTIVEATOMICCOUNTERBUFFERIV_PROC* glpfGetActiveAtomicCounterBufferiv = NULL;
	PFNGLBINDIMAGETEXTURE_PROC* glpfBindImageTexture = NULL;
	PFNGLMEMORYBARRIER_PROC* glpfMemoryBarrier = NULL;
	PFNGLTEXSTORAGE1D_PROC* glpfTexStorage1D = NULL;
	PFNGLTEXSTORAGE2D_PROC* glpfTexStorage2D = NULL;
	PFNGLTEXSTORAGE3D_PROC* glpfTexStorage3D = NULL;
	PFNGLDRAWTRANSFORMFEEDBACKINSTANCED_PROC* glpfDrawTransformFeedbackInstanced = NULL;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED_PROC* glpfDrawTransformFeedbackStreamInstanced = NULL;

	/* GL_VERSION_4_3 */

	PFNGLCLEARBUFFERDATA_PROC* glpfClearBufferData = NULL;
	PFNGLCLEARBUFFERSUBDATA_PROC* glpfClearBufferSubData = NULL;
	PFNGLDISPATCHCOMPUTE_PROC* glpfDispatchCompute = NULL;
	PFNGLDISPATCHCOMPUTEINDIRECT_PROC* glpfDispatchComputeIndirect = NULL;
	PFNGLCOPYIMAGESUBDATA_PROC* glpfCopyImageSubData = NULL;
	PFNGLFRAMEBUFFERPARAMETERI_PROC* glpfFramebufferParameteri = NULL;
	PFNGLGETFRAMEBUFFERPARAMETERIV_PROC* glpfGetFramebufferParameteriv = NULL;
	PFNGLGETINTERNALFORMATI64V_PROC* glpfGetInternalformati64v = NULL;
	PFNGLINVALIDATETEXSUBIMAGE_PROC* glpfInvalidateTexSubImage = NULL;
	PFNGLINVALIDATETEXIMAGE_PROC* glpfInvalidateTexImage = NULL;
	PFNGLINVALIDATEBUFFERSUBDATA_PROC* glpfInvalidateBufferSubData = NULL;
	PFNGLINVALIDATEBUFFERDATA_PROC* glpfInvalidateBufferData = NULL;
	PFNGLINVALIDATEFRAMEBUFFER_PROC* glpfInvalidateFramebuffer = NULL;
	PFNGLINVALIDATESUBFRAMEBUFFER_PROC* glpfInvalidateSubFramebuffer = NULL;
	PFNGLMULTIDRAWARRAYSINDIRECT_PROC* glpfMultiDrawArraysIndirect = NULL;
	PFNGLMULTIDRAWELEMENTSINDIRECT_PROC* glpfMultiDrawElementsIndirect = NULL;
	PFNGLGETPROGRAMINTERFACEIV_PROC* glpfGetProgramInterfaceiv = NULL;
	PFNGLGETPROGRAMRESOURCEINDEX_PROC* glpfGetProgramResourceIndex = NULL;
	PFNGLGETPROGRAMRESOURCENAME_PROC* glpfGetProgramResourceName = NULL;
	PFNGLGETPROGRAMRESOURCEIV_PROC* glpfGetProgramResourceiv = NULL;
	PFNGLGETPROGRAMRESOURCELOCATION_PROC* glpfGetProgramResourceLocation = NULL;
	PFNGLGETPROGRAMRESOURCELOCATIONINDEX_PROC* glpfGetProgramResourceLocationIndex = NULL;
	PFNGLSHADERSTORAGEBLOCKBINDING_PROC* glpfShaderStorageBlockBinding = NULL;
	PFNGLTEXBUFFERRANGE_PROC* glpfTexBufferRange = NULL;
	PFNGLTEXSTORAGE2DMULTISAMPLE_PROC* glpfTexStorage2DMultisample = NULL;
	PFNGLTEXSTORAGE3DMULTISAMPLE_PROC* glpfTexStorage3DMultisample = NULL;
	PFNGLTEXTUREVIEW_PROC* glpfTextureView = NULL;
	PFNGLBINDVERTEXBUFFER_PROC* glpfBindVertexBuffer = NULL;
	PFNGLVERTEXATTRIBFORMAT_PROC* glpfVertexAttribFormat = NULL;
	PFNGLVERTEXATTRIBIFORMAT_PROC* glpfVertexAttribIFormat = NULL;
	PFNGLVERTEXATTRIBLFORMAT_PROC* glpfVertexAttribLFormat = NULL;
	PFNGLVERTEXATTRIBBINDING_PROC* glpfVertexAttribBinding = NULL;
	PFNGLVERTEXBINDINGDIVISOR_PROC* glpfVertexBindingDivisor = NULL;
	PFNGLDEBUGMESSAGECONTROL_PROC* glpfDebugMessageControl = NULL;
	PFNGLDEBUGMESSAGEINSERT_PROC* glpfDebugMessageInsert = NULL;
	PFNGLDEBUGMESSAGECALLBACK_PROC* glpfDebugMessageCallback = NULL;
	PFNGLGETDEBUGMESSAGELOG_PROC* glpfGetDebugMessageLog = NULL;
	PFNGLPUSHDEBUGGROUP_PROC* glpfPushDebugGroup = NULL;
	PFNGLPOPDEBUGGROUP_PROC* glpfPopDebugGroup = NULL;
	PFNGLOBJECTLABEL_PROC* glpfObjectLabel = NULL;
	PFNGLGETOBJECTLABEL_PROC* glpfGetObjectLabel = NULL;
	PFNGLOBJECTPTRLABEL_PROC* glpfObjectPtrLabel = NULL;
	PFNGLGETOBJECTPTRLABEL_PROC* glpfGetObjectPtrLabel = NULL;
	PFNGLGETPOINTERV_PROC* glpfGetPointerv = NULL;

	/* GL_VERSION_4_4 */

	PFNGLBUFFERSTORAGE_PROC* glpfBufferStorage = NULL;
	PFNGLCLEARTEXIMAGE_PROC* glpfClearTexImage = NULL;
	PFNGLCLEARTEXSUBIMAGE_PROC* glpfClearTexSubImage = NULL;
	PFNGLBINDBUFFERSBASE_PROC* glpfBindBuffersBase = NULL;
	PFNGLBINDBUFFERSRANGE_PROC* glpfBindBuffersRange = NULL;
	PFNGLBINDTEXTURES_PROC* glpfBindTextures = NULL;
	PFNGLBINDSAMPLERS_PROC* glpfBindSamplers = NULL;
	PFNGLBINDIMAGETEXTURES_PROC* glpfBindImageTextures = NULL;
	PFNGLBINDVERTEXBUFFERS_PROC* glpfBindVertexBuffers = NULL;

	/* GL_VERSION_4_5 */

	PFNGLCLIPCONTROL_PROC* glpfClipControl = NULL;
	PFNGLCREATETRANSFORMFEEDBACKS_PROC* glpfCreateTransformFeedbacks = NULL;
	PFNGLTRANSFORMFEEDBACKBUFFERBASE_PROC* glpfTransformFeedbackBufferBase = NULL;
	PFNGLTRANSFORMFEEDBACKBUFFERRANGE_PROC* glpfTransformFeedbackBufferRange = NULL;
	PFNGLGETTRANSFORMFEEDBACKIV_PROC* glpfGetTransformFeedbackiv = NULL;
	PFNGLGETTRANSFORMFEEDBACKI_V_PROC* glpfGetTransformFeedbacki_v = NULL;
	PFNGLGETTRANSFORMFEEDBACKI64_V_PROC* glpfGetTransformFeedbacki64_v = NULL;
	PFNGLCREATEBUFFERS_PROC* glpfCreateBuffers = NULL;
	PFNGLNAMEDBUFFERSTORAGE_PROC* glpfNamedBufferStorage = NULL;
	PFNGLNAMEDBUFFERDATA_PROC* glpfNamedBufferData = NULL;
	PFNGLNAMEDBUFFERSUBDATA_PROC* glpfNamedBufferSubData = NULL;
	PFNGLCOPYNAMEDBUFFERSUBDATA_PROC* glpfCopyNamedBufferSubData = NULL;
	PFNGLCLEARNAMEDBUFFERDATA_PROC* glpfClearNamedBufferData = NULL;
	PFNGLCLEARNAMEDBUFFERSUBDATA_PROC* glpfClearNamedBufferSubData = NULL;
	PFNGLMAPNAMEDBUFFER_PROC* glpfMapNamedBuffer = NULL;
	PFNGLMAPNAMEDBUFFERRANGE_PROC* glpfMapNamedBufferRange = NULL;
	PFNGLUNMAPNAMEDBUFFER_PROC* glpfUnmapNamedBuffer = NULL;
	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGE_PROC* glpfFlushMappedNamedBufferRange = NULL;
	PFNGLGETNAMEDBUFFERPARAMETERIV_PROC* glpfGetNamedBufferParameteriv = NULL;
	PFNGLGETNAMEDBUFFERPARAMETERI64V_PROC* glpfGetNamedBufferParameteri64v = NULL;
	PFNGLGETNAMEDBUFFERPOINTERV_PROC* glpfGetNamedBufferPointerv = NULL;
	PFNGLGETNAMEDBUFFERSUBDATA_PROC* glpfGetNamedBufferSubData = NULL;
	PFNGLCREATEFRAMEBUFFERS_PROC* glpfCreateFramebuffers = NULL;
	PFNGLNAMEDFRAMEBUFFERRENDERBUFFER_PROC* glpfNamedFramebufferRenderbuffer = NULL;
	PFNGLNAMEDFRAMEBUFFERPARAMETERI_PROC* glpfNamedFramebufferParameteri = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURE_PROC* glpfNamedFramebufferTexture = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURELAYER_PROC* glpfNamedFramebufferTextureLayer = NULL;
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFER_PROC* glpfNamedFramebufferDrawBuffer = NULL;
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFERS_PROC* glpfNamedFramebufferDrawBuffers = NULL;
	PFNGLNAMEDFRAMEBUFFERREADBUFFER_PROC* glpfNamedFramebufferReadBuffer = NULL;
	PFNGLINVALIDATENAMEDFRAMEBUFFERDATA_PROC* glpfInvalidateNamedFramebufferData = NULL;
	PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATA_PROC* glpfInvalidateNamedFramebufferSubData = NULL;
	PFNGLCLEARNAMEDFRAMEBUFFERIV_PROC* glpfClearNamedFramebufferiv = NULL;
	PFNGLCLEARNAMEDFRAMEBUFFERUIV_PROC* glpfClearNamedFramebufferuiv = NULL;
	PFNGLCLEARNAMEDFRAMEBUFFERFV_PROC* glpfClearNamedFramebufferfv = NULL;
	PFNGLCLEARNAMEDFRAMEBUFFERFI_PROC* glpfClearNamedFramebufferfi = NULL;
	PFNGLBLITNAMEDFRAMEBUFFER_PROC* glpfBlitNamedFramebuffer = NULL;
	PFNGLCHECKNAMEDFRAMEBUFFERSTATUS_PROC* glpfCheckNamedFramebufferStatus = NULL;
	PFNGLGETNAMEDFRAMEBUFFERPARAMETERIV_PROC* glpfGetNamedFramebufferParameteriv = NULL;
	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV_PROC* glpfGetNamedFramebufferAttachmentParameteriv = NULL;
	PFNGLCREATERENDERBUFFERS_PROC* glpfCreateRenderbuffers = NULL;
	PFNGLNAMEDRENDERBUFFERSTORAGE_PROC* glpfNamedRenderbufferStorage = NULL;
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE_PROC* glpfNamedRenderbufferStorageMultisample = NULL;
	PFNGLGETNAMEDRENDERBUFFERPARAMETERIV_PROC* glpfGetNamedRenderbufferParameteriv = NULL;
	PFNGLCREATETEXTURES_PROC* glpfCreateTextures = NULL;
	PFNGLTEXTUREBUFFER_PROC* glpfTextureBuffer = NULL;
	PFNGLTEXTUREBUFFERRANGE_PROC* glpfTextureBufferRange = NULL;
	PFNGLTEXTURESTORAGE1D_PROC* glpfTextureStorage1D = NULL;
	PFNGLTEXTURESTORAGE2D_PROC* glpfTextureStorage2D = NULL;
	PFNGLTEXTURESTORAGE3D_PROC* glpfTextureStorage3D = NULL;
	PFNGLTEXTURESTORAGE2DMULTISAMPLE_PROC* glpfTextureStorage2DMultisample = NULL;
	PFNGLTEXTURESTORAGE3DMULTISAMPLE_PROC* glpfTextureStorage3DMultisample = NULL;
	PFNGLTEXTURESUBIMAGE1D_PROC* glpfTextureSubImage1D = NULL;
	PFNGLTEXTURESUBIMAGE2D_PROC* glpfTextureSubImage2D = NULL;
	PFNGLTEXTURESUBIMAGE3D_PROC* glpfTextureSubImage3D = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE1D_PROC* glpfCompressedTextureSubImage1D = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE2D_PROC* glpfCompressedTextureSubImage2D = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE3D_PROC* glpfCompressedTextureSubImage3D = NULL;
	PFNGLCOPYTEXTURESUBIMAGE1D_PROC* glpfCopyTextureSubImage1D = NULL;
	PFNGLCOPYTEXTURESUBIMAGE2D_PROC* glpfCopyTextureSubImage2D = NULL;
	PFNGLCOPYTEXTURESUBIMAGE3D_PROC* glpfCopyTextureSubImage3D = NULL;
	PFNGLTEXTUREPARAMETERF_PROC* glpfTextureParameterf = NULL;
	PFNGLTEXTUREPARAMETERFV_PROC* glpfTextureParameterfv = NULL;
	PFNGLTEXTUREPARAMETERI_PROC* glpfTextureParameteri = NULL;
	PFNGLTEXTUREPARAMETERIIV_PROC* glpfTextureParameterIiv = NULL;
	PFNGLTEXTUREPARAMETERIUIV_PROC* glpfTextureParameterIuiv = NULL;
	PFNGLTEXTUREPARAMETERIV_PROC* glpfTextureParameteriv = NULL;
	PFNGLGENERATETEXTUREMIPMAP_PROC* glpfGenerateTextureMipmap = NULL;
	PFNGLBINDTEXTUREUNIT_PROC* glpfBindTextureUnit = NULL;
	PFNGLGETTEXTUREIMAGE_PROC* glpfGetTextureImage = NULL;
	PFNGLGETCOMPRESSEDTEXTUREIMAGE_PROC* glpfGetCompressedTextureImage = NULL;
	PFNGLGETTEXTURELEVELPARAMETERFV_PROC* glpfGetTextureLevelParameterfv = NULL;
	PFNGLGETTEXTURELEVELPARAMETERIV_PROC* glpfGetTextureLevelParameteriv = NULL;
	PFNGLGETTEXTUREPARAMETERFV_PROC* glpfGetTextureParameterfv = NULL;
	PFNGLGETTEXTUREPARAMETERIIV_PROC* glpfGetTextureParameterIiv = NULL;
	PFNGLGETTEXTUREPARAMETERIUIV_PROC* glpfGetTextureParameterIuiv = NULL;
	PFNGLGETTEXTUREPARAMETERIV_PROC* glpfGetTextureParameteriv = NULL;
	PFNGLCREATEVERTEXARRAYS_PROC* glpfCreateVertexArrays = NULL;
	PFNGLDISABLEVERTEXARRAYATTRIB_PROC* glpfDisableVertexArrayAttrib = NULL;
	PFNGLENABLEVERTEXARRAYATTRIB_PROC* glpfEnableVertexArrayAttrib = NULL;
	PFNGLVERTEXARRAYELEMENTBUFFER_PROC* glpfVertexArrayElementBuffer = NULL;
	PFNGLVERTEXARRAYVERTEXBUFFER_PROC* glpfVertexArrayVertexBuffer = NULL;
	PFNGLVERTEXARRAYVERTEXBUFFERS_PROC* glpfVertexArrayVertexBuffers = NULL;
	PFNGLVERTEXARRAYATTRIBBINDING_PROC* glpfVertexArrayAttribBinding = NULL;
	PFNGLVERTEXARRAYATTRIBFORMAT_PROC* glpfVertexArrayAttribFormat = NULL;
	PFNGLVERTEXARRAYATTRIBIFORMAT_PROC* glpfVertexArrayAttribIFormat = NULL;
	PFNGLVERTEXARRAYATTRIBLFORMAT_PROC* glpfVertexArrayAttribLFormat = NULL;
	PFNGLVERTEXARRAYBINDINGDIVISOR_PROC* glpfVertexArrayBindingDivisor = NULL;
	PFNGLGETVERTEXARRAYIV_PROC* glpfGetVertexArrayiv = NULL;
	PFNGLGETVERTEXARRAYINDEXEDIV_PROC* glpfGetVertexArrayIndexediv = NULL;
	PFNGLGETVERTEXARRAYINDEXED64IV_PROC* glpfGetVertexArrayIndexed64iv = NULL;
	PFNGLCREATESAMPLERS_PROC* glpfCreateSamplers = NULL;
	PFNGLCREATEPROGRAMPIPELINES_PROC* glpfCreateProgramPipelines = NULL;
	PFNGLCREATEQUERIES_PROC* glpfCreateQueries = NULL;
	PFNGLGETQUERYBUFFEROBJECTI64V_PROC* glpfGetQueryBufferObjecti64v = NULL;
	PFNGLGETQUERYBUFFEROBJECTIV_PROC* glpfGetQueryBufferObjectiv = NULL;
	PFNGLGETQUERYBUFFEROBJECTUI64V_PROC* glpfGetQueryBufferObjectui64v = NULL;
	PFNGLGETQUERYBUFFEROBJECTUIV_PROC* glpfGetQueryBufferObjectuiv = NULL;
	PFNGLMEMORYBARRIERBYREGION_PROC* glpfMemoryBarrierByRegion = NULL;
	PFNGLGETTEXTURESUBIMAGE_PROC* glpfGetTextureSubImage = NULL;
	PFNGLGETCOMPRESSEDTEXTURESUBIMAGE_PROC* glpfGetCompressedTextureSubImage = NULL;
	PFNGLGETGRAPHICSRESETSTATUS_PROC* glpfGetGraphicsResetStatus = NULL;
	PFNGLGETNCOMPRESSEDTEXIMAGE_PROC* glpfGetnCompressedTexImage = NULL;
	PFNGLGETNTEXIMAGE_PROC* glpfGetnTexImage = NULL;
	PFNGLGETNUNIFORMDV_PROC* glpfGetnUniformdv = NULL;
	PFNGLGETNUNIFORMFV_PROC* glpfGetnUniformfv = NULL;
	PFNGLGETNUNIFORMIV_PROC* glpfGetnUniformiv = NULL;
	PFNGLGETNUNIFORMUIV_PROC* glpfGetnUniformuiv = NULL;
	PFNGLREADNPIXELS_PROC* glpfReadnPixels = NULL;
	PFNGLTEXTUREBARRIER_PROC* glpfTextureBarrier = NULL;

	/* GL_ARB_bindless_texture */

	PFNGLGETTEXTUREHANDLEARB_PROC* glpfGetTextureHandleARB = NULL;
	PFNGLGETTEXTURESAMPLERHANDLEARB_PROC* glpfGetTextureSamplerHandleARB = NULL;
	PFNGLMAKETEXTUREHANDLERESIDENTARB_PROC* glpfMakeTextureHandleResidentARB = NULL;
	PFNGLMAKETEXTUREHANDLENONRESIDENTARB_PROC* glpfMakeTextureHandleNonResidentARB = NULL;
	PFNGLGETIMAGEHANDLEARB_PROC* glpfGetImageHandleARB = NULL;
	PFNGLMAKEIMAGEHANDLERESIDENTARB_PROC* glpfMakeImageHandleResidentARB = NULL;
	PFNGLMAKEIMAGEHANDLENONRESIDENTARB_PROC* glpfMakeImageHandleNonResidentARB = NULL;
	PFNGLUNIFORMHANDLEUI64ARB_PROC* glpfUniformHandleui64ARB = NULL;
	PFNGLUNIFORMHANDLEUI64VARB_PROC* glpfUniformHandleui64vARB = NULL;
	PFNGLPROGRAMUNIFORMHANDLEUI64ARB_PROC* glpfProgramUniformHandleui64ARB = NULL;
	PFNGLPROGRAMUNIFORMHANDLEUI64VARB_PROC* glpfProgramUniformHandleui64vARB = NULL;
	PFNGLISTEXTUREHANDLERESIDENTARB_PROC* glpfIsTextureHandleResidentARB = NULL;
	PFNGLISIMAGEHANDLERESIDENTARB_PROC* glpfIsImageHandleResidentARB = NULL;
	PFNGLVERTEXATTRIBL1UI64ARB_PROC* glpfVertexAttribL1ui64ARB = NULL;
	PFNGLVERTEXATTRIBL1UI64VARB_PROC* glpfVertexAttribL1ui64vARB = NULL;
	PFNGLGETVERTEXATTRIBLUI64VARB_PROC* glpfGetVertexAttribLui64vARB = NULL;

	/* GL_ARB_sparse_texture */

	PFNGLTEXPAGECOMMITMENTARB_PROC* glpfTexPageCommitmentARB = NULL;

	/* GL_ARB_indirect_parameters */

	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARB_PROC* glpfMultiDrawArraysIndirectCountARB = NULL;
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARB_PROC* glpfMultiDrawElementsIndirectCountARB = NULL;

	/* GL_EXT_direct_state_access */

	PFNGLMATRIXLOADFEXT_PROC* glpfMatrixLoadfEXT = NULL;
	PFNGLMATRIXLOADDEXT_PROC* glpfMatrixLoaddEXT = NULL;
	PFNGLMATRIXMULTFEXT_PROC* glpfMatrixMultfEXT = NULL;
	PFNGLMATRIXMULTDEXT_PROC* glpfMatrixMultdEXT = NULL;
	PFNGLMATRIXLOADIDENTITYEXT_PROC* glpfMatrixLoadIdentityEXT = NULL;
	PFNGLMATRIXROTATEFEXT_PROC* glpfMatrixRotatefEXT = NULL;
	PFNGLMATRIXROTATEDEXT_PROC* glpfMatrixRotatedEXT = NULL;
	PFNGLMATRIXSCALEFEXT_PROC* glpfMatrixScalefEXT = NULL;
	PFNGLMATRIXSCALEDEXT_PROC* glpfMatrixScaledEXT = NULL;
	PFNGLMATRIXTRANSLATEFEXT_PROC* glpfMatrixTranslatefEXT = NULL;
	PFNGLMATRIXTRANSLATEDEXT_PROC* glpfMatrixTranslatedEXT = NULL;
	PFNGLMATRIXFRUSTUMEXT_PROC* glpfMatrixFrustumEXT = NULL;
	PFNGLMATRIXORTHOEXT_PROC* glpfMatrixOrthoEXT = NULL;
	PFNGLMATRIXPOPEXT_PROC* glpfMatrixPopEXT = NULL;
	PFNGLMATRIXPUSHEXT_PROC* glpfMatrixPushEXT = NULL;
	PFNGLCLIENTATTRIBDEFAULTEXT_PROC* glpfClientAttribDefaultEXT = NULL;
	PFNGLPUSHCLIENTATTRIBDEFAULTEXT_PROC* glpfPushClientAttribDefaultEXT = NULL;
	PFNGLTEXTUREPARAMETERFEXT_PROC* glpfTextureParameterfEXT = NULL;
	PFNGLTEXTUREPARAMETERFVEXT_PROC* glpfTextureParameterfvEXT = NULL;
	PFNGLTEXTUREPARAMETERIEXT_PROC* glpfTextureParameteriEXT = NULL;
	PFNGLTEXTUREPARAMETERIVEXT_PROC* glpfTextureParameterivEXT = NULL;
	PFNGLTEXTUREIMAGE1DEXT_PROC* glpfTextureImage1DEXT = NULL;
	PFNGLTEXTUREIMAGE2DEXT_PROC* glpfTextureImage2DEXT = NULL;
	PFNGLTEXTURESUBIMAGE1DEXT_PROC* glpfTextureSubImage1DEXT = NULL;
	PFNGLTEXTURESUBIMAGE2DEXT_PROC* glpfTextureSubImage2DEXT = NULL;
	PFNGLCOPYTEXTUREIMAGE1DEXT_PROC* glpfCopyTextureImage1DEXT = NULL;
	PFNGLCOPYTEXTUREIMAGE2DEXT_PROC* glpfCopyTextureImage2DEXT = NULL;
	PFNGLCOPYTEXTURESUBIMAGE1DEXT_PROC* glpfCopyTextureSubImage1DEXT = NULL;
	PFNGLCOPYTEXTURESUBIMAGE2DEXT_PROC* glpfCopyTextureSubImage2DEXT = NULL;
	PFNGLGETTEXTUREIMAGEEXT_PROC* glpfGetTextureImageEXT = NULL;
	PFNGLGETTEXTUREPARAMETERFVEXT_PROC* glpfGetTextureParameterfvEXT = NULL;
	PFNGLGETTEXTUREPARAMETERIVEXT_PROC* glpfGetTextureParameterivEXT = NULL;
	PFNGLGETTEXTURELEVELPARAMETERFVEXT_PROC* glpfGetTextureLevelParameterfvEXT = NULL;
	PFNGLGETTEXTURELEVELPARAMETERIVEXT_PROC* glpfGetTextureLevelParameterivEXT = NULL;
	PFNGLTEXTUREIMAGE3DEXT_PROC* glpfTextureImage3DEXT = NULL;
	PFNGLTEXTURESUBIMAGE3DEXT_PROC* glpfTextureSubImage3DEXT = NULL;
	PFNGLCOPYTEXTURESUBIMAGE3DEXT_PROC* glpfCopyTextureSubImage3DEXT = NULL;
	PFNGLBINDMULTITEXTUREEXT_PROC* glpfBindMultiTextureEXT = NULL;
	PFNGLMULTITEXCOORDPOINTEREXT_PROC* glpfMultiTexCoordPointerEXT = NULL;
	PFNGLMULTITEXENVFEXT_PROC* glpfMultiTexEnvfEXT = NULL;
	PFNGLMULTITEXENVFVEXT_PROC* glpfMultiTexEnvfvEXT = NULL;
	PFNGLMULTITEXENVIEXT_PROC* glpfMultiTexEnviEXT = NULL;
	PFNGLMULTITEXENVIVEXT_PROC* glpfMultiTexEnvivEXT = NULL;
	PFNGLMULTITEXGENDEXT_PROC* glpfMultiTexGendEXT = NULL;
	PFNGLMULTITEXGENDVEXT_PROC* glpfMultiTexGendvEXT = NULL;
	PFNGLMULTITEXGENFEXT_PROC* glpfMultiTexGenfEXT = NULL;
	PFNGLMULTITEXGENFVEXT_PROC* glpfMultiTexGenfvEXT = NULL;
	PFNGLMULTITEXGENIEXT_PROC* glpfMultiTexGeniEXT = NULL;
	PFNGLMULTITEXGENIVEXT_PROC* glpfMultiTexGenivEXT = NULL;
	PFNGLGETMULTITEXENVFVEXT_PROC* glpfGetMultiTexEnvfvEXT = NULL;
	PFNGLGETMULTITEXENVIVEXT_PROC* glpfGetMultiTexEnvivEXT = NULL;
	PFNGLGETMULTITEXGENDVEXT_PROC* glpfGetMultiTexGendvEXT = NULL;
	PFNGLGETMULTITEXGENFVEXT_PROC* glpfGetMultiTexGenfvEXT = NULL;
	PFNGLGETMULTITEXGENIVEXT_PROC* glpfGetMultiTexGenivEXT = NULL;
	PFNGLMULTITEXPARAMETERIEXT_PROC* glpfMultiTexParameteriEXT = NULL;
	PFNGLMULTITEXPARAMETERIVEXT_PROC* glpfMultiTexParameterivEXT = NULL;
	PFNGLMULTITEXPARAMETERFEXT_PROC* glpfMultiTexParameterfEXT = NULL;
	PFNGLMULTITEXPARAMETERFVEXT_PROC* glpfMultiTexParameterfvEXT = NULL;
	PFNGLMULTITEXIMAGE1DEXT_PROC* glpfMultiTexImage1DEXT = NULL;
	PFNGLMULTITEXIMAGE2DEXT_PROC* glpfMultiTexImage2DEXT = NULL;
	PFNGLMULTITEXSUBIMAGE1DEXT_PROC* glpfMultiTexSubImage1DEXT = NULL;
	PFNGLMULTITEXSUBIMAGE2DEXT_PROC* glpfMultiTexSubImage2DEXT = NULL;
	PFNGLCOPYMULTITEXIMAGE1DEXT_PROC* glpfCopyMultiTexImage1DEXT = NULL;
	PFNGLCOPYMULTITEXIMAGE2DEXT_PROC* glpfCopyMultiTexImage2DEXT = NULL;
	PFNGLCOPYMULTITEXSUBIMAGE1DEXT_PROC* glpfCopyMultiTexSubImage1DEXT = NULL;
	PFNGLCOPYMULTITEXSUBIMAGE2DEXT_PROC* glpfCopyMultiTexSubImage2DEXT = NULL;
	PFNGLGETMULTITEXIMAGEEXT_PROC* glpfGetMultiTexImageEXT = NULL;
	PFNGLGETMULTITEXPARAMETERFVEXT_PROC* glpfGetMultiTexParameterfvEXT = NULL;
	PFNGLGETMULTITEXPARAMETERIVEXT_PROC* glpfGetMultiTexParameterivEXT = NULL;
	PFNGLGETMULTITEXLEVELPARAMETERFVEXT_PROC* glpfGetMultiTexLevelParameterfvEXT = NULL;
	PFNGLGETMULTITEXLEVELPARAMETERIVEXT_PROC* glpfGetMultiTexLevelParameterivEXT = NULL;
	PFNGLMULTITEXIMAGE3DEXT_PROC* glpfMultiTexImage3DEXT = NULL;
	PFNGLMULTITEXSUBIMAGE3DEXT_PROC* glpfMultiTexSubImage3DEXT = NULL;
	PFNGLCOPYMULTITEXSUBIMAGE3DEXT_PROC* glpfCopyMultiTexSubImage3DEXT = NULL;
	PFNGLENABLECLIENTSTATEINDEXEDEXT_PROC* glpfEnableClientStateIndexedEXT = NULL;
	PFNGLDISABLECLIENTSTATEINDEXEDEXT_PROC* glpfDisableClientStateIndexedEXT = NULL;
	PFNGLGETFLOATINDEXEDVEXT_PROC* glpfGetFloatIndexedvEXT = NULL;
	PFNGLGETDOUBLEINDEXEDVEXT_PROC* glpfGetDoubleIndexedvEXT = NULL;
	PFNGLGETPOINTERINDEXEDVEXT_PROC* glpfGetPointerIndexedvEXT = NULL;
	PFNGLENABLEINDEXEDEXT_PROC* glpfEnableIndexedEXT = NULL;
	PFNGLDISABLEINDEXEDEXT_PROC* glpfDisableIndexedEXT = NULL;
	PFNGLISENABLEDINDEXEDEXT_PROC* glpfIsEnabledIndexedEXT = NULL;
	PFNGLGETINTEGERINDEXEDVEXT_PROC* glpfGetIntegerIndexedvEXT = NULL;
	PFNGLGETBOOLEANINDEXEDVEXT_PROC* glpfGetBooleanIndexedvEXT = NULL;
	PFNGLCOMPRESSEDTEXTUREIMAGE3DEXT_PROC* glpfCompressedTextureImage3DEXT = NULL;
	PFNGLCOMPRESSEDTEXTUREIMAGE2DEXT_PROC* glpfCompressedTextureImage2DEXT = NULL;
	PFNGLCOMPRESSEDTEXTUREIMAGE1DEXT_PROC* glpfCompressedTextureImage1DEXT = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXT_PROC* glpfCompressedTextureSubImage3DEXT = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXT_PROC* glpfCompressedTextureSubImage2DEXT = NULL;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXT_PROC* glpfCompressedTextureSubImage1DEXT = NULL;
	PFNGLGETCOMPRESSEDTEXTUREIMAGEEXT_PROC* glpfGetCompressedTextureImageEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXIMAGE3DEXT_PROC* glpfCompressedMultiTexImage3DEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXIMAGE2DEXT_PROC* glpfCompressedMultiTexImage2DEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXIMAGE1DEXT_PROC* glpfCompressedMultiTexImage1DEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXT_PROC* glpfCompressedMultiTexSubImage3DEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXT_PROC* glpfCompressedMultiTexSubImage2DEXT = NULL;
	PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXT_PROC* glpfCompressedMultiTexSubImage1DEXT = NULL;
	PFNGLGETCOMPRESSEDMULTITEXIMAGEEXT_PROC* glpfGetCompressedMultiTexImageEXT = NULL;
	PFNGLMATRIXLOADTRANSPOSEFEXT_PROC* glpfMatrixLoadTransposefEXT = NULL;
	PFNGLMATRIXLOADTRANSPOSEDEXT_PROC* glpfMatrixLoadTransposedEXT = NULL;
	PFNGLMATRIXMULTTRANSPOSEFEXT_PROC* glpfMatrixMultTransposefEXT = NULL;
	PFNGLMATRIXMULTTRANSPOSEDEXT_PROC* glpfMatrixMultTransposedEXT = NULL;
	PFNGLNAMEDBUFFERDATAEXT_PROC* glpfNamedBufferDataEXT = NULL;
	PFNGLNAMEDBUFFERSUBDATAEXT_PROC* glpfNamedBufferSubDataEXT = NULL;
	PFNGLMAPNAMEDBUFFEREXT_PROC* glpfMapNamedBufferEXT = NULL;
	PFNGLUNMAPNAMEDBUFFEREXT_PROC* glpfUnmapNamedBufferEXT = NULL;
	PFNGLGETNAMEDBUFFERPARAMETERIVEXT_PROC* glpfGetNamedBufferParameterivEXT = NULL;
	PFNGLGETNAMEDBUFFERPOINTERVEXT_PROC* glpfGetNamedBufferPointervEXT = NULL;
	PFNGLGETNAMEDBUFFERSUBDATAEXT_PROC* glpfGetNamedBufferSubDataEXT = NULL;
	PFNGLPROGRAMUNIFORM1FEXT_PROC* glpfProgramUniform1fEXT = NULL;
	PFNGLPROGRAMUNIFORM2FEXT_PROC* glpfProgramUniform2fEXT = NULL;
	PFNGLPROGRAMUNIFORM3FEXT_PROC* glpfProgramUniform3fEXT = NULL;
	PFNGLPROGRAMUNIFORM4FEXT_PROC* glpfProgramUniform4fEXT = NULL;
	PFNGLPROGRAMUNIFORM1IEXT_PROC* glpfProgramUniform1iEXT = NULL;
	PFNGLPROGRAMUNIFORM2IEXT_PROC* glpfProgramUniform2iEXT = NULL;
	PFNGLPROGRAMUNIFORM3IEXT_PROC* glpfProgramUniform3iEXT = NULL;
	PFNGLPROGRAMUNIFORM4IEXT_PROC* glpfProgramUniform4iEXT = NULL;
	PFNGLPROGRAMUNIFORM1FVEXT_PROC* glpfProgramUniform1fvEXT = NULL;
	PFNGLPROGRAMUNIFORM2FVEXT_PROC* glpfProgramUniform2fvEXT = NULL;
	PFNGLPROGRAMUNIFORM3FVEXT_PROC* glpfProgramUniform3fvEXT = NULL;
	PFNGLPROGRAMUNIFORM4FVEXT_PROC* glpfProgramUniform4fvEXT = NULL;
	PFNGLPROGRAMUNIFORM1IVEXT_PROC* glpfProgramUniform1ivEXT = NULL;
	PFNGLPROGRAMUNIFORM2IVEXT_PROC* glpfProgramUniform2ivEXT = NULL;
	PFNGLPROGRAMUNIFORM3IVEXT_PROC* glpfProgramUniform3ivEXT = NULL;
	PFNGLPROGRAMUNIFORM4IVEXT_PROC* glpfProgramUniform4ivEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2FVEXT_PROC* glpfProgramUniformMatrix2fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3FVEXT_PROC* glpfProgramUniformMatrix3fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4FVEXT_PROC* glpfProgramUniformMatrix4fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X3FVEXT_PROC* glpfProgramUniformMatrix2x3fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X2FVEXT_PROC* glpfProgramUniformMatrix3x2fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X4FVEXT_PROC* glpfProgramUniformMatrix2x4fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X2FVEXT_PROC* glpfProgramUniformMatrix4x2fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X4FVEXT_PROC* glpfProgramUniformMatrix3x4fvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X3FVEXT_PROC* glpfProgramUniformMatrix4x3fvEXT = NULL;
	PFNGLTEXTUREBUFFEREXT_PROC* glpfTextureBufferEXT = NULL;
	PFNGLMULTITEXBUFFEREXT_PROC* glpfMultiTexBufferEXT = NULL;
	PFNGLTEXTUREPARAMETERIIVEXT_PROC* glpfTextureParameterIivEXT = NULL;
	PFNGLTEXTUREPARAMETERIUIVEXT_PROC* glpfTextureParameterIuivEXT = NULL;
	PFNGLGETTEXTUREPARAMETERIIVEXT_PROC* glpfGetTextureParameterIivEXT = NULL;
	PFNGLGETTEXTUREPARAMETERIUIVEXT_PROC* glpfGetTextureParameterIuivEXT = NULL;
	PFNGLMULTITEXPARAMETERIIVEXT_PROC* glpfMultiTexParameterIivEXT = NULL;
	PFNGLMULTITEXPARAMETERIUIVEXT_PROC* glpfMultiTexParameterIuivEXT = NULL;
	PFNGLGETMULTITEXPARAMETERIIVEXT_PROC* glpfGetMultiTexParameterIivEXT = NULL;
	PFNGLGETMULTITEXPARAMETERIUIVEXT_PROC* glpfGetMultiTexParameterIuivEXT = NULL;
	PFNGLPROGRAMUNIFORM1UIEXT_PROC* glpfProgramUniform1uiEXT = NULL;
	PFNGLPROGRAMUNIFORM2UIEXT_PROC* glpfProgramUniform2uiEXT = NULL;
	PFNGLPROGRAMUNIFORM3UIEXT_PROC* glpfProgramUniform3uiEXT = NULL;
	PFNGLPROGRAMUNIFORM4UIEXT_PROC* glpfProgramUniform4uiEXT = NULL;
	PFNGLPROGRAMUNIFORM1UIVEXT_PROC* glpfProgramUniform1uivEXT = NULL;
	PFNGLPROGRAMUNIFORM2UIVEXT_PROC* glpfProgramUniform2uivEXT = NULL;
	PFNGLPROGRAMUNIFORM3UIVEXT_PROC* glpfProgramUniform3uivEXT = NULL;
	PFNGLPROGRAMUNIFORM4UIVEXT_PROC* glpfProgramUniform4uivEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXT_PROC* glpfNamedProgramLocalParameters4fvEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXT_PROC* glpfNamedProgramLocalParameterI4iEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXT_PROC* glpfNamedProgramLocalParameterI4ivEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT_PROC* glpfNamedProgramLocalParametersI4ivEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXT_PROC* glpfNamedProgramLocalParameterI4uiEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT_PROC* glpfNamedProgramLocalParameterI4uivEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT_PROC* glpfNamedProgramLocalParametersI4uivEXT = NULL;
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT_PROC* glpfGetNamedProgramLocalParameterIivEXT = NULL;
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT_PROC* glpfGetNamedProgramLocalParameterIuivEXT = NULL;
	PFNGLENABLECLIENTSTATEIEXT_PROC* glpfEnableClientStateiEXT = NULL;
	PFNGLDISABLECLIENTSTATEIEXT_PROC* glpfDisableClientStateiEXT = NULL;
	PFNGLGETFLOATI_VEXT_PROC* glpfGetFloati_vEXT = NULL;
	PFNGLGETDOUBLEI_VEXT_PROC* glpfGetDoublei_vEXT = NULL;
	PFNGLGETPOINTERI_VEXT_PROC* glpfGetPointeri_vEXT = NULL;
	PFNGLNAMEDPROGRAMSTRINGEXT_PROC* glpfNamedProgramStringEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXT_PROC* glpfNamedProgramLocalParameter4dEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXT_PROC* glpfNamedProgramLocalParameter4dvEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXT_PROC* glpfNamedProgramLocalParameter4fEXT = NULL;
	PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXT_PROC* glpfNamedProgramLocalParameter4fvEXT = NULL;
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXT_PROC* glpfGetNamedProgramLocalParameterdvEXT = NULL;
	PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXT_PROC* glpfGetNamedProgramLocalParameterfvEXT = NULL;
	PFNGLGETNAMEDPROGRAMIVEXT_PROC* glpfGetNamedProgramivEXT = NULL;
	PFNGLGETNAMEDPROGRAMSTRINGEXT_PROC* glpfGetNamedProgramStringEXT = NULL;
	PFNGLNAMEDRENDERBUFFERSTORAGEEXT_PROC* glpfNamedRenderbufferStorageEXT = NULL;
	PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXT_PROC* glpfGetNamedRenderbufferParameterivEXT = NULL;
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT_PROC* glpfNamedRenderbufferStorageMultisampleEXT = NULL;
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT_PROC* glpfNamedRenderbufferStorageMultisampleCoverageEXT = NULL;
	PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXT_PROC* glpfCheckNamedFramebufferStatusEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXT_PROC* glpfNamedFramebufferTexture1DEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXT_PROC* glpfNamedFramebufferTexture2DEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXT_PROC* glpfNamedFramebufferTexture3DEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXT_PROC* glpfNamedFramebufferRenderbufferEXT = NULL;
	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT_PROC* glpfGetNamedFramebufferAttachmentParameterivEXT = NULL;
	PFNGLGENERATETEXTUREMIPMAPEXT_PROC* glpfGenerateTextureMipmapEXT = NULL;
	PFNGLGENERATEMULTITEXMIPMAPEXT_PROC* glpfGenerateMultiTexMipmapEXT = NULL;
	PFNGLFRAMEBUFFERDRAWBUFFEREXT_PROC* glpfFramebufferDrawBufferEXT = NULL;
	PFNGLFRAMEBUFFERDRAWBUFFERSEXT_PROC* glpfFramebufferDrawBuffersEXT = NULL;
	PFNGLFRAMEBUFFERREADBUFFEREXT_PROC* glpfFramebufferReadBufferEXT = NULL;
	PFNGLGETFRAMEBUFFERPARAMETERIVEXT_PROC* glpfGetFramebufferParameterivEXT = NULL;
	PFNGLNAMEDCOPYBUFFERSUBDATAEXT_PROC* glpfNamedCopyBufferSubDataEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTUREEXT_PROC* glpfNamedFramebufferTextureEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXT_PROC* glpfNamedFramebufferTextureLayerEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXT_PROC* glpfNamedFramebufferTextureFaceEXT = NULL;
	PFNGLTEXTURERENDERBUFFEREXT_PROC* glpfTextureRenderbufferEXT = NULL;
	PFNGLMULTITEXRENDERBUFFEREXT_PROC* glpfMultiTexRenderbufferEXT = NULL;
	PFNGLVERTEXARRAYVERTEXOFFSETEXT_PROC* glpfVertexArrayVertexOffsetEXT = NULL;
	PFNGLVERTEXARRAYCOLOROFFSETEXT_PROC* glpfVertexArrayColorOffsetEXT = NULL;
	PFNGLVERTEXARRAYEDGEFLAGOFFSETEXT_PROC* glpfVertexArrayEdgeFlagOffsetEXT = NULL;
	PFNGLVERTEXARRAYINDEXOFFSETEXT_PROC* glpfVertexArrayIndexOffsetEXT = NULL;
	PFNGLVERTEXARRAYNORMALOFFSETEXT_PROC* glpfVertexArrayNormalOffsetEXT = NULL;
	PFNGLVERTEXARRAYTEXCOORDOFFSETEXT_PROC* glpfVertexArrayTexCoordOffsetEXT = NULL;
	PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXT_PROC* glpfVertexArrayMultiTexCoordOffsetEXT = NULL;
	PFNGLVERTEXARRAYFOGCOORDOFFSETEXT_PROC* glpfVertexArrayFogCoordOffsetEXT = NULL;
	PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXT_PROC* glpfVertexArraySecondaryColorOffsetEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXT_PROC* glpfVertexArrayVertexAttribOffsetEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXT_PROC* glpfVertexArrayVertexAttribIOffsetEXT = NULL;
	PFNGLENABLEVERTEXARRAYEXT_PROC* glpfEnableVertexArrayEXT = NULL;
	PFNGLDISABLEVERTEXARRAYEXT_PROC* glpfDisableVertexArrayEXT = NULL;
	PFNGLENABLEVERTEXARRAYATTRIBEXT_PROC* glpfEnableVertexArrayAttribEXT = NULL;
	PFNGLDISABLEVERTEXARRAYATTRIBEXT_PROC* glpfDisableVertexArrayAttribEXT = NULL;
	PFNGLGETVERTEXARRAYINTEGERVEXT_PROC* glpfGetVertexArrayIntegervEXT = NULL;
	PFNGLGETVERTEXARRAYPOINTERVEXT_PROC* glpfGetVertexArrayPointervEXT = NULL;
	PFNGLGETVERTEXARRAYINTEGERI_VEXT_PROC* glpfGetVertexArrayIntegeri_vEXT = NULL;
	PFNGLGETVERTEXARRAYPOINTERI_VEXT_PROC* glpfGetVertexArrayPointeri_vEXT = NULL;
	PFNGLMAPNAMEDBUFFERRANGEEXT_PROC* glpfMapNamedBufferRangeEXT = NULL;
	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXT_PROC* glpfFlushMappedNamedBufferRangeEXT = NULL;
	PFNGLNAMEDBUFFERSTORAGEEXT_PROC* glpfNamedBufferStorageEXT = NULL;
	PFNGLCLEARNAMEDBUFFERDATAEXT_PROC* glpfClearNamedBufferDataEXT = NULL;
	PFNGLCLEARNAMEDBUFFERSUBDATAEXT_PROC* glpfClearNamedBufferSubDataEXT = NULL;
	PFNGLNAMEDFRAMEBUFFERPARAMETERIEXT_PROC* glpfNamedFramebufferParameteriEXT = NULL;
	PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXT_PROC* glpfGetNamedFramebufferParameterivEXT = NULL;
	PFNGLPROGRAMUNIFORM1DEXT_PROC* glpfProgramUniform1dEXT = NULL;
	PFNGLPROGRAMUNIFORM2DEXT_PROC* glpfProgramUniform2dEXT = NULL;
	PFNGLPROGRAMUNIFORM3DEXT_PROC* glpfProgramUniform3dEXT = NULL;
	PFNGLPROGRAMUNIFORM4DEXT_PROC* glpfProgramUniform4dEXT = NULL;
	PFNGLPROGRAMUNIFORM1DVEXT_PROC* glpfProgramUniform1dvEXT = NULL;
	PFNGLPROGRAMUNIFORM2DVEXT_PROC* glpfProgramUniform2dvEXT = NULL;
	PFNGLPROGRAMUNIFORM3DVEXT_PROC* glpfProgramUniform3dvEXT = NULL;
	PFNGLPROGRAMUNIFORM4DVEXT_PROC* glpfProgramUniform4dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2DVEXT_PROC* glpfProgramUniformMatrix2dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3DVEXT_PROC* glpfProgramUniformMatrix3dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4DVEXT_PROC* glpfProgramUniformMatrix4dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X3DVEXT_PROC* glpfProgramUniformMatrix2x3dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX2X4DVEXT_PROC* glpfProgramUniformMatrix2x4dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X2DVEXT_PROC* glpfProgramUniformMatrix3x2dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX3X4DVEXT_PROC* glpfProgramUniformMatrix3x4dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X2DVEXT_PROC* glpfProgramUniformMatrix4x2dvEXT = NULL;
	PFNGLPROGRAMUNIFORMMATRIX4X3DVEXT_PROC* glpfProgramUniformMatrix4x3dvEXT = NULL;
	PFNGLTEXTUREBUFFERRANGEEXT_PROC* glpfTextureBufferRangeEXT = NULL;
	PFNGLTEXTURESTORAGE1DEXT_PROC* glpfTextureStorage1DEXT = NULL;
	PFNGLTEXTURESTORAGE2DEXT_PROC* glpfTextureStorage2DEXT = NULL;
	PFNGLTEXTURESTORAGE3DEXT_PROC* glpfTextureStorage3DEXT = NULL;
	PFNGLTEXTURESTORAGE2DMULTISAMPLEEXT_PROC* glpfTextureStorage2DMultisampleEXT = NULL;
	PFNGLTEXTURESTORAGE3DMULTISAMPLEEXT_PROC* glpfTextureStorage3DMultisampleEXT = NULL;
	PFNGLVERTEXARRAYBINDVERTEXBUFFEREXT_PROC* glpfVertexArrayBindVertexBufferEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXT_PROC* glpfVertexArrayVertexAttribFormatEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXT_PROC* glpfVertexArrayVertexAttribIFormatEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXT_PROC* glpfVertexArrayVertexAttribLFormatEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXT_PROC* glpfVertexArrayVertexAttribBindingEXT = NULL;
	PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXT_PROC* glpfVertexArrayVertexBindingDivisorEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXT_PROC* glpfVertexArrayVertexAttribLOffsetEXT = NULL;
	PFNGLTEXTUREPAGECOMMITMENTEXT_PROC* glpfTexturePageCommitmentEXT = NULL;
	PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXT_PROC* glpfVertexArrayVertexAttribDivisorEXT = NULL;

	/* GL_NV_bindless_multi_draw_indirect */

	PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNV_PROC* glpfMultiDrawArraysIndirectBindlessNV = NULL;
	PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNV_PROC* glpfMultiDrawElementsIndirectBindlessNV = NULL;

	/* GL_NV_command_list */

	PFNGLCREATESTATESNV_PROC* glpfCreateStatesNV = NULL;
	PFNGLDELETESTATESNV_PROC* glpfDeleteStatesNV = NULL;
	PFNGLISSTATENV_PROC* glpfIsStateNV = NULL;
	PFNGLSTATECAPTURENV_PROC* glpfStateCaptureNV = NULL;
	PFNGLGETCOMMANDHEADERNV_PROC* glpfGetCommandHeaderNV = NULL;
	PFNGLGETSTAGEINDEXNV_PROC* glpfGetStageIndexNV = NULL;
	PFNGLDRAWCOMMANDSNV_PROC* glpfDrawCommandsNV = NULL;
	PFNGLDRAWCOMMANDSADDRESSNV_PROC* glpfDrawCommandsAddressNV = NULL;
	PFNGLDRAWCOMMANDSSTATESNV_PROC* glpfDrawCommandsStatesNV = NULL;
	PFNGLDRAWCOMMANDSSTATESADDRESSNV_PROC* glpfDrawCommandsStatesAddressNV = NULL;
	PFNGLCREATECOMMANDLISTSNV_PROC* glpfCreateCommandListsNV = NULL;
	PFNGLDELETECOMMANDLISTSNV_PROC* glpfDeleteCommandListsNV = NULL;
	PFNGLISCOMMANDLISTNV_PROC* glpfIsCommandListNV = NULL;
	PFNGLLISTDRAWCOMMANDSSTATESCLIENTNV_PROC* glpfListDrawCommandsStatesClientNV = NULL;
	PFNGLCOMMANDLISTSEGMENTSNV_PROC* glpfCommandListSegmentsNV = NULL;
	PFNGLCOMPILECOMMANDLISTNV_PROC* glpfCompileCommandListNV = NULL;
	PFNGLCALLCOMMANDLISTNV_PROC* glpfCallCommandListNV = NULL;

	/* GL_NV_vertex_buffer_unified_memory */

	PFNGLBUFFERADDRESSRANGENV_PROC* glpfBufferAddressRangeNV = NULL;
	PFNGLVERTEXFORMATNV_PROC* glpfVertexFormatNV = NULL;
	PFNGLNORMALFORMATNV_PROC* glpfNormalFormatNV = NULL;
	PFNGLCOLORFORMATNV_PROC* glpfColorFormatNV = NULL;
	PFNGLINDEXFORMATNV_PROC* glpfIndexFormatNV = NULL;
	PFNGLTEXCOORDFORMATNV_PROC* glpfTexCoordFormatNV = NULL;
	PFNGLEDGEFLAGFORMATNV_PROC* glpfEdgeFlagFormatNV = NULL;
	PFNGLSECONDARYCOLORFORMATNV_PROC* glpfSecondaryColorFormatNV = NULL;
	PFNGLFOGCOORDFORMATNV_PROC* glpfFogCoordFormatNV = NULL;
	PFNGLVERTEXATTRIBFORMATNV_PROC* glpfVertexAttribFormatNV = NULL;
	PFNGLVERTEXATTRIBIFORMATNV_PROC* glpfVertexAttribIFormatNV = NULL;
	PFNGLGETINTEGERUI64I_VNV_PROC* glpfGetIntegerui64i_vNV = NULL;

	/* GL_NV_shader_buffer_load */

	PFNGLMAKEBUFFERRESIDENTNV_PROC* glpfMakeBufferResidentNV = NULL;
	PFNGLMAKEBUFFERNONRESIDENTNV_PROC* glpfMakeBufferNonResidentNV = NULL;
	PFNGLISBUFFERRESIDENTNV_PROC* glpfIsBufferResidentNV = NULL;
	PFNGLMAKENAMEDBUFFERRESIDENTNV_PROC* glpfMakeNamedBufferResidentNV = NULL;
	PFNGLMAKENAMEDBUFFERNONRESIDENTNV_PROC* glpfMakeNamedBufferNonResidentNV = NULL;
	PFNGLISNAMEDBUFFERRESIDENTNV_PROC* glpfIsNamedBufferResidentNV = NULL;
	PFNGLGETBUFFERPARAMETERUI64VNV_PROC* glpfGetBufferParameterui64vNV = NULL;
	PFNGLGETNAMEDBUFFERPARAMETERUI64VNV_PROC* glpfGetNamedBufferParameterui64vNV = NULL;
	PFNGLGETINTEGERUI64VNV_PROC* glpfGetIntegerui64vNV = NULL;
	PFNGLUNIFORMUI64NV_PROC* glpfUniformui64NV = NULL;
	PFNGLUNIFORMUI64VNV_PROC* glpfUniformui64vNV = NULL;
	PFNGLGETUNIFORMUI64VNV_PROC* glpfGetUniformui64vNV = NULL;
	PFNGLPROGRAMUNIFORMUI64NV_PROC* glpfProgramUniformui64NV = NULL;
	PFNGLPROGRAMUNIFORMUI64VNV_PROC* glpfProgramUniformui64vNV = NULL;



	static void add_extension(const char* extension)
	{
		if (strcmp("GL_ARB_bindless_texture", extension) == 0) {
			FLEXT_ARB_bindless_texture = GL_TRUE;
		}
		if (strcmp("GL_ARB_sparse_texture", extension) == 0) {
			FLEXT_ARB_sparse_texture = GL_TRUE;
		}
		if (strcmp("GL_ARB_indirect_parameters", extension) == 0) {
			FLEXT_ARB_indirect_parameters = GL_TRUE;
		}
		if (strcmp("GL_ARB_pipeline_statistics_query", extension) == 0) {
			FLEXT_ARB_pipeline_statistics_query = GL_TRUE;
		}
		if (strcmp("GL_ARB_texture_non_power_of_two", extension) == 0) {
			FLEXT_ARB_texture_non_power_of_two = GL_TRUE;
		}
		if (strcmp("GL_EXT_direct_state_access", extension) == 0) {
			FLEXT_EXT_direct_state_access = GL_TRUE;
		}
		if (strcmp("GL_EXT_texture_compression_s3tc", extension) == 0) {
			FLEXT_EXT_texture_compression_s3tc = GL_TRUE;
		}
		if (strcmp("GL_EXT_texture_sRGB", extension) == 0) {
			FLEXT_EXT_texture_sRGB = GL_TRUE;
		}
		if (strcmp("GL_ARB_shader_draw_parameters", extension) == 0) {
			FLEXT_ARB_shader_draw_parameters = GL_TRUE;
		}
		if (strcmp("GL_ARB_map_buffer_alignment", extension) == 0) {
			FLEXT_ARB_map_buffer_alignment = GL_TRUE;
		}
		if (strcmp("GL_NV_bindless_multi_draw_indirect", extension) == 0) {
			FLEXT_NV_bindless_multi_draw_indirect = GL_TRUE;
		}
		if (strcmp("GL_NVX_gpu_memory_info", extension) == 0) {
			FLEXT_NVX_gpu_memory_info = GL_TRUE;
		}
		if (strcmp("GL_NV_command_list", extension) == 0) {
			FLEXT_NV_command_list = GL_TRUE;
		}
		if (strcmp("GL_NV_uniform_buffer_unified_memory", extension) == 0) {
			FLEXT_NV_uniform_buffer_unified_memory = GL_TRUE;
		}
		if (strcmp("GL_NV_vertex_buffer_unified_memory", extension) == 0) {
			FLEXT_NV_vertex_buffer_unified_memory = GL_TRUE;
		}
		if (strcmp("GL_NV_shader_buffer_load", extension) == 0) {
			FLEXT_NV_shader_buffer_load = GL_TRUE;
		}
	}


	/* ------------------ get_proc from Slavomir Kaslev's gl3w ----------------- */

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>

	static HMODULE libgl;

	static void open_libgl(void)
	{
		libgl = LoadLibraryA("opengl32.dll");
	}

	static void close_libgl(void)
	{
		FreeLibrary(libgl);
	}

	static GLPROC get_proc(const char *proc)
	{
		GLPROC res;

		res = (GLPROC)wglGetProcAddress(proc);
		if (!res)
			res = (GLPROC)GetProcAddress(libgl, proc);
		return res;
	}
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#include <Carbon/Carbon.h>

	CFBundleRef bundle;
	CFURLRef bundleURL;

	static void open_libgl(void)
	{
		bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
			CFSTR("/System/Library/Frameworks/OpenGL.framework"),
			kCFURLPOSIXPathStyle, true);

		bundle = CFBundleCreate(kCFAllocatorDefault, bundleURL);
		assert(bundle != NULL);
	}

	static void close_libgl(void)
	{
		CFRelease(bundle);
		CFRelease(bundleURL);
	}

	static GLPROC get_proc(const char *proc)
	{
		GLPROC res;

		CFStringRef procname = CFStringCreateWithCString(kCFAllocatorDefault, proc,
			kCFStringEncodingASCII);
		res = CFBundleGetFunctionPointerForName(bundle, procname);
		CFRelease(procname);
		return res;
	}
#else
#include <dlfcn.h>
#include <GL/glx.h>

	static void *libgl;

	static void open_libgl(void)
	{
		libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
	}

	static void close_libgl(void)
	{
		dlclose(libgl);
	}

	static GLPROC get_proc(const char *proc)
	{
		GLPROC res;

		res = glXGetProcAddress((const GLubyte *)proc);
		if (!res)
			res = dlsym(libgl, proc);
		return res;
	}
#endif

#ifdef __cplusplus
}
#endif
