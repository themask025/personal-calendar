#ifndef __CALENDAR_HPP
#define __CALENDAR_HPP

#include <vector>
#include "Event.hpp"

class Calendar
{
private:
    std::vector<Event> events;

    bool isCompatibleTimeInterval(const Date &date, const Time &startTime, const Time &endTime);
    bool isCompatibleEditingOfEvent(const Date &newDate, const Time &newStartTime, const Time &newEndTime, std::vector<Event>::iterator eventToEdit);
    std::vector<Event>::const_iterator searchEvent(const Date &date, const Time &startTime) const;
    std::vector<Event>::iterator getEvent(const Date &date, const Time &startTime);
    std::vector<Event> findEventsByKeyword(const std::string keyword) const;

public:
    Calendar();

    const std::vector<Event> &getEvents() const;
    bool containsEvent(const Date &date, const Time &startTime) const;

    void addEvent(const Event &event);
    void removeEvent(const Date &date, const Time &startTime);
    void editEvent(
        const Date &date,
        const Time &startTime,
        std::string newName,
        std::string newComment,
        Date newDate,
        Time newStartTime,
        Time newEndTime);

    void printDailySchedule(const Date &date) const;
    void printEventsByKeyword(const std::string keyword) const; 
    void printEvents() const;
};

#endif