#include <stdio.h>
#include <sys/sysinfo.h>

void print_uptime() 
{
    struct sysinfo info;
    if (sysinfo(&info) != 0) 
    {
        printf("error retrieving sysinfo");
        return;
    }

    long uptime = info.uptime;
    int hours = uptime / 3600;
    int minutes = (uptime % 3600) / 60;
    int seconds = uptime % 60;

    printf("Uptime: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
}

int main() 
{
    print_uptime();
    return 0;
}
