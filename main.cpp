#include <iostream>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Memory {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialize() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }
};

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

    void Reset(Memory &memory) {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = D = 0;
        A = X = Y = 0;

        memory.Initialize();
    }

};

int main() {
    Memory memory;
    CPU cpu;

    cpu.Reset(memory);

    return 0;
}
