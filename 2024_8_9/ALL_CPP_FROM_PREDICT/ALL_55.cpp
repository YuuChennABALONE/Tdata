 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction", "[math][Plane][p1]") {
	SECTION("SetDn") {
        Vector3 normal(1.0, 2.0, 3.0);
        Vector3 point(2.0, 3.0, 4.0);
        Plane plane(normal, point);
        CHECK(plane.SetDn(normal));
        CHECK_FALSE(plane.SetDn(Vector3(1.0, 2.0, 3.01)));
    }}