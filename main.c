#include <stdio.h>
#include <stdlib.h>

#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

void get_cpu_info() {
    FILE *fp;
    char buffer[128];

    // CPU Model
    printf(BLUE "--------------------------------\n" RESET);
    printf(BLUE "|        SYSTEM INFORMATION    |\n" RESET);
    printf(BLUE "--------------------------------\n" RESET);

    fp = popen("grep 'model name' /proc/cpuinfo | head -1 | cut -d':' -f2", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    printf(GREEN "CPU Model:" RESET " %s", buffer);

    // CPU Cores
    fp = popen("grep -c '^processor' /proc/cpuinfo", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    printf(GREEN "CPU Cores:" RESET " %s", buffer);

    // CPU Speed
    fp = popen("lscpu | grep 'CPU MHz' | awk '{print $3}'", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    printf(GREEN "CPU Speed:" RESET " %s MHz\n", buffer);
}

void get_ram_info() {
    FILE *fp;
    char buffer[128];

    // Total RAM
    fp = popen("grep 'MemTotal' /proc/meminfo | awk '{print $2}'", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    printf(YELLOW "Total RAM:" RESET " %.2f GB\n", atof(buffer) / 1024 / 1024);

    // Free RAM
    fp = popen("grep 'MemAvailable' /proc/meminfo | awk '{print $2}'", "r");
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);
    printf(YELLOW "Available RAM:" RESET " %.2f GB\n", atof(buffer) / 1024 / 1024);
    
    printf(BLUE "--------------------------------\n" RESET);
}

int main() {
    get_cpu_info();
    get_ram_info();
    return 0;
}
