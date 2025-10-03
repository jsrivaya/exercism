#include <string>

namespace log_line {
    std::string message(const std::string line) {
        size_t errorPos = line.find("[ERROR]: ");
        if (errorPos != std::string::npos) {
            return line.substr(errorPos+9);
        }
        size_t warningPos = line.find("[WARNING]: ");
        if (warningPos != std::string::npos) {
            return line.substr(warningPos+11);
        }
        size_t infoPos = line.find("[INFO]: ");
        if (infoPos != std::string::npos) {
            return line.substr(infoPos+8);
        }
        return "";
    }

    std::string log_level(const std::string line) {
        size_t pos = line.find("INFO");
        if (pos != std::string::npos) {
            return "INFO";
        }
        pos = line.find("WARNING");
        if (pos != std::string::npos) {
            return "WARNING";
        }
        pos = line.find("ERROR");
        if (pos != std::string::npos) {
            return "ERROR";
        }
        return "";
    }

    std::string reformat(const std::string line) {
        return message(line) + " (" + log_level(line) + ")";
    }
}
