#include <stdio.h>

void init_router(){
    printf("Router initialized!\n");
}

void route_packet(const char* src, const char* dest){
    printf("Routing packet from %s to %s\n", src, dest);
}