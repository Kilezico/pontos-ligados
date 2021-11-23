#pragma once
#include <SDL2/SDL.h>

class RenderWindow
{
public:
    RenderWindow(const char* title, int w, int h);
    void clear();
    
    void changeColor(int red, int green, int blue, int alpha=255);    
    void drawPoint(int x, int y);
    void drawLine(int x1, int y1, int x2, int y2);

    void update();
    
    void quit();

    int getWidth() { return width; }
    int getHeight() { return height; }
private:
    int width;
    int height;

    SDL_Window* window;
    SDL_Renderer* renderer;

};