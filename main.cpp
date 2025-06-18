#include <iostream>
#include "SDL3/SDL.h"

bool quit = false;

int main() {
    // Initialize SDL
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* screen = SDL_CreateWindow("8Bit Emulator", 640, 320, SDL_WINDOW_OPENGL);

    
    
    return 0;
}