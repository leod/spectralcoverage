#include "net.h"

#include <assert.h>

ENetPacket *net_message_to_packet(const Message *message) {
    // TODO 
    return enet_packet_create(message, sizeof(Message),
                              ENET_PACKET_FLAG_RELIABLE);
}

Message net_packet_to_message(const ENetPacket *packet) {
    assert(packet->dataLength == sizeof(Message));
    return *(Message*)packet->data;
}
