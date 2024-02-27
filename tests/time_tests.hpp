#include "../Time.hpp"
// #include "../common/doctest.h"

TEST_CASE("Time: Creating an object with implicit parameters.")
{
    Time time;
    CHECK_EQ(time.getHours(), 0);
    CHECK_EQ(time.getMinutes(), 0);
}