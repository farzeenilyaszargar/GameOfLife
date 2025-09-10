#include <iostream>
#include <SDL.h>

using namespace std;

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "Nigga";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Conways Game of Life By Fizzy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    int running = 1;

    while (running)
    {
        // game loop
    }



    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}