#pragma once
/*
The MIT License (MIT)

Copyright (c) 2015 Dennis Wandschura

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <vxLib/types.h>
#include <algorithm>

namespace vx
{
	namespace gl
	{
		enum class DataType : u32
		{
			Byte = 0x1400,
			Unsigned_Byte = 0x1401,
			Short = 0x1402,
			Unsigned_Short = 0x1403,
			Int = 0x1404,
			Unsigned_Int = 0x1405,
			Float = 0x1406
		};

		enum class PrimitveType : u32
		{
			Points = 0x0000,
			LINES = 0x0001,
			Line_Loop = 0x0002,
			Line_Strip = 0x0003,
			Triangles = 0x0004,
			Triangle_Strip = 0x0005,
			Triangle_Fan = 0x0006
		};

		enum class Capabilities : u8
		{
			Blend,
			Color_Logic_Op,
			Cull_Face,
			Debug_Output,
			Debug_Output_Syncronous,
			Depth_Clamp,
			Depth_Test,
			Dither,
			Framebuffer_sRGB,
			Line_Smooth,
			Multisample,
			Polygon_Offset_Fill,
			Polygon_Offset_Line,
			Polygon_Offset_Point,
			Polygon_Smooth,
			Primitive_Restart,
			Primitive_Restart_Fixed_Index,
			Rasterizer_Discard,
			Sample_Alpha_To_Coverage,
			Sample_Alpha_To_One,
			Sample_Coverage,
			Sample_Shading,
			Sample_Mask,
			Scissor_Test,
			Stencil_Test,
			Texture_Cube_Map_Seamless,
			Program_Point_Size
		};

		enum class ShaderProgramType : u8
		{
			VERTEX,
			GEOMETRY,
			COMPUTE,
			FRAGMENT,
			TESS_CONTROL,
			TESS_EVAL
		};

		enum class BufferType : u8
		{
			Array_Buffer,
			Atomic_Counter_Buffer,
			Copy_Read_Buffer,
			Copy_Write_Buffer,
			Draw_Indirect_Buffer,
			Dispatch_Indirect_Buffer,
			Element_Array_Buffer,
			Pixel_Pack_Buffer,
			Pixel_Unpack_Buffer,
			Query_Buffer,
			Shader_Storage_Buffer,
			Texture_Buffer,
			Transform_Feedback_Buffer,
			Uniform_Buffer,
			Parameter_Buffer
		};

		enum class TextureFilter : u8
		{
			NEAREST,
			LINEAR,
			LINEAR_MIPMAP_LINEAR
		};

		enum class TextureWrapMode : u8
		{
			CLAMP_TO_EDGE,
			CLAMP_TO_BORDER,
			MIRRORED_REPEAT,
			REPEAT,
			MIRROR_CLAMP_TO_EDGE
		};

		enum ClearBufferBit
		{
			ClearBufferBit_Depth = 0x00000100,
			ClearBufferBit_Stencil = 0x00000400,
			ClearBufferBit_Color = 0x00004000
		};

		struct DrawElementsIndirectCommand
		{
			u32  count;
			u32  instanceCount;
			u32  firstIndex;
			u32  baseVertex;
			u32  baseInstance;
		};

		typedef  struct {
			u32  count;
			u32  instanceCount;
			u32  first;
			u32  baseInstance;
		} DrawArraysIndirectCommand;

		namespace detail
		{
			u32 getCapability(Capabilities cap);
			u32 getShaderProgramType(ShaderProgramType type);
			u32 getTextureFilter(TextureFilter filter);
			u32 getTextureWrapMode(TextureWrapMode wrapMode);
		}

		template<class T>
		class Base
		{
		protected:
			u32 m_id;

			inline Base() noexcept :m_id(0) {}

			inline ~Base()
			{
				static_cast<T*>(this)->destroy();
			}

		public:
			Base(const Base&) = delete;

			Base(Base &&rhs) noexcept
				:m_id(rhs.m_id)
			{
				rhs.m_id = 0;
			}

			Base& operator=(const Base&) = delete;

			Base& operator = (Base &&rhs) noexcept
			{
				if (this != &rhs)
				{
					this->swap(rhs);
				}

				return *this;
			}

			void swap(Base &rhs) noexcept
			{
				std::swap(m_id, rhs.m_id);
			}

			bool isValid() const
			{
				return m_id != 0;
			}

			inline u32 getId() const noexcept
			{
				return m_id;
			}
		};
	}
}