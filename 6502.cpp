#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;


struct Memory {
  // constexpr means it's possible to evaluate the value at compile time
  // it must be static in this context
  static constexpr u32 MAX_MEM = 1024 * 64;
  Byte Data[MAX_MEM];

  void Initialize() {
    for ( u32 i = 0; i < MAX_MEM; i++ ) {
      Data[i] = 0;
    }
  }

  /* [] allows u to access the Data array within Memory using array-like syntax
  Rather than accessing the Data array directly via mem.Data[index], using this operator
  preserves encapsulation
   */
  Byte operator[]( u32 Address ) const {
    // assert that Address < MAX_MEM
    return Data[Address];
  }
};

struct CPU {
  Word PC; // program counter
  Word SP; // stack pointer

  Byte A, X, Y, PS; // registers, processor status

  // bit-field notation, creating a 1 bit Byte field for status flags
  Byte C : 1;
  Byte Z : 1;
  Byte I : 1;
  Byte D : 1;
  Byte B : 1;
  Byte V : 1;
  Byte N : 1;
  
  void Reset( Memory& memory ) {
    PC = 0xFFFC;
    C = Z = I = B = V = N = D = 0;
    SP = 0x0100;
    A = X = Y = 0;
    memory.Initialize();
  }

  Byte FetchByte ( u32& cycles, Memory& memory ) {
    Byte data = memory[PC];
    PC++;
    cycles--;
    return data;
  }

  void Execute ( u32 cycles, Memory& memory ) {
    while ( cycles > 0 ) {
      Byte instruction = FetchByte( cycles, memory );
    }
  }
};

int main() {
  Memory mem;
  CPU cpu;
  cpu.Reset( mem );
  cpu.Execute( 2, mem );
  return 0;
}