#include "../include/taskExecutor.h"


void executeProgram(const std::string& path_name, bool& result_var) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution distr(0.5);
    bool result = distr(gen);
    result_var = result;
}

void lookForTask(std::queue<std::string>& tasks_queue, std::mutex& queue_mutex) {
    bool result;
    while (true) {
        queue_mutex.lock();
        if (!tasks_queue.empty()) {
            std::string current_task = tasks_queue.front();
            tasks_queue.pop();
            queue_mutex.unlock();
            std::cout << "Task \"" << current_task << "\" started\n";
            std::thread execution_thread(executeProgram, std::ref(current_task), std::ref(result));
            execution_thread.join();
            std::cout << "Task \"" << current_task << "\" finished\n";
        } else {
            queue_mutex.unlock();
            std::cout << "There is no task yet.\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}