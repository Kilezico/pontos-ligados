#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "RenderWindow.hpp"
#include "Point.hpp"


int main(int argv, char* args[])
{   
    int POINT_AMOUNT;
    if (argv > 1) POINT_AMOUNT = atoi(args[1]);
    else POINT_AMOUNT = 0;

    if (SDL_Init(SDL_INIT_AUDIO))
        std::cout << "ERRO EM SDL_Init. ERRO: " << SDL_GetError() << std::endl;

    RenderWindow window("Pontos Conectados", 1080, 576);
    
    std::vector<Point> points;
    for (int i=0; i<POINT_AMOUNT; i++) {
        Point p;
        points.push_back(p);
    }

    srand(time(NULL));


    SDL_Event event;
    bool isRunning = true;
    while (isRunning)
    {
        int start = SDL_GetTicks();

        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) isRunning = false;
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                {
                    Point p;
                    points.push_back(p);
                    break;
                }
                case SDLK_r:
                    points.clear();
                    break;
                case SDLK_q:
                    isRunning = false;
                    break;
                default:
                    break;
                }

            }
        }

        window.changeColor(100, 100, 100);
        window.clear();
        
        window.changeColor(255, 255, 255);
        for (int i=0; i<(int)points.size(); i++) {
            points[i].draw(&window);
            points[i].update(&window);
        }
        window.changeColor(255, 255, 255);
        for (int i=0; i<(int) points.size(); i++) {
            for (int j=0; j<(int) points.size(); j++) {
                if (i > j) continue;

                points[i].line(&window, points[j]);
            }
        }

        window.update();

        int end = SDL_GetTicks();
        int timeMS = start - end;
        SDL_Delay(16 - timeMS);
    }

    window.quit();
    SDL_Quit();

    return 0;
}
