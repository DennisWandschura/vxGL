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
#include <vxGL/VertexArray.h>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		VertexArray::VertexArray():MyBase(){}

		VertexArray::VertexArray(VertexArray &&rhs)
			: MyBase(std::move(rhs))
		{
		}

		VertexArray::~VertexArray()
		{
		}

		VertexArray& VertexArray::operator=(VertexArray &&rhs)
		{
			MyBase::operator=(std::move(rhs));
			return *this;
		}

		void VertexArray::create()
		{
			if (m_id == 0)
			{
				glCreateVertexArrays(1, &m_id);
			}
		}

		void VertexArray::destroy()
		{
			if (m_id != 0)
			{
				glBindVertexArray(0);
				glDeleteVertexArrays(1, &m_id);
			}
		}

		void VertexArray::bind() const
		{
			glBindVertexArray(getId());
		}

		void VertexArray::bindZero() const
		{
			glBindVertexArray(0);
		}

		void VertexArray::enableArrayAttrib(u32 index) const
		{
			glEnableVertexArrayAttrib(getId(), index);
		}

		void VertexArray::arrayAttribBinding(u32 attribIndex, u32 bindingIndex) const
		{
			glVertexArrayAttribBinding(getId(), attribIndex, bindingIndex);
		}

		void VertexArray::arrayAttribFormatI(u32 attribIndex, u32 size, DataType dataType, u32 relativeOffset) const
		{
			VX_ASSERT(dataType != DataType::Float);
			auto type = (u32)dataType;//detail::getDataType(dataType);

			glVertexArrayAttribIFormat(getId(), attribIndex, size, type, relativeOffset);
		}

		void VertexArray::arrayAttribFormatF(u32 attribIndex, u32 size, u8 normalized, u32 relativeOffset) const
		{
			glVertexArrayAttribFormat(getId(), attribIndex, size, GL_FLOAT, normalized, relativeOffset);
		}

		void VertexArray::arrayBindingDivisor(u32 bindingIndex, u32 divisor) const
		{
			glVertexArrayBindingDivisor(getId(), bindingIndex, divisor);
		}

		void VertexArray::bindIndexBuffer(u32 ibo) const
		{
			glVertexArrayElementBuffer(getId(), ibo);
		}

		void VertexArray::bindVertexBuffer(u32 vbo, u32 bindingIndex, size_t offset, size_t stride) const
		{
			glVertexArrayVertexBuffer(getId(), bindingIndex, vbo, offset, stride);
		}
	}
}