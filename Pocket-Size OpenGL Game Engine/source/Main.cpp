#include "ENGINE/Application.hpp"

#include <stdexcept>
#include <iostream>

int main() {
	pse::Application application{};
	try {
		application.run();
	} catch(std::exception& exception) {
		spdlog::error("Caught exception: {}", exception.what());

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}