// Chris Seifried
// Constantino Flouras

#ifndef CHIP8EMU_CHIP8CPU_H
#define CHIP8EMU_CHIP8CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <SDL2/SDL.h>
using namespace std;

typedef mt19937 RNG;

class CHIP8Cpu {
public:
    explicit CHIP8Cpu(const char *romname);
    ~CHIP8Cpu();
    void getInput();
    void nextInstruction();
    void render();
    ifstream rom;               // Input stream for the ROM file
    RNG rng;
    uniform_int_distribution<int> dist {0,255};


private:
    int pc = 0x200;             // Program counter
    int sp = 0;                 // Stack pointer
    int callstack[48] = {};     // Allows for 24 nested calls
    int vregs[16] = {};         // V registers
    bool keys[16] = {false};    // Keys are 1-15 inclusive
    int ireg = 0;               // I register
};

#endif //CHIP8EMU_CHIP8CPU_H
