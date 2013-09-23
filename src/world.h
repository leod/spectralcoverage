#ifndef _OBJECT_H
#define _OBJECT_H

#include <stdbool.h>
#include <stdint.h>
#include "direction.h"

#define NUM_LAYERS 3
#define NUM_COLORS 4
#define NUM_PLAYERS 10

typedef int16_t PlayerID;
typedef int16_t ObjectID;
typedef int8_t ArmID;

typedef enum ObjectType {
    OT_NULL,
    OT_SEG,
    OT_CORE,
} ObjectType;

typedef struct Coords {
    int16_t x, y, z;
} Coords;

typedef struct Object {
    ObjectID id;
    Coords coords;
    ObjectType type; 
    PlayerID owner;

    int life;

    union {
        struct SegObject {
            struct SegObject *next;    
            struct Arm *arm;
        } seg;

        struct CoreObject {
            struct Arm *arm;
        } core;
    };
} Object;

typedef struct Layer {
   struct Object *grid;
} Layer;

typedef struct Map {
    int width;
    int height;

    Layer layers[NUM_LAYERS]; 
} Map;

typedef struct Arm {
    Object *core;
    Object *activeSeg;
    struct SegObject *firstSeg;
    ArmID color;
} Arm;

typedef struct Player {
    Arm arms[NUM_COLORS];        
    int numArms;
} Player;

Object* map_get_object(const Map *map, const Coords *coords);
Object* map_get_adjacent_object(const Map *map, const Coords *coords, Direction dir);

#endif
