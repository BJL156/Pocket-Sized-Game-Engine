#include "Shader.hpp"

namespace pse {
	Shader::Shader(std::string vertexFilepath, std::string fragmentFilepath) {
		createShaderProgram(vertexFilepath, fragmentFilepath);
	}

	Shader::~Shader() {
		glDeleteProgram(m_Id);
	}

	void Shader::createShaderProgram(std::string& vertexFilepath, std::string& fragmentFilepath) {
		std::string vertexCode = utils::getFileContents(vertexFilepath);
		std::string fragmentCode = utils::getFileContents(fragmentFilepath);

		if (utils::enableDebugMode) {
			spdlog::info("Vertex code:\n{}", vertexCode);
			spdlog::info("Fragment code:\n{}", fragmentCode);
		}


		const char* vertexShaderSource = vertexCode.c_str();
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);

		bool vertexSuccess = false;
		if (utils::enableDebugMode) {
			vertexSuccess = isShaderCompiled(vertexShader);
			if (!vertexSuccess) {
				spdlog::error("SHADER_HPP::Failed to compile vertex shader.");
			}
		}

		const char* fragmentShaderSource = fragmentCode.c_str();
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(fragmentShader);

		bool fragmentSuccess = false;
		if (utils::enableDebugMode) {
			fragmentSuccess = isShaderCompiled(fragmentShader);
			if (!fragmentSuccess) {
				spdlog::error("SHADER_HPP::Failed to compile fragment shader.");
			}
		}

		m_Id = glCreateProgram();
		glAttachShader(m_Id, vertexShader);
		glAttachShader(m_Id, fragmentShader);
		glLinkProgram(m_Id);

		bool shaderProgramSuccess = false;
		if (utils::enableDebugMode) {
			shaderProgramSuccess = isProgramLinked(m_Id);
			if (!shaderProgramSuccess) {
				spdlog::error("SHADER_HPP::Failed to link program.");
			}
		}

		if (utils::enableDebugMode) {
			if (!vertexSuccess || !fragmentSuccess || !shaderProgramSuccess) {
				spdlog::error("SHADER_HPP::Failed to create shader.");
				throw std::runtime_error("Failed to create shader.");
			}
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	bool Shader::isShaderCompiled(unsigned int shader) {
		int success;
		char infoLog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			spdlog::error("SHADER_HPP::Failed to compile shader: {}.", infoLog);
			return false;
		}

		return true;
	}

	bool Shader::isProgramLinked(unsigned int program) {
		int success;
		char infoLog[512];

		glGetShaderiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(program, 512, nullptr, infoLog);
			spdlog::error("SHADER_HPP::Failed to link program: {}.", infoLog);
			return false;
		}

		return true;
	}
}