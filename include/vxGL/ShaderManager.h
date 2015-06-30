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
#include <vxLib/Container/sorted_vector.h>
#include <vxLib/StringID.h>
#include <string>
#include <vxLib/TextPreprocessor.h>

namespace vx
{
	struct FileHandle;
	class StackAllocator;

	namespace gl
	{
		class ProgramPipeline;
		class ShaderProgram;
		struct ShaderParameter;

		class ShaderManager
		{
			struct LoadUseProgramDescription;

			vx::sorted_vector<vx::StringID, ProgramPipeline> m_programPipelines;
			vx::sorted_vector<vx::StringID, ShaderProgram> m_shaderPrograms;
			vx::TextPreprocessor m_textPreprocessor;
			std::string m_dataDir;

			bool loadProgram(const FileHandle &programHandle, vx::gl::ShaderProgramType type, const std::string &programDir, const std::string &includeDir, vx::StackAllocator* scratchAllocator);
			bool useProgram(vx::gl::ProgramPipeline &pipe, const FileHandle &handle);
			bool loadUseProgram(const LoadUseProgramDescription &desc, vx::StackAllocator* scratchAllocator);

			const vx::gl::ShaderProgram* getProgram(const vx::StringID &sid) const;

			bool loadPipelines(vx::StackAllocator* scratchAllocator);
			bool loadPipeline(const FileHandle &fileHandle, const char *id, const std::string &pipelineDir, const std::string &programDir, const std::string &includeDir, vx::StackAllocator* scratchAllocator);

		public:
			ShaderManager();
			~ShaderManager();

			bool initialize(const std::string &dataDir, vx::StackAllocator* scratchAllocator, bool loadAllPipelinesFromDir);
			void clear();

			bool loadPipeline(const FileHandle &filehandle, const char *id, vx::StackAllocator* scratchAllocator);

			void addParameter(const char* id, s32 value);
			void addParameter(const char* id, u32 value);
			void addParameter(const char* id, f32 value);

			void setDefine(const char* define);
			void removeDefine(const char* define);

			void addIncludeFile(const char* file, const char* key);

			const vx::gl::ProgramPipeline* getPipeline(const char* id) const;
			const vx::gl::ProgramPipeline* getPipeline(const vx::StringID &sid) const;
		};
	}
}