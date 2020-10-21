#pragma once
#include <fstream>
#include <string>
#include <stdlib.h>

/**
 * @brief The function return data source file
 * 
 * @param fileName - file name 
 * @return std::string - data source file
 */
std::string getDataFile(const std::string& fileName);