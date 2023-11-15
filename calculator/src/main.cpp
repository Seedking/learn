#include <iostream>
#include "SDL2/SDL.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        SDL_Log("Init failed %s", SDL_GetError());
        return -1;
    }

    SDL_Window* win = SDL_CreateWindow(
        "calculator",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        114,
        514,
        SDL_WINDOW_BORDERLESS
    );

    if (win == nullptr) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
    }

    SDL_Delay(1145);

    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
