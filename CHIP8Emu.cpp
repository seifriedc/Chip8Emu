// Chris Seifried
// Constantino Flouras

#include "CHIP8Emu.h"
#include "CHIP8Cpu.h"
using namespace std;

// Suppress warnings about infinite loops
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

int main(int argc, char** argv) {
    // TODO: Use exceptions
    // Check if user provided a rom to open
    if (argc != 2) {
        cout << "Error: incorrect arguments." << endl;
        return 1;
    }

    // Open the ROM, initialize the CPU
    CHIP8Cpu chip8 (argv[1]);

    while (true) {
        chip8.getInput();
        chip8.nextInstruction();
        chip8.render();
        

        // less granularity for the delay
        SDL_Delay(2);

    }
}

#pragma clang diagnostic pop

