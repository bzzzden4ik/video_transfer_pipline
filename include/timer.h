#pragma once
#include <chrono>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <queue>
#include "./fileFinder.h"


/**
 * Timer function that starts in new thread.
 * @param isRunning  Bool that controlls working flow
 * @param config  project config (take a look at README.md)
 * @param files  std::unordered_map that save used files (their path names) in history
 * @param tasks_queue  std::queue that organize queue of tasks. Pushing new files and poping old ones
 * @param file_mutex  Mutex for files map
 * @param queue_mutex  Mutex for files queue
 */
void timerObservation (bool& isRunning, Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue, std::mutex& file_mutex, std::mutex& queue_mutex);