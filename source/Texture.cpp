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
#include <vxGL/Texture.h>
#include <vxGL/gl.h>
#include <cstdio>

namespace vx
{
	namespace gl
	{
		void getTextureFormat(TextureFormat textureFormat, u32 &format, u32 &internalFormat, bool* compressed)
		{
			format = 0;
			internalFormat = 0;
			*compressed = false;

			switch (textureFormat)
			{
			case TextureFormat::R8:
			{
				format = GL_RED;
				internalFormat = GL_R8;
			}break;
			case TextureFormat::R8S:
			{
				format = GL_RED;
				internalFormat = GL_R8_SNORM;
			}break;
			case TextureFormat::R16:
			{
				format = GL_RED;
				internalFormat = GL_R16;
			}break;
			case TextureFormat::R16S:
			{
				internalFormat = GL_R16_SNORM;
				format = GL_RED;
			}break;
			case TextureFormat::RG8:
			{
				internalFormat = GL_RGB8;
				format = GL_RG;
			}break;
			case TextureFormat::RG8S:
			{
				internalFormat = GL_RG8_SNORM;
				format = GL_RG;
			}break;
			case TextureFormat::RG16:
			{
				internalFormat = GL_RGB16;
				format = GL_RG;
			}break;
			case TextureFormat::RG16S:
			{
				internalFormat = GL_RGB16_SNORM;
				format = GL_RG;
			}break;
			case TextureFormat::RGB4:
			{
				internalFormat = GL_RGB4;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB5:
			{
				internalFormat = GL_RGB5;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB8:
			{
				internalFormat = GL_RGB8;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB8S:
			{
				internalFormat = GL_RGB8_SNORM;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB10:
			{
				internalFormat = GL_RGB10;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB12:
			{
				internalFormat = GL_RGB12;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB16S:
			{
				internalFormat = GL_RGB16_SNORM;
				format = GL_RGB;
			}break;
			case TextureFormat::RGBA2:
			{
				internalFormat = GL_RGBA2;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA4:
			{
				internalFormat = GL_RGBA4;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGB5A1:
			{
				internalFormat = GL_RGB5_A1;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA8:
			{
				internalFormat = GL_RGBA8;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA8S:
			{
				internalFormat = GL_RGBA8_SNORM;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGB10A2:
			{
				format = GL_RGB;
				internalFormat = GL_RGB10_A2;
			}break;
			case TextureFormat::RGB10A2UI:
			{
				format = GL_RGBA;
				internalFormat = GL_RGB10_A2UI;
			}break;
			case TextureFormat::RGBA12:
			{
				internalFormat = GL_RGBA12;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA16:
			{
				internalFormat = GL_RGBA16;
				format = GL_RGBA;
			}break;
			case TextureFormat::SRGB8:
			{
				format = GL_RGB;
				internalFormat = GL_SRGB8;
			}break;
			case TextureFormat::SRGBA8:
			{
				format = GL_RGBA;
				internalFormat = GL_SRGB8_ALPHA8;
			}break;
			case TextureFormat::RGB_DXT1:
			{
				format = GL_RGB;
				internalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
				*compressed = true;
			}break;
			case TextureFormat::RGBA_DXT1:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
				*compressed = true;
			}break;
			case TextureFormat::RGBA_DXT3:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
				*compressed = true;
			}break;
			case TextureFormat::RGBA_DXT5:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
				*compressed = true;
			}break;
			case TextureFormat::SRGB_DXT1:
			{
				format = GL_RGB;
				internalFormat = GL_COMPRESSED_SRGB_S3TC_DXT1_EXT;
				*compressed = true;
			}break;
			case TextureFormat::SRGBA_DXT1:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT;
				*compressed = true;
			}break;
			case TextureFormat::SRGBA_DXT3:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT;
				*compressed = true;
			}break;
			case TextureFormat::SRGBA_DXT5:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT;
				*compressed = true;
			}break;
			case TextureFormat::RGB_BC6UF:
			{
				format = GL_RGB;
				internalFormat = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT;
				*compressed = true;
			}break;
			case TextureFormat::RGB_BC6F:
			{
				format = GL_RGB;
				internalFormat = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;
				*compressed = true;
			}break;
			case TextureFormat::RGBA_BC7:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_RGBA_BPTC_UNORM;
				*compressed = true;
			}break;
			case TextureFormat::SRGBA_BC7:
			{
				format = GL_RGBA;
				internalFormat = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;
				*compressed = true;
			}break;
			case TextureFormat::R16F:
			{
				format = GL_RED;
				internalFormat = GL_R16F;
			}break;
			case TextureFormat::RG16F:
			{
				format = GL_RG;
				internalFormat = GL_RG16F;
			}break;
			case TextureFormat::RGB16F:
			{
				format = GL_RGB;
				internalFormat = GL_RGB16F;
			}break;
			case TextureFormat::RGBA16F:
			{
				format = GL_RGBA;
				internalFormat = GL_RGBA16F;
			}break;
			case TextureFormat::R32F:
			{
				format = GL_RED;
				internalFormat = GL_R32F;
			}break;
			case TextureFormat::RG32F:
			{
				format = GL_RG;
				internalFormat = GL_RG32F;
			}break;
			case TextureFormat::RGB32F:
			{
				format = GL_RGB;
				internalFormat = GL_RGB32F;
			}break;
			case TextureFormat::RGBA32F:
			{
				format = GL_RGBA;
				internalFormat = GL_RGBA32F;
			}break;
			case TextureFormat::R8I:
			{
				format = GL_RED;
				internalFormat = GL_R8I;
			}break;
			case TextureFormat::R8UI:
			{
				format = GL_RED;
				internalFormat = GL_R8UI;
			}break;
			case TextureFormat::R16I:
			{
				format = GL_RED;
				internalFormat = GL_R16I;
			}break;
			case TextureFormat::R16UI:
			{
				format = GL_RED;
				internalFormat = GL_R16UI;
			}break;
			case TextureFormat::R32I:
			{
				format = GL_RED;
				internalFormat = GL_R32I;
			}break;
			case TextureFormat::R32UI:
			{
				format = GL_RED;
				internalFormat = GL_R32UI;
			}break;
			case TextureFormat::RG8I:
			{
				internalFormat = GL_RG8I;
				format = GL_RG;
			}break;
			case TextureFormat::RG8UI:
			{
				internalFormat = GL_RG8UI;
				format = GL_RG;
			}break;
			case TextureFormat::RG16I:
			{
				internalFormat = GL_RG16I;
				format = GL_RG;
			}break;
			case TextureFormat::RG16UI:
			{
				internalFormat = GL_RG16UI;
				format = GL_RG;
			}break;
			case TextureFormat::RG32I:
			{
				internalFormat = GL_RG32I;
				format = GL_RG;
			}break;
			case TextureFormat::RG32UI:
			{
				internalFormat = GL_RG32UI;
				format = GL_RG;
			}break;
			case TextureFormat::RGB8I:
			{
				internalFormat = GL_RGB8I;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB8UI:
			{
				internalFormat = GL_RGB8UI;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB16I:
			{
				internalFormat = GL_RGB16I;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB16UI:
			{
				internalFormat = GL_RGB16UI;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB32I:
			{
				internalFormat = GL_RGB32I;
				format = GL_RGB;
			}break;
			case TextureFormat::RGB32UI:
			{
				internalFormat = GL_RGB32UI;
				format = GL_RGB;
			}break;
			case TextureFormat::RGBA8I:
			{
				internalFormat = GL_RGBA8I;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA8UI:
			{
				internalFormat = GL_RGBA8UI;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA16I:
			{
				internalFormat = GL_RGBA16I;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA16UI:
			{
				internalFormat = GL_RGBA16UI;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA32I:
			{
				internalFormat = GL_RGBA32I;
				format = GL_RGBA;
			}break;
			case TextureFormat::RGBA32UI:
			{
				internalFormat = GL_RGBA32UI;
				format = GL_RGBA;
			}break;
			case TextureFormat::DEPTH16:
			{
				internalFormat = GL_DEPTH_COMPONENT16;
				format = GL_DEPTH_COMPONENT;
			}break;
			case TextureFormat::DEPTH24:
			{
				internalFormat = GL_DEPTH_COMPONENT24;
				format = GL_DEPTH_COMPONENT;
			}break;
			case TextureFormat::DEPTH32:
			{
				internalFormat = GL_DEPTH_COMPONENT32;
				format = GL_DEPTH_COMPONENT;
			}break;
			case TextureFormat::DEPTH32F:
			{
				internalFormat = GL_DEPTH_COMPONENT32F;
				format = GL_DEPTH_COMPONENT;
			}break;
			default:
				VX_ASSERT(false);
				break;
			}
		}

		namespace detail
		{
			u32 getTarget(TextureType type)
			{
				auto target = 0u;
				switch (type)
				{
				case gl::TextureType::Texture_1D:
					target = GL_TEXTURE_1D;
					break;
				case gl::TextureType::Texture_2D:
					target = GL_TEXTURE_2D;
					break;
				case gl::TextureType::Texture_2D_MS:
					target = GL_TEXTURE_2D_MULTISAMPLE;
					break;
				case gl::TextureType::Texture_3D:
					target = GL_TEXTURE_3D;
					break;
				case gl::TextureType::Texture_Cubemap:
					target = GL_TEXTURE_CUBE_MAP;
					break;
				case gl::TextureType::Texture_Cubemap_Array:
					target = GL_TEXTURE_CUBE_MAP_ARRAY;
					break;
				case gl::TextureType::Texture_1D_Array:
					target = GL_TEXTURE_1D_ARRAY;
					break;
				case gl::TextureType::Texture_2D_Array:
					target = GL_TEXTURE_2D_ARRAY;
					break;
				case gl::TextureType::Texture_2D_MS_Array:
					target = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
					break;
				default:
					VX_ASSERT(false);
					break;
				}

				return target;
			}

			void subImage2D
				(
				u32 id,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 width,
				u32 height,
				u32 format,
				DataType dataType,
				const void *p
				)
			{
				auto type = (u32)dataType;//detail::getDataType(dataType);

				glTextureSubImage2D(id, level, xoffset, yoffset, width, height, format, type, p);
			}

			void subImage2D(
				u32 id,
				GLenum target,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 width,
				u32 height,
				u32 format,
				DataType dataType,
				const void *p
				)
			{
				auto type = (u32)dataType;//detail::getDataType(dataType);

				glBindTexture(target, id);
				glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, p);
				glBindTexture(target, 0);
			}

			void compressedSubImage2D
				(
				u32 id,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 width,
				u32 height,
				u32 format,
				u32 dataSize,
				const void *p
				)
			{
				glCompressedTextureSubImage2D(id, level, xoffset, yoffset, width, height, format, dataSize, p);
			}

			void compressedSubImage2D
				(
				u32 id,
				GLenum target,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 width,
				u32 height,
				u32 format,
				u32 dataSize,
				const void *p
				)
			{
				glBindTexture(target, id);
				glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, dataSize, p);
				glBindTexture(target, 0);
			}

			void subImage3D
				(
				u32 id,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 zoffset,
				u32 width,
				u32 height,
				u32 depth,
				u32 format,
				DataType dataType,
				const void *p
				)
			{
				auto type = (u32)dataType;//detail::getDataType(dataType);

				glTextureSubImage3D(id, level, xoffset, yoffset, zoffset, width, height, depth, format, type, p);
			}

			void compressedSubImage3D
				(
				u32 id,
				u32 level,
				u32 xoffset,
				u32 yoffset,
				u32 zoffset,
				u32 width,
				u32 height,
				u32 depth,
				u32 format,
				u32 dataSize,
				const void *p
				)
			{
				glCompressedTextureSubImage3D(id, level, xoffset, yoffset, zoffset, width, height, depth, format, dataSize, p);
			}
		}

		/*

		Texture

		*/

		Texture::Texture()
			:Base(),
			m_target(0),
			m_format(0),
			m_internalFormat(0),
			m_size(),
			m_formatData(),
			m_compressed(0)
		{
		}

		Texture::Texture(Texture &&rhs) noexcept
			: Base(std::move(rhs)),
			m_target(rhs.m_target),
			m_format(rhs.m_format),
			m_internalFormat(rhs.m_internalFormat),
			m_size(rhs.m_size),
			m_formatData(std::move(rhs.m_formatData)),
			m_compressed(rhs.m_compressed)
		{
		}

		Texture::~Texture()
		{
		}

		Texture& Texture::operator = (Texture &&rhs) noexcept
		{
			if (this != &rhs)
			{
				Base::operator=(std::move(rhs));

				m_target = rhs.m_target;
				m_format = rhs.m_format;
				m_internalFormat = rhs.m_internalFormat;
				m_size = rhs.m_size;
				m_formatData = rhs.m_formatData;
				m_compressed = rhs.m_compressed;
			}

			return *this;
		}

			void Texture::allocate1D(const TextureDescription &desc)
		{
			assert(desc.miplevels >= 1);
			assert(desc.size.x != 0);
			assert(m_internalFormat != 0);

			glTextureStorage1D(m_id, desc.miplevels, m_internalFormat, desc.size.x);
		}

		void Texture::allocate2D(const TextureDescription &desc)
		{
			assert(desc.miplevels >= 1);
			assert(desc.size.x != 0);
			assert(desc.size.y != 0);
			assert(m_internalFormat != 0);

			glTextureStorage2D(m_id, desc.miplevels, m_internalFormat, desc.size.x, desc.size.y);
		}

		void Texture::allocate2D_MS(const TextureDescription &desc)
		{
			assert(desc.samples != 0);
			assert(desc.size.x != 0);
			assert(desc.size.y != 0);
			assert(m_internalFormat != 0);

			glTextureStorage2DMultisample(m_id, desc.samples, m_internalFormat, desc.size.x, desc.size.y, desc.fixedsamplelocations);
		}

		void Texture::allocate3D(const TextureDescription &desc)
		{
			assert(desc.miplevels >= 1);
			assert(desc.size.x != 0);
			assert(desc.size.y != 0);
			assert(desc.size.z != 0);
			assert(m_internalFormat != 0);

			glTextureStorage3D(m_id, desc.miplevels, m_internalFormat, desc.size.x, desc.size.y, desc.size.z);
		}

		void Texture::create(const TextureDescription &desc)
		{
			if (m_id == 0)
			{
				m_target = ::vx::gl::detail::getTarget(desc.type);
				m_size = desc.size;

				bool compressed;
				getTextureFormat(desc.format, m_format, m_internalFormat, &compressed);

				m_compressed = (u8)compressed;

				glCreateTextures(m_target, 1, &m_id);

				if (desc.sparse == 1)
				{
					m_formatData.set<0>();

					glTextureParameteri(m_id, GL_TEXTURE_SPARSE_ARB, GL_TRUE);
				}

				switch (desc.type)
				{
				case gl::TextureType::Texture_2D:
					m_formatData.set<2>();
					allocate2D(desc);
					break;
				case gl::TextureType::Texture_2D_Array:
					m_formatData.set<2>();
					allocate3D(desc);
					break;
				case gl::TextureType::Texture_3D:
					m_formatData.set<3>();
					allocate3D(desc);
					break;
				case gl::TextureType::Texture_1D:
					m_formatData.set<1>();
					allocate1D(desc);
					break;
				case gl::TextureType::Texture_2D_MS:
					m_formatData.set<2>();
					allocate2D_MS(desc);
					break;
				case gl::TextureType::Texture_Cubemap:
					allocate2D(desc);
					m_formatData.set<2>();
					break;
				case gl::TextureType::Texture_Cubemap_Array:
					allocate3D(desc);
					m_formatData.set<3>();
					break;
				default:
					VX_ASSERT(false);
					break;
				}
			}
		}

		void Texture::destroy()
		{
			if (m_id != 0)
			{
				glDeleteTextures(1, &m_id);
				m_id = 0;
			}
		}

		void Texture::bind() const
		{
			glBindTexture(m_target, m_id);
		}

		void Texture::subImage(const TextureSubImageDescription &desc) const
		{
			bool compressed = isCompressed();
			VX_ASSERT(!compressed);

			switch (m_target)
			{
			case GL_TEXTURE_2D_ARRAY:
				vx::gl::detail::subImage3D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.offset.z, desc.size.x, desc.size.y, desc.size.z, m_format, desc.dataType, desc.p);
				break;
			case GL_TEXTURE_2D:
				vx::gl::detail::subImage2D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_format, desc.dataType, desc.p);
				break;
			case GL_TEXTURE_3D:
				vx::gl::detail::subImage3D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.offset.z, desc.size.x, desc.size.y, desc.size.z, m_format, desc.dataType, desc.p);
				break;
			case GL_TEXTURE_1D_ARRAY:
				vx::gl::detail::subImage2D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_format, desc.dataType, desc.p);
				break;
			case GL_TEXTURE_CUBE_MAP:
			{
				::vx::gl::detail::subImage2D(m_id, GL_TEXTURE_CUBE_MAP_POSITIVE_X + desc.offset.z, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_format, desc.dataType, desc.p);
			}break;
			default:
				VX_ASSERT(false);
				break;
			}
		}

		void Texture::subImageCompressed(const TextureCompressedSubImageDescription &desc) const
		{
			bool compressed = isCompressed();
			VX_ASSERT(compressed);

			switch (m_target)
			{
			case GL_TEXTURE_2D_ARRAY:
				vx::gl::detail::compressedSubImage3D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.offset.z, desc.size.x, desc.size.y, desc.size.z, m_internalFormat, desc.dataSize, desc.p);
				break;
			case GL_TEXTURE_2D:
				vx::gl::detail::compressedSubImage2D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_internalFormat, desc.dataSize, desc.p);
				break;
			case GL_TEXTURE_3D:
				vx::gl::detail::compressedSubImage3D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.offset.z, desc.size.x, desc.size.y, desc.size.z, m_internalFormat, desc.dataSize, desc.p);
				break;
			case GL_TEXTURE_1D_ARRAY:
				vx::gl::detail::compressedSubImage2D(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_internalFormat, desc.dataSize, desc.p);
				break;
			case GL_TEXTURE_CUBE_MAP:
			{
				::vx::gl::detail::compressedSubImage2D(m_id, GL_TEXTURE_CUBE_MAP_POSITIVE_X + desc.offset.z, desc.miplevel, desc.offset.x, desc.offset.y, desc.size.x, desc.size.y, m_internalFormat, desc.dataSize, desc.p);
			}break;
			default:
				VX_ASSERT(false);
				break;
			}

		}

		void Texture::commit(const TextureCommitDescription &desc) const
		{
			if (!isSparseTexture())
				return;
			glTexturePageCommitmentEXT(m_id, desc.miplevel, desc.offset.x, desc.offset.y, desc.offset.z, desc.size.x, desc.size.y, desc.size.z, desc.commit);
		}

		void Texture::setWrapMode1D(TextureWrapMode wrap_s) const
		{
			auto s = detail::getTextureWrapMode(wrap_s);
			glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, s);
		}

		void Texture::setWrapMode2D(TextureWrapMode wrap_s, TextureWrapMode wrap_t) const
		{
			setWrapMode1D(wrap_s);

			auto t = detail::getTextureWrapMode(wrap_t);
			glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, t);
		}

		void Texture::setWrapMode3D(TextureWrapMode wrap_s, TextureWrapMode wrap_t, TextureWrapMode wrap_r) const
		{
			setWrapMode2D(wrap_s, wrap_t);

			auto r = detail::getTextureWrapMode(wrap_r);
			glTextureParameteri(m_id, GL_TEXTURE_WRAP_R, r);
		}

		void Texture::setFilter(TextureFilter min, TextureFilter mag) const
		{
			auto minFilter = detail::getTextureFilter(min);
			auto magFilter = detail::getTextureFilter(mag);

			glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, minFilter);
			glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, magFilter);
		}

