#pragma once
#include "Core.h"

#include "Window.h"
#include "Miro/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Miro/ImGui/ImGuiLayer.h"

namespace Miro
{

	class MIRO_API Application
	{
	public:
		Application();
		//virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

	private:
		static Application* s_Instance;
	};

	// To be defined in Client
	Application* CreateApplication();
}
