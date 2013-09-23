#include "sim.h"

static void runCommand(SimState* state, const Command *c) {
    switch (c->type) {
    case CT_BUILD:

    }
}

void sim_run_tick(SimState* state, const CommandList *commands) {

}

bool sim_check_command(SimState* state, const Command* command) {
    switch (c->type) {
    case CT_BUILD: {
        Object *object = map_get_object(&state->map, &command->build.coords)
        
        if (
    }
    }
}
