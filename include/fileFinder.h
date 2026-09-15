#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <unordered_map>
#include <filesystem>
#include "./types.h"

/**
 * Function that init files map and tasks_queue. It starts once on the programm starting
 * @param config  project config (take a look at README.md)
 * @param files  std::unordered_map that save used files (their path names) in history
 * @param tasks_queue  std::queue that organize queue of tasks
 */
void fileFinderInit (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue);

/**
 * Function that once a [config.check_delay] looking for new files or other changes
 * @param config  project config (take a look at README.md)
 * @param files  std::unordered_map that save used files (their path names) in history
 * @param tasks_queue  std::queue that organize queue of tasks. Pushing new files and poping old ones
 * @param file_mutex  Mutex for files map
 * @param queue_mutex  Mutex for files queue
 */
void lookForNewFiles (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue, std::mutex& files_mutex, std::mutex& queue_mutex);