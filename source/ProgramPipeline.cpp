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

#include <vxGL/ProgramPipeline.h>
#include <vxGL/ShaderProgram.h>
#include <memory>
#include <fstream>
#include <vxGL/gl.h>

namespace vx
{
	namespace gl
	{
		namespace detail
		{
			inline u32 getStageBit(ShaderProgramType type)
			{
				switch (type)
				{
				case gl::ShaderProgramType::VERTEX:
					return GL_VERTEX_SHADER_BIT;
				case gl::ShaderProgramType::GEOMETRY:
					return GL_GEOMETRY_SHADER_BIT;
				case gl::ShaderProgramType::COMPUTE:
					return GL_COMPUTE_SHADER_BIT;
				case gl::ShaderProgramType::FRAGMENT:
					return GL_FRAGMENT_SHADER_BIT;
				case gl::ShaderProgramType::TESS_CONTROL:
					return GL_TESS_CONTROL_SHADER_BIT;
				case gl::ShaderProgramType::TESS_EVAL:
					return GL_TESS_EVALUATION_SHADER_BIT;
				default:
					return 0;
				}
			}
		}

		std::unique_ptr<char[]> loadProgramData(const char *filename)
		{
			std::ifstream inFile(filename);
			if (!inFile.is_open())
				return nullptr;

			inFile.seekg(0, inFile.end);
			u32 length = inFile.tellg();
			inFile.seekg(0, inFile.beg);

			auto ptr = std::unique_ptr<char[]>(new char[length + 1]);

			inFile.read(ptr.get(), length);

			ptr[length] = '\0';

			//if (pCount)
			//	*pCount = length + 1;

			return std::move(ptr);
		}

		ProgramPipeline::ProgramPipeline() noexcept
			:Base(),
			m_programIds()
		{
		}

		ProgramPipeline::ProgramPipeline(ProgramPipeline &&rhs) noexcept
			: Base(std::move(rhs))
		{
			memcpy(m_programIds, rhs.m_programIds, sizeof(m_programIds));
		}

		ProgramPipeline::~ProgramPipeline()
		{
			destroy();
		}

		ProgramPipeline& ProgramPipeline::operator=(ProgramPipeline &&rhs) noexcept
		{
			if (this != &rhs)
			{
				Base::operator=(std::move(rhs));
				std::swap(m_programIds, rhs.m_programIds);
			}
			return *this;
		}

		void ProgramPipeline::create()
		{
			if (m_id == 0)
			{
				glCreateProgramPipelines(1, &m_id);
			}
		}

		void ProgramPipeline::destroy()
		{
			if (m_id != 0)
			{
				glDeleteProgramPipelines(1, &m_id);
				m_id = 0;
			}
		}

		void ProgramPipeline::useProgram(const ShaderProgram &program)
		{
			auto programId = program.getId();
			auto type = program.getType();
			glUseProgramStages(m_id, ::vx::gl::detail::getStageBit(type), programId);

			m_programIds[static_cast<u32>(type)] = programId;
		}

		void ProgramPipeline::validatePipeline() const
		{
			glValidateProgramPipeline(m_id);
		}

		void ProgramPipeline::bind() const
		{
			glBindProgramPipeline(m_id);
		}

		void ProgramPipeline::bindZero() const
		{
			glBindProgramPipeline(0);
		}

		u32 ProgramPipeline::operator[](ShaderProgramType type) const
		{
			return m_programIds[static_cast<u32>(type)];
		}

		u32 ProgramPipeline::getVertexShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::VERTEX)];
		}

		u32 ProgramPipeline::getFragmentShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::FRAGMENT)];
		}

		u32 ProgramPipeline::getGeometryShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::GEOMETRY)];
		}

			u32 ProgramPipeline::getComputeShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::COMPUTE)];
		}

		u32 ProgramPipeline::getTessControlShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::TESS_CONTROL)];
		}

		u32 ProgramPipeline::getTessEvalShader() const noexcept
		{
			return m_programIds[static_cast<u32>(ShaderProgramType::TESS_EVAL)];
		}
	}
}