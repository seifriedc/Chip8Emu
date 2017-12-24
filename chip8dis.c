// Chris Seifried
// CHIP-8 Disassembler

// NOTES: - ROMS are in the Public Domain and are free
// 	        to use, modify, and distribute.
//        - Use "od -tx1 <file>" to dump rom contents
//        - Instruction info is based off of documentation found on Wikipedia

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Traditionally, the CHIP-8 interpreter occupied the first 512 (0x200) bytes
// of the memory space. So roms are loaded at this address
#define ROM_START 0x200

void disInstruction(int pc, unsigned char* buf);

int main(int argc, char** argv) {

    // Read in rom file
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Could not open the file %s\n", argv[1]);
        exit(-1);
    }

    // Get rom file size
    long size;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Allocate memory for rom
    unsigned char* buffer = malloc(size + ROM_START);

    // Read rom into memory starting at address 0x200
    fread(buffer + ROM_START, size, 1, f);
    fclose(f);

    // Program counter
    int pc = ROM_START;

    // Disassemble instructions in rom
    while (pc < (size + ROM_START))
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
                case 0xE0: printf("%s", "CLS"); break;
                case 0xEE: printf("%s", "RET"); break;
                case 0x00: printf("%s", "NOP"); break;
                default:   printf("UNKNOWN 0x0 OP"); break;
            } break;
        case 0x1: printf("%s 0x%03x", "JP", (inst & 0x0FFF));break;
        case 0x2: printf("%s (0x%03x)", "CALL", (inst & 0x0FFF)); break;
        case 0x3: printf("%s V%X, 0x%02x", "SE", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x4: printf("%s V%X, 0x%02x", "SNE", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x5: printf("%s V%X, V%X", "SE", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
        case 0x6: printf("%s V%X, 0x%02x", "LD", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x7: printf("%s V%X, 0x%02x", "ADD", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x8:
            switch (inst & 0x000F)
            {
                case 0x0: printf("%s V%X, V%X", "LD", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x1: printf("%s V%X, V%X", "OR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x2: printf("%s V%X, V%X", "AND", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x3: printf("%s V%X, V%X", "XOR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x4: printf("%s V%X, V%X", "ADD", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x5: printf("%s V%X, V%X", "SUB", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x6: printf("%s V%X, V%X", "SHR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x7: printf("%s V%X, V%X", "SUBN", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0xE: printf("%s V%X, V%X", "SHL", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                default:  printf("UNKNOWN 0x8 OP"); break;
            } break;
        case 0x9: printf("%s V%X, V%X", "SNE", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
        case 0xA: printf("%s I, 0x%03x", "LD", (inst & 0x0FFF)); break;
        case 0xB: printf("%s 0x%03x(V0)", "JP", (inst & 0x0FFF)); break;
        case 0xC: printf("%s V%X, 0x%02x", "RND", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0xD: printf("%s V%X, V%X, %#x", "DRW", (inst>>8 & 0x0F), (inst>>4 & 0x00F), (inst & 0x000F)); break;
        case 0xE:
            switch (inst & 0x00FF)
            {
                case 0x9E: printf("%s V%X", "SKP", (inst>>8 & 0x0F)); break;
                case 0xA1: printf("%s V%X", "SKNP", (inst>>8 & 0x0F)); break;
                default:   printf("UNKNOWN 0xE OP"); break;
            } break;
        case 0xF:
            switch (inst & 0x00FF)
            {
                case 0x07: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "DT"); break;
                case 0x0A: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "K"); break;
                case 0x15: printf("%s %s, V%X", "LD", "DT", (inst>>8 & 0x0F)); break;
                case 0x18: printf("%s %s, V%X", "LD", "ST", (inst>>8 & 0x0F)); break;
                case 0x1E: printf("%s %s, V%X", "ADD", "I", (inst>>8 & 0x0F)); break;
                case 0x29: printf("%s %s, V%X", "LD", "F", (inst>>8 & 0x0F)); break;
                case 0x33: printf("%s %s, V%X", "LD", "B", (inst>>8 & 0x0F)); break;
                case 0x55: printf("%s %s, V%X", "LD", "(I)", (inst>>8 & 0x0F)); break;
                case 0x65: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "(I)"); break;
                default:  printf("UNKNOWN 0xF OP"); break;
            } break;
        default: break;
    }
}
