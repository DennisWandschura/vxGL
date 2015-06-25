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

#include <vxGL/Buffer.h>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		namespace detail
		{
			const u32 g_bufferTypes[15] = 
			{
				GL_ARRAY_BUFFER,
				GL_ATOMIC_COUNTER_BUFFER,
				GL_COPY_READ_BUFFER,
				GL_COPY_WRITE_BUFFER,
				GL_DRAW_INDIRECT_BUFFER,
				GL_DISPATCH_INDIRECT_BUFFER,
				GL_ELEMENT_ARRAY_BUFFER,
				GL_PIXEL_PACK_BUFFER,
				GL_PIXEL_UNPACK_BUFFER,
				GL_QUERY_BUFFER,
				GL_SHADER_STORAGE_BUFFER,
				GL_TEXTURE_BUFFER,
				GL_TRANSFORM_FEEDBACK_BUFFER,
				GL_UNIFORM_BUFFER,
				GL_PARAMETER_BUFFER_ARB
			};

			inline u32 getBufferType(BufferType type)
			{
				return g_bufferTypes[(u32)type];
			}

			bool BufferInterface::create(const BufferDescription &desc, u32 &id)
			{
				if (id == 0)
				{
					glCreateBuffers(1, &id);

					if (id == 0)
						return false;
					if (desc.immutable == 0)
					{
						glNamedBufferData(id, desc.size, desc.pData, (u32)desc.usage);
					}
					else
					{
						glNamedBufferStorage(id, desc.size, desc.pData, (u32)desc.flags);
					}

					return true;
				}

				return false;
			}

			void BufferInterface::destroy(u32 &id)
			{
				if (id != 0)
				{
					glDeleteBuffers(1, &id);
					id = 0;
				}
			}

			void BufferInterface::bind(u32 id, BufferType type)
			{
				glBindBuffer(getBufferType(type), id);
			}

			u32 BufferInterface::getTarget(BufferType type)
			{
				return getBufferType(type);
			}

			void* BufferInterface::map(u32 id, Map access)
			{
				return glMapNamedBuffer(id, (u32)access);
			}

			void* BufferInterface::mapRange(u32 id, u32 offsetBytes, u32 sizeBytes, MapRange::Access access)
			{
				return glMapNamedBufferRange(id, offsetBytes, sizeBytes, (u32)access);
			}

			void BufferInterface::unmap(u32 id)
			{
				glUnmapNamedBuffer(id);
			}
		}

		Buffer BufferDescription::createImmutable(BufferType type, ptrdiff_t size, BufferStorageFlags::Flags flags, const void* data)
		{
			BufferDescription desc;
			desc.bufferType = type;
			desc.size = size;
			desc.flags = flags;
			desc.pData = data;
			desc.immutable = 1;

			Buffer b;
			b.create(desc);

			return b;
		}

		Buffer BufferDescription::createMutable(BufferType type, ptrdiff_t size, BufferDataUsage usage, const void* data)
		{
			BufferDescription desc;
			desc.bufferType = type;
			desc.size = size;
			desc.usage = usage;
			desc.pData = data;
			desc.immutable = 0;

			Buffer b;
			b.create(desc);

			return b;
		}

		Buffer::Buffer()
			:Base(),
			m_target(0)
		{
		}

		Buffer::Buffer(Buffer &&rhs)
			: Base(std::move(rhs)),
			m_target(rhs.m_target)
		{

		}

		Buffer& Buffer::operator = (Buffer &&rhs)
		{
			if (this != &rhs)
			{
				Base::operator=(std::move(rhs));
				std::swap(m_target, rhs.m_target);
			}
			return *this;
		}

		void Buffer::create(const BufferDescription &desc)
		{
			if (m_id == 0)
			{
				auto target = ::vx::gl::detail::getBufferType(desc.bufferType);
				m_target = target | ((u8)desc.bufferType >> 24);
				detail::BufferInterface::create(desc, m_id);
			}
		}

		void Buffer::destroy()
		{
			return detail::BufferInterface::destroy(m_id);
		}

		void Buffer::bind() const
		{
			glBindBuffer((m_target & 0x00FFFFFF), m_id);
		}

		void* Buffer::map(Map access) const
		{
			VX_ASSERT(getType() != BufferType::Parameter_Buffer);
			auto ptr = detail::BufferInterface::map(m_id, access);
			return ptr;
		}

		void* Buffer::mapRange(u32 offsetBytes, u32 sizeBytes, MapRange::Access access) const
		{
			VX_ASSERT(getType() != BufferType::Parameter_Buffer);
			auto ptr = detail::BufferInterface::mapRange(m_id, offsetBytes, sizeBytes, access);
			return ptr;
		}

		void Buffer::unmap() const
		{
			detail::BufferInterface::unmap(m_id);
		}

		void Buffer::subData(s64 offset, s64 size, const void* data) const
		{
			glNamedBufferSubData(m_id, offset, size, data);
		}

		u32 Buffer::getTarget() const noexcept
		{
			return (m_target & 0x00FFFFFF);
		}

		BufferType Buffer::getType() const noexcept
		{
			return BufferType((m_target >> 24));
		}
	}
}
