#ifndef DEVICE_H
#define DEVICE_H

void init_devices();
void send_packet(const char* device, const char* data);
void receive_packet(const char* device, const char* data);

#endif
