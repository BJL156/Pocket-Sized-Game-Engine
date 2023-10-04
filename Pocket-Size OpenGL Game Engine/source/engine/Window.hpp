#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <SPDLOG/spdlog.h>

#include "Utils.hpp"

#include <stdexcept>
#include <string>

namespace pse {
	class Window {
	public:
		Window(uint32_t width, uint32_t height, std::string title);
		~Window();

		bool shouldClose() { return glfwWindowShouldClose(m_Window); }

		void update();

		uint32_t getWidth() const { return m_Width; }
		uint32_t getHeight() const { return m_Height; }
		glm::vec2 getSize() const { return { m_Width, m_Height }; }
		GLFWwindow* getWindow() const { return m_Window; }
	private:
		void createGlfwWindow();

		static void glfwErrorCallback(int error, const char* description);

		uint32_t m_Width;
		uint32_t m_Height;
		std::string m_Title;
		GLFWwindow* m_Window;
	};
}

#endif // !WINDOW_HPP