#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <unordered_map>
#include <filesystem>
#include "./types.h"

/**
 * 
 */
void fileFinderInit (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue);

/**
 * 
 */
void lookForNewFiles (const Config& config, std::unordered_map<std::string, bool>& files, std::queue<std::string>& tasks_queue, std::mutex& files_mutex, std::mutex& queue_mutex);