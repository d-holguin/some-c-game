/*
 * Just for practice with C making a "game"
 */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 680

void initialize(void);
void termninate(int exit_code);
void handle_input(void);

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int running;
} Game;

Game game = {
    .renderer = NULL,
    .window = NULL,
    .running = 1,
};

int main() {

  initialize();

  while (game.running) {
    SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
    SDL_RenderClear(game.renderer);

    handle_input();

    // TODO: add update and draw Functions

    SDL_RenderPresent(game.renderer);
    // wait 100ms before next iteration
    SDL_Delay(100);
  }

  termninate(EXIT_SUCCESS);
}
void initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("error: failed to initialize SDL: %s\n", SDL_GetError());
    termninate(EXIT_FAILURE);
  }

  // create game window

  game.window = SDL_CreateWindow("Score: 0", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                 SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (!game.window) {
    printf("error: failed to open %d x %d window: %s\n", SCREEN_WIDTH,
           SCREEN_HEIGHT, SDL_GetError());
    termninate(EXIT_FAILURE);
  }
}
void terminate(int exit_code) {
  if (game.renderer) {
    SDL_DestroyRenderer(game.renderer);
  }
  if (game.window) {
    SDL_DestroyWindow(game.renderer);
  }
  if (game.window) {
    SDL_DestroyWindow(game.renderer);
  }
  SDL_Quit();
  exit(exit_code);
}
void handle_input() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT ||
        (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
      game.running = 0;
    }
  }
}