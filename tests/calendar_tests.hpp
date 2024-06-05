#include "../Calendar.hpp"

#include "../common/doctest.h"

TEST_CASE("addEvent() throws an exception on overlapping events.")
{
    Calendar calendar;

    Event firstEvent("First event", "Comment", Date(2024, 2, 2), Time(1, 0), Time(2, 0));
    Event secondEvent("Second event ", "Comment", Date(2024, 2, 2), Time(1, 30), Time(2, 30));

    calendar.addEvent(firstEvent);
    CHECK_THROWS(calendar.addEvent(secondEvent), "Event overlaps with an existing event");
}

TEST_CASE("removeEvent() removes from the vector of calendar events an event, specified by date and starting time.")
{
    Calendar calendar;

    Event firstEvent("First event", "Comment", Date(2024, 2, 2), Time(1, 0), Time(2, 0));
    Event secondEvent("Second event", "Comment", Date(2024, 2, 3), Time(1, 0), Time(2, 0));
    Event thirdEvent("Third event", "Comment", Date(2024, 2, 4), Time(1, 0), Time(2, 0));
    Event fourthEvent("Fourth event", "Comment", Date(2024, 2, 4), Time(2, 0), Time(3, 0));

    calendar.addEvent(firstEvent);
    calendar.addEvent(secondEvent);
    calendar.addEvent(thirdEvent);
    calendar.addEvent(fourthEvent);

    calendar.removeEvent(secondEvent.getDate(),secondEvent.getStartTime());
    calendar.removeEvent(fourthEvent.getDate(),fourthEvent.getStartTime());

    CHECK(calendar.containsEvent(firstEvent.getDate(), firstEvent.getStartTime()));
    CHECK(calendar.containsEvent(thirdEvent.getDate(), thirdEvent.getStartTime()));
    CHECK_FALSE(calendar.containsEvent(secondEvent.getDate(), secondEvent.getStartTime()));
    CHECK_FALSE(calendar.containsEvent(fourthEvent.getDate(), fourthEvent.getStartTime()));
}

