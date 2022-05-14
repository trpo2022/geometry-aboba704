#include "../thirdparty/ctest.h"
#include <libgeometry/intersections.h>

CTEST(geometry_test, circle_intersection_intersect)
{
    char* x1 = "0";
    char* y1 = "0";
    char* x2 = "0";
    char* y2 = "0";
    char* rad1 = "1";
    char* rad2 = "1";

    const int expect = 0;
    int res = intersection(x1, y1, x2, y2, rad1, rad2);
    ASSERT_EQUAL(expect, res);
}

CTEST(geometry_test, circle_intersection_not)
{
    char* x1 = "100";
    char* y1 = "100";
    char* x2 = "0";
    char* y2 = "0";
    char* rad1 = "1";
    char* rad2 = "1";

    const int expect = -1;
    int res = intersection(x1, y1, x2, y2, rad1, rad2);
    ASSERT_EQUAL(expect, res);
}

CTEST(geometry_test, circle_intersection_touch)
{
    char* x1 = "-10";
    char* y1 = "8";
    char* x2 = "14";
    char* y2 = "-24";
    char* rad1 = "30";
    char* rad2 = "10";

    const int expect = 1;
    int res = intersection(x1, y1, x2, y2, rad1, rad2);
    ASSERT_EQUAL(expect, res);
}
