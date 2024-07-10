#include "Calendar.hpp"
#include <iostream>
#include <algorithm>

bool Calendar::isCompatibleTimeInterval(const Date &date, const Time &startTime, const Time &endTime)
{
    for (Event existingEvent : events)
    {
        if (date == existingEvent.getDate() &&
            (((existingEvent.getStartTime() <= startTime) && (endTime < existingEvent.getEndTime())) ||
             ((existingEvent.getStartTime() < endTime) && (endTime <= existingEvent.getEndTime()))))
        {
            return false;
        }
    }

    return true;
}

std::vector<Event>::const_iterator Calendar::searchEvent(const Date &date, const Time &startTime) const
{
    for (std::vector<Event>::const_iterator it = events.begin(); it != events.end(); ++it)
    {
        if (it->getDate() == date && it->getStartTime() == startTime)
            return it;
    }

    return events.end();
}

Calendar::Calendar() : events({}) {}

const std::vector<Event> &Calendar::getEvents() const
{
    return this->events;
}

bool Calendar::containsEvent(const Date &date, const Time &startTime) const
{
    return searchEvent(date, startTime) != events.end();
}

void Calendar::addEvent(const Event &event)
{
    if (!isCompatibleTimeInterval(event.getDate(), event.getStartTime(), event.getEndTime()))
        throw("Event overlaps with an existing event");

    this->events.push_back(event);
}

void Calendar::removeEvent(const Date &date, const Time &startTime)
{
    std::vector<Event>::const_iterator target = searchEvent(date, startTime);

    if (target == events.end())
        throw("The event targeted for removal does not exist.");

    events.erase(target);
}

void Calendar::printDailySchedule(const Date &date) const
{
    std::vector<Event> filteredEvents;

    for (Event event : events)
    {
        if (event.getDate() == date)
            filteredEvents.push_back(event);
    }

    std::sort(filteredEvents.begin(), filteredEvents.end());

    for (const Event &event : filteredEvents)
    {
        std::cout << event << std::endl;
    }
}

void Calendar::printEvents() const
{
    for (const Event &event : this->events)
    {
        std::cout << event << std::endl;
    }
}