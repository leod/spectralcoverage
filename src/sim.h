#ifndef _SIM_H
#define _SIM_H

#include "world.h"
#include "command.h"

typedef struct SimState {
    Map map;
    int tick;

    Player *players[NUM_PLAYERS];
    int numPlayers;
} SimState;

void sim_run_tick(SimState *state, CommandList *commands);

#endif
