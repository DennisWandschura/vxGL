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
#include <memory>

namespace vx
{
	namespace gl
	{
		enum class Map
		{
			Read_Only = 0x88B8,
			Write_Only = 0x88B9,
			Read_Write = 0x88BA
		};

		struct MapRange
		{
			enum _Access : u32
			{
				_Mask = 0
			};

			typedef u32 Access;

			static const _Access Read = (_Access)0x0001;
			static const _Access Write = (_Access)0x0002;
			static const _Access Invalidate_Range = (_Access)0x0004;
			static const _Access Invalidate_Buffer = (_Access)0x0008;
			static const _Access Flush_Explicit = (_Access)0x0010;
			static const _Access Unsyncronized = (_Access)0x0020;
			static const _Access Persistend = (_Access)0x0040;
			static const _Access Coherent = (_Access)0x0080;
		};

		struct BufferStorageFlags
		{
			enum _Flags : u32
			{
				_Mask = 0xFFFF
			};

			typedef u32 Flags;

			static const _Flags None = (_Flags)0x0000;
			static const _Flags Dynamic_Storage = (_Flags)0x0100;
			static const _Flags Read = (_Flags)0x0001;
			static const _Flags Write = (_Flags)0x0002;
			static const _Flags Persistent = (_Flags)0x0040;
			static const _Flags Coherent = (_Flags)0x0080;
			static const _Flags Client_Storage = (_Flags)0x0200;
		};

		enum class BufferDataUsage : u32
		{
			None = 0,
			Stream_Draw = 0x88E0,
			Stream_Read = 0x88E1,
			Stream_Copy = 0x88E2,
			Static_Draw = 0x88E4,
			Static_Read = 0x88E5,
			Static_Copy = 0x88E6,
			Dynamic_Draw = 0x88E8,
			Dynamic_Read = 0x88E9,
			Dynamic_Copy = 0x88EA
		};

		class Buffer;

		struct BufferDescription
		{
			const void *pData{nullptr};
			ptrdiff_t size{0};
			union
			{
				// immutable
				BufferStorageFlags::Flags flags;
				// mutable
				BufferDataUsage usage;
			};
			BufferType bufferType{};
			u8 immutable{1};

			BufferDescription() :flags(BufferStorageFlags::None) {}

			static Buffer createImmutable(BufferType type, ptrdiff_t size, BufferStorageFlags::Flags flags, const void* data);
			static Buffer createMutable(BufferType type, ptrdiff_t size, BufferDataUsage usage, const void* data);
		};

		namespace detail
		{
			class BufferInterface
			{
			public:
				static bool create(const BufferDescription &desc, u32 &id);
				static void destroy(u32 &id);

				static void bind(u32 id, BufferType type);
				static u32 getTarget(BufferType type);
				static void* map(u32 id, Map access);
				static void* mapRange(u32 id, u32 offsetBytes, u32 sizeBytes, MapRange::Access access);
				static void unmap(u32 id);
			};
		}

		template<typename T, typename B>
		class MappedBuffer
		{
			typedef B _MyBuffer;
			typedef T value_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;

			pointer m_ptr;
			const _MyBuffer* m_buffer;

		public:
			MappedBuffer(const _MyBuffer* buffer, void* ptr) :m_ptr(reinterpret_cast<pointer>(ptr)), m_buffer(buffer){}
			MappedBuffer(const MappedBuffer&) = delete;
			MappedBuffer(MappedBuffer &&rhs)
				:m_ptr(rhs.m_ptr),
				m_buffer(rhs.m_buffer)
			{}

			~MappedBuffer()
			{
				unmap();
			}

			MappedBuffer& operator=(const MappedBuffer&) = delete;
			MappedBuffer& operator=(MappedBuffer &&rhs)
			{
				if (this != &rhs)
				{
					std::swap(m_ptr, rhs.m_ptr);
					std::swap(m_buffer, rhs.m_buffer);
				}
				return *this;
			}

			pointer get()
			{
				return m_ptr;
			}

			const pointer get() const
			{
				return m_ptr;
			}

			pointer operator->()
			{
				return m_ptr;
			}

			const pointer operator->() const
			{
				return m_ptr;
			}

			reference operator*()
			{
				return *m_ptr;
			}

			const_reference operator*() const
			{
				return *m_ptr;
			}

			reference operator[](u32 i)
			{
				return m_ptr[i];
			}

			const_reference operator[](u32 i) const
			{
				return m_ptr[i];
			}

			void unmap()
			{
				if (m_ptr)
				{
					m_buffer->unmap();
					m_buffer = nullptr;
					m_ptr = nullptr;
				}
			}

			bool isValid() const
			{
				return m_ptr != nullptr;
			}
		};

		class Buffer : public Base<Buffer>
		{
			template<typename T, typename B>
			friend class MappedBuffer;
			// contains the opengl enum in first 24 bits, and BufferType enum in last 8 bits
			u32 m_target;

			void* map(Map access) const;
			void* mapRange(u32 offsetBytes, u32 sizeBytes, MapRange::Access access) const;
			void unmap() const;

		public:
			Buffer();
			Buffer(const Buffer&) = delete;
			Buffer(Buffer &&rhs);

			Buffer& operator=(const Buffer&) = delete;
			Buffer& operator=(Buffer &&rhs);

			void create(const BufferDescription &desc);
			void destroy();

			void bind() const;

			template<typename T>
			MappedBuffer<T, Buffer> map(Map access) const
			{
				void* ptr = map(access);
				return MappedBuffer<T, Buffer>(this, ptr);
			}

			template<typename T>
			MappedBuffer<T, Buffer> mapRange(u32 offsetBytes, u32 sizeBytes, MapRange::Access access) const
			{
				void* ptr = mapRange(offsetBytes, sizeBytes, access);
				return MappedBuffer<T, Buffer>(this, ptr);
			}

			void subData(s64 offset, s64 size, const void* data) const;

			u32 getTarget() const noexcept;
			BufferType getType() const noexcept;
		};
	}
}