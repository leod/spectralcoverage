#ifndef _COMMAND_H
#define _COMMAND_H

#include "direction.h"
#include "world.h"

typedef enum CommandType {
    CT_START,
    CT_END,
    CT_BUILD,
    CT_DESTROY,
    CT_SELECT
} CommandType;

typedef struct Command {
    CommandType type;
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
} Command;

typedef struct CommandList {
    Command command;
    struct CommandList *next;
} CommandList;

#endif
