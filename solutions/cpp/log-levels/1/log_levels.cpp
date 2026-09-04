#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    // log_line::message("[ERROR]: Invalid operation");
    size_t keyPosition = line.find(' ');
    std::string alteredMessage = line.substr(keyPosition + 1);
    return alteredMessage;   
}

std::string log_level(std::string line) {
    // return the log level
    size_t start = line.find('[');
    size_t end = line.find(']');
    std::string result = line.substr(start + 1, end - start - 1);
    return result;
}

std::string reformat(std::string line) {
    // return the reformatted message
    log_line::message(line);
    log_line::log_level(line);
    return log_line::message(line) + " (" + log_line::log_level(line) + ')';
}

}  // namespace log_line
