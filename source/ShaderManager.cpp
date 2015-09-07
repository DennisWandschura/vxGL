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

#include <vxGL/ShaderManager.h>
#include <vxGL/ProgramPipeline.h>
#include <vxGL/ShaderProgram.h>
#include <Shlwapi.h>
#include <vxGL/gl.h>
#include <vxLib/memory.h>
#include <vxLib/File/FileHandle.h>
#include <vxLib/Variant.h>
#include <vxLib/ScopeGuard.h>
#include <vxLib/Allocator/StackAllocator.h>
#include <fstream>

namespace vx
{
	namespace gl
	{
		enum ShaderParameterType{ Int, Uint, Float };

		struct ShaderParameter
		{
			union
			{
				u32 u;
				s32 s;
				f32 f;
			};

			ShaderParameterType type;

			explicit ShaderParameter(u32 v) :u(v), type(ShaderParameterType::Uint){}
			explicit ShaderParameter(s32 v) :s(v), type(ShaderParameterType::Int){}
			explicit ShaderParameter(f32 v) :f(v), type(ShaderParameterType::Float){}

			int operator()(char(&paramBuffer)[64]) const
			{
				if (type == ShaderParameterType::Int)
				{
					return sprintf(paramBuffer, "%d", s);
				}
				else if (type == ShaderParameterType::Float)
				{
					return sprintf(paramBuffer, "%f", f);
				}
				else
				{
					return sprintf(paramBuffer, "%u", u);
				}
			}
		};
	}
}

namespace ShaderManagerCpp
{
	const char* findParameter(const char* str)
	{
		while (true)
		{
			if (str[0] == '\0' || str[0] == '$')
				break;

			++str;
		}

		return str;
	}

	bool insertParameter(char** str, const vx::sorted_vector<vx::StringID, vx::gl::ShaderParameter> &params, vx::StackAllocator* scratchAllocator)
	{
		auto paramBegin = findParameter(*str);
		auto sizeToParam = paramBegin - *str;
		if (paramBegin[0] == '\0')
			return false;

		++paramBegin;

		auto paramEnd = findParameter(paramBegin);
		if (paramEnd[0] == '\0')
			return false;

		auto paramNameSize = paramEnd - paramBegin;
		char paramName[64] = {};
		strncpy(paramName, paramBegin, paramNameSize);

		auto it = params.find(vx::make_sid(paramName));
		if (it == params.end())
		{
			printf("could not find value for parameter '%s'\n", paramName);
			return false;
		}

		++paramEnd;

		auto sizeToEnd = strlen(paramEnd);

		char paramBuffer[64] = {};

		auto valueSize = (*it)(paramBuffer);

		auto bufferSize = sizeToParam + valueSize + sizeToEnd;

		auto newText = (char*)scratchAllocator->allocate(bufferSize + 1);
		memset(newText, 0, bufferSize + 1);

		strncpy(newText, *str, sizeToParam);
		strncpy(newText + sizeToParam, paramBuffer, valueSize);
		strncpy(newText + sizeToParam + valueSize, paramEnd, sizeToEnd);

		*str = newText;

		return true;
	}

	/*bool loadFile(const char* str, char** buffer, u32 &size, vx::StackAllocator* scratchAllocator)
	{
		std::ifstream inFile(str);

		if (!inFile.is_open())
		{
			printf("could not open file %s\n", str);
			return false;
		}

		inFile.seekg(0, std::ios::end);
		size = inFile.tellg();
		inFile.seekg(0, std::ios::beg);

		*buffer = (char*)scratchAllocator->allocate(size);
		memset(*buffer, 0, size);

		inFile.read(*buffer, size);

		return true;
	}*/

	const char* getInclude(const char* text)
	{
		while (true)
		{
			auto c = text[0];

			if (c == '\0' || c == '"')
				break;

			++text;
		}

		return text;
	}

	const char* getPreprocessorCommandEnd(const char* text)
	{
		while (true)
		{
			auto c = text[0];

			if (c == '\0' || c == ' ' || c == '\n')
				break;

			++text;
		}

		return text;
	}

