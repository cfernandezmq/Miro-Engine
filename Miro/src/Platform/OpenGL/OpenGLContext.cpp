#include "stdafx.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Miro
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		MR_CORE_ASSERT(windowHandle, "Window Handle is NULL");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);

	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MR_CORE_ASSERT(status, "Failed to initialize Glad!");

		MR_CORE_INFO("OpenGL Renderer:");
		MR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		MR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		MR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

}