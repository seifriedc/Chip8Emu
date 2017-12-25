// Constantino Flouras

#include <iostream>

// This is simply a simulation of the screen. I want to test and make sure that this is going to work the way I expect
char buffer[64][32];

int vx = 0, vy = 0, h = 0;

unsigned short inst = 0xD003;
unsigned short I = 512;
char memory[1024];

void initBuffer();
void printScreen();
void doDraw();

int main()
{
    initBuffer();
    printScreen();
    doDraw();
    std::cout << "after: \n\n";
    printScreen();
}

void initBuffer()
{
    for (int i = 0; i < (64*32); i++)
    {
        buffer[i%64][i/64] = 48;
    }
    
    // Set memory at I and beyond to the appropriate bytes.
    memory[I] = 0x3C;
    memory[I+1] = 0xC3;
    memory[I+2] = 0xFF;
}

void doDraw()
{
    for (int lineNum = 0; lineNum < (inst & 0x000F); lineNum++)
    {
        for (int rowNum = 0; rowNum < 8; rowNum++)
        {
            if ( ( ( memory[I + lineNum] ) >> (7 - rowNum) ) & 0x0001 )
            {
                buffer[vx + rowNum][vy + lineNum] = 49;
            }
        }
    }
}

void printScreen()
{
    for(int i = 0; i < 64*32; i++)
    {
        if (i % 64 == 0)
        {
            std::cout << "\n";
        }
        
        std::cout << buffer[i%64][i/64];
    }
}