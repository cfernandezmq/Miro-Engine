#pragma once
#ifdef MR_PLATFORM_WINDOWS

extern Miro::Application* Miro::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Miro::CreateApplication();
	app->Run();
	delete app;
}

#endif