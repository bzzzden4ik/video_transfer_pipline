#pragma once
#include <chrono>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <queue>
#include "./fileFinder.h"


void timerObservation (bool& isRunning, Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue, std::mutex& file_mutex, std::mutex& queue_mutex);