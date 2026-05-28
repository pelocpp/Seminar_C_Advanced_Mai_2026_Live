#include <stdio.h>

#include "Time.h"

// besser
const int MaxSize2 = 100;


//struct time
//{
//    int hours;
//    int minutes;
//    int seconds;
//} /*now*/;
//

void demo_structs()
{
    Time now;  // ohne Vorbelegung // kann zu Fehlern führen

    // geht, aber dennoch schlecht
    now.hours = 14;
    now.minutes = 7;
    now.seconds = 30;

    Time later = { 15, 30, 0 }; // mit Vorbelegung // __init__ in Python

    // besser lesbar
    Time moreLater = { .hours = 17, .minutes= 0, .seconds = 0 }; // mit Vorbelegung

    //printf("Time: %02d:%02d:%02d\n", now.hours, now.minutes, now.seconds);
    //printf("Time: %02d:%02d:%02d\n", later.hours, later.minutes, later.seconds);

    printTime(&now);

    resetTime(&now);

    printTime(&now);
}

void demo_structs_bad()
{
    int hours;
    int minutes;
    int seconds;

    //int hours2;
    //int minutes2;
    //int seconds2;


    hours = 14;
    minutes = 3;
    seconds = 30;
}

void printTime( const Time* self)
{
    printf("Time: %02d:%02d:%02d\n", self->hours, self->minutes, self->seconds);
}

//void resetTime(Time t)
//{
//    t.hours = 0;
//    t.minutes = 0;
//    t.seconds = 0;
//}

void resetTime(Time* self)
{
    //t.hours = 0;
    //t.minutes = 0;
    //t.seconds = 0;

    //(*t).hours = 0;
    //(*t).minutes = 0;
    //(*t).seconds = 0;

    // oder / gleichbedeutend

    self->hours = 0;
    self->minutes = 0;
    self->seconds = 0;
}

void addSeconds(Time* self, int seconds)
{
    self->seconds = self->seconds + seconds;

    // Überlauf
    if (self->seconds >= 60) {

        int min = self->seconds / 60;

        self->seconds = self->seconds % 60;
        self->minutes = self->minutes + min;
    }
}