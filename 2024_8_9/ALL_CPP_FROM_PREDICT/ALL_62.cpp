 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Default constructor") {
        Plane plane;
        REQUIRE(plane.Contains(Point3(0.0, 0.0, 0.0), 0.01));
        Point3 point1(0.0, 0.0, 0.01);
        Point3 point2(0.0, 0.0, -0.01);
        Point3 point3(0.01, 0.0, 0.0);
        Point3 point4(-0.01, 0.0, 0.0);
        REQUIRE(plane.Contains(point1, 0.01));
        REQUIRE(plane.Contains(point2, 0.01));
        REQUIRE(plane.Contains(point3, 0.01));
        REQUIRE(plane.Contains(point4, 0.01));
    }}