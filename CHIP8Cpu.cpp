// Chris Seifried
// Constantino Flouras

#include "CHIP8Cpu.h"

CHIP8Cpu::CHIP8Cpu(const char *romname) {
    rom.open(romname);
    if (rom.fail()) {
        cout << "Error opening file " << romname << ", aborting." << endl;
        abort();
    }
}

void CHIP8Cpu::getInput() {

}

void CHIP8Cpu::nextInstruction() {

}

void CHIP8Cpu::render() {

}

CHIP8Cpu::~CHIP8Cpu() {
    rom.close();
}