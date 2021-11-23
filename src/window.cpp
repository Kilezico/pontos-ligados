#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Point.hpp"

RenderWindow::RenderWindow(const char* title, int w, int h)
    : width(w), height(h), window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h, SDL_WINDOW_SHOWN);
    if (window == NULL)
        std::cout << "Erro ao criar janela. Erro: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        std::cout << "Erro ao criar renderizador. Erro: " << SDL_GetError() << std::endl;  


    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::changeColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void RenderWindow::drawPoint(int x, int y)
{
    SDL_RenderDrawPoint(renderer, x, y);
}

void RenderWindow::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void RenderWindow::update()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}