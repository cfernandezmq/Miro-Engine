#include "stdafx.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Miro
{

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MR_TRACE(e);

		while (true);
	}

}