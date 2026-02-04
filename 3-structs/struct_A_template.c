#include <stdio.h>
#include <string.h>

int main()
{

    typedef struct
    {
        float temp;
        int wind;
        char weekday[10];
    } day;

    day currentDay;

    currentDay.temp = 20.5;
    currentDay.wind = 3;

    strcpy(currentDay.weekday, "Monday\0");

    printf("%f\n", currentDay.temp);
    printf("%d\n", currentDay.wind);
    printf("%s\n", currentDay.weekday);

    return 0;
}