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

    calendar.removeEvent(secondEvent.getDate(), secondEvent.getStartTime());
    calendar.removeEvent(fourthEvent.getDate(), fourthEvent.getStartTime());

    CHECK(calendar.containsEvent(firstEvent.getDate(), firstEvent.getStartTime()));
    CHECK(calendar.containsEvent(thirdEvent.getDate(), thirdEvent.getStartTime()));
    CHECK_FALSE(calendar.containsEvent(secondEvent.getDate(), secondEvent.getStartTime()));
    CHECK_FALSE(calendar.containsEvent(fourthEvent.getDate(), fourthEvent.getStartTime()));
}

TEST_CASE("editEvent() successfully edits an event when it is the only event")
{
    Calendar calendar;
    Event firstEvent("First event", "Comment", Date(2024, 2, 2), Time(1, 0), Time(2, 0));

    calendar.addEvent(firstEvent);
    calendar.editEvent(Date(2024, 2, 2), Time(1, 0), "Edited first event", "Edited comment", Date(2024, 2, 2), Time(1, 30), Time(2, 0));
    CHECK(((calendar.getEvents().size() == 1) &&
           ((*(calendar.getEvents().begin())) == Event("Edited first event", "Edited comment", Date(2024, 2, 2), Time(1, 30), Time(2, 0)))));
}

TEST_CASE("editEvent() successfully edits an event when there are multiple events in the calendar")
{
    Calendar calendar;
    Event firstEvent("First event", "Comment", Date(2024, 2, 2), Time(1, 0), Time(2, 0));
    Event secondEvent("Second event", "Comment", Date(2024, 2, 2), Time(2, 0), Time(3, 0));
    Event thirdEvent("Third event", "Comment", Date(2024, 2, 2), Time(4, 0), Time(5, 0));

    calendar.addEvent(firstEvent);
    calendar.addEvent(secondEvent);
    calendar.addEvent(thirdEvent);
    CHECK_NOTHROW(calendar.editEvent(Date(2024, 2, 2), Time(1, 0), "Edited first event", "Edited comment", Date(2024, 2, 2), Time(3, 0), Time(4, 0)));
}

TEST_CASE("editEvent() throws an exception when the edited time interval is overlapping with that of another event")
{
    Calendar calendar;
    Event firstEvent("First event", "Comment", Date(2024, 2, 2), Time(1, 0), Time(2, 0));
    Event secondEvent("Second event", "Comment", Date(2024, 2, 2), Time(2, 0), Time(3, 0));

    calendar.addEvent(firstEvent);
    calendar.addEvent(secondEvent);
    CHECK_THROWS(calendar.editEvent(Date(2024, 2, 2), Time(1, 0), "Edited first event", "Edited comment", Date(2024, 2, 2), Time(2, 30), Time(3, 0)));
}