	const char* getPreprocessorCommand(const char* text)
	{
		while (true)
		{
			auto c = text[0];

			if (c == '\0' || c == '#')
				break;

			++text;
		}

		return text;
	}

	const char* getElseOrEndif(const char* text)
	{
		int layer = 0;
		std::string buffer;
		while (true)
		{
			auto command = getPreprocessorCommand(text);
			if (command[0] == '\0')
				break;

			auto commandEnd = getPreprocessorCommandEnd(command);

			buffer.clear();
			buffer.assign(command, commandEnd);

			text = commandEnd;
			if (strcmp(buffer.c_str(), "#if") == 0)
			{
				++layer;
			}
			else if (strcmp(buffer.c_str(), "#ifdef") == 0)
			{
				++layer;
			}
			else if (strcmp(buffer.c_str(), "#ifndef") == 0)
			{
				++layer;
			}
			else if (strcmp(buffer.c_str(), "#else") == 0)
			{
				if (layer == 0)
				{
					break;
				}
			}
			else if (strcmp(buffer.c_str(), "#endif") == 0)
			{
				if (layer == 0)
				{
					break;
				}
				--layer;
			}
		}

		return text;
	}

	const char* getNextLine(const char* text)
	{
		while (true)
		{
			auto c = text[0];

			if (c == '\0' || c == '\n')
				break;

			++text;
		}

		return text;
	}

	const char* getCommandValue(const char* ptr, std::string* commandValue)
	{
		auto valueStart = ptr + 1;
		auto valueEnd = getPreprocessorCommandEnd(valueStart);

		commandValue->clear();
		commandValue->assign(valueStart, valueEnd);

		return valueEnd;
	}

	const char* getEof(const char* ptr)
	{
		while (true)
		{
			if (ptr[0] == '\0')
				break;

			++ptr;
		}

		return ptr;
	}

	bool hasDefine(const vx::StringID &sid, const vx::sorted_vector<vx::StringID, s32> &localDefines, const vx::sorted_vector<vx::StringID, s32> &globalDefines)
	{
		bool found = false;

		auto it = localDefines.find(sid);
		if (it != localDefines.end())
		{
			found = true;
		}
		else
		{
			auto itGlobal = globalDefines.find(sid);
			if (itGlobal != globalDefines.end())
			{
				found = true;
			}
		}

		return found;
	}

	void handleIfndef(char* ptr, const char* end, std::string* commandValue, 
		const vx::sorted_vector<vx::StringID, s32> &localDefines, const vx::sorted_vector<vx::StringID, s32> &globalDefines)
	{
		auto valueEnd = getCommandValue(end + 1, commandValue);
		auto sid = vx::make_sid(commandValue->c_str());

		bool found = hasDefine(sid, localDefines, globalDefines);

		if (found)
		{
			auto endifEnd = getElseOrEndif(valueEnd);
			auto endifEndOther = getElseOrEndif(endifEnd + 1);

			if (endifEnd != endifEndOther)
			{
				auto sizeToElse = endifEnd - ptr;
				memset(ptr, ' ', sizeToElse);

				auto endifStart = endifEndOther;
				while (true)
				{
					if (endifStart[0] == '#')
						break;

					--endifStart;
				}

				endifEnd = endifStart;
			}

			auto size = endifEndOther - endifEnd;
			auto offset = endifEnd - ptr;
			memset(ptr + offset, ' ', size);
		}
	}

	void handleIfDef(char* ptr, const char* end, std::string* commandValue,
		const vx::sorted_vector<vx::StringID, s32> &localDefines, const vx::sorted_vector<vx::StringID, s32> &globalDefines)
	{
		auto valueEnd = getCommandValue(end + 1, commandValue);

		auto sid = vx::make_sid(commandValue->c_str());

		bool found = hasDefine(sid, localDefines, globalDefines);

		if (!found)
		{
			auto endifEnd = getElseOrEndif(valueEnd);
			auto endifEndOther = getElseOrEndif(endifEnd + 1);

			if (endifEnd != endifEndOther)
			{
				auto sizeToElse = endifEnd - ptr;
				memset(ptr, ' ', sizeToElse);

				auto endifStart = endifEndOther;
				while (true)
				{
					if (endifStart[0] == '#')
						break;

					--endifStart;
				}

				endifEnd = endifStart;
			}

			auto size = endifEndOther - endifEnd;
			auto offset = endifEnd - ptr;
			memset(ptr + offset, ' ', size);
		}
	}

