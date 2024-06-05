#include "Date.hpp"

bool isLeap(int year)
{
    if (year % 100 == 0)
        return (year % 400) == 0;
    return (year % 4) == 0;
}

bool Date::validate(int year, int month, int day)
{
    if (year < 0)
        return false;

    int maxValidDay = 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxValidDay = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxValidDay = 30;
        break;
    case 2:
        if (isLeap(year))
            maxValidDay = 29;
        else
            maxValidDay = 28;
        break;
    default:
        // throw("Invalid month value!");
        return false;
        break;
    }

    return (1 <= day && day <= maxValidDay);
}

Date::Date(int year, int month, int day)
{
    if (!validate(year, month, day))
        throw("Invalid date!");
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getYear() const
{
    return this->year;
}
int Date::getMonth() const
{
    return this->month;
}
int Date::getDay() const
{
    return this->day;
}

void Date::setYear(int year)
{
    if (year < 0)
        throw("Invalid year given for setting");
    this->year = year;
}
void Date::setMonth(int month)
{
    if (month < 1 || month > 12)
        throw("Invalid month given for setting");
    this->month = month;
}
void Date::setDay(int day)
{
    if (!validate(this->year, this->month, this->day))
        throw("Invalid day given for setting");
    this->day = day;
}

bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs.getYear() == rhs.getYear() &&
           lhs.getMonth() == rhs.getMonth() &&
           lhs.getDay() == rhs.getDay();
}
bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.getYear() == rhs.getYear())
    {
        if (lhs.getMonth() == rhs.getMonth())
        {
            return lhs.getDay() < rhs.getDay();
        }
        return lhs.getMonth() < rhs.getMonth();
    }
    return lhs.getYear() < rhs.getYear();
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    if (date.getDay() < 10)
        os << "0";

    os << date.getDay() << ".";

    if (date.getMonth() < 10)
        os << "0";

    os << date.getMonth() << "." << date.getYear();

    return os;
}