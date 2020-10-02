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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;


		void Begin();
		void End();
	private:

		float m_Time = 0;
	};
}