	/*void processText(char** text, int bufferSize, const std::string &includeDir, 
		const vx::sorted_vector<vx::StringID, s32> &globalDefines, vx::sorted_vector<vx::StringID, s32>* localDefines,
		vx::sorted_vector<vx::StringID, std::string>* includeFiles, vx::sorted_vector<vx::StringID, s32>* includedFiles, vx::StackAllocator* scratchAllocator)
	{
		const char* commandDefine = "#define";
		const char* commandIfdef = "#ifdef";
		const char* commandIfndef = "#ifndef";
		const char* commandInclude = "#include";

		std::string command;
		std::string commandValue;

		char* ptr = *text;
		while (true)
		{
			auto c = ptr[0];
			if (c == '\0')
				break;

			if (c == '#')
			{
				auto end = getPreprocessorCommandEnd(ptr);

				command.clear();
				command.assign(ptr, end);

				if (strcmp(command.c_str(), commandDefine) == 0)
				{
					getCommandValue(end + 1, &commandValue);

					auto sid = vx::make_sid(commandValue.c_str());
					localDefines->insert(sid, 1);
				}
				else if (strcmp(command.c_str(), commandIfdef) == 0)
				{
					handleIfDef(ptr, end, &commandValue, *localDefines, globalDefines);
				}
				else if (strcmp(command.c_str(), commandIfndef) == 0)
				{
					handleIfndef(ptr, end, &commandValue, *localDefines, globalDefines);
				}
				else if (strcmp(command.c_str(), commandInclude) == 0)
				{
					auto includeFileStart = getInclude(end + 1) + 1;
					auto includeFileEnd = getInclude(includeFileStart + 1);

					commandValue.clear();
					commandValue.assign(includeFileStart, includeFileEnd);

					auto sid = vx::make_sid(commandValue.c_str());

					auto itIncluded = includedFiles->find(sid);
					if (itIncluded == includedFiles->end())
					{
						auto it = includeFiles->find(sid);
						if (it == includeFiles->end())
						{
							std::string file = includeDir + commandValue;
							//file.pop_back();

							char* includeBuffer = nullptr;
							//printf("trying to open file %s\n", file.c_str());

							u32 includeSize = 0;
							if (loadFile(file.c_str(), &includeBuffer, includeSize, scratchAllocator))
							{
								std::string includeFile;
								includeFile.assign(includeBuffer);

								includedFiles->insert(sid, 1);
								it = includeFiles->insert(std::move(sid), std::move(includeFile));
							}
						}

						if (it != includeFiles->end())
						{
							auto includeSize = it->size();

							auto eof = getEof(includeFileEnd);
							auto sizeToEnd = eof - includeFileEnd;

							bufferSize += includeSize;
							auto newBuffer = (char*)scratchAllocator->allocate(bufferSize);

							int copiedSize = 0;
							auto sizeToInclude = ptr - *text;
							memcpy(newBuffer, *text, sizeToInclude);
							copiedSize += sizeToInclude;
							memcpy(newBuffer + sizeToInclude, it->c_str(), includeSize);
							copiedSize += includeSize;
							memcpy(newBuffer + copiedSize, includeFileEnd + 1, sizeToEnd);

							*text = newBuffer;

							ptr = *text + sizeToInclude;
						}
					}
				}
				else
				{
					//	printf("Not supported: %s\n", command.c_str());
				}
			}

			++ptr;
		}
	}

	/*bool loadShaderProgram(const char* programFile,
		const char* fileName,
		const std::string &includeDir, const vx::sorted_vector<vx::StringID, vx::gl::ShaderParameter> &params,
		const vx::sorted_vector<vx::StringID, s32> &globalDefines,
		vx::gl::ShaderProgram* program, vx::sorted_vector<vx::StringID, std::string>* includeFiles, vx::StackAllocator* scratchAllocator)
	{
		auto allocMarker = scratchAllocator->getMarker();
		SCOPE_EXIT
		{
			scratchAllocator->clear(allocMarker);
		};
			
		char* programBuffer = nullptr;
		u32 programSize;
		if (!loadFile(programFile, &programBuffer, programSize, scratchAllocator))
			return false;

		vx::sorted_vector<vx::StringID, s32> localDefines;

		vx::sorted_vector<vx::StringID, s32> included;
		processText(&programBuffer, programSize, includeDir, globalDefines, &localDefines, includeFiles, &included, scratchAllocator);

		while (insertParameter(&programBuffer, params, scratchAllocator))
			;

		const char* ptr = programBuffer;

		s32 logSize = 0;
		auto log = program->create(&ptr, logSize);
		if (log)
		{
			printf("Error '%s'\n%s\n", programFile, log.get());

			std::string errorFile("error_");
			errorFile.append(fileName);
			std::ofstream outFile(errorFile);
			outFile << ptr;
			//printf("%s\n", ptr);

			return false;
		}

		return true;
	}*/
}

