#include "world.h"

#include <assert.h>

Object* map_get_object(Map *map, const Coords *coords) {
    Object *object = map_try_get_object(map, coords);
    assert(object);

    return object;
}

Object* map_try_get_object(Map *map, const Coords *coords) {
    if (coords->z < 0 || coords->z >= NUM_LAYERS ||
        coords->x < 0 || coords->x >= map->width ||
        coords->y < 0 || coords->y >= map->height)
        return 0;

    return &map->layers[coords->z].grid[map->width * coords->y + coords->x];
}

bool map_is_pipe_adjacent(Map *map, const Coords *coords, PlayerID owner) {
}
