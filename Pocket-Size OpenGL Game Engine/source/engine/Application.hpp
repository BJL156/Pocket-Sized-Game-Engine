#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window.hpp"
#include "Renderer2D.hpp"

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
	};
}

#endif // !APPLICATION_HPP