		void Texture::makeTextureResident() const
		{
			auto handle = getTextureHandle();
			glMakeTextureHandleResidentARB(handle);
		}

		void Texture::makeTextureNonResident() const
		{
			auto handle = getTextureHandle();
			glMakeTextureHandleNonResidentARB(handle);
		}

		void Texture::makeImageResident(u32 level, u8 layered, u32 layer, TextureAccess access) const
		{
			auto handle = getImageHandle(level, layered, layer);
			glMakeImageHandleResidentARB(handle, (u32)access);
		}

		void Texture::makeImageNonResident(u32 level, u8 layered, u32 layer) const
		{
			auto handle = getImageHandle(level, layered, layer);
			glMakeImageHandleNonResidentARB(handle);
		}

		void Texture::generateMipmaps() const
		{
			glGenerateTextureMipmap(m_id);
		}

		void Texture::clearImage(u32 level, u32 format, u32 type, const void* data) const
		{
			glClearTexImage(m_id, level, format, type, data);
		}

		u32 Texture::getId() const
		{
			return m_id;
		}

		u64 Texture::getTextureHandle() const
		{
			return glGetTextureHandleARB(m_id);
		}

		u64 Texture::getImageHandle(u32 level, u8 layered, u32 layer) const
		{
			return glGetImageHandleARB(m_id, level, layered, layer, m_internalFormat);
		}

		const vx::ushort3& Texture::getSize() const
		{
			return m_size;
		}

		u32 Texture::getTarget() const
		{
			return m_target;
		}

		bool Texture::isSparseTexture() const
		{
			return m_formatData.get<0>();
		}

		bool Texture::is1D() const
		{
			return m_formatData.get<1>();
		}

		bool Texture::is2D() const
		{
			return m_formatData.get<2>();
		}

		bool Texture::is3D() const
		{
			return m_formatData.get<3>();
		}

		bool Texture::isCompressed() const
		{
			return m_compressed != 0;
		}
	}
}