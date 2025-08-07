#include "lib.h"

#define B_WIDTH 1000
#define B_HEIGHT 500
#define N 100
#define RADIUS 3
#define MASS 1
#define SPEED 500
#define DT 0.0001

int main(int argc, char* argv[]) {
    // Инициализация SDL3
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Log("Failed to initializate SDL3: %s", SDL_GetError());
        return 1;
    }

    // Создание окна для отображения движения шаров
    SDL_Window* window_balls = SDL_CreateWindow("Balls", B_WIDTH, B_HEIGHT, 0);
    if (!window_balls) {
        SDL_Log("Failed to create window_balls: %s", SDL_GetError());
        return 1;
    }
    SDL_Renderer* renderer_balls = SDL_CreateRenderer(window_balls, NULL);
    if (!renderer_balls) {
        SDL_Log("Failed to create renderer_balls: %s", SDL_GetError());
        SDL_DestroyWindow(window_balls);
        SDL_Quit();
        return 1;
    }

    // Основной цикл работы программы
    SDL_Event event;
    bool quit = false;
    struct Balls_2d ball[N];
    Balls_2d_creation(ball, N, SPEED, RADIUS, MASS, 0, 0, B_WIDTH, B_HEIGHT);
    while (!quit) {
        BallDraw(renderer_balls);
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) quit = true;
    }

    for (int i = 0; i < N; i++) {
        SDL_Log("%3d %6.1lf  %6.1lf  %6.1lf  %6.1lf  %d  %d", i, ball[i].x, ball[i].y, ball[i].vx, ball[i].vy, ball[i].r, ball[i].m);
    }

    // Завершение работы
    SDL_DestroyRenderer(renderer_balls);
    SDL_DestroyWindow(window_balls);
    SDL_Quit();
    return 0;
}
