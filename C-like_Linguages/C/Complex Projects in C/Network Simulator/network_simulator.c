#include <stdio.h>
#include "router.h"
#include "device.h"
#include "utils.h"

void network_main(){
    init_router();
    init_devices();
    printf("Network simulator initialized!\n");
}
int main(){
    network_main();
    return 0;
}