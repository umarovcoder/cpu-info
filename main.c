#include <stdio.h>
#include <stdlib.h>

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

void getInternetSpeed() {
    printf("\n🌍 Internet tezligi:\n");
    system("speedtest-cli --simple || echo \"speedtest-cli o'rnatilmagan\"");
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
    getDEInfo();
    getTemperature();
    getDiskInfo();
    getOSInfo();
    getUptime();
    getInternetSpeed();
    getCPULoad();
    printf("====================================\n");
    return 0;
}
