#include "sim.h"

<<<<<<< HEAD
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
=======
#include <stdbool.h>
#include <assert.h>

static bool sim_verify_command(const SimState *state, const Command *command) {
    if (command->player < 0 || command->player >= NUM_PLAYERS)
        return false;
    Player *player = state->players[command->player];
    if (player == 0)
        return false;

    switch (command->type) {
    case CT_START:
    case CT_END:
        return true;
    case CT_BUILD: {
        if (command->build.arm < 0 || command->build.arm >= player->numCores)
            return false;
        Arm *arm = &player->arms[command->build.arm];
        if (!arm)
            return false;
        assert(arm->activeSeg);
        assert(arm->activeSeg->type == OT_SEG);

        Object *object = map_get_adjacent_object(&state->map, &arm->activeSeg->coords,
                                                 command->build.dir);  
        if (!object)
            return false;
        return object->type != OT_DEF;
    }
    case CT_DESTROY: {
        Object *object = map_get_object(&state->map, &command->destroy.coords);
        if (!object)
            return false;
        if (object->owner != command->player)
            return false;
        return true;
    }
    case CT_SELECT: {
        Object *object = map_get_object(&state->map, &command->select.coords);
        if (object == 0) return false; 
        if (object->owner != command->player) return false;
        return true;
    }
    default:                
        return false;
    } 
}

void sim_run_tick(SimState *state, CommandList *commands) {
    
>>>>>>> 4f3060951537f7d36e54da9be9687e02dedc33e2
}
