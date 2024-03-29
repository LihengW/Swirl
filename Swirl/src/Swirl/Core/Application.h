#pragma once
#include "Swirl/Core/Core.h"
#include "Swirl/Core/Window.h"

#include "Swirl/Core/LayerStack.h"

#include "Swirl/Events/Event.h"
#include "Swirl/Events/ApplicationEvent.h"

#include "Swirl/ImGui/ImGuiLayer.h"
#include "Swirl/Core/Timestep.h"


namespace Swirl {
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		// windows and layers
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer; // innative imgui UI;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

