#pragma once


#include "Miro/Layer.h"

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

		float m_Time = 0;
	};
}