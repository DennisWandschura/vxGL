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

#include <vxLib/math/matrix.h>
#include <Windows.h>
#include <memory>

namespace vx
{
	class Window;
	
	namespace gl
	{
		struct OpenGLDescription
		{
			HWND hwnd;
			vx::uint2 resolution;
			u8 majVersion;
			u8 minVersion;
			bool bVsync;
			bool bDebugMode;
		};

		struct ContextDescription
		{
			HWND tmpHwnd;
			HINSTANCE hInstance;
			LPCWSTR windowClass;
			OpenGLDescription glParams;

			ContextDescription()
				:tmpHwnd(),
				hInstance(0),
				windowClass(0),
				glParams()
			{
			}
		};

		class RenderContext
		{
			HDC m_pDeviceContext;
			HGLRC m_pRenderingContext;
			std::unique_ptr<s32[]> m_pContextAttribs;

			bool initializeExtensions(HWND hwnd);
			bool initializeOpenGl(const OpenGLDescription &desc);
			bool initializeExtensionsWithTempWindow(HINSTANCE hInstance, LPCWSTR windowClass);
			bool initializeOpenGl(const OpenGLDescription &params, const int *pContextAttribs);

			void setDefaultStates(const OpenGLDescription &params);

		public:
			RenderContext();
			~RenderContext();

			bool initialize(const ContextDescription &params);

			void shutdown(HWND hwnd);
			void shutdown(const Window &window);

			void swapBuffers();

			void makeCurrent(bool b);

			const HDC getDeviceContext() const
			{
				return m_pDeviceContext;
			}

			const HGLRC getRenderingContext() const
			{
				return m_pRenderingContext;
			}

			const s32* getContextAttributes() const { return m_pContextAttribs.get(); }
		};
	}
}