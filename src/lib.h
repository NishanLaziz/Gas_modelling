#ifndef LIB_H
#define LIB_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define PI 3.14159265358979323846

#define RED 255, 0, 0, 255
#define BLUE 0, 0, 255, 255
#define BLACK 0, 0, 0, 255

struct Balls_2d {
    double x, y, vx, vy;
    int r, m;
};

void Balls_2d_creation(struct Balls_2d* ball, int n, double velocity, int radius, int mass, int x_start, int y_start, int x_end, int y_end);
void BallDraw(SDL_Renderer* renderer);

#endif
