#include "Utils.hpp"

namespace pse {
    namespace utils {
        std::string getFileContents(std::string filepath) {
            std::ifstream file(filepath);
            if (!file.is_open()) {
                spdlog::error("UTILS_HPP::Failed to open file: {}.", filepath);
                throw std::runtime_error("Failed to open file: " + filepath);
                return std::string{};
            }

            std::string fileContents{ std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };

            file.close();

            return fileContents;
        }
    }
}