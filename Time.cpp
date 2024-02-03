#include "Time.hpp"

bool Time::validate(int hours, int minutes)
{
    return 0 <= hours <= 23 && 0 <= minutes <= 59;
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
    if(hours < 0 || hours > 23)
        throw("Invalid hours given for setting");
    this->hours = hours;
}
void Time::setMinutes(int minutes)
{
    if(minutes < 0 || minutes > 59)
        throw("Invalid minutes given for setting");
    this->minutes = minutes;
}