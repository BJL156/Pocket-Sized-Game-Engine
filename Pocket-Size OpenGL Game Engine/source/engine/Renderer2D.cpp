#include "Renderer2D.hpp"

namespace pse {
	pse::Renderer2D::Renderer2D() {
		createRenderData();
	}

	pse::Renderer2D::~Renderer2D() {
		glDeleteBuffers(1, &m_Vbo);
		glDeleteBuffers(1, &m_Ebo);
		glDeleteVertexArrays(1, &m_Vao);
	}

	void pse::Renderer2D::draw(const glm::vec2 windowSize) {
		shader.use();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::ortho(0.0f, windowSize.x, windowSize.y, 0.0f);

		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(100.0f, 100.0f, 0.0f));

		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("proj", proj);

		glBindVertexArray(m_Vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void pse::Renderer2D::createRenderData() {
		const float vertices[8] = {
			0.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			1.0f, 0.0f
		};
		const unsigned int indices[6] = {
			0, 2, 3,
			1, 2, 3
		};

		glGenBuffers(1, &m_Vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &m_Vao);
		glBindVertexArray(m_Vao);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glGenBuffers(1, &m_Ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}