#!/bin/bash
g++ -c src/*.cpp -O3 -std=c++14 -m64 -Wall -I include && g++ *.o -o bin/release/Linux-x86_64/pontos-ligados -s -lSDL2main -lSDL2 && bin/debug/main 
