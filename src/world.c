#include "world.h"

#include <assert.h>

Object* map_get_object(const Map *map, const Coords *coords) {
    if (coords->z < 0 || coords->z >= NUM_LAYERS
        || coords->x < 0 || coords->x >= map->width
        || coords->y < 0 || coords->y >= map->height)
        return 0;

    return &map->layers[coords->z].grid[coords->y * map->width + coords->x];
}

Object* map_get_adjacent_object(const Map *map, const Coords *coords, Direction dir) {
    Coords trans = *coords;    
    switch (dir) {
    case DIR_FORWARD:
        trans.x--;
        break;
    case DIR_BACKWARD:
        trans.x++;
        break;
    case DIR_LEFT:
        trans.y--;
        break;
    case DIR_RIGHT:
        trans.y++;
        break;
    case DIR_UP:
        trans.z++;
        break;
    case DIR_DOWN:
        trans.z--;
        break;
    default:
        assert(0);
    }

    return map_get_object(map, &trans);
}
