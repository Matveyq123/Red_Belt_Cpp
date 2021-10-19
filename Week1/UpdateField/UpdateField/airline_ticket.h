#ifndef __AIRLINE_TICKET_H__
#define __AIRLINE_TICKET_H__

#include <string>
using namespace std;

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

struct AirlineTicket {
    string from;
    string to;
    string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    int price;
};

#endif

