#include <iostream>


struct CPU {
    using Byte = unsigned char;
    using Word = unsigned short;

    Word PC; // Program Counter
    Word SP;    // Stack Pointer

    Byte A, X, Y; // Registers

    Byte C : 1; // Status Flags
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

};

int main() {
    CPU cpu;

    return 0;
}
