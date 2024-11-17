#include <stdio.h>
#include <stdlib.h>

int zellersCongruence(int day, int month, int year) 
{
    if (month < 3) 
    {
        month += 12;
        year -= 1;
    }
    int d = day;
    int m = month;
    int k = year % 100;   
    int j = year / 100;       
    int f= d + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + (5 * j);
    return (f%7)-1;
}

void printCalendar(int month, int year)
{
    char *months[] = {"", "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[2] = 29;

    printf("     %s %d\n", months[month], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int startDay = zellersCongruence(1, month, year);
    int day, i;

    for (i = 0; i < startDay; i++)
        printf("   ");

    for (day = 1; day <= daysInMonth[month]; day++) 
    {
        printf("%2d ", day);
        if ((day + startDay) % 7 == 0)
            printf("\n");
    }
    if ((day + startDay - 1) % 7 != 0)
        printf("\n");
}

void invalid() 
{
    printf("Usage: Enter a valid month (1-12) and year (>0)\n");
}

int main() 
{
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    if (month < 1 || month > 12) 
    {
        printf("Invalid month!\n");
        invalid();
        return 1;
    }

    printf("Enter year (>0): ");
    scanf("%d", &year);
    if (year < 1) 
    {
        printf("Invalid year!\n");
        invalid();
        return 1;
    }

    printCalendar(month, year);
    return 0;
}
