#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <queue>
#include <string>

// Fake execution
void executeProgram(const std::string& path_name, bool& result_var);


void taskObservation(bool& isRunning, std::queue<std::string>& tasks_queue, std::mutex& queue_mutex);