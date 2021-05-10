#include <cstdint>
#include <iostream>

#include <interpreter.h>

void run(){
    std::uint32_t eax, ebx, ecx, edx;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        std::cout << "You did something wrong";
        return 1;
    }
    run();
    return 0;
}