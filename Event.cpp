#include "Event.hpp"
#include <iostream>

Event::Event(std::string name,
             std::string comment,
             Date date,
             Time startTime,
             Time endTime) : name(name),
                             comment(comment),
                             date(date)
{
    if (startTime > endTime)
        throw("Invalid values for startTime and endTime");

    this->startTime = startTime;
    this->endTime = endTime;
}

const std::string &Event::getName() const
{
    return this->name;
}
const std::string &Event::getComment() const
{
    return this->comment;
}
const Date &Event::getDate() const
{
    return this->date;
}
const Time &Event::getStartTime() const
{
    return this->startTime;
}
const Time &Event::getEndTime() const
{
    return this->endTime;
}

void Event::setName(std::string name)
{
    this->name = name;
}
void Event::setComment(std::string comment)
{
    this->comment = comment;
}
void Event::setDate(Date date)
{
    this->date = date;
}
void Event::setStartTime(Time startTime)
{
    if (startTime > this->endTime)
        throw("Event: Invalid startTime value for setting");
    this->startTime = startTime;
}
void Event::setEndTime(Time endTime)
{
    if (endTime < this->startTime)
        throw("Event: Invalid endTime value for setting");
    this->endTime = endTime;
}

std::ostream &operator<<(std::ostream &os, const Event &event)
{
    os << "Event -----------------------" << std::endl;
    os << "Name: " << event.getName() << std::endl;
    os << "Comment: " << event.getComment() << std::endl;
    os << "Date: " << event.getDate() << std::endl;
    os << "Start time: " << event.getStartTime() << std::endl;
    os << "End time: " << event.getEndTime() << std::endl;
    os << "-----------------------------" << std::endl;

    return os;
}

bool operator<(const Event &lhs, const Event &rhs)
{
    if (lhs.getDate() == rhs.getDate())
    {
        return lhs.getStartTime() < rhs.getStartTime();
    }
    return lhs.getDate() < rhs.getDate();
}

bool operator==(const Event &lhs, const Event &rhs)
{
    return lhs.getName() == rhs.getName() &&
           lhs.getComment() == rhs.getComment() &&
           lhs.getDate() == rhs.getDate() &&
           lhs.getStartTime() == rhs.getStartTime();
}

bool operator!=(const Event &lhs, const Event &rhs)
{
    return !(lhs == rhs);
}
