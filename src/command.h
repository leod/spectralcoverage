#ifndef _COMMAND_H
#define _COMMAND_H

<<<<<<< HEAD
#include "world.h"

typedef enum CommandType {
    CT_BUILD,
    CT_SELECT,
=======
#include "direction.h"
#include "world.h"

typedef enum CommandType {
    CT_START,
    CT_END,
    CT_BUILD,
    CT_DESTROY,
    CT_SELECT
>>>>>>> 4f3060951537f7d36e54da9be9687e02dedc33e2
} CommandType;

typedef struct Command {
    CommandType type;
<<<<<<< HEAD
    PlayerID player;

    union {
        struct BuildCommand {
            Direction dir;
        } build;
        struct SelectCommand {
            ObjectId id;
        } select;
    };  
=======
    player_id player;

    union {
        struct BuildCommand {
            int arm;
            ObjectType type; 
            Direction dir;    
        } build;

        struct SelectCommand {
            Coords coords;    
        } select;

        struct DestroyCommand {
            Coords coords;
        } destroy;
    };
>>>>>>> 4f3060951537f7d36e54da9be9687e02dedc33e2
} Command;

typedef struct CommandList {
    Command command;
    struct CommandList *next;
} CommandList;

#endif
