#ifndef _OBJECT_H
#define _OBJECT_H

#include <stdbool.h>

#define NUM_LAYERS 3

typedef int PlayerID;

typedef enum ObjectType {
    OT_NULL,
    OT_PIPE,
    OT_CORE,
    OT_ATT,
    OT_DEF,
    OT_RES
} ObjectType;

typedef struct Coords {
    int x, y, z;
} Coords;

typedef struct Object {
    ObjectType type;

    union {
        struct PipeObject {
            
        } pipe;

        struct CoreObject {

        } core;

        struct AttObject {

        } att;

        struct DefObject {

        } def;

        struct ResObject {

        } res;
    };
} Object;

typedef struct Layer {
   struct Object* grid;
} Layer;

typedef struct Map {
    int width;
    int height;

    Layer layers[NUM_LAYERS]; 
} Map;

Object* map_get_object(Map *map, const Coords *coords);
Object* map_try_get_object(Map *map, const Coords *coords);

bool map_is_pipe_adjacent(Map *map, const Coords *coords, PlayerID owner);

#endif
