#include "../include/configReader.h"

std::pair<std::string, std::string> splitParams(const std::string& param) {
    size_t divider_index = param.find('=', 0);
    if (divider_index == std::string::npos) {
        throw std::invalid_argument("Wrong config parameter recieved. Take a look in README.md.");
    }
    std::string param_key = param.substr(0, divider_index);
    std::string param_value = param.substr(divider_index + 1);
    return {param_key, param_value};
}

void readConfig (Config& config) {
    std::ifstream input_stream("./config/config.cfg");
    std::string param;
    while (std::getline(input_stream, param)) {
        size_t first_char = param.find_first_not_of(" \t\n\r");
        if (param.empty() || first_char == std::string::npos) continue;
        param = param.substr(first_char);
        if (param[0] == '#') continue;
        std::pair<std::string, std::string> splited_params = splitParams(param);
        if (splited_params.first == "path") {
            config.path_name = splited_params.second;
        } else if (splited_params.first == "fileName") {
            config.file_name = splited_params.second;
        } else if (splited_params.first == "fileCounter") {
            config.file_counter = splited_params.second;
        } else if (splited_params.first == "fileSize") {
            config.file_size = std::stoi(splited_params.second);
        } else if (splited_params.first == "checkDelay") {
            config.check_delay = std::stoi(splited_params.second);
        } else {
            throw std::invalid_argument("Wrong cfg parameter recieved: " + splited_params.first);
        }
    }
}