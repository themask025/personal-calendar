#include "../Event.hpp"

// #include "../common/doctest.h"

TEST_CASE("Getters return correct values.")
{
    Event event("test name", "test comment", Date(2024, 2, 2), Time(2, 0), Time(3, 0));
    CHECK_EQ(event.getName(), "test name");
    CHECK_EQ(event.getComment(), "test comment");
    CHECK_EQ(event.getDate(), Date(2024, 2, 2));
    CHECK_EQ(event.getStartTime(), Time(2, 0));
    CHECK_EQ(event.getEndTime(), Time(3, 0));
}

TEST_CASE("Setters set correct values.")
{
    Event event;

    event.setName("test name");
    event.setComment("test comment");
    event.setDate(Date(2024, 2, 2));
    event.setEndTime(Time(3, 0));
    event.setStartTime(Time(2, 0));

    CHECK_EQ(event.getName(), "test name");
    CHECK_EQ(event.getComment(), "test comment");
    CHECK_EQ(event.getDate(), Date(2024, 2, 2));
    CHECK_EQ(event.getStartTime(), Time(2, 0));
    CHECK_EQ(event.getEndTime(), Time(3, 0));
}