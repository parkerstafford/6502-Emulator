#include <iostream>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Memory {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte data[MAX_MEM];

    void Initialize() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            data[i] = 0;
        }
    }

    Byte operator[] (u32 Address) const {
        return data[address];
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

    Byte Fetch(u32 &ticks, Mem &memory) {
        Byte data = memory[pc];
        PC++;
        cycles--;
    }

    static constexpr Byte
        INS_LDA_IM = 0xA9;

    void Execute(u32 ticks, Memory &memory) {
        while (Cycles > 0) {
            Byte ins = Fetch(ticks, memory);
            switch (ins) {
                case INS_LDA_IM {
                    Fetch(ticks, memory)

                    A = Value;
                    Z = (A == 0);
                    N = (A & 0b10000000) > 0;
                    break;
                }
            }
        }
    }

};

int main() {
    Memory memory;
    CPU cpu;

    cpu.Reset(memory);
    cpu.Excecute(2, memory);

    return 0;
}
