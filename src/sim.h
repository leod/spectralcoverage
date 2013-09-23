#ifndef _SIM_H
#define _SIM_H

#include "world.h"
#include "command.h"

struct SimState {
    Map map;
    int tick;
};

void sim_run_tick(SimState* state, const CommandList *commands);

bool sim_check_command(SimState* state, const Command* command);

#endif
