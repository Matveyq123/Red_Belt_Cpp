#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;
// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time

bool operator < (const Date& lhs, const Date& rhs)
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

bool operator != (const Date& lhs, const Date& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator << (std::ostream& os, const Date& date)
{
    os << date.year << " " << date.month << " " << date.day;
    return os;
}

std::istream& operator >> (std::istream& is, Date& date)
{
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    
    return is;
}


bool operator < (const Time& lhs, const Time& rhs)
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

bool operator != (const Time& lhs, const Time& rhs)
{
    return !(lhs.minutes == rhs.minutes);
}

std::ostream& operator << (std::ostream& os, const Time& time)
{
    os << time.hours << " " << time.minutes;
    return os;
}

std::istream& operator >> (std::istream& is, Time& time)
{
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;

    return is;
}

#define UPDATE_FIELD(ticket, field, values)  \
{                                            \
    map<string, string>::const_iterator it;  \
    it = values.find(#field);                \
    if(it != values.end())                   \
    {                                        \
     std::istringstream is(it->second);      \
     is >> ticket.field;                     \
    }                                        \
}

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
      {"departure_date", "2018-2-28"},
      {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
      {"price", "12550"},
      {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{ 20, 33 }));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}