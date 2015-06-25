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

#include <vxGL/RenderContext.h>
#include <cstdio>
#include <vxGL/gl.h>
#include <vxGL/wgl_core.h>
#include <vxGL/StateManager.h>
#include <vxLib\Window.h>

namespace vx
{
	namespace gl
	{
		RenderContext::RenderContext()
			:m_pDeviceContext(nullptr),
			m_pRenderingContext(nullptr),
			m_pContextAttribs(nullptr)
		{
		}

		RenderContext::~RenderContext()
		{
		}

		bool RenderContext::initialize(const ContextDescription &params)
		{
			if (params.tmpHwnd != nullptr)
			{
				if (!initializeExtensions(params.tmpHwnd))
				{
					printf("tmp Could not initialize the OpenGL extensions.\n");
					return false;
				}
			}
			else
			{
				// Initialize a temporary OpenGL window and load the OpenGL extensions.
				if (!initializeExtensionsWithTempWindow(params.hInstance, params.windowClass))
				{
					printf("Could not initialize the OpenGL extensions.\n");
					return false;
				}
			}

			return initializeOpenGl(params.glParams);
		}

		bool RenderContext::initializeOpenGl(const OpenGLDescription &params)
		{
			if (params.bDebugMode)
			{
				m_pContextAttribs = std::unique_ptr<int[]>(new int[7]);
				m_pContextAttribs[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
				m_pContextAttribs[1] = params.majVersion;
				m_pContextAttribs[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
				m_pContextAttribs[3] = params.minVersion;
				m_pContextAttribs[4] = WGL_CONTEXT_FLAGS_ARB;
				m_pContextAttribs[5] = WGL_CONTEXT_DEBUG_BIT_ARB;
				m_pContextAttribs[6] = 0;
			}
			else
			{
				m_pContextAttribs = std::unique_ptr<int[]>(new int[5]);
				m_pContextAttribs[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
				m_pContextAttribs[1] = params.majVersion;
				m_pContextAttribs[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
				m_pContextAttribs[3] = params.minVersion;
				m_pContextAttribs[4] = 0;
			}

			return initializeOpenGl(params, m_pContextAttribs.get());
		}

		bool RenderContext::initializeExtensionsWithTempWindow(HINSTANCE hInstance, LPCWSTR windowClass)
		{
			// Create a temporary window for the OpenGL extension setup.
			auto hwnd = CreateWindowEx
				(WS_EX_APPWINDOW,
				windowClass,
				windowClass,
				WS_POPUP,
				0,
				0,
				640,
				480,
				NULL,
				NULL,
				hInstance,
				NULL);

			if (!initializeExtensions(hwnd))
			{

				// Release the temporary window now that the extensions have been initialized.
				DestroyWindow(hwnd);
				hwnd = NULL;
				return false;
			}

			// Release the temporary window now that the extensions have been initialized.
			DestroyWindow(hwnd);
			hwnd = NULL;

			return true;
		}

		bool RenderContext::initializeExtensions(HWND hwnd)
		{
			const PIXELFORMATDESCRIPTOR pixelFormat =
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
				PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
				32,                        //Colordepth of the framebuffer.
				0, 0, 0, 0, 0, 0,
				0,
				0,
				0,
				0, 0, 0, 0,
				24,                        //Number of bits for the depthbuffer
				8,                        //Number of bits for the stencilbuffer
				0,                        //Number of Aux buffers in the framebuffer.
				PFD_MAIN_PLANE,
				0,
				0, 0, 0
			};

			if (hwnd == NULL)
				return false;

			// Don't show the window.
			ShowWindow(hwnd, SW_HIDE);

			// Get the device context for this window.
			auto deviceContext = GetDC(hwnd);
			if (!deviceContext)
				return false;

			//PIXELFORMATDESCRIPTOR pixelFormat;
			// Set a temporary default pixel format.
			auto error = SetPixelFormat(deviceContext, 1, &pixelFormat);
			if (error != 1)
				return false;

			// Create a temporary rendering context.
			auto renderContext = wglCreateContext(deviceContext);
			if (!renderContext)
				return false;

			// Set the temporary rendering context as the current rendering context for this window.
			error = wglMakeCurrent(deviceContext, renderContext);
			if (error != 1)
				return false;

			// Initialize the OpenGL extensions needed for this application.  Note that a temporary rendering context was needed to do so.
			auto result = gl_load(deviceContext);
			if (!result)
				return false;

			// Release the temporary rendering context now that the extensions have been loaded.
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(renderContext);
			renderContext = NULL;

			// Release the device context for this window.
			ReleaseDC(hwnd, deviceContext);
			deviceContext = 0;

			// Release the temporary window now that the extensions have been initialized.
			//DestroyWindow(hwnd);
			//hwnd = NULL;

			return true;
		}

		bool RenderContext::initializeOpenGl(const OpenGLDescription &params, const int *pContextAttribs)
		{
			puts("Initializing OpgenGL");

			// Get the device context for this window.
			m_pDeviceContext = GetDC(params.hwnd);
			if (!m_pDeviceContext)
			{
				puts("Error");
				return false;
			}

			const int attributeListInt[] =
			{
				// Support for OpenGL rendering.
				WGL_SUPPORT_OPENGL_ARB, TRUE,

				// Support for rendering to a window.
				WGL_DRAW_TO_WINDOW_ARB, TRUE,

				// Support for hardware acceleration.
				WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,

				// Support for 32bit color.
				WGL_COLOR_BITS_ARB, 32,

				// Support for 24 bit depth buffer.
				WGL_DEPTH_BITS_ARB, 24,

				// Support for double buffer.
				WGL_DOUBLE_BUFFER_ARB, GL_TRUE,

				// Support for swapping front and back buffer.
				WGL_SWAP_METHOD_ARB, WGL_SWAP_EXCHANGE_ARB,

				// Support for the RGBA pixel type.
				WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,

				// Support for a 8 bit stencil buffer.
				WGL_STENCIL_BITS_ARB, 8,

				// support for default srgb buffer
				//WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, GL_TRUE,

				// Null terminate the attribute list.
				0
			};

			// MSAA
			//attributeListInt[18] = WGL_SAMPLE_BUFFERS_ARB;
			//attributeListInt[19] = 1;

			//attributeListInt[20] = WGL_SAMPLES_ARB;
			//attributeListInt[21] = 4;

			int pixelFormat[1];
			unsigned int formatCount;
			// Query for a pixel format that fits the attributes we want.
			auto result = wglChoosePixelFormatARB(m_pDeviceContext, attributeListInt, NULL, 1, pixelFormat, &formatCount);
			if (result != 1)
			{
				puts("Error choosing pixel format");
				return false;
			}

			PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
			// If the video card/display can handle our desired pixel format then we set it as the current one.
			result = SetPixelFormat(m_pDeviceContext, pixelFormat[0], &pixelFormatDescriptor);
			if (result != 1)
			{
				auto error = GetLastError();
				printf("Error setting pixel format: %lu\n", error);
				return false;
			}

			// Create a OpenGL 4.5 rendering context.
			m_pRenderingContext = wglCreateContextAttribsARB(m_pDeviceContext, 0, pContextAttribs);
			if (m_pRenderingContext == nullptr)
			{
				puts("Error creating context");
				return false;
			}

			// Set the rendering context to active.
			result = wglMakeCurrent(m_pDeviceContext, m_pRenderingContext);
			if (result != 1)
			{
				puts("Error wglMakeCurrent");
				return false;
			}

			// Set the depth buffer to be entirely cleared to 1.0 values.
			glClearDepth(1.0f);

			// set opengl defaults
			setDefaultStates(params);

			// get version info
			auto renderer = glGetString(GL_RENDERER); // get renderer string
			auto version = glGetString(GL_VERSION); // version as a string
			printf("Renderer: %s\n", renderer);
			printf("OpenGL version supported %s\n", version);

			m_orthoMatrix = MatrixOrthographicRH(static_cast<f32>(params.resolution.x), static_cast<f32>(params.resolution.y), params.nearZ, params.farZ);

			auto screenAspect = (f32)params.resolution.x / (f32)params.resolution.y;
			m_projectionMatrix = MatrixPerspectiveFovRH(params.fovRad, screenAspect, params.nearZ, params.farZ);

			if (params.bVsync)
				result = wglSwapIntervalEXT(1);
			else
				result = wglSwapIntervalEXT(0);

			// Check if vsync was set correctly.
			if (result != 1)
			{
				puts("Error setting vsync");
				return false;
			}

			puts("Initialized OpgenGL");

			return true;
		}

		void RenderContext::setDefaultStates(const OpenGLDescription &params)
		{
			StateManager::enable(Capabilities::Depth_Test);
			StateManager::enable(Capabilities::Cull_Face);
			StateManager::setViewport(0, 0, params.resolution.x, params.resolution.y);

			StateManager::enable(Capabilities::Multisample);
			StateManager::enable(Capabilities::Dither);

			glFrontFace(GL_CCW);
			glCullFace(GL_BACK);
			glDepthFunc(GL_LESS);
		}

		void RenderContext::shutdown(HWND hwnd)
		{
			// Release the rendering context.
			if (m_pRenderingContext)
			{
				wglMakeCurrent(NULL, NULL);
				wglDeleteContext(m_pRenderingContext);
				m_pRenderingContext = nullptr;
			}

			// Release the device context.
			if (m_pDeviceContext)
			{
				ReleaseDC(hwnd, m_pDeviceContext);
				m_pDeviceContext = nullptr;
			}
		}

		void RenderContext::shutdown(const Window &window)
		{
			shutdown(window.getHwnd());
		}

		void RenderContext::swapBuffers()
		{
			// Present the back buffer to the screen since rendering is complete.
			SwapBuffers(m_pDeviceContext);
		}

		void RenderContext::makeCurrent(bool b)
		{
			if (b)
			{
				wglMakeCurrent(m_pDeviceContext, m_pRenderingContext);
			}
			else
			{
				wglMakeCurrent(m_pDeviceContext, nullptr);
			}
		}
	}
}