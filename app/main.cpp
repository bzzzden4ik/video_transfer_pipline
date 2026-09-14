#include <iostream>
#include <thread>
#include <queue>
#include <unordered_map>
#include <string>
#include "../include/configReader.h"
#include "../include/fileFinder.h"
#include "../include/timer.h"
#include "../include/types.h"


int main () {
    Config config;
    std::unordered_map<std::string, bool> files;
    std::queue<std::string> tasks_queue;
    bool isRunning = true;
    try {
        readConfig(config);
        fileFinderInit(config, files, tasks_queue);
        std::thread timer_thread(timerObservation, std::ref(isRunning), std::ref(config), std::ref(files), std::ref(tasks_queue));
        std::cout << "Press any button to finish proccess...\n";
        std::cin.get();
        isRunning = false;
        timer_thread.join();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}