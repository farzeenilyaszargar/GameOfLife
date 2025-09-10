#include <iostream>
#include <SDL.h>

using namespace std;

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 600;
const int ROWS = 20;
const int COLS = 20;
const int CELL_W = WINDOW_WIDTH/COLS;
const int CELL_H = WINDOW_HEIGHT/ROWS;


int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "Nah Failed Bruv";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Conways Game of Life By Fizzy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_HEIGHT, WINDOW_WIDTH, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_Event event;

    int running = 1;

    bool active[ROWS][COLS] = {false};

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = 0;

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                int col = mouseX/CELL_W;
                int row = mouseY/CELL_H;

                active[row][col] = !active[row][col];
            }
            
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        for (int r = 0; r<ROWS; r++)
        {
            for (int c = 0; c<COLS; c++)
            {
                SDL_Rect cell = {c*CELL_W, r*CELL_H, CELL_W, CELL_H};
                if(active[r][c])
                {
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &cell);
            }
        }


        


        SDL_RenderPresent(renderer);
        
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}