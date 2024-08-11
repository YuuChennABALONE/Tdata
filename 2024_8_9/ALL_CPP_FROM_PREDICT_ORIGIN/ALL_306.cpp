 #include <catch.hpp>
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Construct from point and direction") {
        Point3 point1(0.0, 0.0, 0.0);
        Direction3 dir1(0.0, 0.0, 1.0);
        Plane plane1(point1, dir1);
        Point3 point2(1.0, 0.0, 0.0);
        Direction3 dir2(0.0, 0.0, 1.0);
        Plane plane2(point2, dir2);
        CHECK(plane1.Distance(point2) < 0.001);
        CHECK(plane1.Contains(point2, 0.0));
        CHECK(plane1.Contains(point2, 0.001) == false);
        CHECK(plane1.Determinant(point2, dir2) < 0.001);
        CHECK(plane1.Fit(point1, point2));
        Point3 point3(0.5, 0.0, 0.0);
        Direction3 dir3(0.0, 0.0, 1.0);
        Plane plane3(point3, dir3);
        CHECK(plane1.Distance(point3) == Approx(0.0));
        CHECK(plane1.Contains(point3, 0.0));
        CHECK(plane1.Contains(point3, 0.001) == false);
        CHECK(plane1.Determinant(point3, dir3) == Approx(0.0));
        CHECK(plane1.Fit(point3, dir3));
        PointT p1(0.0, 0.0, 0.0);
        DirectionT d(0.0, 0.0, 1.0);
        Plane plane4(p1, d);
        PointT p2(1.0, 0.0, 0.0);
        DirectionT d2(0.0, 0.0, 1.0);
        Plane plane5(p2, d2);
        CHECK(plane4.Distance(p2) < 0.001);
        CHECK(plane4.Contains(p2, 0.0));
        CHECK(plane4.Contains(p2, 0.001) == false);
        CHECK(plane4.Determinant(p2, d2) < 0.001);
        CHECK(plane4.Fit(p2, d2));
        PointT p3(0.5, 0.0, 0.0);
        DirectionT d3(0.0, 0.0, 1.0);
        Plane plane6(p3, d3);
        PointT p4(0.0, 0.0, 0.5);
        CHECK(plane6.Distance(p4) < 0.001);
        CHECK(plane6.Contains(p4, 0.0));
        CHECK(plane6.Contains(p4, 0.001) == false);
        CHECK(plane6.Determinant(p4, d3) < 0.001);
        CHECK(plane6.Fit(p4, d3));
    }}