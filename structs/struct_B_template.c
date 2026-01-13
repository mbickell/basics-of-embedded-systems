#include <stdio.h>
#include <string.h>

typedef struct
{
    float temp;
    int wind;
    char weekday[10];
} day;

void writeData(day *p_day, float temp, int wind, char *weekday)
{
    p_day->temp = temp;
    p_day->wind = wind;

    strcpy(p_day->weekday, weekday);

} // writeData

void printData(day *p_day)
{

    printf("%f\n", p_day->temp);
    printf("%d\n", p_day->wind);
    printf("%s\n", p_day->weekday);

} // printData

int main()
{
    day currentDay;

    day days[7];

    for (int i = 0; i < 7; i++)
    {
        writeData(&days[i], 1.4 + i, 10 + i, "Sunday\0");
    }

    for (int i = 0; i < 7; i++)
    {
        printData(&days[i]);
    }

    return 0;
}