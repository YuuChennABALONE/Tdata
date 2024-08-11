 #include <catch.hpp>
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Construct from frame") {
        Frame3 frame1(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0));
        Frame3 frame2(Point3(1.0, 1.0, 1.0), Direction3(0.0, 0.0, 1.0));
        Plane plane1(frame1);
        Plane plane2(frame2);  
        double a1, b1, c1, d1;
        plane1.Coefficients(a1, b1, c1, d1);
        double a2, b2, c2, d2;
        plane2.Coefficients(a2, b2, c2, d2);
        REQUIRE(a1 == Approx(0));
        REQUIRE(b1 == Approx(0));
        REQUIRE(c1 == Approx(1));
        REQUIRE(d1 == Approx(0));
        REQUIRE(a2 == Approx(0));
        REQUIRE(b2 == Approx(0));
        REQUIRE(c2 == Approx(1));
        REQUIRE(d2 == Approx(0));
    }}