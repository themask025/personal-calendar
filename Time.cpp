#include "Time.hpp"
#include <iostream>

bool Time::validate(int hours, int minutes)
{
    return 0 <= hours && hours <= 23 && 0 <= minutes && minutes <= 59;
}

Time::Time(int hours, int minutes)
{
    if (!validate(hours, minutes))
    {
        throw("Invalid time!");
    }
    this->hours = hours;
    this->minutes = minutes;
}

int Time::getHours() const
{
    return this->hours;
}
int Time::getMinutes() const
{
    return this->minutes;
}

void Time::setHours(int hours)
{
    if (hours < 0 || hours > 23)
        throw("Invalid hours given for setting");
    this->hours = hours;
}
void Time::setMinutes(int minutes)
{
    if (minutes < 0 || minutes > 59)
        throw("Invalid minutes given for setting");
    this->minutes = minutes;
}

double Time::toHours() const
{
    return (this->hours + (double(this -> minutes) / 60));
}

bool operator<=(const Time &lhs, const Time &rhs)
{
    return lhs.getHours() < rhs.getHours() ||
           (lhs.getHours() == rhs.getHours() && lhs.getMinutes() <= rhs.getMinutes());
}
bool operator>=(const Time &lhs, const Time &rhs)
{
    return rhs <= lhs;
}
bool operator<(const Time &lhs, const Time &rhs)
{
    return (lhs.getHours() < rhs.getHours()) ||
           ((lhs.getHours() == rhs.getHours()) && (lhs.getMinutes() < rhs.getMinutes()));
}
bool operator>(const Time &lhs, const Time &rhs)
{
    return !(lhs <= rhs);
}
bool operator==(const Time &lhs, const Time &rhs)
{
    return lhs >= rhs && lhs <= rhs;
}
bool operator!=(const Time &lhs, const Time &rhs)
{
    return !(lhs == rhs);
}

Time operator+(const Time &lhs, const Time &rhs)
{
    Time result;

    result.setMinutes((lhs.getMinutes() + rhs.getMinutes()) % 60);
    result.setHours((lhs.getHours() + rhs.getHours() + (lhs.getMinutes() + rhs.getMinutes()) / 60) % 24);

    return result;
}

Time operator-(const Time &lhs, const Time &rhs)
{
    if (lhs < rhs)
    {
        throw("Attempt to substract greater time from smaller time!");
    }

    Time result;
    if (lhs.getMinutes() < rhs.getMinutes())
    {
        result.setMinutes((lhs.getMinutes() + 60) - rhs.getMinutes());
        result.setHours((lhs.getHours() - 1) - rhs.getHours());
    }
    else
    {
        result.setMinutes(lhs.getMinutes() - rhs.getMinutes());
        result.setHours(lhs.getHours() - rhs.getHours());
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time &time)
{
    if (time.getHours() < 10)
        os << "0";

    os << time.getHours() << ":";

    if (time.getMinutes() < 10)
        os << "0";

    os << time.getMinutes();

    return os;
}

std::istream &operator>>(std::istream &is, Time &time)
{
    int hours = 0;
    int minutes = 0;

    std::cout << "Please enter hours:" << std::endl;
    is >> hours;
    std::cout << "Please enter minutes:" << std::endl;
    is >> minutes;

    time.setHours(hours);
    time.setMinutes(minutes);

    return is;
}
