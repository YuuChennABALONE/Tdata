/* "AMCAX_API Plane(const Point3& point, const Direction3& dir)\t @param dir The direction\n\t @param point The point\n\t @brief Construct from a point and a direction\n,\n",
      */
 #include "catch.hpp"
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Construct from point and direction") {
        Point3 point(1., 1., 1.);
        Direction3 dir(0., 0., 1.);
        Plane plane(point, dir);  
        Point3 point2(3., 4., 4.);
        Direction3 dir2(2., 2., 1.);
        Plane plane2(point2, dir2);  
        double a, b, c, d;
        plane.Coefficients(a, b, c, d);
        double a2, b2, c2, d2;
        plane2.Coefficients(a2, b2, c2, d2);
        REQUIRE(a == Approx(0));
        REQUIRE(b == Approx(0));
        REQUIRE(c == Approx(1));
        REQUIRE(d == Approx(-1));
        REQUIRE(a2 == Approx(2./3).margin(0.0001));
        REQUIRE(b2 == Approx(2./3).margin(0.0001));
        REQUIRE(c2 == Approx(1./3).margin(0.0001));
        REQUIRE(d2 == Approx(-6));
    }}