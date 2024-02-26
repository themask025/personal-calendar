#include "Event.hpp"

Event::Event(std::string name = "Event",
             std::string comment = "Comment",
             Date date = {2024, 1, 1},
             Time startTime = {0, 0},
             Time endTime = {1, 0}) : name(name),
                             comment(comment),
                             date(date)
{
    if (startTime > endTime)
        throw("Invalid values for startTime and endTime");

    this->startTime = startTime;
    this->endTime = endTime;
}

const std::string& Event::getName() const
{
    return this->name;
}
const std::string& Event::getComment() const
{
    return this->comment;
}
const Date& Event::getDate() const
{
    return this->date;
}
const Time& Event::getStartTime() const
{
    return this->startTime;
}
const Time& Event::getEndTime() const
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