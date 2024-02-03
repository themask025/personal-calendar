#ifndef __DATE_HPP
#define __DATE_HPP

class Date
{
private:
    int year;
    int month;
    int day;

bool validate(int year, int month, int day);

public:
Date(int year = 2024, int month = 1, int day = 1);

int getYear() const;
int getMonth() const;
int getDay() const;

void setYear(int year);
void setMonth(int month);
void setDay(int day);

};

#endif