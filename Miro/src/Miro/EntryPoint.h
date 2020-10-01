#pragma once
#ifdef MR_PLATFORM_WINDOWS

extern Miro::Application* Miro::CreateApplication();

int main(int argc, char** argv)
{
	Miro::Log::Init();
	MR_CORE_WARN("Initialized Log!");
	int a = 5;
	MR_INFO("Hello! Var={0}", a);


	auto app = Miro::CreateApplication();
	app->Run();
	delete app;
}

#endif