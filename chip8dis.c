// Chris Seifried
// CHIP-8 Disassembler

// NOTE: ROMS are in the Public Domain and are free
// 	 to use, modify, and distribute.

// NOTE: use "od -tx1 <file>" to dump rom contents

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void disInstruction(int pc, unsigned char* buf);

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
        printf("\n");

        // Increment program counter
        pc += 2;
    }

    return 0;
}

void disInstruction(int pc, unsigned char* buf)
{
    uint16_t tmp = *(uint16_t*)(buf+pc);        // Get instr
    uint16_t inst = (tmp >> 8) | (tmp << 8);    // Flip endianness
    uint8_t top = (inst >> 12);                 // Get top half-byte

    // Print address and op
    printf("%04x %04x    ", pc, inst);

    // Act on op
    switch (top)
    {
    	case 0x0:
            switch (inst & 0x00FF)
            {
               	case 0xE0: printf("%s", "CLRSCREEN"); break;
               	case 0xEE: printf("%s", "RET"); break;
                case 0x00: printf("%s", "NOP"); break;
               	default:   printf("UNKNOWN 0x0 OP"); break;
            }
            break;
        case 0x1: printf("%s 0x%03x", "JA", (inst & 0x0FFF)); break;
        case 0x2: printf("%s (0x%03x)", "CALL", (inst & 0x0FFF)); break;
        case 0x3: printf("%s V%X, 0x%02x", "SKP.EQ", (inst>>2 & 0x0F), (inst & 0x00FF)); break;
       	case 0x4: printf("%s V%X, 0x%02x", "SKP.NEQ", (inst>>2 & 0x0F), (inst & 0x00FF)); break;
       	case 0x5: printf("%s V%X, V%X", "SKP.EQ", (inst>>2 & 0x0F), (inst>>1 & 0x000F)); break;
        case 0x6: printf("%s V%X, 0x%02x", "MOVI", (inst>>2 & 0x0F), (inst & 0x00FF)); break;
        case 0x7: printf("%s V%X, 0x%02x", "ADDI", (inst>>2 & 0x0F), (inst & 0x00FF)); break;
       	case 0x8: printf("0x8 not implemented yet"); break;
       	case 0x9: printf("%s V%X, V%X", "SKP.NEQ", (inst>>2 & 0x0F), (inst>>1 & 0x000F)); break;
        case 0xA: printf("%s I, 0x%03x", "MOVI", (inst & 0x0FFF)); break;
        case 0xB: printf("%s 0x%03x(V0)", "JA", (inst & 0x0FFF)); break;
       	case 0xC: printf("0xC not implemented yet"); break;
       	case 0xD: printf("0xD not implemented yet"); break;
       	case 0xE: printf("0xE not implemented yet"); break;
       	case 0xF: printf("0xF not implemented yet"); break;
       	default: break;
    }
}
