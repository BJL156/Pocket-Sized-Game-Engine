#ifndef SHADER_HPP
#define SHADER_HPP

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/type_ptr.hpp>
#include <SPDLOG/spdlog.h>

#include "Utils.hpp"

#include <string>
#include <stdexcept>

namespace pse {
	class Shader {
	public:
		Shader(std::string vertexFilepath, std::string fragmentFilepath);
		~Shader();

		void use() { glUseProgram(m_Id); }

		void setMat4(std::string name, glm::mat4 mat4) { glUniformMatrix4fv(glGetUniformLocation(m_Id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat4)); }
		void setMat3(std::string name, glm::mat3 mat3) { glUniformMatrix3fv(glGetUniformLocation(m_Id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat3)); }
		void setMat2(std::string name, glm::mat2 mat2) { glUniformMatrix2fv(glGetUniformLocation(m_Id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat2)); }

		void setVec4(std::string name, glm::vec4 vec4) { glUniform4fv(glGetUniformLocation(m_Id, name.c_str()), 1, glm::value_ptr(vec4)); }
		void setVec4(std::string name, float x, float y, float z, float w) { glUniform4f(glGetUniformLocation(m_Id, name.c_str()), x, y, z, w); }

		void setVec3(std::string name, glm::vec3 vec3) { glUniform3fv(glGetUniformLocation(m_Id, name.c_str()), 1, glm::value_ptr(vec3)); }
		void setVec3(std::string name, float x, float y, float z) { glUniform3f(glGetUniformLocation(m_Id, name.c_str()), x, y, z); }

		void setVec2(std::string name, glm::vec2 vec2) { glUniform2fv(glGetUniformLocation(m_Id, name.c_str()), 1, glm::value_ptr(vec2)); }
		void setVec2(std::string name, float x, float y) { glUniform2f(glGetUniformLocation(m_Id, name.c_str()), x, y); }
	private:
		void createShaderProgram(std::string& vertexFilepath, std::string& fragmentFilepath);

		static bool isShaderCompiled(unsigned int shader);
		static bool isProgramLinked(unsigned int program);

		unsigned int m_Id;
	};
}

#endif // !SHADER_HPP