 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction", "[math][Plane][p1]") {
	SECTION("Default constructor") {
        Plane plane;
        REQUIRE(plane.Contains(Point3(0.0, 0.0, 0.0), 0.0));
    }}