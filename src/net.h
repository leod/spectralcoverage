#ifndef _NET_H
#define _NET_H

#include <enet/enet.h>

#include "command.h"
#include "sim.h"

typedef enum MessageType {
    MT_SETUP,
    MT_COMMAND,
    MT_TICK
} MessageType;

typedef struct Message {
    MessageType type;

    union {
        struct SetupMessage {
            int8_t playerCount;
            int16_t mapID;
            PlayerID id;
        } setup;

        struct CommandMessage {
            Command command;
            Tick tick;
        } command;

        struct TickMessage {
            Tick tick;
        } tick;
    };
} Message;

ENetPacket *net_message_to_packet(const Message *message);
Message net_packet_to_message(const ENetPacket *packet);


#endif
