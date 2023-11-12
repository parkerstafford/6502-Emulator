#include <iostream>


struct CPU {
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

    void Reset() {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = D = 0;
        A = X = Y = 0;
    }

};

int main() {
    CPU cpu;

    cpu.Reset();

    return 0;
}
