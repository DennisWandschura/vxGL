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

#include <vxGL/Base.h>

namespace vx
{
	namespace gl
	{
		class VertexArray : public Base < VertexArray >
		{
			using MyBase = Base < VertexArray >;

		public:
			VertexArray();
			VertexArray(VertexArray &&rhs);

			~VertexArray();

			VertexArray& operator=(VertexArray &&rhs);

			void create();

			void destroy();

			void bind() const;

			void bindZero() const;

			void enableArrayAttrib(u32 index) const;
			void arrayAttribBinding(u32 attribIndex, u32 bindingIndex) const;
			void arrayAttribFormatI(u32 attribIndex, u32 size, DataType type, u32 relativeOffset) const;
			void arrayAttribFormatF(u32 attribIndex, u32 size, u8 normalized, u32 relativeOffset) const;
			void arrayBindingDivisor(u32 bindingIndex, u32 divisor) const;

			template<typename IBO>
			void bindIndexBuffer(const IBO &ibo) const
			{
				bindIndexBuffer(ibo.getId());
			}

			void bindIndexBuffer(u32 ibo) const;

			template<typename VBO>
			void bindVertexBuffer(const VBO &vbo, u32 bindingIndex, size_t offset, size_t stride) const
			{
				bindVertexBuffer(vbo.getId(), bindingIndex, offset, stride);
			}

			void bindVertexBuffer(u32 vbo, u32 bindingIndex, size_t offset, size_t stride) const;
		};
	}
}