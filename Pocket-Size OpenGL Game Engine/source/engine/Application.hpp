#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window.hpp"
#include "Renderer2D.hpp"
#include "GameObject.hpp"

#include <string>

namespace pse {
	class Application {
	public:
		Application();
		~Application();

		void run();
	private:
		const uint32_t m_Width = 800;
		const uint32_t m_Height = 600;
		const std::string m_Title = "PSE";
		Window m_Window{ m_Width, m_Height, m_Title };

		Renderer2D m_Renderer2D{};
		GameObject m_GameObject{ glm::vec2(40.0f, 10.0f), glm::vec2(10.0f, 50.0f) };
	};
}

#endif // !APPLICATION_HPP