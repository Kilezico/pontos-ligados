#pragma once
#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

class Point
{
public:
    Point();
    void draw(RenderWindow* window);
    void update(RenderWindow* window);
    void line(RenderWindow* window, Point p2);

    double dist(Point p2);    

    double getX() { return x; }
    double getY() { return y; }
private:
    double x, y;
    double vx , vy;
};