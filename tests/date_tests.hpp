#include "../Date.hpp"

TEST_CASE("getYear() returns value for year.")
{
    CHECK_EQ((Date(2, 1, 1)).getYear(), 2);
}

TEST_CASE("getMonth() returns value for month.")
{
    CHECK_EQ((Date(1, 2, 1)).getMonth(), 2);
}

TEST_CASE("getDay() returns value for day.")
{
    CHECK_EQ((Date(1, 1, 2)).getDay(), 2);
}

TEST_CASE("Constructor does not throw exceptions when given valid values.")
{
    CHECK_NOTHROW(Date(1, 1, 1));
    CHECK_NOTHROW(Date(1, 1, 31));
    CHECK_NOTHROW(Date(1, 4, 30));
    CHECK_NOTHROW(Date(2024, 2, 29));
    CHECK_NOTHROW(Date(1, 1, 15));
}

TEST_CASE("Constructor throws an exception when given invalid values for year.")
{
    CHECK_THROWS_WITH(new Date(-1, 1, 1), "Invalid date!");
}

TEST_CASE("Constructor throws an exception when given invalid values for month.")
{
    CHECK_THROWS_WITH(Date(1, -1, 1), "Invalid date!");
    CHECK_THROWS_WITH(Date(1, 13, 1), "Invalid date!");
}

TEST_CASE("Constructor throws an exception when given invalid values for day.")
{
    CHECK_THROWS_WITH(Date(1, 1, 0), "Invalid date!");

    // the month has a maximum of 31 days
    CHECK_THROWS_WITH(Date(1, 1, 32), "Invalid date!");

    // the month has a maximum of 30 days
    CHECK_THROWS_WITH(Date(1, 4, 31), "Invalid date!");

    // the month has a maximum of 28 days - the year is not leap
    CHECK_THROWS_WITH(Date(2023, 2, 29), "Invalid date!");

    // the month has a maximim of 29 days - the year is leap
    CHECK_THROWS_WITH(Date(2024, 2, 30), "Invalid date!");
}

TEST_CASE("Operator == returns true for Date objects with fields with equal values.")
{
    Date lhs(2024, 2, 15);
    Date rhs(2024, 2, 15);
    CHECK(lhs == rhs);
}

TEST_CASE("Operator == returns false for Date objects with fields with different values.")
{
    Date lhs(2024, 2, 14);
    Date rhs(2024, 2, 15);
    CHECK_FALSE(lhs == rhs);
}

TEST_CASE("Operator != returns true for Date objects with fields with different values.")
{
    Date lhs(2024, 2, 14);
    Date rhs(2024, 2, 15);
    CHECK(lhs != rhs);

    lhs = Date(2024, 4, 15);
    rhs = Date(2024, 2, 15);
    CHECK(lhs != rhs);

    lhs = Date(2026, 2, 15);
    rhs = Date(2024, 2, 15);
    CHECK(lhs != rhs);

    lhs = Date(2026, 8, 5);
    rhs = Date(2024, 1, 25);
    CHECK(lhs != rhs);
}

TEST_CASE("Operator != returns false for Date objects with fields with equal values")
{
    Date lhs(2024, 2, 15);
    Date rhs(2024, 2, 15);
    CHECK_FALSE(lhs != rhs);
}

TEST_CASE("(lhs < rhs) returns true for Date objects lhs and rhs when lhs represents an earlier date than rhs")
{
    Date lhs(2015, 3, 20);
    Date rhs(2024, 2, 15);
    CHECK(lhs < rhs);
}

TEST_CASE("(lhs > rhs) returns true for Date objects lhs and rhs when lhs represents a later date than rhs")
{
    Date lhs(2024, 2, 15);
    Date rhs(2015, 3, 20);
    CHECK(lhs > rhs);
}

TEST_CASE("(lhs <= rhs) returns true for Date objects lhs and rhs when lhs represents an earlier or equal date than rhs")
{
    Date lhs(2015, 3, 20);
    Date rhs(2024, 2, 15);
    CHECK(lhs <= rhs);

    lhs = Date(2024, 2, 15);
    rhs = Date(2024, 2, 15);
    CHECK(lhs <= rhs);
}

TEST_CASE("(lhs >= rhs) returns true for Date objects lhs and rhs when lhs represents a later or equal date than rhs")
{
    Date lhs(2024, 2, 15);
    Date rhs(2015, 3, 20);
    CHECK(lhs >= rhs);

    lhs = Date(2024, 2, 15);
    rhs = Date(2024, 2, 15);
    CHECK(lhs >= rhs);
}

TEST_CASE("Operator << writes to output stream correctly.")
{
    Date date(2024, 3, 30);
    std::ostringstream oss;
    oss << date;
    CHECK(oss.str() == "30.03.2024");
}

TEST_CASE("dayOfWeek() returns a number corresponding to the day of week for the date")
{
    Date date(2024, 10, 16);
    CHECK_EQ(date.getWeekday(), 2);

    date = Date(2020, 1, 1);
    CHECK_EQ(date.getWeekday(), 2);

    date = Date(1889, 10, 1);
    CHECK_EQ(date.getWeekday(), 1);
}