#include <stdio.h>
#include <stdlib.h>

struct CPU {
  using Byte = unsigned char;
  using Word = unsigned short;

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
};

int main() {
  CPU cpu;
  return 0;
}