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
#include <unordered_map>

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
    unordered_map<SDL_Keycode , int> keymap = { // Map SDL keys to CHIP8 keys
            {SDLK_1, 0x1},
            {SDLK_2, 0x2},
            {SDLK_3, 0x3},
            {SDLK_4, 0xC},
            {SDLK_q, 0x4},
            {SDLK_w, 0x5},
            {SDLK_e, 0x6},
            {SDLK_r, 0xD},
            {SDLK_a, 0x7},
            {SDLK_s, 0x8},
            {SDLK_d, 0x9},
            {SDLK_f, 0xE},
            {SDLK_z, 0xA},
            {SDLK_x, 0x0},
            {SDLK_c, 0xB},
            {SDLK_v, 0xF}
    };

private:
    // Stack
    int sp = 0;                 // Stack pointer
    int callstack[48] = {};     // Allows for 24 nested calls

    // Registers
    unsigned char vregs[16] = {};         // V registers
    unsigned short I = 0;                  // I register
    int pc = 0x200;             // Program counter

    // Input
    bool keys[16] = {false};    // Keys are 0-15 inclusive
    int keyChanged = 0;         // Key most recently changed

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
