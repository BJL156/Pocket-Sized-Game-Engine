#include "Application.hpp"

namespace pse {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		while (!m_Window.shouldClose()) {
			m_Window.update();

			m_Renderer2D.draw(m_Window.getSize());
		}
	}
}