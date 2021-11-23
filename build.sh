#!/bin/bash
g++ -c src/*.cpp -g -std=c++14 -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 && bin/debug/main 
