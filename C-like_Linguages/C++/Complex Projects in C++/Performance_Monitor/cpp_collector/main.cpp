#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "cpu_monitor.cpp"
#include "memory_monitor.cpp"
#include "network_monitor.cpp"

int main() {
    while(true) {
     double cpuUsage = getCpuUsage();
        double memoryUsage = getMemoryUsage();
        double nteworkUsage = getNetworkUsage();

    std::ofstream outfile;
        outfile.open("data/performance_data.csv", std::ios_base::app);
        outfile << cpuUsage << "," << memoryUsage << "," << networkUsage << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
return 0;
}