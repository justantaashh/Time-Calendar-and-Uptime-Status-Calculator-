#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
pid_t pid1, pid2, pid3;

pid1 = fork();
if (pid1 == 0) 
{
    execl("./date", "date", NULL);
    exit(0);
}
wait(NULL);
pid2 = fork();
if (pid2 == 0) 
{
    execl("./cal", "cal", NULL);
    exit(0);
}
wait(NULL);
pid3 = fork();
if (pid3 == 0) 
{
    execl("./uptime", "uptime", NULL);
    exit(0);
}
wait(NULL);
return 0;
}
