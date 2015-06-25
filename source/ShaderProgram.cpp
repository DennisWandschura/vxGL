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
#include <vxGL/ShaderProgram.h>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		ShaderProgram::ShaderProgram(ShaderProgramType type)
			:Base(),
			m_type(type)
		{
		}

		ShaderProgram::ShaderProgram(ShaderProgram &&rhs) noexcept
			: Base(std::move(rhs)),
			m_type(rhs.m_type)
		{
		}

		ShaderProgram::~ShaderProgram()
		{
			destroy();
		}

		ShaderProgram& ShaderProgram::operator = (ShaderProgram &&rhs) noexcept
		{
			if (this != &rhs)
			{
				MyBase::operator=(std::move(rhs));
				std::swap(m_type, rhs.m_type);
			}

			return *this;
		}

		bool ShaderProgram::checkLinkStatus()
		{
			int bDidLink;
			glGetProgramiv(m_id, GL_LINK_STATUS, &bDidLink);

			return (bDidLink == GL_TRUE);
		}

		bool ShaderProgram::checkValidateStatuts()
		{
			glValidateProgram(m_id);
			int isValid;
			glGetProgramiv(m_id, GL_VALIDATE_STATUS, &isValid);

			return (isValid == GL_TRUE);
		}

		std::unique_ptr<char[]> ShaderProgram::getProgramInfoLog(int *pLength)
		{
			glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, pLength);

			std::unique_ptr<char[]> log;

			if (*pLength != 0)
			{
				log = std::unique_ptr<char[]>(new char[*pLength]);
				glGetProgramInfoLog(m_id, (*pLength), 0, log.get());
			}

			return log;
		}

		std::unique_ptr<char[]> ShaderProgram::create(const char **program, s32 &logLength)
		{
			std::unique_ptr<char[]> log;

			if (m_id == 0)
			{
				auto type = detail::getShaderProgramType(m_type);
				m_id = glCreateShaderProgramv(type, 1, program);
				if (m_id == 0)
					return log;

				if (!checkLinkStatus() || !checkValidateStatuts())
				{
					log = getProgramInfoLog(&logLength);
				}
			}

			return log;
		}

		void ShaderProgram::destroy()
		{
			if (m_id != 0)
			{
				glDeleteProgram(m_id);
				m_id = 0;
			}
		}
	}
}