#include "../Time.hpp"
// #include "../common/doctest.h"

TEST_CASE("Time: Creating a time object with implicit arguments has zeroes for hours and minutes values.")
{
    Time time;
    CHECK_EQ(time.getHours(), 0);
    CHECK_EQ(time.getMinutes(), 0);
}

TEST_CASE("Time: Values passed to constructor are assigned correctly to object")
{
    Time time(21, 43);
    CHECK_EQ(time.getHours(), 21);
    CHECK_EQ(time.getMinutes(), 43);
}

TEST_CASE("Time: Creating an object with invalid values throws an exception")
{
    Time time;
    CHECK_THROWS_WITH(new Time(25, 0), "Invalid time!");
    CHECK_THROWS_WITH(new Time(21, 70), "Invalid time!");
    CHECK_THROWS_WITH(new Time(60, 61), "Invalid time!");
}

TEST_CASE("getHours() returns value of hours field")
{
    CHECK_EQ((new Time(1, 0))->getHours(), 1);
    CHECK_EQ((new Time(10, 0))->getHours(), 10);
    CHECK_EQ((new Time(20, 0))->getHours(), 20);
}

TEST_CASE("getMinutes() returns value of minutes field")
{
    CHECK_EQ((new Time(0, 5))->getMinutes(), 5);
    CHECK_EQ((new Time(0, 20))->getMinutes(), 20);
    CHECK_EQ((new Time(0, 59))->getMinutes(), 59);
}