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

#include <vxGL/Base.h>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		namespace detail
		{
			const u32 g_capabilities[28] = { GL_BLEND, GL_COLOR_LOGIC_OP, GL_CULL_FACE, GL_DEBUG_OUTPUT, GL_DEBUG_OUTPUT_SYNCHRONOUS, GL_DEPTH_CLAMP,
				GL_DEPTH_TEST, GL_DITHER, GL_FRAMEBUFFER_SRGB, GL_LINE_SMOOTH, GL_MULTISAMPLE, GL_POLYGON_OFFSET_FILL, GL_POLYGON_OFFSET_LINE,
				GL_POLYGON_OFFSET_POINT, GL_POLYGON_SMOOTH, GL_PRIMITIVE_RESTART, GL_PRIMITIVE_RESTART_FIXED_INDEX, GL_RASTERIZER_DISCARD,
				GL_SAMPLE_ALPHA_TO_COVERAGE, GL_SAMPLE_ALPHA_TO_ONE, GL_SAMPLE_COVERAGE, GL_SAMPLE_SHADING, GL_SAMPLE_MASK, GL_SCISSOR_TEST,
				GL_STENCIL_TEST, GL_TEXTURE_CUBE_MAP_SEAMLESS, GL_PROGRAM_POINT_SIZE,
			GL_CONSERVATIVE_RASTERIZATION_NV };

			const u32 g_dataTypes[] =
			{
				GL_BYTE ,
				GL_UNSIGNED_BYTE ,
				GL_SHORT ,
				GL_UNSIGNED_SHORT ,
				GL_INT,
				GL_UNSIGNED_INT,
				GL_FLOAT
			};

			const u32 g_shaderProgramTypes[6] =
			{
				GL_VERTEX_SHADER,
				GL_GEOMETRY_SHADER,
				GL_COMPUTE_SHADER,
				GL_FRAGMENT_SHADER,
				GL_TESS_CONTROL_SHADER,
				GL_TESS_EVALUATION_SHADER
			};

			const u32 g_textureFilters[3] =
			{
				GL_NEAREST, GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR
			};

			const u32 g_textureWrapModes[5] =
			{
				GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT, GL_REPEAT, GL_MIRROR_CLAMP_TO_EDGE
			};

			u32 getCapability(Capabilities cap)
			{
				return detail::g_capabilities[(u32)cap];
			}

			u32 getShaderProgramType(ShaderProgramType type)
			{
				return detail::g_shaderProgramTypes[(u32)type];
			}

			/*u32 getDataType(DataType dataType)
			{
				return g_dataTypes[(u32)dataType];
			}*/

			u32 getTextureFilter(TextureFilter filter)
			{
				return detail::g_textureFilters[(u32)filter];
			}

			u32 getTextureWrapMode(TextureWrapMode wrapMode)
			{
				return g_textureWrapModes[(u32)wrapMode];
			}
		}
	}
}