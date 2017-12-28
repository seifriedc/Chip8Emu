// Chris Seifried
// Constantino Flouras

#include <iostream>
#include <ctime>
#include <chrono>

#include "../include/CHIP8Emu.h"
#include "../include/CHIP8Cpu.h"
using namespace std;
using namespace std::chrono;

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
        // TODO: Take as runtime arg?
        // SDL_Delay(2);
        // delay(20);
    }
}

void delay(double milliseconds)
{
    int64_t now = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (int64_t) (milliseconds * 100000);

    //cout << " We want: " << now << endl;
    while (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() < now)
    {
        //cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "\n";
    };
}

#pragma clang diagnostic pop

