#pragma once


#include "Miro/Layer.h"
#include "Miro/Events/ApplicationEvent.h"
#include "Miro/Events/KeyEvent.h"
#include "Miro/Events/MouseEvent.h"

namespace Miro
{
	class MIRO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowRezisedEvent(WindowResizeEvent& e);


	private:

		float m_Time = 0;
	};
}