#ifndef RENDERER2D_HPP
#define RENDERER2D_HPP

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/matrix_transform.hpp>
#include <SPDLOG/spdlog.h>

#include "Shader.hpp"

#include <stdexcept>

namespace pse {
	class Renderer2D {
	public:
		Renderer2D();
		~Renderer2D();

		void draw(const glm::vec2 position, const glm::vec2 scale, const glm::vec2 windowSize);
	private:
		void createRenderData();

		unsigned int m_Vbo;
		unsigned int m_Vao;
		unsigned int m_Ebo;

		Shader shader {
			"RESOURCES/ENGINE/SHADERS/solid2d.vert",
			"RESOURCES/ENGINE/SHADERS/solid.frag"
		};
	};
}

#endif // !RENDERER2D_HPP