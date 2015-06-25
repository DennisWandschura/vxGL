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
		class ShaderProgram;

		class ProgramPipeline : public Base < ProgramPipeline >
		{
			u32 m_programIds[6];

		public:
			ProgramPipeline() noexcept;
			ProgramPipeline(ProgramPipeline &&rhs) noexcept;
			~ProgramPipeline();

			ProgramPipeline& operator=(ProgramPipeline &&rhs) noexcept;

			void create();
			void destroy();

			void useProgram(const ShaderProgram &program);
			void validatePipeline() const;

			void bind() const;

			void bindZero() const;

			u32 operator[](ShaderProgramType type) const;

			u32 getVertexShader() const noexcept;
			u32 getFragmentShader() const noexcept;
			u32 getGeometryShader() const noexcept;
			u32 getComputeShader() const noexcept;
			u32 getTessControlShader() const noexcept;
			u32 getTessEvalShader() const noexcept;
		};
	}
}