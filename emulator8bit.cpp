#include <iostream>
#include <vector>
#include <string.h>

// This is a simple 8-bit emulator structure in C++
// It includes memory, registers, an index register, a program counter, and a stack.(see chip8 spec)
typedef unsigned char byte;
typedef unsigned short int word;
    
byte gameMemory[0xfff]; // 4096 bytes of memory
byte registers[16]; //16 registers, 1 byte each

word adressI; // Index register
word programCounter; // Program counter

std::vector<word> stack; // i need to see how this actually works
// Stack is used to store return addresses for subroutines

byte screenData[64] [32]; // 64x32 pixel screen
// Each pixel is represented by a byte, 0 for off, 1 for on

// Function to reset/set the CPU state
// This function initializes the CPU state, including memory, registers, and program counter.
// It also loads a game into memory from a file. (maybe it should be a parameter)
void CPUReset() {
    adressI = 0;
    programCounter = 0x200; //starts at 0x200
    memset(registers, 0, sizeof(registers)); // Clear registers

    //load the game in the memory
    FILE *gameFile;
    gameFile = fopen("Space Invaders.ch8", "rb");
    
    if (gameFile == NULL) {
        std::cout << "Error opening game file." << std::endl;
        return;
    }

    fread(&gameMemory[0x200], 0xfff, 1, gameFile);//reads the game file into memory starting at 0x200
    fclose(gameFile);
}

word getNextOpcode() {
    word res = 0;
    res = gameMemory[programCounter] << 8; // Get the first byte and shift it to the high byte
    res |= gameMemory[programCounter + 1]; // Get the second byte and combine it with the first
    // The opcode is a 16-bit value formed by combining two bytes

    programCounter += 2;
    // Increment the program counter by 2 to point to the next opcode

    return res;
}

//maybe in another class?
word opcode = getNextOpcode();

/*
word firstNumber = opcode & 0xF000; // Get the first number from the opcode
word secondNumber = opcode & 0x0F00; // Get the second number from the opcode
word secondAndLastNumber = opcode & 0x0F0F; // Get the second and last number from the opcode
word lastTwoNumbers = opcode & 0x00FF; // Get the last two numbers from the opcode
*/

