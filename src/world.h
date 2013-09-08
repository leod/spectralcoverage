#ifndef _OBJECT_H
#define _OBJECT_H

#define NUM_LAYERS 3

typedef enum ObjectType {
    OT_PIPE,
    OT_CORE,
    OT_ATT,
    OT_DEF,
    OT_RES
} ObjectType;

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

#endif
