#include <iostream>
#include <SDL.h>
// #include <SDL_ttf.h>

using namespace std;

const int WINDOW_HEIGHT = 670;
const int WINDOW_WIDTH = 600;
const int TOPBAR_HEIGHT = 70;
const int ROWS = 20;
const int COLS = 20;
const int CELL_W = WINDOW_WIDTH/COLS;
const int CELL_H = (WINDOW_HEIGHT-TOPBAR_HEIGHT)/ROWS;


int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "Nah Failed Bruv";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Conways Game of Life By Fizzy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_Event event;

    int running = 1;

    bool active[ROWS][COLS] = {false};
    bool startPlay = false;

    SDL_Rect startBtn = {100, 10, 100, 50};
    SDL_Rect stopBtn = {250, 10, 100, 50};
    SDL_Rect resetBtn = {400, 10, 100, 50};



    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = 0;

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                SDL_Point startPoints = {mouseX, mouseY};
                cout << "Mouse clicked at: " << mouseX << ", " << mouseY << endl;


                if (SDL_PointInRect(&startPoints, &startBtn))
                {
                    cout << "Start Button Pressed";
                }

                if (SDL_PointInRect(&startPoints, &stopBtn))
                {
                    cout << "Stop Button Pressed";
                }

                 if (SDL_PointInRect(&startPoints, &resetBtn))
                {
                    cout << "Reset Button Pressed";
                }

                if (mouseY>TOPBAR_HEIGHT)
                {
                    int col = mouseX/CELL_W;
                    int row = (mouseY-TOPBAR_HEIGHT)/CELL_H;
                    active[row][col] = !active[row][col];

                }



                
            }
            
            
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
        SDL_RenderFillRect(renderer, &startBtn);

        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
        SDL_RenderFillRect(renderer, &stopBtn);


        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
        SDL_RenderFillRect(renderer, &resetBtn);




        for (int r = 0; r<ROWS; r++)
        {
            for (int c = 0; c<COLS; c++)
            {
                SDL_Rect cell = {c*CELL_W, TOPBAR_HEIGHT+(r*CELL_H), CELL_W, CELL_H};
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