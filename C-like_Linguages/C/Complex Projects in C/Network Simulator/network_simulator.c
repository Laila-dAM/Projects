#include <stdio.h>
#include "router.c"
#include "device.c"
#include "utils.c"

void network_main(){
    init_router();
    init_devices();
    printf("Network simulator initialized!\n");
}
int main(){
    network_main();
    return 0;
}