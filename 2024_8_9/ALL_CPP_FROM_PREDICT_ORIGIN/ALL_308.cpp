 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Plane.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods Test", "[math][Plane][p1]") {
	SECTION("Contains point") {
        Point3 point1(6.0, 3.0, 0.0);
        Point3 point2(2.0, 4.0, 0.0);
        Point3 point3(4.0, 1.0, 0.0);
        Plane plane(point1, point2, point3);
        double x = 3.0;
        double y = 4.0;
        double z = 0.0;
        CHECK(plane.Contains(point1, 1e-6) == true);
        CHECK(plane.Contains(point2, 1e-6) == true);
        CHECK(plane.Contains(point3, 1e-6) == true);
        CHECK(plane.Contains(Point3(x, y, z), 1e-6) == true);
        CHECK(plane.Contains(Point3(y, x, z), 1e-6) == false);
    }}