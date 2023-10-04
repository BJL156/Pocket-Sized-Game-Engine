#include "Window.hpp"

namespace pse {
	Window::Window(uint32_t width, uint32_t height, std::string title)
		: m_Width(width), m_Height(height), m_Title(title) {
		createGlfwWindow();
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::update() {
		glfwSwapBuffers(m_Window);
		glfwPollEvents();

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::createGlfwWindow() {
		if (glfwInit() == GLFW_FALSE) {
			spdlog::error("WINDOW_HPP::Failed to initialize GLFW.");
			throw std::runtime_error("Failed to initialize GLFW.");
		}


		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
		if (m_Window == nullptr) {
			spdlog::error("WINODW_HPP::Failed to create a GLFW window.");
			throw std::runtime_error("Failed to create a GLFW window.");
		}
		glfwMakeContextCurrent(m_Window);

		if (utils::enableDebugMode) {
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetErrorCallback(glfwErrorCallback);
		}

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			spdlog::error("WINDOW_HPP::Failed to initialize GLAD.");
			throw std::runtime_error("Failed to initialize GLAD.");
		}
	}

	void Window::glfwErrorCallback(int error, const char* description) {
		spdlog::error("WINDOW_HPP::GLFW ERROR: {} CODE: {}.", description, error);
		throw std::runtime_error("Failed to initialize GLFW.");
	}
}