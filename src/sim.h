#ifndef _SIM_H
#define _SIM_H

#include <stdint.h>

#include "world.h"
#include "command.h"

typedef int32_t Tick;

typedef struct SimState {
    Map map;
    int tick;
} SimState;

void sim_run_tick(SimState *state, const CommandList *commands);

bool sim_check_command(SimState *state, const Command *command);

#endif
