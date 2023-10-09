#include "GameObject.hpp"

namespace pse {
	GameObject::GameObject(glm::vec2 pos, glm::vec2 scale)
		: position(pos), size(scale) {

	}

	GameObject::~GameObject() {

	}

	void GameObject::draw(Renderer2D& renderer2D, Window& window) {
		renderer2D.draw(position, size, window.getSize());
	}
}