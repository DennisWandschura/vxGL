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
#include <vxLib/math/Vector.h>
#include <vxLib/Container/bitset.h>

namespace vx
{
	namespace gl
	{
		enum class TextureType : u8
		{
			Texture_1D,
			Texture_2D,
			Texture_2D_MS,
			Texture_3D,
			Texture_Cubemap,
			Texture_Cubemap_Array,
			Texture_1D_Array,
			Texture_2D_Array,
			Texture_2D_MS_Array
		};

		enum class TextureFormat : u8
		{
			R8,
			R8S,
			R16,
			R16S,
			RG8,
			RG8S,
			RG16,
			RG16S,
			RGB4,
			RGB5,
			RGB8,
			RGB8S,
			RGB10,
			RGB12,
			RGB16S,
			RGBA2,
			RGBA4,
			RGB5A1,
			RGBA8,
			RGBA8S,
			RGB10A2,
			RGB10A2UI,
			RGBA12,
			RGBA16,
			SRGB8,
			SRGBA8,
			RGB_DXT1,
			RGBA_DXT1,
			RGBA_DXT3,
			RGBA_DXT5,
			SRGB_DXT1,
			SRGBA_DXT1,
			SRGBA_DXT3,
			SRGBA_DXT5,
			RGB_BC6UF,
			RGB_BC6F,
			RGBA_BC7,
			SRGBA_BC7,
			R16F,
			RG16F,
			RGB16F,
			RGBA16F,
			R32F,
			RG32F,
			RGB32F,
			RGBA32F,
			R8I,
			R8UI,
			R16I,
			R16UI,
			R32I,
			R32UI,
			RG8I,
			RG8UI,
			RG16I,
			RG16UI,
			RG32I,
			RG32UI,
			RGB8I,
			RGB8UI,
			RGB16I,
			RGB16UI,
			RGB32I,
			RGB32UI,
			RGBA8I,
			RGBA8UI,
			RGBA16I,
			RGBA16UI,
			RGBA32I,
			RGBA32UI,
			DEPTH16,
			DEPTH24,
			DEPTH32,
			DEPTH32F
		};

		enum class TextureAccess : u32
		{
			Read = 0x88B8,
			Write = 0x88B9,
			Read_Write = 0x88BA
		};

		struct TextureDescription
		{
			vx::ushort3 size;
			union
			{
				u16 miplevels;
				u16 samples; // only used by multisample
			};

			TextureType type;
			TextureFormat format;
			u8 fixedsamplelocations; // only used by multisample
			u8 sparse; // if sparse textures are supported

			TextureDescription() :size(), miplevels(0), type((gl::TextureType)0), format((gl::TextureFormat)0), fixedsamplelocations(0), sparse(0){}
		};

		struct TextureCommitDescription
		{
			u32 miplevel;
			vx::uint3 offset;
			vx::uint3 size;
			u8 commit;
		};

		struct TextureSubImageDescription
		{
			u32 miplevel;
			vx::uint3 offset;
			vx::uint3 size;
			vx::gl::DataType dataType;
			const void *p;
		};

		struct TextureCompressedSubImageDescription
		{
			u32 miplevel;
			vx::uint3 offset;
			vx::uint3 size;
			u32 dataSize;
			const void *p;
		};

		class Texture : public Base < Texture >
		{
			u32 m_target;
			u32 m_format;
			u32 m_internalFormat;
			vx::ushort3 m_size;
			vx::bitset<4> m_formatData; // 1. bit sparse, 2. bit 1d, 3. bit 2d, 4. bit 3d
			u8 m_compressed;

			void allocate1D(const TextureDescription &desc);
			void allocate2D(const TextureDescription &desc);
			void allocate2D_MS(const TextureDescription &desc);
			void allocate3D(const TextureDescription &desc);

		public:
			Texture();

			Texture(const Texture&) = delete;
			Texture(Texture &&rhs) noexcept;

			~Texture();

			Texture& operator=(const Texture&) = delete;
			Texture& operator=(Texture &&rhs) noexcept;

			void create(const TextureDescription &desc);
			void destroy();

			void bind() const;

			// only used by sparse textures
			void commit(const TextureCommitDescription &desc) const;

			void subImage(const TextureSubImageDescription &desc) const;
			void subImageCompressed(const TextureCompressedSubImageDescription &desc) const;

			void setWrapMode1D(TextureWrapMode wrap_s) const;
			void setWrapMode2D(TextureWrapMode wrap_s, TextureWrapMode wrap_t) const;
			void setWrapMode3D(TextureWrapMode wrap_s, TextureWrapMode wrap_t, TextureWrapMode wrap_r) const;
			void setFilter(TextureFilter min, TextureFilter mag) const;
			void makeTextureResident() const;
			void makeTextureNonResident() const;
			void makeImageResident(u32 level, u8 layered, u32 layer, TextureAccess access) const;
			void makeImageNonResident(u32 level, u8 layered, u32 layer) const;
			void generateMipmaps() const;
			void clearImage(u32 level, u32 format, u32 type, const void* data) const;

			u32 getId() const;
			u64 getTextureHandle() const;
			u64 getImageHandle(u32 level, u8 layered, u32 layer) const;
			const vx::ushort3& getSize() const;
			u32 getTarget() const;

			bool isSparseTexture() const;
			bool is1D() const;
			bool is2D() const;
			bool is3D() const;
			bool isCompressed() const;
		};
	}
}