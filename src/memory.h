#include <cstdint>

class Memory{
    public:
        std::uint32_t eax, ebx, ecx, edx, //uint32_t Max = 0xFFFF
                      eip, ebp, esp;      //CPU Cache
        std::uint8_t virtualMemory[65535];//[16.77696 mb]//RAM
        //EAX = Pointer but [EAX] = content @ EAX
        //EIP won't do anything as of right now
    public:
        Memory(){
            std::cout << "CPU + Memory Initialized" << "\n";
        }
    
    //General
    std::uint32_t valueAtLocation(int high){
        //Modify to do any size!!!
        std::uint32_t value = 0;
        value |= virtualMemory[high - 3];
        value |= virtualMemory[high - 2] << 8 ;
        value |= virtualMemory[high - 1] << 16;
        value |= virtualMemory[high    ] << 24;
        return value;
    }

    void copy(std::uint32_t destination, std::uint32_t start){
        virtualMemory[destination    ] = virtualMemory[start    ];
        virtualMemory[destination - 1] = virtualMemory[start - 1];
        virtualMemory[destination - 2] = virtualMemory[start - 2];
        virtualMemory[destination - 3] = virtualMemory[start - 3];
    }

    //Stack -- NEEDS UPDATE!
    void pushStackFrame(){
        copy(esp, ebp);   //Store old EBP 
        ebp = esp-4;      //Frame pointer now at the old stack pointer-4
        copy(ebp-4 , eax);//Kinda hacky solution -- will rewrite to make accurate
        eax = ebp-4;
        copy(ebp-8 , ebx);
        ebx = ebp-8;
        copy(ebp-12, ecx);
        ecx = ebp-12;
        copy(ebp-16, edx);
        edx = ebp-16;
    }

    void popStackFrame(){
        ebp = valueAtLocation(ebp+4);
        eax = ebp - 4;
        ebx = ebp - 8;
        ecx = ebp - 12;
        edx = ebp - 16;
    }

    void push(int& x){
        //ADD IN STACK UPDATE
    }
    void pop (int& x){
        //ADD IN STACK UPDATE
    }

    //Heap -- NEEDS UPDATE TO MAKE DYNAMIC!!!
    private:
        int heapTop = -1;
    public:
        void saveVariable(std::uint8_t data[]){
            heapTop = heapTop + sizeof(*data)/sizeof(std::uint8_t);
            for(int i = 0; i <  sizeof(*data)/sizeof(std::uint8_t); i++){
                virtualMemory[heapTop - i] = data[i];
            }
        }
};