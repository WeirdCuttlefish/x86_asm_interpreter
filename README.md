# x86_asm_interpreter
## Keywords/Phrases
**Waypoint**
_foo:
    bar
The _ will search for text then a colon - if there is no colon an error arises
**Section**
SECTION .foo
Creates a section .foo: This could be .data, .bss, .text etc.
**Global**
global _foo
Identifies where to begin the program
## Instructions
MOV  x,y - Copies y into x
SUB  x,y - x = x-y
MUL  EBX - EAX = EAX * EBX
DIV  EBX - EAX = EAX/EBX
INC  EAX - Increments EAX
DEC  EAX - Decrements EAX
PUSH EAX - Pushes EAX to the stack
POP  EAX - Pops EAX from the stack
INT  80h - Calls opcode 80h
JMP  txt - Jumps to .txt in file
CMP  x,y - Compares x and y
JNE  txt - Jumps to .txt in file if above CMP is not equal
JE   txt - Jumps to .txt in file if above CMP is equal
JZ   txt - Functionally same as above
CALL txt - Runs the function txt

ADD:
XOR

## Pointers
EAX  - Regular Pointer
EBX  - Regular Pointer
ECX  - Regular Pointer
EDX  - Regular Pointer
ESP  - Stack Pointer
EBP  - Base Pointer

ADD:
EDI
ESI
