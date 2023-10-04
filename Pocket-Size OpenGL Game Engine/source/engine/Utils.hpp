#ifndef UTILS_HPP
#define UTILS_HPP

#include <SPDLOG/spdlog.h>

#include <string>
#include <fstream>
#include <stdexcept>

namespace pse {
	namespace utils {
#ifdef NDEBUG
		const bool enableDebugMode = false;
#else
		const bool enableDebugMode = true;
#endif // NDEBUG

		std::string getFileContents(std::string filepath);
	}
}

#endif // !UTILS_HPP