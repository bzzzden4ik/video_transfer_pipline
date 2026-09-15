#include "../include/timer.h"


void timerObservation (bool& isRunning, Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue, std::mutex& files_mutex, std::mutex& queue_mutex) {
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::seconds(config.check_delay));
        lookForNewFiles(config, files, tasks_queue, files_mutex, queue_mutex);
    }
    std::cout << "[System] Timer Thread just finished.\n";
}