#include <cstdint>
#include <fstream>
#include <iostream>

#include "memory.h"

int main(int argc, char* argv[]){
    Memory RAM;
    
    RAM.virtualMemory[65535] = 0xFF;
    RAM.virtualMemory[65534] = 0xEE;
    RAM.virtualMemory[65533] = 0xDD;
    RAM.virtualMemory[65532] = 0xCC;
    RAM.eax = 0xFFFF;

    std::cout << RAM.valueAtLocation(RAM.eax);
    
    return 0;
}