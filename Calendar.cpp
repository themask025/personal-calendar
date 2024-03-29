#include "Calendar.hpp"
#include <iostream>

bool Calendar::isCompatible(const Event &event)
{
    if (events.empty())
        return true;

    for (Event existingEvent : events)
    {
        if (event.getDate() == existingEvent.getDate() &&
            (((existingEvent.getStartTime() <= event.getStartTime()) && (event.getStartTime() < existingEvent.getEndTime())) ||
             ((existingEvent.getStartTime() < event.getEndTime()) && (event.getEndTime() <= existingEvent.getEndTime()))))
        {
            return false;
        }
    }

    return true;
}

Calendar::Calendar() : events({}) {}

const std::vector<Event>& Calendar::getEvents() const
{
    return this->events;
}

void Calendar::addEvent(const Event &event)
{
    if (!isCompatible(event))
        throw("Event overlaps with an existing event");

    this->events.push_back(event);
}

void Calendar::printEvents() const
{
    for (const Event &event : this->events)
    {
        std::cout << event << std::endl;
    }
}