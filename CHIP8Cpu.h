// Chris Seifried
// Constantino Flouras

#ifndef CHIP8EMU_CHIP8CPU_H
#define CHIP8EMU_CHIP8CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

#define ROM_START 0x200

class CHIP8Cpu {
public:
    explicit CHIP8Cpu(const char *romname)
    {
        // ROM input
        ifstream rom;

        // Open the ROM file
        rom.open(romname);

        // If the ROM file does not open, then we'll abort.
        if (rom.fail()) {
            cout << "Error opening file " << romname << ", aborting." << endl;
            abort();
        }

        // Now, we need the ROM file size.
        long romSize = rom.tellg();
        rom.seekg( 0, std::ios::end );
        romSize = rom.tellg() - romSize;
        rom.seekg( 0, std::ios::beg );

        // Read the entirety of the ROM file into memory.

        /*
            About the CHIP-8 Memory Map
            ---------------------------

            Starting at address 0x200 (or 512 in decimal), memory space contains the
            ROM that was inputted by the user.
        */

        char * romStart = (char *) &memory[ROM_START];
        rom.read(romStart, romSize);

        // The ROM is now in memory. Close the ROM.
        rom.close();
    }

    void getInput();
    void nextInstruction();
    void render();

private:
    unsigned short opcode;      // stores the current opcode
    unsigned char memory[4096]; // 4K of memory

    // Stack and SP register
    char stack [48] {};         // Allows for 24 nested calls
    unsigned short sp;          // stack pointer

    // V registers, I register, and PC register
    char vregs [16] {};         // V registers
    unsigned short I = 0;       // I register
    unsigned short pc = 0x200;  // PC register

    // User input
    bool keys [16] {false};     // Keys are 1-15 inclusive



};

#endif //CHIP8EMU_CHIP8CPU_H
