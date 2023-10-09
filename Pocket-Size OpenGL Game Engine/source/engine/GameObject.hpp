#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <GLM/glm.hpp>

#include "Window.hpp"
#include "Renderer2D.hpp"

namespace pse {
	class GameObject {
	public:
		GameObject(glm::vec2 pos, glm::vec2 scale);
		~GameObject();

		void draw(Renderer2D& renderer2D, Window& window);

		glm::vec2 position;
		glm::vec2 size;
	};
}

#endif // !GAME_OBJECT_HPP