#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "memory.h"

void run(std::string file){
    Memory VM;
    std::unordered_map<std::string, int> wayPoints;
    std::unordered_map<std::string, int> variables;
    //Parse File
    std::string section = "NONE";
    for(int i = 0; i < file.size(); i++){
        //Only supports SECTION.TEXT
    }
}