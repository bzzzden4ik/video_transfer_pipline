#include "../include/timer.h"


void timerObservation (bool& isRunning, Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue) {
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::seconds(config.check_delay));
        lookForNewFiles(config, files, tasks_queue);
    }
    std::cout << "Timer Thread just finished.";
}