#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void printDate(const char *format) 
{
    time_t current = time(NULL);
    struct tm *tm_struct = localtime(&current);
    char date[100];
    if (strftime(date, sizeof(date), format, tm_struct) == 0) 
    {
        fprintf(stderr, "Error formatting date\n");
        exit(1);
    }
    printf("%s\n", date);
}

int main() 
{
    printDate("%c");
    int choice;
    printf("Enter Time Format: 1)UTC FORMAT 2)RFC FORMAT : ");
    scanf("%d",&choice);

    if(choice==1)
        printDate("%Y-%m-%dT%H:%M:%SZ");
    else if(choice==2)
        printDate("%a, %d %b %Y %H:%M:%S %z");
    else 
    {
        printf("Invalid choice");
        return 1;
    }

    return 0;
}
