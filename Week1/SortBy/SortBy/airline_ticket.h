#ifndef AIRLINE_TICKET_H
#define AIRLINE_TICKET_H

#include <string>
using namespace std;

struct Date {
    int year, month, day;
};

/*bool operator < (const Date& lhs, const Date& rhs)
{

    if (lhs.year != rhs.year)
    {
        return lhs.year < rhs.year;
    }

    if (lhs.month != rhs.month)
    {
        return lhs.month < rhs.month;
    }
    
    return lhs.day < rhs.day;
}

bool operator == (const Date& lhs, const Date& rhs)
{
    if (lhs.year != rhs.year)
    {
        return lhs.year == rhs.year;
    }

    if (lhs.month != rhs.month)
    {
        return lhs.month == rhs.month;
    }

    return lhs.day == rhs.day;
}

std::ostream& operator << (std::ostream& os, const Date& date)
{
    os << date.year << " " << date.month << " " << date.day;
    return os;
}*/

struct Time {
    int hours, minutes;
};

/*bool operator < (const Time& lhs, const Time& rhs)
{
    if (lhs.hours != rhs.hours)
    {
        return lhs.hours < rhs.hours;
    }

    return lhs.minutes < rhs.minutes;
}

bool operator == (const Time& lhs, const Time& rhs)
{
    if (lhs.hours != rhs.hours)
    {
        return lhs.hours == rhs.hours;
    }

    return lhs.minutes == rhs.minutes;
}

std::ostream& operator << (std::ostream& os, const Time& time)
{
    os << time.hours << " " << time.minutes;
    return os;
}*/


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
