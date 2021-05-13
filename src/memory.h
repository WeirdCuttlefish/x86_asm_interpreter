#include <cstdint>

class Memory{
    public:
        std::uint32_t eax, ebx, ecx, edx, //uint32_t Max = 0xFFFF
                      eip, ebp, esp;      //CPU Cache
        std::uint8_t virtualMemory[65535];//[16.77696 mb]//RAM
        //EAX = Pointer but [EAX] = content @ EAX
        //Maybe make my registers linked list nodes to make stack easier?

    public:
        Memory(){
            std::cout << "CPU + Memory Initialized" << "\n";
        }
    
    //STACK STUFF
    std::uint32_t valueAtLocation(int high){
        //Converts from Little Endian!
        std::uint32_t value = 0;
        value |= virtualMemory[high - 3];
        value |= virtualMemory[high - 2] << 8 ;
        value |= virtualMemory[high - 1] << 16;
        value |= virtualMemory[high    ] << 24;
        return value;
    }

    void pushStackFrame(){
        //Convert to Little Endian
        virtualMemory[esp] = ebp;
        ebp = esp - 2;
        esp = ebp - 2; 
    }

    void popStackFrame(){
        int returnLocation = virtualMemory[ebp+4];
        eip = returnLocation;
    }
    void push(int& x){
        //Do I create a new stack frame for this ???
    }
    void pop (int& x){
        //pop(eax) -> eax = old eax
    }
    //HEAP STUFF
    
};