#ifndef _GRAPHICS_H
#define _GRAPHICS_H

typedef enum ScreenMode {
    SM_FULL,
    SM_WINDOWED
} ScreenMode;

typedef struct GraphicsOptions {
    int width;
    int height;
    ScreenMode mode;
} GraphicsOptions;

void graphics_init(const GraphicsOptions*);
void graphics_draw();

#endif
