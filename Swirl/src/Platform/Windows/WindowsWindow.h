#pragma once
#include "Swirl/Core/Window.h"
#include <GLFW/glfw3.h>
#include "Swirl/Renderer/GraphicsContext.h"

namespace Swirl {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth () const override { return m_Data.Width; }
		inline unsigned int GetHeight () const override { return m_Data.Height ;}

		// Window Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_window;
		Scope<GraphicsContext> m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback; // dont change, use this func to call the callback func
		};
		WindowData m_Data;
	};
}