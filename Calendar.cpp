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

std::vector<Event>::const_iterator Calendar::searchEvent(const Date& date, const Time& startTime) const
{
    for(std::vector<Event>::const_iterator it = events.begin(); it != events.end(); ++it)
    {
        if(it->getDate() == date && it->getStartTime() == startTime)
            return it;
    }

    return events.end();
}

Calendar::Calendar() : events({}) {}

const std::vector<Event>& Calendar::getEvents() const
{
    return this->events;
}

bool Calendar::containsEvent(const Date& date, const Time& startTime) const
{
    return searchEvent(date, startTime) != events.end();
}


void Calendar::addEvent(const Event &event)
{
    if (!isCompatible(event))
        throw("Event overlaps with an existing event");

    this->events.push_back(event);
}

void Calendar::removeEvent(const Date& date, const Time& startTime)
{
    std::vector<Event>::const_iterator target = searchEvent(date, startTime);

    if(target == events.end())
        throw("The event targeted for removal does not exist.");

    events.erase(target);  
}

void Calendar::printEvents() const
{
    for (const Event &event : this->events)
    {
        std::cout << event << std::endl;
    }
}