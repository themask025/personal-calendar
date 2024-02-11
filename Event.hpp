#ifndef __EVENT_HPP
#define __EVENT_HPP

#include "Time.hpp"
#include "Date.hpp"
#include <string>

class Event
{
private:
    std::string name;
    std::string comment;
    Date date;
    Time startTime;
    Time endTime;

public:
    Event(std::string name,
          std::string comment,
          Date date,
          Time startTime,
          Time endTime);

    const std::string& getName() const;
    const std::string& getComment() const;
    const Date& getDate() const;
    const Time& getStartTime() const;
    const Time& getEndTime() const;

    void setName(std::string name);
    void setComment(std::string comment);
    void setDate(Date date);
    void setStartTime(Time startTime);
    void setEndTime(Time endTime);
};

#endif