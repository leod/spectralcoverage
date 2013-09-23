#include <stdbool.h>
#include <stdio.h>

#include "net.h"
#include "error.h"

int main(int argc, char* argv[]) {
    if (enet_initialize() != 0)
        fatal_error("No init");

    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = NET_STANDARD_PORT;

    ENetHost *server;
    server = enet_host_create(&address, 32, 1, 0, 0);
    if (server == NULL)
        fatal_error("No server");

    int numExpectedPlayers = 2;
    int numPlayers = 0;
    bool gameStarted = false;

    while (1) {
        ENetEvent event;
        while (enet_host_service(server, &event, 0) > 0) {
            switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",
                       event.peer->address.host,
                       event.peer->address.port);
                numPlayers++;
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                break;
            default:
                break;
            }
        }
    }

    enet_host_destroy(server);
}
