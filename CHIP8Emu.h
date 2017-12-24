// Chris Seifried

#ifndef CHIP8EMU_CHIP8EMU_H
#define CHIP8EMU_CHIP8EMU_H

#include <SDL2/SDL.h>

class CHIP8Emu {
public:
    void emulate(); // Will call our private helper methods

private:
    char callstack [48]; // Allows for 24 nested calls
    char vregs [16];     // V registers
    bool keys [16];      // Keys are 1-15 inclusive
    unsigned short ireg; // I register

    void getInput();
    void update();
    void render();
};

#endif //CHIP8EMU_CHIP8EMU_H
