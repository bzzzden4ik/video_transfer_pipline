#pragma once
#include <string>


/** Config structure that contains next fields:
 * @property path_name  variable [std::string] for realative or absolute pathname straight to the folder where your files are
 * @property file_name  variable [std::string] for common filename that you files start with [name...]
 * @property file_counter  variable [std::string] for counter that allows define files from each others [...00000]
 * @property check_delay  variable [unsigned] that contains time between file checker executions
 * @property file_size  variable [unsigned] that contains expected file size
 **/
struct Config {
    std::string path_name;
    std::string file_name;
    std::string file_counter;
    unsigned file_size;
    unsigned check_delay;
};