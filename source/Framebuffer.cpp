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

#include <vxGL/Framebuffer.h>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		Framebuffer::Framebuffer()
			:Base()
		{
		}

		Framebuffer::Framebuffer(Framebuffer &&rhs) noexcept
			: Base(std::move(rhs))
		{
		}

		Framebuffer& Framebuffer::operator = (Framebuffer &&rhs) noexcept
		{
			Base::operator=(std::move(rhs));
			return *this;
		}

			void Framebuffer::create()
		{
			if (m_id == 0)
			{
				glCreateFramebuffers(1, &m_id);
			}
		}

		void  Framebuffer::destroy()
		{
			if (m_id != 0)
			{
				glDeleteFramebuffers(1, &m_id);
				m_id = 0;
			}
		}

		u32 Framebuffer::checkStatus() const
		{
			return glCheckNamedFramebufferStatus(m_id, GL_FRAMEBUFFER);
		}

		void Framebuffer::bind() const
		{
			glBindFramebuffer(GL_FRAMEBUFFER, m_id);
		}

		void Framebuffer::bindZero() const
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		void Framebuffer::attachTexture(Attachment attachment, u32 textureId, u32 level) const
		{
			glNamedFramebufferTexture(m_id, (u32)attachment, textureId, level);
		}

		void Framebuffer::attachTextureLayer(Attachment attachment, u32 textureId, u32 level, u32 layer) const
		{
			glNamedFramebufferTextureLayer(m_id, (u32)attachment, textureId, level, layer);
		}

		void Framebuffer::drawBuffer(const Attachment attachment) const
		{
			glNamedFramebufferDrawBuffer(m_id, (u32)attachment);
		}

		void Framebuffer::drawBuffers(const Attachment* attachments, u32 count) const
		{
			glNamedFramebufferDrawBuffers(m_id, count, (const u32*)attachments);
		}
	}
}