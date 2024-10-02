#include "../Time.hpp"

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

TEST_CASE("Substraction throws an exception on substracting greater from smaller time")
{
    CHECK_THROWS(Time(10, 00) - Time(20, 0));
}

TEST_CASE("Substraction gives correct results")
{
    CHECK_EQ(Time(0, 10) - Time(0, 5), Time(0, 5));
    CHECK_EQ(Time(11, 0) - Time(4, 0), Time(7, 0));
    CHECK_EQ(Time(15, 20) - Time(10, 10), Time(5, 10));
    CHECK_EQ(Time(15, 20) - Time(14, 30), Time(0, 50));
}

TEST_CASE("Addition gives correct results")
{
    CHECK_EQ(Time(0, 20) + Time(0, 10), Time(0, 30));
    CHECK_EQ(Time(14, 0) + Time(5, 0), Time(19, 0));
    CHECK_EQ(Time(6, 15) + Time(10, 20), Time(16, 35));
    CHECK_EQ(Time(22, 0) + Time(4, 0), Time(2, 0));
}

TEST_CASE("toHours() gives the time in hours")
{
    CHECK_EQ(Time(12,30).toHours(), 12.5);
    CHECK_EQ(Time(10,15).toHours(), 10.25);
}