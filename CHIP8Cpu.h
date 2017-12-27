// Chris Seifried
// Constantino Flouras

#ifndef CHIP8EMU_CHIP8CPU_H
#define CHIP8EMU_CHIP8CPU_H

#define ROM_START 0x200

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <SDL2/SDL.h>

// Screen functionality
#include "Screen/Screen.h"

using namespace std;

typedef mt19937 RNG;

class CHIP8Cpu {
public:
    explicit CHIP8Cpu(const char *romname);
    ~CHIP8Cpu();

    void getInput();
    void nextInstruction();
    void render();


    RNG rng;        // Random number gen engine
    uniform_int_distribution<int> dist {0,255}; // Distribution for RNG

private:
    // Stack
    int sp = 0;                 // Stack pointer
    int callstack[48] = {};     // Allows for 24 nested calls

    // Registers
    unsigned char vregs[16] = {};         // V registers
    unsigned short I = 0;                  // I register
    int pc = 0x200;             // Program counter

    // Input
    bool keys[16] = {false};    // Keys are 1-15 inclusive

    // Memory
    unsigned char memory[4096]; // 4K of memory

    // Timers
    unsigned char delay_timer;
    unsigned char sound_timer;
    
    // Screen
    Screen screen;

    // Debug trace method
    void debugTrace();
};

#endif //CHIP8EMU_CHIP8CPU_H
