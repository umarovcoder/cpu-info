#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

// CPU ma'lumotini olish
void get_cpu_info() {
    long num_procs = sysconf(_SC_NPROCESSORS_ONLN);
    printf("🖥  CPU: %ld cores\n", num_procs);
}

// RAM ma'lumotini olish
void get_ram_info() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("💾 RAM: %.2f GB total, %.2f GB available\n",
               (double)info.totalram / (1024 * 1024 * 1024),
               (double)info.freeram / (1024 * 1024 * 1024));
    } else {
        printf("💾 RAM ma'lumotini olishda xatolik!\n");
    }
}

// GPU ma'lumotini olish
void get_gpu_info() {
    FILE *fp;
    char buffer[128];

    fp = popen("lspci | grep -i vga", "r");
    if (fp == NULL) {
        printf("🎮 GPU ma'lumotini olishda xatolik!\n");
        return;
    }

    printf("🎮 GPU: ");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

// Desktop Environment (DE) ni aniqlash
void get_desktop_env() {
    FILE *fp;
    char buffer[128];

    fp = popen("echo $XDG_CURRENT_DESKTOP", "r");
    if (fp == NULL) {
        printf("🖥  DE ma'lumotini olishda xatolik!\n");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("🖥  Desktop Environment: %s", buffer);
    } else {
        printf("🖥  Desktop Environment topilmadi!\n");
    }
    pclose(fp);
}

int main() {
    printf("\n🚀 System Info Detector 🚀\n");
    get_cpu_info();
    get_ram_info();
    get_gpu_info();
    get_desktop_env();
    printf("\n");
    return 0;
}
