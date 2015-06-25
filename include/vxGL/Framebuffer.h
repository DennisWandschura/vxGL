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
		enum class Attachment : u32
		{
			Color0 = 0x8CE0,
			Color1 = 0x8CE1,
			Color2 = 0x8CE2,
			Color3 = 0x8CE3,
			Color4 = 0x8CE4,
			Color5 = 0x8CE5,
			Color6 = 0x8CE6,
			Color7 = 0x8CE7,
			Color8 = 0x8CE8,
			Color9 = 0x8CE9,
			Color10 = 0x8CEA,
			Color11 = 0x8CEB,
			Color12 = 0x8CEC,
			Color13 = 0x8CED,
			Color14 = 0x8CEE,
			Color15 = 0x8CEF,
			Depth = 0x8D00,
			Stencil = 0x8D20,
			Depth_Stencil = 0x821A
		};

		class Framebuffer : public Base < Framebuffer >
		{
		public:
			Framebuffer();
			Framebuffer(const Framebuffer&) = delete;
			Framebuffer(Framebuffer &&rhs) noexcept;

			Framebuffer& operator=(const Framebuffer&) = delete;
			Framebuffer& operator=(Framebuffer &&rhs) noexcept;

			void create();
			void destroy();

			u32 checkStatus() const;

			void bind() const;
			void bindZero() const;

			void attachTexture(Attachment attachment, u32 textureId, u32 level) const;
			void attachTextureLayer(Attachment attachment, u32 textureId, u32 level, u32 layer) const;

			template<class Texture>
			void attachTexture(Attachment attachment, const Texture &texture, u32 level) const
			{
				attachTexture(attachment, texture.getId(), level);
			}

			template<class Texture>
			void attachTextureLayer(Attachment attachment, const Texture &texture, u32 level, u32 layer) const
			{
				attachTextureLayer(attachment, texture.getId(), level, layer);
			}

			void drawBuffer(const Attachment attachment) const;
			void drawBuffers(const Attachment* attachments, u32 count) const;
		};
	}
}