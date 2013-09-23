#ifndef _SIM_H
#define _SIM_H

#include "world.h"
#include "command.h"

<<<<<<< HEAD
struct SimState {
    Map map;
    int tick;
};

void sim_run_tick(SimState* state, const CommandList *commands);

bool sim_check_command(SimState* state, const Command* command);
=======
typedef struct SimState {
    Map map;
    int tick;

    Player *players[NUM_PLAYERS];
    int numPlayers;
} SimState;

void sim_run_tick(SimState *state, CommandList *commands);
>>>>>>> 4f3060951537f7d36e54da9be9687e02dedc33e2

#endif
