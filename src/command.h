#ifndef _COMMAND_H
#define _COMMAND_H

#include "world.h"
#include "direction.h"

typedef enum CommandType {
    CT_BUILD,
    CT_SELECT,
} CommandType;

typedef struct Command {
    CommandType type;
    PlayerID player;

    union {
        struct BuildCommand {
            Direction dir;
        } build;
        struct SelectCommand {
            ObjectID id;
        } select;
    };  
} Command;

typedef struct CommandList {
    Command command;
    struct CommandList *next;
} CommandList;

#endif
