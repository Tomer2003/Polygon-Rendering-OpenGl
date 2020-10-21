#include "files_io.hpp"
#include <iostream>
std::string getDataFile(const std::string& fileName){
    std::ifstream inFile(fileName);
  
    std::string dataFile( (std::istreambuf_iterator<char>(inFile) ),
                       (std::istreambuf_iterator<char>()));

    return dataFile;
} 