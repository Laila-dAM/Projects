#include <stdio.h>

void init_devices(){
    printf("Devices initialized!\n");
}

void send_packet(const char* device, const char* data){
    printf("Device %s sent data: %s\n", device, data);
}
void receive_packet(const char* device, const char* data){
    printf("Device %s received data: %s\n", device, data);
}