#ifndef __TIME_HPP
#define __TIME_HPP

#include <iostream>

class Time
{
private:
    int hours;
    int minutes;

    bool validate(int hours, int minutes);

public:
    Time(int hours = 0, int minutes = 0);

    int getHours() const;
    int getMinutes() const;

    void setHours(int hours);
    void setMinutes(int minutes);
};

bool operator<=(const Time &lhs, const Time &rhs);
bool operator>=(const Time &lhs, const Time &rhs);
bool operator<(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator==(const Time &lhs, const Time &rhs);
bool operator!=(const Time &lhs, const Time &rhs);

std::ostream& operator<<(std::ostream& os, const Time& time);

#endif