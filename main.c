#include <stdio.h>
#include <stdlib.h>

void getTopRAMProcesses() {
    printf("\n🔝 Eng ko‘p RAM ishlatayotgan jarayonlar:\n");
    system("ps aux --sort=-%mem | awk 'NR<=6 {print $1, $2, $4\"%\", $11}'");
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
    getCPUTemperature();  // 🆕 CPU harorati
    getRAMUsage();        // 🆕 RAM yuklanishi
    getDEInfo();
    getTemperature();
    getDiskInfo();
    getOSInfo();
    getUptime();
    getInternetSpeed();
    getCPULoad();
    getTopRAMProcesses();  // 🆕 Eng ko‘p RAM ishlatayotgan jarayonlar
    printf("====================================\n");
    return 0;
}
