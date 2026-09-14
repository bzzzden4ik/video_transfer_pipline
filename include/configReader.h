#pragma once
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include "./types.h"


/** SplitParams split string value by literal "=" into pair<std::string, std::string>
 * @param param  string value
**/
std::pair<std::string, std::string> splitParams(const std::string& param);

/** ReadConfig allows read cfg file and set params
 * @param config  Config structure that has main fileds
 **/
void readConfig (Config& config);

// void readConfig (std::string& path_name, std::string& file_name, std::string& file_counter, unsigned& check_delay, unsigned& file_size);
