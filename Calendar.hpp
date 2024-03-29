#ifndef __CALENDAR_HPP
#define __CALENDAR_HPP

#include <vector>
#include "Event.hpp"

class Calendar
{
private:
    std::vector<Event> events;

    bool isCompatible(const Event& event);
public:
    Calendar();

    const std::vector<Event>& getEvents() const;

    void addEvent(const Event& event);
    void printEvents() const;
};


#endif