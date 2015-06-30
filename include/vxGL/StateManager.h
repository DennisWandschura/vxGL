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

#include <vxLib/math/Vector.h>
#include <vxLib/Container/bitset.h>
#include <vxGL/Base.h>

namespace vx
{
	namespace gl
	{
		class VertexArray;
		class ProgramPipeline;
		class Framebuffer;
		class Buffer;

		class StateManager
		{
			static const u32 s_bufferTypeCount = 15;

			static u32 s_currentFrameBuffer;
			static u32 s_currentPipeline;
			static u32 s_currentVao;
			static vx::ushort4 s_viewPort;
			static vx::bitset<32> s_currentCapabilities;
			static u32 s_bindBuffer[s_bufferTypeCount];
			static vx::float4 s_clearColor;
			static u8 s_colorMask;

			StateManager();

		public:
			static void enable(Capabilities cap);
			static void disable(Capabilities cap);
			static void setClearColor(f32 r, f32 g, f32 b, f32 a);
			static void setViewport(u32 x, u32 y, u32 width, u32 height);
			static void bindFrameBuffer(u32 id);
			static void bindFrameBuffer(const Framebuffer &fbo);
			static void bindVertexArray(u32 id);
			static void bindVertexArray(const VertexArray &vao);
			static void bindBuffer(BufferType target, u32 id);
			static void bindBuffer(BufferType target, const Buffer &buffer);
			static void bindPipeline(u32 pipeline);
			static void bindPipeline(const ProgramPipeline &pipe);
			static void setColorMask(bool r, bool g, bool b, bool a);
			static void setDepthMask(bool d);
		};
	}
}