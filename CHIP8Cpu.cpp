// Chris Seifried
// Constantino Flouras

#include "CHIP8Cpu.h"

CHIP8Cpu::CHIP8Cpu(const char *romname) {
    // Open the ROM file
    rom.open(romname);
    if (rom.fail()) {
        cout << "Error opening file " << romname << ", aborting." << endl;
        abort();
    }

    // Set up random number generation
    random_device rd;
    rng.seed(rd());
}

void CHIP8Cpu::getInput() {

}

void CHIP8Cpu::nextInstruction() {
    unsigned short tmp, inst, top;     // For reading in the instruction
    int vx, vy, arg;                   // Regs and immediate value in instruction, if present

    rom >> tmp;                        // Read in next instruction
    inst = (tmp >> 8) | (tmp << 8);    // Flip endianness
    top = (inst >> 12);                // Get top half-byte

    // By default
    vx = inst>>8 & 0x0F;
    vy = inst>>4 & 0x000F;
    arg = inst & 0x00FF;

    // Select parse actions based on top half-byte of instruction
    switch (top)
    {
        case 0x0:
            switch (inst & 0x00FF)
            {
                case 0xE0: // CLS
                    break;
                case 0xEE: // RET
                    pc = callstack[sp];  // Set $pc to addr at top of stack
                    callstack[sp--] = 0; // Pop, decrement $sp
                    break;
                case 0x00: // NOP
                default: break;
            }
            break;
        case 0x1: // JP addr
            pc = inst & 0x0FFF; // Set $pc to jump addr
            break;
        case 0x2: // CALL addr
            callstack[++sp] = pc; // Increment $sp, push current $pc to top of stack
            pc = inst & 0x0FFF;   // Set $pc to jump addr
            break;
        case 0x3: // SE Vx, byte
            if (vregs[vx] == arg) pc += 2;
            break;
        case 0x4: // SNE Vx, byte
            if (vregs[vx] != arg) pc += 2;
            break;
        case 0x5: // SE Vx, Vy
            if (vregs[vx] == vregs[vy]) pc += 2;
            break;
        case 0x6: // LD Vx, byte
            vregs[vx] = arg;
            break;
        case 0x7: // ADD Vx, byte
            vregs[vx] += arg;
            break;
        case 0x8:
            switch (inst & 0x000F)
            {
                case 0x0: vregs[vx] = vregs[vy]; break; // LD Vx, Vy
                case 0x1: vregs[vx] |= vregs[vy]; break; // OR Vx, Vy
                case 0x2: vregs[vx] &= vregs[vy]; break; // AND Vx, Vy
                case 0x3: vregs[vx] ^= vregs[vy]; break; // XOR Vx, Vy
                case 0x4: // ADD Vx, Vy
                {
                    int sum = vregs[vx] + vregs[vy]; // Add Vx and Vy together
                    vregs[15] = (sum > 255) ? 1 : 0; // Set carry flag (VF) if necessary
                    vregs[vx] = sum & 0x00FF;        // Put last 8 bits of sum in Vx
                    break;
                }
                case 0x5: // SUB Vx, Vy
                    vregs[15] = (vregs[vx] > vregs[vy]) ? 1 : 0;  // Set borrow flag (VF) if necessary
                    vregs[vx] -= vregs[vy];                       // Vx = Vx - Vy
                    break;
                case 0x6: // SHR Vx {, Vy}
                    vregs[15] = (vregs[vx] % 2 != 0) ? 1 : 0;  // If Vx odd, set VF to 1, otherwise 0
                    vregs[vx] >>= 1; // Divide by 2
                    break;
                case 0x7: // SUBN Vx, Vy
                    vregs[15] = (vregs[vy] > vregs[vx]) ? 1 : 0;  // Set borrow flag (VF) if necessary
                    vregs[vx] = vregs[vy] - vregs[vx];            // Vx = Vy - Vx
                    break;
                case 0xE: // SHL Vx {, Vy}
                    vregs[15] = ((vregs[vx] & 128) == 128) ? 1 : 0;  // If MSB is 1, set VF to 1, otherwise 0
                    vregs[vx] <<= 1; // Multiply by 2
                    break;
                default: break;
            } break;
        case 0x9: // SNE Vx, Vy
            if (vregs[vx] != vregs[vy]) pc += 2;
            break;
        case 0xA: // LD I, addr
            ireg = inst & 0x0FFF;
            break;
        case 0xB: // JP V0, addr
            pc = vregs[0] + (inst & 0x0FFF);
            break;
        case 0xC: // RND Vx, byte
            vregs[vx] = dist(rng) & (inst & 0x00FF);
            break;
        case 0xD: // DRW Vx, Vy, nibble
            break;
        case 0xE:
            switch (inst & 0x00FF)
            {
                case 0x9E: // SKP Vx
                    if (keys[vregs[vx]]) pc += 2; // Skip instruction if key is pressed
                    break;
                case 0xA1:
                    if (!keys[vregs[vx]]) pc += 2; // Skip instruction if key is not pressed
                    break;
                default: break;
            } break;

        // TODO: Finish 0xF and draw instructions

        default: break;
    }

    pc += 2;
}

void CHIP8Cpu::render() {

}

CHIP8Cpu::~CHIP8Cpu() {
    rom.close();
}