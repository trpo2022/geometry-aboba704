#include <ctest.h>
#include <libgeometry/intersections.h>

CTEST(geometry_test, circle_intersection)
{
    char x1 = 0;
    char y1 = 0;
    char x2 = 0;
    char y2 = 0;
    char rad1 = 1;
    char rad2 = 1;

    const int expect = 0;
    int res = intersection(x1, y1, x2, y2, rad1, rad2);
    ASSERT_EQUAL(expect, res);
}