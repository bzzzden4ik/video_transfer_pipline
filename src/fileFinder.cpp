#include "../include/fileFinder.h"


void fileFinderInit (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue) {
    std::string full_path = config.path_name;
    size_t file_name_size = config.file_name.size();
    if (!std::filesystem::exists(full_path) || !std::filesystem::is_directory(full_path)) {
        throw std::invalid_argument("Wrong path name. There is no: " + full_path + " found");
    }
    for (const auto& entry : std::filesystem::directory_iterator(full_path)) {
        auto name = entry.path().filename();
        if (entry.is_regular_file() && name.extension().string() == ".mp4" && name.string().substr(0, file_name_size + 1) == config.file_name + config.file_counter) {
            files[name.string()] = true;
            tasks_queue.push(name.string());
            std::cout << name << " initiated and added to queue.\n";
        }
    }
}

void lookForNewFiles (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue) {
    std::string full_path = config.path_name;
    size_t file_name_size = config.file_name.size();
    for (const auto& entry : std::filesystem::directory_iterator(full_path)) {
        auto name = entry.path().filename();
        if (files.contains(name.string())) {
            continue;
        }
        if (entry.is_regular_file() && name.extension().string() == ".mp4" && name.string().substr(0, file_name_size + 1) == config.file_name + config.file_counter) {
            files[name.string()] = true;
            tasks_queue.push(name.string());
            std::cout << name << " just appeared and added to queue.\n";
        }
    }
}