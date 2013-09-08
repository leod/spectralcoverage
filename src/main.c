#include "graphics.h"
#include "error.h"
#include "world.h"

#include <SDL/SDL.h>

static void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        fatal_error("Failed to initialize SDL");
    SDL_WM_SetCaption("Spectral Coverage", NULL);
}

#undef main
int main(int argc, char* argv[]) {
    initSDL();

    GraphicsOptions gopts = { 800, 640, SM_WINDOWED };
    graphics_init(&gopts);

    while (1) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                return 0;

            case SDL_KEYDOWN:
                break;
            }
        }

        graphics_draw();
    }

    return 0;
}
