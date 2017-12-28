// Chris Seifried
// Constantino Flouras

#include "../include/CHIP8Cpu.h"

// For debugging purposes...
#include <stdio.h>

CHIP8Cpu::CHIP8Cpu(const char *romname) {
    ifstream rom;   // Input stream for the ROM file

    // Open the ROM file
    rom.open(romname);
    if (rom.fail()) {
        cout << "Error opening file " << romname << ", aborting." << endl;
        abort();
    }

    // Now, we need the ROM file size.
    long romSize = rom.tellg();
    rom.seekg( 0, ios::end );
    romSize = rom.tellg() - romSize;
    rom.seekg( 0, ios::beg );

    // Read the entirety of the ROM file into memory.

    /*
        About the CHIP-8 Memory Map
        ---------------------------

        Starting at address 0x200 (or 512 in decimal), memory space contains the
        ROM that was inputted by the user.
    */

    char * romStart = (char *) ( &(memory[ROM_START]));
    rom.read(romStart, romSize);

    // The ROM is now in memory. Close the ROM.
    rom.close();

    // Set up random number generation
    random_device rd;
    rng.seed(rd());

    // Next, we'll need to import the standard font into memory. This is freely provided 
    unsigned char chip8_fontset[80] =
	{ 
	  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	  0x20, 0x60, 0x20, 0x20, 0x70, // 1
	  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

	//		Destination of the font
	memcpy( (unsigned char *) &memory[0x050], (unsigned char *) &chip8_fontset[0], 80);
}

int CHIP8Cpu::getInput() {
    SDL_Event event;
    SDL_PollEvent(&event);

    // Catch key presses and other events
    switch (event.type)
    {
        // There's probably a smarter way to do this, but this can work for now.
        // event.key.keysym.sym is the key that has been acted upon
        case SDL_KEYDOWN:
            keys[keymap[event.key.keysym.sym]] = true;
            keyChanged = keymap[event.key.keysym.sym];
            return 1;

        case SDL_KEYUP:
            keys[keymap[event.key.keysym.sym]] = false;
            keyChanged = keymap[event.key.keysym.sym];
            return 1;

        // For once, we can actually CLOSE the PROGRAM without ERRORS!
        case SDL_QUIT:
            exit(0);
            break;

        default: break;
    }

    return 0;
}

void disInstruction(int pc, unsigned short inst);

void CHIP8Cpu::nextInstruction() {
    // Debug flag
    //#define DEBUG_CHIP8CPU_NEXTINSTRUCTION
    //#define DEBUG_PRINT_INSTRUCTION
    //#define ENABLE_STEP_INSTRUCTIONS

    unsigned short inst, top;     // For reading in the instruction
    int vx, vy, arg;                   // Regs and immediate value in instruction, if present

    // Read in next instruction (2 bytes)
    inst = (memory[pc] << 8) | memory[pc+1];

    // Also, simply because of the way I fixed tmp, we don't need to flip the endianness
    top = (inst >> 12);                    // Get top half-byte

    // By default
    vx = inst>>8 & 0x0F;
    vy = inst>>4 & 0x000F;
    arg = inst & 0x00FF;

    #ifdef DEBUG_PRINT_INSTRUCTION
    	disInstruction(pc,inst);
    #endif

    // If the program counter is less than the start of the ROM, something has gone wrong, and we should throw an exception.
    if (pc < ROM_START)
    {
    	printf("ERROR: An invalid program counter %x was detected!\n", pc);
    	debugTrace();
    	abort();
    }

    // Select parse actions based on top half-byte of instruction
    switch (top)
    {
        case 0x0:
            switch (inst & 0x00FF)
            {
                case 0xE0: // CLS
                    for (int cnt = 0; cnt < 64*32; cnt++)
                    {
                        screen.buffer[cnt%64][cnt/64] = 0; 
                    }
                    screen.blit();
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
        	// In an unconditional jump, I'm pretty sure that the address also has to be offset by the program counter increment value (in this case, 2)
            pc = (inst & (unsigned short) 0x0FFF) - 2; // Set $pc to jump addr
            break;
        case 0x2: // CALL addr
            callstack[++sp] = pc; // Increment $sp, push current $pc to top of stack
            pc = (inst & (unsigned short) 0x0FFF) - 2;   // Set $pc to jump addr
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
            vregs[vx] = (unsigned char) arg;
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
                    vregs[vx] = (unsigned char) (sum & 0x00FF);        // Put last 8 bits of sum in Vx
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
            I = (unsigned short) (inst & 0x0FFF);
            //cout << "DEBUG_CHIP8CPU_NEXTINSTRUCTION: Memory address I points to byte: " << I << endl;
            break;
        case 0xB: // JP V0, addr
            pc = (vregs[0] + (inst & 0x0FFF)) - 2;
            break;
        case 0xC: // RND Vx, byte
            vregs[vx] = (unsigned char)(dist(rng) & (inst & 0x00FF));
            break;
        case 0xD: // DRW Vx, Vy, nibble
        	
        	// Implement the draw functionality. We'll need to use a screen.
            // The screen has been implemented in file Screen.cpp

        	// We'll pull the actual "bitmap" of the graphic from location I
        	// in memory. In our case, we'll simply iterate through location I.
        	arg = (inst & 0x000F);

            // We will assume that our draw is successful, until proven failed.
            vregs[0xF] = 0;
            for (int lineNum = 0; lineNum < (inst & 0x000F); lineNum++)
            {
                for (int rowNum = 0; rowNum < 8; rowNum++)
                {
                    if ( ( ( memory[I + lineNum] ) >> (7 - rowNum) ) & 0x0001 )
                    {
                    	// If we've reached this point, we need to flip the bit.
                        if (screen.buffer[vregs[vx] + rowNum][vregs[vy] + lineNum] != 0)
                        {
                            // This bit has already been set to something else!
                            // A collision has occured! Set VF to 1.
                        	vregs[0xF] = 1;
                        	screen.buffer[vregs[vx] + rowNum][vregs[vy] + lineNum] = 0;
                        }
                        else
                        {
                        	screen.buffer[vregs[vx] + rowNum][vregs[vy] + lineNum] = 1;
                        }
                    }
                }
            }
            screen.blit();
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
        case 0xF:
        	switch (inst & 0x00FF)
            {
                case 0x07:
                // Load the value from delay_timer into V(inst & 0x0F00);
                vregs[vx] = delay_timer;
                break;

                case 0x0A: 
                //printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "K");
                
                // BLOCKING CALL
                // A key press is awaited, then stored in VX.
                    while (getInput() == 0); // Is this right? Maybe use SDL_WaitEvent() here
                    vregs[vx] = (unsigned char) keyChanged;

                // Implement the keypress functionality from SCREEN here
                //cout << "\tWARNING: Unimplemented instruction! \n" << endl;
                break;

                case 0x15:
                //printf("%s %s, V%X", "LD", "DT", (inst>>8 & 0x0F));
                // Load the value in (inst & 0x0F00) into delay_timer;
                delay_timer = (unsigned char)(inst & 0x0F00);
                break;

                case 0x18:
                //printf("%s %s, V%X", "LD", "ST", (inst>>8 & 0x0F));
                // Load the value in (inst & 0x0F00) into sound_timer;
                sound_timer = (unsigned char)(inst & 0x0F00);
                break;

                case 0x1E:
                //printf("%s %s, V%X", "ADD", "I", (inst>>8 & 0x0F));

                // Add the value of VX to I.
                I += vregs[vx];
                break;

                case 0x29:
                //printf("%s %s, V%X", "LD", "F", (inst>>8 & 0x0F));

                    // Load the corresponding sprite value
                    // We want the address in memory of the start of the sprite
                    // Sprites start at address 0x050, then we offset
                    I = 0x050 + (vregs[vx] * 5);
                break;

                case 0x33:
                //printf("%s %s, V%X", "LD", "B", (inst>>8 & 0x0F));
                
                // Store the binary representation of VX (whichever one is given), with:
                //		the hundreds digit at address I
                //		the tens digit at address I + 1
                //		the ones digit at address I + 2
                memory[I] = (vregs[vx] % 1000) / 100;		//hundreds
                memory[I+1] = (vregs[vx] % 100) / 10;		//tens
                memory[I+2] = (vregs[vx] % 10); 			//ones
                break;

                case 0x55:
                //printf("%s %s, V%X", "LD", "(I)", (inst>>8 & 0x0F));
                    for (int i = 0; i <= vx; i++) 
                    {
                        memory[I+i] = vregs[i];
                    }
                break;

                case 0x65:
                //printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "(I)");
                    for (int i = 0; i <= vx; i++)
                    {
                        vregs[i] = memory[I+i];
                    }
                break;

                default:
                //printf("UNKNOWN 0xF OP");
                cout << "\tWARNING: Unimplemented instruction! \n" << endl;
                break;
            } break;
        default: break;
    }
    pc += 2;

    // Handle the delay and sound timers.
    if (delay_timer > 0)
    {
    	delay_timer--;
    }

    #ifdef ENABLE_STEP_INSTRUCTIONS
    	debugTrace();
    	cin.get();
    	system("clear");
    #endif




}

void CHIP8Cpu::render() {

}

void disInstruction(int pc, unsigned short inst)
{
    uint8_t top = (inst >> 12);                 // Get top half-byte

    // Print address and op
    //if (top == 0xF)
    //{
    	printf("%04x %04x    ", pc, inst);
    //}
    // Act on op
    switch (top)
    {
        case 0x0:
            switch (inst & 0x00FF)
            {
                case 0xE0: printf("%s", "CLS"); break;
                case 0xEE: printf("%s", "RET"); break;
                case 0x00: printf("%s", "NOP"); break;
                default:   printf("UNKNOWN 0x0 OP"); break;
            } break;
        case 0x1: printf("%s 0x%03x", "JP", (inst & 0x0FFF));break;
        case 0x2: printf("%s (0x%03x)", "CALL", (inst & 0x0FFF)); break;
        case 0x3: printf("%s V%X, 0x%02x", "SE", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x4: printf("%s V%X, 0x%02x", "SNE", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x5: printf("%s V%X, V%X", "SE", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
        case 0x6: printf("%s V%X, 0x%02x", "LD", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x7: printf("%s V%X, 0x%02x", "ADD", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0x8:
            switch (inst & 0x000F)
            {
                case 0x0: printf("%s V%X, V%X", "LD", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x1: printf("%s V%X, V%X", "OR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x2: printf("%s V%X, V%X", "AND", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x3: printf("%s V%X, V%X", "XOR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x4: printf("%s V%X, V%X", "ADD", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x5: printf("%s V%X, V%X", "SUB", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x6: printf("%s V%X, V%X", "SHR", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0x7: printf("%s V%X, V%X", "SUBN", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                case 0xE: printf("%s V%X, V%X", "SHL", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
                default:  printf("UNKNOWN 0x8 OP"); break;
            } break;
        case 0x9: printf("%s V%X, V%X", "SNE", (inst>>8 & 0x0F), (inst>>4 & 0x000F)); break;
        case 0xA: printf("%s I, 0x%03x", "LD", (inst & 0x0FFF)); break;
        case 0xB: printf("%s 0x%03x(V0)", "JP", (inst & 0x0FFF)); break;
        case 0xC: printf("%s V%X, 0x%02x", "RND", (inst>>8 & 0x0F), (inst & 0x00FF)); break;
        case 0xD: printf("%s V%X, V%X, %#x", "DRW", (inst>>8 & 0x0F), (inst>>4 & 0x00F), (inst & 0x000F)); break;
        case 0xE:
            switch (inst & 0x00FF)
            {
                case 0x9E: printf("%s V%X", "SKP", (inst>>8 & 0x0F)); break;
                case 0xA1: printf("%s V%X", "SKNP", (inst>>8 & 0x0F)); break;
                default:   printf("UNKNOWN 0xE OP"); break;
            } break;
        case 0xF:
            switch (inst & 0x00FF)
            {
                case 0x07: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "DT"); break;
                case 0x0A: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "K"); break;
                case 0x15: printf("%s %s, V%X", "LD", "DT", (inst>>8 & 0x0F)); break;
                case 0x18: printf("%s %s, V%X", "LD", "ST", (inst>>8 & 0x0F)); break;
                case 0x1E: printf("%s %s, V%X", "ADD", "I", (inst>>8 & 0x0F)); break;
                case 0x29: printf("%s %s, V%X", "LD", "F", (inst>>8 & 0x0F)); break;
                case 0x33: printf("%s %s, V%X", "LD", "B", (inst>>8 & 0x0F)); break;
                case 0x55: printf("%s %s, V%X", "LD", "(I)", (inst>>8 & 0x0F)); break;
                case 0x65: printf("%s V%X, %s", "LD", (inst>>8 & 0x0F), "(I)"); break;
                default:  printf("UNKNOWN 0xF OP"); break;
            } break;
        default: break;
    }

    printf("\n");
}

void CHIP8Cpu::debugTrace()
{
	// The following will print out useful information in regards to the CPU.


	printf("DEBUG_TRACE:\n-----------\n\n");
	// First, we're going to print out all of the V registers.
	printf("%4s %4s %4s %4s %4s %4s %4s %4s\n", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7");
	printf("%4x %4x %4x %4x %4x %4x %4x %4x\n", vregs[0], vregs[1], vregs[2], vregs[3], vregs[4], vregs[5], vregs[6], vregs[7]);
	printf("%4x %4x %4x %4x %4x %4x %4x %4x\n", vregs[8], vregs[9], vregs[10], vregs[11], vregs[12], vregs[13], vregs[14], vregs[15]);
	printf("%4s %4s %4s %4s %4s %4s %4s %9s\n", "v8", "v9", "vA", "vB", "vC", "vD", "vE", "vF(carry)");

	// Then, we'll print out the current I location, and the contents of it.
	printf("\nI: %x     contains:  %x %x %x %x\n", I, memory[I], memory[I+1], memory[I+2], memory[1+3]);

	// Finally, we'll print out the current callStack.
	printf("STACK:\n");
	for (int i = sp; i >= 0; i--)
	{
		printf("call %d: %x\n", i, callstack[i]);
	}

    printf("\nKEYPAD:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("key %d: %d\n", i, keys[i]);
    }
}





CHIP8Cpu::~CHIP8Cpu() = default;
