#include <iostream>
#include <thread>
#include <queue>
#include <string>
#include <chrono>
#include <fstream>
#include "../include/configReader.h"
#include "../include/fileFinder.h"
#include "../include/timer.h"
#include "../include/types.h"



int main () {
    Config config;
    std::queue<std::string> tasks_queue;
    try {
        readConfig(config);
        std::cout << std::format("{:s}\n{:s}\n{:s}\n{:d}\n{:d}", config.path_name, config.file_name, config.file_counter, config.file_size, config.check_delay);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    // std::thread timer_thread(timer);
    return 0;
}