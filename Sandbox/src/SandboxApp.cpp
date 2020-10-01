#include <Miro.h>

class ExampleLayer : public Miro::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		MR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Miro::Event& event) override
	{
		MR_TRACE("{0}", event);
	}
};

class Sandbox : public Miro::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}


	~Sandbox() {}

};

Miro::Application* Miro::CreateApplication()
{
	return new Sandbox();
}