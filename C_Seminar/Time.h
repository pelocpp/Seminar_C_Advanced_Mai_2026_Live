#pragma once

// Daten: Einfachster Fall einer Klasse / Objekts
struct time
{
    int hours;
    int minutes;
    int seconds;
};

typedef struct time Time;

// Funktionen, die alle auf struct time operieren / arbeiten:
// Einfachster Fall von Methoden 
extern void printTime   (const Time* self);
extern void resetTime   (      Time* self);
extern void addSeconds  (      Time* self, int seconds);

