#include <SDL2/SDL.h>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "Point.hpp"
#include "RenderWindow.hpp"

Point::Point()
{
    // Área em que os pontos podem spawnar: (100, 100, 980, 476)
    x = rand() % 1078 + 1;
    y = rand() % 574 + 1;

    vx = 0;
    vy = 0;
    while (vx == 0) {
        vx = rand() % 200; // -1 a 1
        vx = vx / 100 - 1;
    }
    while (vy == 0) {
        vy = rand() % 200; // -1 a 1
        vy = vy / 100 - 1;
    }
}

void Point::draw(RenderWindow* window)
{
    // Ponto do meio
    window->drawPoint(x, y);

    // Pontos em +
    window->drawPoint(x-1, y);
    window->drawPoint(x+1, y);
    window->drawPoint(x, y-1);
    window->drawPoint(x, y-1);
       
}

void Point::update(RenderWindow* window)
{
    x += vx;
    y += vy;

    if (x <= 0 || x >= window->getWidth()) vx *= -1;
    if (y <= 0 || y >= window->getHeight()) vy *= -1; 
}

void Point::line(RenderWindow* window, Point p2)
{
    double dist = sqrt( pow(abs(x-p2.getX()), 2) + pow(y-p2.getY(), 2) );
    double alpha;
    if (dist > 250) return;
    else if (dist > 100)
        alpha = 255 - (dist - 100) / 150 * 255;
    else alpha = 255;

    window->changeColor(255, 255, 255, alpha);

    window->drawLine(x, y, p2.getX(), p2.getY());
    
    window->drawLine(x-1, y, p2.getX()-1, p2.getY());
    window->drawLine(x+1, y, p2.getX()+1, p2.getY());
    window->drawLine(x, y-1, p2.getX(), p2.getY()-1);
    window->drawLine(x, y+1, p2.getX(), p2.getY()+1);
    
}

double Point::dist(Point p2)
{
    int dx = abs(p2.getX() - x);
    int dy = abs(p2.getY() - y);
    double dist = sqrt((dx*dx + dy*dy));

    return dist;
}