namespace vx
{
	namespace gl
	{
		struct ShaderManager::LoadUseProgramDescription
		{
			vx::gl::ProgramPipeline* pipe;
			const char* id;
			ShaderProgramType type;
			const std::string* programDir;
			const std::string* includeDir;
		};

		ShaderManager::ShaderManager()
			:m_programPipelines(),
			m_shaderPrograms(),
			m_textPreprocessor()
		{

		}

		ShaderManager::~ShaderManager()
		{
		}

		void ShaderManager::initialize(const std::string &dataDir)
		{
			m_dataDir = dataDir;
		}

		void ShaderManager::clear()
		{
			m_programPipelines.clear();
			m_shaderPrograms.clear();
		}

		bool ShaderManager::loadProgram(const FileHandle &programHandle, vx::gl::ShaderProgramType type, const std::string &programDir, const std::string &includeDir, vx::StackAllocator* scratchAllocator, std::string* error)
		{
			auto programFile = programDir + programHandle.m_string;

			auto sid = programHandle.m_sid;
			auto it = m_shaderPrograms.find(sid);
			if (it == m_shaderPrograms.end())
			{
				auto programData = m_textPreprocessor.preprocessFile(programFile.c_str());
				vx::gl::ShaderProgram program(type);

				const char* ptr = programData.c_str();

				s32 logSize = 0;
				auto log = program.create(&ptr, logSize);
				if (log)
				{
					//printf("Error '%s'\n%s\n", programFile, log.get());
					error->append("shader error: ");
					error->append(programFile);
					error->push_back('\n');

					error->append(log.get());

					std::string errorFile("error_");
					errorFile.append(programHandle.m_string);
					std::ofstream outFile(errorFile);
					outFile << ptr;

					return false;
				}

				m_shaderPrograms.insert(std::move(sid), std::move(program));

				/*vx::gl::ShaderProgram program(type);
				if (!ShaderManagerCpp::loadShaderProgram(programFile.c_str(), programHandle.m_string, includeDir, m_parameters, m_defines, &program, &m_includeFiles, scratchAllocator))
				{
					printf("Error ShaderManager::loadProgram\n");
					return false;
				}

				m_shaderPrograms.insert(std::move(sid), std::move(program));*/
			}

			return true;
		}

		bool ShaderManager::useProgram(vx::gl::ProgramPipeline &pipe, const FileHandle &handle)
		{
			auto pProgram = getProgram(handle.m_sid);
			if (!pProgram)
			{
				printf("Error ShaderManager::useProgram '%s'\n", handle.m_string);
				return false;
			}

			pipe.useProgram(*pProgram);
			return true;
		}

		bool ShaderManager::loadUseProgram(const LoadUseProgramDescription &desc, vx::StackAllocator* scratchAllocator, std::string* error)
		{
			// check for not used shader stage
			if (strcmp(desc.id, "''") == 0)
			{
				return true;
			}

			auto fileHandle = FileHandle(desc.id);
			if (!loadProgram(fileHandle, desc.type, *desc.programDir, *desc.includeDir, scratchAllocator, error))
				return false;
			if (!useProgram(*desc.pipe, fileHandle))
				return false;

			return true;
		}

