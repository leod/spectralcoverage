#include "graphics.h"

#include "error.h"

#include <SDL/SDL.h>
#include <GL/gl.h>

static void initGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void graphics_init(const GraphicsOptions* opts) {
    int flags = SDL_OPENGL;
    if (opts->mode == SM_FULL) flags |= SDL_FULLSCREEN;

    if (SDL_SetVideoMode(opts->width, opts->height, 32, flags) == NULL)
        fatal_error("Failed to initialize SDL video mode");

    initGL();
}

void graphics_draw() {

}

