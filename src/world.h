#ifndef _OBJECT_H
#define _OBJECT_H

#include <stdint.h>
#include <stdbool.h>

#include "direction.h"

#define NUM_LAYERS 3
#define NUM_COLORS 4
#define NUM_PLAYERS 10

typedef int16_t player_id;

typedef enum ObjectType {
    OT_NULL,
    OT_SEG,
    OT_CORE,
    OT_ATT,
    OT_DEF,
    OT_RES
} ObjectType;

struct Arm;

typedef struct Coords {
    int x;
    int y;
    int z;
} Coords;

typedef struct Object {
    Coords coords;
    ObjectType type; 
    player_id owner;

    int life;

    union {
        struct SegObject {
            struct SegObject *next;    
            struct Arm *arm;
        } seg;

        struct CoreObject {
            struct Arm *arm;
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
    int color;
} Arm;

typedef enum ResourceType {
    RT_SALT,
    RT_SUGAR,
    RT_NUM
} ResourceType;

typedef struct Player {
    Arm arms[NUM_COLORS];        
    Object *core[NUM_COLORS];
    int numCores;

    int res[RT_NUM];
} Player;

Object* map_get_object(const Map *map, const Coords *coords);
Object* map_get_adjacent_object(const Map *map, const Coords *coords, Direction dir);

#endif
