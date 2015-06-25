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

#include <vxLib/types.h>
#include <iostream>

namespace vx
{
	namespace gl
	{
		using DebugHighSeverityCallback = void(__stdcall*)();

		class Debug
		{
			static void errorCallback(u32 source, u32 type, u32 id, u32 severity, s32 length, const char *message, const void *userParam);

			static void printStack();

			/// The stream to where messages are directed
			static std::ostream *s_pOuts;

			static void *s_pUserData;

			static DebugHighSeverityCallback s_highSeverityCallback;

		public:
			static bool initialize(std::ostream *pOutStream = nullptr);

			static void __stdcall enableCallback(bool enable);

			static void enableLowSeverityMessages(bool enabled);

			static void setHighSeverityCallback(DebugHighSeverityCallback callback);
		};
	}
}