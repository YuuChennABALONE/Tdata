 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
TEST_CASE("case1: Cone construction", "[math][Cone][p1]") {
	SECTION("Cone frame default r 0 angle 0") {
        AMCAX::Frame3 frame;
        AMCAX::Cone cone(frame, 0.0, 0.0);
        AMCAX::Point3 point1(0.0, 0.0, 0.0);
        AMCAX::Point3 point2(1.0, 0.0, 0.0);
        CHECK(cone.Location().IsEqual(frame.Location(), 1e-6));
        CHECK(cone.Radius() == Approx(0.0));
        CHECK(cone.SemiAngle() == Approx(0.0));
        CHECK(cone.Contains(point1, 1e-6, 1e-6));
        CHECK(cone.Contains(point2, 1e-6, 1e-6));
    }}