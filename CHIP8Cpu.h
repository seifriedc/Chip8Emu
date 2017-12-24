// Chris Seifried
// Constantino Flouras

#ifndef CHIP8EMU_CHIP8CPU_H
#define CHIP8EMU_CHIP8CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class CHIP8Cpu {
public:
    explicit CHIP8Cpu(const char *romname);
    ~CHIP8Cpu();
    void getInput();
    void nextInstruction();
    void render();

private:
    int pc = {0x200};           // Program counter
    char callstack [48] = {};   // Allows for 24 nested calls
    char vregs [16] = {};       // V registers
    bool keys [16] = {false};   // Keys are 1-15 inclusive
    unsigned short ireg  = {0}; // I register
    ifstream rom;               // Input stream for the ROM file
};

#endif //CHIP8EMU_CHIP8CPU_H
