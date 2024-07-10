#ifndef __CALENDAR_HPP
#define __CALENDAR_HPP

#include <vector>
#include "Event.hpp"

class Calendar
{
private:
    std::vector<Event> events;

    bool isCompatibleTimeInterval(const Date& date, const Time& startTime, const Time& endTime);
    std::vector<Event>::const_iterator searchEvent(const Date& date, const Time& startTime) const;

public:
    Calendar();

    const std::vector<Event>& getEvents() const;
    bool containsEvent(const Date& date, const Time& startTime) const;

    void addEvent(const Event& event);
    void removeEvent(const Date& date, const Time& startTime);
    void printDailySchedule(const Date& date) const;
    void printEvents() const;
};


#endif