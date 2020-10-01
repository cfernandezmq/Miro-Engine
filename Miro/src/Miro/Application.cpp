#include "stdafx.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"


namespace Miro
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	void Application::Run()
	{
		while (m_Running)
		{

			m_Window->OnUpdate();
		}
	}

}