		bool ShaderManager::loadPipeline(const FileHandle &fileHandle, const char *id, const std::string &pipelineDir, 
			const std::string &programDir, const std::string &includeDir, vx::StackAllocator* scratchAllocator, std::string* error)
		{
			auto sid = vx::make_sid(id);
			auto it = m_programPipelines.find(sid);
			if (it != m_programPipelines.end())
			{
				printf("Error, pipeline with id '%s' already exists !\n", id);
				return false;
			}

			auto pipelineFileWithPath = pipelineDir + fileHandle.m_string;

			std::ifstream inFile(pipelineFileWithPath.c_str());
			if (!inFile.is_open())
			{
				printf("could not open pipeline file '%s'\n", pipelineFileWithPath.c_str());
				printf("'%s'\n", fileHandle.m_string);
				return false;
			}

			std::string shaders[4];
			u32 shaderIndex = 0;
			char buffer[128];
			while (!inFile.eof())
			{
				if (!inFile.getline(buffer, 128))
				{
					puts("error reading line");
					return false;
				}

				shaders[shaderIndex++] = buffer;
			}

			vx::gl::ProgramPipeline pipe;
			pipe.create();

			LoadUseProgramDescription desc;
			desc.includeDir = &includeDir;
			desc.pipe = &pipe;
			desc.programDir = &programDir;

			desc.id = shaders[0].c_str();
			desc.type = vx::gl::ShaderProgramType::VERTEX;
			if (!loadUseProgram(desc, scratchAllocator, error))
				return false;

			desc.id = shaders[1].c_str();
			desc.type = vx::gl::ShaderProgramType::GEOMETRY;
			if (!loadUseProgram(desc, scratchAllocator, error))
				return false;

			desc.id = shaders[2].c_str();
			desc.type = vx::gl::ShaderProgramType::FRAGMENT;
			if (!loadUseProgram(desc, scratchAllocator, error))
				return false;

			desc.id = shaders[3].c_str();
			desc.type = vx::gl::ShaderProgramType::COMPUTE;
			if (!loadUseProgram(desc, scratchAllocator, error))
				return false;

		//	printf("Added pipeline '%s'\n", id);
			m_programPipelines.insert(std::move(sid), std::move(pipe));

			return true;
		}

		bool ShaderManager::loadPipeline(const FileHandle &fileHandle, const char *id, vx::StackAllocator* scratchAllocator, std::string* error)
		{
			auto pipelineDir = m_dataDir + "shaders/";
			const std::string programDir(m_dataDir + "shaders/programs/");
			const std::string includeDir = m_dataDir + "shaders/include/";

			return loadPipeline(fileHandle, id, pipelineDir, programDir, includeDir, scratchAllocator, error);
		}

		void ShaderManager::addParameter(const char* id, s32 value)
		{
			m_textPreprocessor.setCustomValue(id, value);
		}

		void ShaderManager::addParameter(const char* id, u32 value)
		{
			m_textPreprocessor.setCustomValue(id, value);
		}

		void ShaderManager::addParameter(const char* id, f32 value)
		{
			m_textPreprocessor.setCustomValue(id, value);
		}

		void ShaderManager::setDefine(const char* define)
		{
			m_textPreprocessor.setDefine(define);
		}

		void ShaderManager::removeDefine(const char* define)
		{
			m_textPreprocessor.removeDefine(define);
		}

		void ShaderManager::addIncludeFile(const char* file, const char* key)
		{
			m_textPreprocessor.loadIncludeFile(file, key);
		}

		const vx::gl::ShaderProgram* ShaderManager::getProgram(const vx::StringID &sid) const
		{
			auto it = m_shaderPrograms.find(sid);
			if (it == m_shaderPrograms.end())
				return nullptr;

			return &*it;
		}

		const vx::gl::ProgramPipeline* ShaderManager::getPipeline(const char* id) const
		{
			return getPipeline(vx::make_sid(id));
		}

		const vx::gl::ProgramPipeline* ShaderManager::getPipeline(const vx::StringID &sid) const
		{
			auto it = m_programPipelines.find(sid);
			if (it == m_programPipelines.end())
				return nullptr;

			return &*it;
		}
	}
}