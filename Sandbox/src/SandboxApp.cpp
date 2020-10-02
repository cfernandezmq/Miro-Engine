#include <Miro.h>

#include "ImGui/imgui.h"

class ExampleLayer : public Miro::Layer
{
public:
	ExampleLayer() : Layer("Example") 
	{

	}

	void OnUpdate() override
	{
		// MR_INFO("ExampleLayer::Update");

		if (Miro::Input::IsKeyPressed(MR_KEY_TAB))
		{
			MR_INFO("TAB KEY IS PRESSED!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world");
		ImGui::End();
	}

	void OnEvent(Miro::Event& event) override
	{
		// MR_TRACE("{0}", event);

		if (event.GetEventType() == Miro::EventType::KeyPressed)
		{
			Miro::KeyPressedEvent& e = (Miro::KeyPressedEvent&)event;
			if (e.GetKeyCode() == MR_KEY_TAB)
			{
				MR_TRACE("Tab key is pressed (event)!");
			}
			MR_TRACE("{0}", (char)e.GetKeyCode());
		}
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