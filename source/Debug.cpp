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

#include <vxGL/Debug.h>
#include <vxGL/gl.h>
#include <windows.h>
#include <DbgHelp.h>

#pragma comment(lib, "Dbghelp")

namespace vx
{
	namespace gl
	{
		std::ostream* Debug::s_pOuts = nullptr;
		void* Debug::s_pUserData = nullptr;
		DebugHighSeverityCallback Debug::s_highSeverityCallback = nullptr;

		template<size_t DestSize, size_t SourceSize>
		void bufferCopy(char(&dst)[DestSize], const char(&src)[SourceSize])
		{
			static_assert(SourceSize < DestSize, "Destination size too small");

			memcpy(dst, src, SourceSize);
			dst[SourceSize] = '\0';
		}

		template<size_t size>
		void getStringForType(GLenum type, char(&buffer)[size])
		{
			/*
			DEBUG_TYPE_ERROR_ARB                              0x824C
			DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB                0x824D
			DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB                 0x824E
			DEBUG_TYPE_PORTABILITY_ARB                        0x824F
			DEBUG_TYPE_PERFORMANCE_ARB                        0x8250
			DEBUG_TYPE_OTHER_ARB                              0x8251
			*/

			switch (type)
			{
			case GL_DEBUG_TYPE_ERROR:
				bufferCopy(buffer, "Error");
				break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
				bufferCopy(buffer, "Deprecated Behavior");
				break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				bufferCopy(buffer, "Undefined Behavior");
				break;
			case GL_DEBUG_TYPE_PORTABILITY:
				bufferCopy(buffer, "Portability");
				break;
			case GL_DEBUG_TYPE_PERFORMANCE:
				bufferCopy(buffer, "Performance");
				break;
			case GL_DEBUG_TYPE_OTHER:
				bufferCopy(buffer, "Other");
				break;
			default:
				buffer[0] = '\0';
				break;
			}
		}

		template<size_t size>
		void getStringForSource(GLenum source, char(&buffer)[size])
		{
			/*
			DEBUG_SOURCE_API_ARB                              0x8246
			DEBUG_SOURCE_WINDOW_SYSTEM_ARB                    0x8247
			DEBUG_SOURCE_SHADER_COMPILER_ARB                  0x8248
			DEBUG_SOURCE_THIRD_PARTY_ARB                      0x8249
			DEBUG_SOURCE_APPLICATION_ARB                      0x824A
			DEBUG_SOURCE_OTHER_ARB                            0x824B
			*/

			switch (source)
			{
			case GL_DEBUG_SOURCE_API:
				bufferCopy(buffer, "API");
				break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
				bufferCopy(buffer, "Window System");
				break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER:
				bufferCopy(buffer, "Shader Compiler");
				break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:
				bufferCopy(buffer, "Third Party");
				break;
			case GL_DEBUG_SOURCE_APPLICATION:
				bufferCopy(buffer, "Application");
				break;
			case GL_DEBUG_SOURCE_OTHER:
				bufferCopy(buffer, "Other");
				break;
			default:
				buffer[0] = '\0';
				break;
			}
		}

		template<size_t size>
		void getStringForSeverity(GLenum severity, char(&buffer)[size])
		{
			/*
			DEBUG_SEVERITY_HIGH_ARB                           0x9146
			DEBUG_SEVERITY_MEDIUM_ARB                         0x9147
			DEBUG_SEVERITY_LOW_ARB                            0x9148
			*/

			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:
			{
				bufferCopy(buffer, "High");
			}break;
			case GL_DEBUG_SEVERITY_MEDIUM:
				bufferCopy(buffer, "Medium");
				break;
			case GL_DEBUG_SEVERITY_LOW:
			{
				bufferCopy(buffer, "Low");
			}break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:
				bufferCopy(buffer, "Notification");
			default:
				buffer[0] = '\0';
				break;
			}
		}

		void Debug::errorCallback
			(
			u32 source, 
			u32 type, 
			u32 id, 
			u32 severity,
			s32 length, 
			const char *message, 
			const void *userParam
			)
		{
			char bufferType[21], bufferSource[17];

			char bufferSeverity[14];

			getStringForType(type, bufferType);
			getStringForSource(source, bufferSource);
			getStringForSeverity(severity, bufferSeverity);

			*s_pOuts << " -- \n Type: " <<
				bufferType << "; Source: " <<
				bufferSource << "; ID: " << id << "; Severity: " <<
				bufferSeverity << "\n" << message << "\n";

			printStack();

			if (s_highSeverityCallback && (severity == GL_DEBUG_SEVERITY_HIGH))
			{
				s_highSeverityCallback();
			}
		}

		bool Debug::initialize(std::ostream *pOutStream)
		{
			// set the output stream
			if (!pOutStream)
				s_pOuts = (std::iostream *)&std::cout;
			else
				s_pOuts = pOutStream;

			// check if the extension is there
			char *s;
			auto i = 0;
			auto max = 0;
			glGetIntegerv(GL_NUM_EXTENSIONS, &max);
			do
			{
				s = (char *)glGetStringi(GL_EXTENSIONS, i++);
			} while (i < max && strcmp(s, "GL_ARB_debug_output") != 0);

			// if we have the extension then ...
			if (s != nullptr)
			{
				glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
				glDebugMessageCallback((GLDEBUGPROC)errorCallback, s_pUserData);
				// disable notifications
				glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
			}
			else
			{
				*s_pOuts << "VSDebugLib Error: OpenGL Debug Context not enabled\n";
				return false;
			}

			return true;
		}

		void Debug::enableCallback(bool enable)
		{
			if (enable)
				glDebugMessageCallback((GLDEBUGPROC)errorCallback, s_pUserData);
			else
				glDebugMessageCallback(nullptr, nullptr);
		}

		void Debug::enableLowSeverityMessages(bool enabled)
		{
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_LOW, 0, NULL, enabled);
		}

		void Debug::setHighSeverityCallback(DebugHighSeverityCallback callback)
		{
			s_highSeverityCallback = callback;
		}

		void Debug::printStack()
		{
			auto process = GetCurrentProcess();
			SymSetOptions(SYMOPT_LOAD_LINES);
			SymInitialize(process, NULL, TRUE);

			void *stack[100];
			auto frames = CaptureStackBackTrace(0, 200, stack, NULL);

			u8 symbolBuffer[sizeof(SYMBOL_INFO) + 256 * sizeof(char)];
			auto symbol = (SYMBOL_INFO*)symbolBuffer;//(SYMBOL_INFO *)calloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char), 1);
			symbol->MaxNameLen = 255;
			symbol->SizeOfStruct = sizeof(SYMBOL_INFO);

			for (auto i = 0u; i < frames; i++)
			{
				SymFromAddr(process, (DWORD64)(stack[i]), 0, symbol);
				DWORD dwDisplacement;
				IMAGEHLP_LINE64 line;
				line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

				if (!strstr(symbol->Name, "VSDebugLib::") &&
					SymGetLineFromAddr64(process, (DWORD64)(stack[i]), &dwDisplacement, &line))
				{
					*s_pOuts << "function: " << symbol->Name <<
						" - line: " << line.LineNumber << "\n";
				}

				if (0 == strcmp(symbol->Name, "main"))
					break;
			}

			//free(symbol);
		}
	}
}