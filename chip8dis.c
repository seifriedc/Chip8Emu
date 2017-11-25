// Chris Seifried
// CHIP-8 Disassembler

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int disInstruction(int pc, unsigned char* buf);

int main(int argc, char** argv) {

    // Read in rom file
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Could not open the file %s\n", argv[1]);
        exit(-1);
    }

    // Get rom file size
    int size;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Allocate memory for rom
    unsigned char* buffer = malloc(size+0x200);

    // Read rom into memory starting at 0x200
    // CHIP-8 puts roms in memory at 0x200
    fread(buffer+0x200, size, 1, f);
    fclose(f);

    // Program counter
    int pc = 0x200;

    // Disassemble instructions in rom
    while (pc < (size + 0x200))
    {
        // Disassemble next instruction
        disInstruction(pc, buffer);

        // Increment program counter
        pc += 2;
    }

    return 0;
}

int disInstruction(int pc, unsigned char* buf)
{
    return -1;
}
