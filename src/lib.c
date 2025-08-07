#include "lib.h"

// Функция задает начальные координаты, скорость, массу и радиус всем шарам структуры
void Balls_2d_creation(struct Balls_2d* ball, int n, double velocity, int radius, int mass, int x_start, int y_start, int x_end, int y_end) {
    for (int i = 0; i < n; i++) {
        ball[i].r = radius;
        ball[i].m = mass;
        double alpha = SDL_randf() * 2 * PI;
        ball[i].vx = velocity * SDL_cos(alpha);
        ball[i].vy = velocity * SDL_sin(alpha);
        bool good = false;
        while (!good) {
            ball[i].x = SDL_rand(x_end - x_start - 2 * radius) + radius + x_start;
            ball[i].y = SDL_rand(y_end - y_start - 2 * radius) + radius + y_start;
            good = true;
            for (int j = 0; j < i; j++) {
                double dx = SDL_pow((ball[i].x - ball[j].x), 2);
                double dy = SDL_pow((ball[i].y - ball[j].y), 2);
                if (dx + dy <= radius * radius) good = false;
            }
        }
    }
}

// Функция отвечает за отображние всех объектов на экране
void BallDraw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, BLACK);
    SDL_RenderClear(renderer);





    SDL_RenderPresent(renderer);
}

