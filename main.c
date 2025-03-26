#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void getBatteryStatus() {
    FILE *fp;
    int battery;
    char status[16];

    // Foydalanuvchi tizimiga qarab avtomatik aniqlash
    char battery0_path[] = "/sys/class/power_supply/BAT0/capacity";
    char status0_path[] = "/sys/class/power_supply/BAT0/status";
    char battery1_path[] = "/sys/class/power_supply/BAT1/capacity";
    char status1_path[] = "/sys/class/power_supply/BAT1/status";

    char *battery_path = NULL;
    char *status_path = NULL;

    // Avval BAT0 ni tekshiramiz
    if (access(battery0_path, F_OK) == 0) {
        battery_path = battery0_path;
        status_path = status0_path;
    } 
    // Agar BAT0 yo‘q bo‘lsa, BAT1 ni tekshiramiz
    else if (access(battery1_path, F_OK) == 0) {
        battery_path = battery1_path;
        status_path = status1_path;
    } 


void getTopCPUProcesses() {
    printf("\n🔴 Eng ko‘p CPU ishlatayotgan jarayonlar:\n");
    printf("=========================================================\n");
    printf("| %-6s | %-10s | %-6s | %-6s | %-s \n", "PID", "User", "CPU%", "RAM%", "Command");
    printf("=========================================================\n");
    system("ps aux --sort=-%cpu | awk 'NR==1 || NR<=6 {printf(\"| %-6s | %-10s | %-6s | %-6s | %-s \\n\", $2, $1, $3, $4, $11)}'");
    printf("=========================================================\n");
}


void getTopRAMProcesses() {
    printf("\n🟢 Eng ko‘p RAM ishlatayotgan jarayonlar:\n");
    printf("=========================================================\n");
    printf("| %-6s | %-10s | %-6s | %-6s | %-s \n", "PID", "User", "CPU%", "RAM%", "Command");
    printf("=========================================================\n");
    system("ps aux --sort=-%mem | awk 'NR==1 || NR<=6 {printf(\"| %-6s | %-10s | %-6s | %-6s | %-s \\n\", $2, $1, $3, $4, $11)}'");
    printf("=========================================================\n");
}


void getCPUTemperature() {
    printf("\n🌡️ CPU harorati:\n");
    system("sensors | grep 'Core 0' | awk '{print $3}' || echo 'lm-sensors o‘rnatilmagan'");
}

void getRAMUsage() {
    printf("\n💾 RAM yuklanishi:\n");
    system("free -h | awk 'NR==2{print \"Jami: \" $2 \" | Ishlatilgan: \" $3 \" | Bo‘sh: \" $4}'");
}

void getCPUInfo() {
    printf("\n🖥  CPU ma'lumotlari:\n");
    system("nproc");
}

void getRAMInfo() {
    printf("\n💾 RAM ma'lumotlari:\n");
    system("free -h | grep Mem");
}

void getGPUInfo() {
    printf("\n🎮 GPU ma'lumotlari:\n");
    system("lspci | grep VGA");
}

void getDEInfo() {
    printf("\n🖥  Desktop Environment (DE):\n");
    system("echo $XDG_CURRENT_DESKTOP");
}

void getTemperature() {
    printf("\n🌡  Harorat ma'lumotlari:\n");
    system("sensors | grep 'Core' || echo 'Sensor topilmadi'");
}

void getDiskInfo() {
    printf("\n💽 Disk ma'lumotlari:\n");
    system("df -h --total | grep 'total'");
}

void getOSInfo() {
    printf("\n🖥  Operatsion tizim ma'lumotlari:\n");
    system("cat /etc/os-release | grep PRETTY_NAME");
}

void getUptime() {
    printf("\n⏳ Ishlash vaqti:\n");
    system("uptime -p");
}


void getCPULoad() {
    printf("\n🚀 CPU yuklamasi:\n");
    system("top -bn1 | grep 'Cpu(s)' | awk '{print $2 + $4 \"% loaded\"}'");
}


int main() {
    printf("\n🔥 Linux tizim ma'lumotlari\n");
    printf("====================================\n");
    getCPUInfo();
    getRAMInfo();
    getGPUInfo();
    getCPUTemperature();  // 🆕 CPU harorati
    getRAMUsage();        // 🆕 RAM yuklanishi
    getDEInfo();
    getTemperature();
    getDiskInfo();
    getOSInfo();
    getUptime();
    getCPULoad();
    getTopRAMProcesses();  // 🆕 Eng ko‘p RAM ishlatayotgan jarayonlar
    getTopCPUProcesses();  // 🆕 Eng ko‘p CPU ishlatayotgan jarayonlar
    getBatteryStatus();
    int main() {
    getBatteryStatus();
    return 0;
}

    printf("====================================\n");
    return 0;
}
