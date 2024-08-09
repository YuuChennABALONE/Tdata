 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereD0 1/2 ", "[math][CurveCalculation][P1][SphereD0]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	Point3 point3 = CurveCalculation::SphereD0(0.0, 0.0, defaultFrame3, radius);
	CHECK(point3.X() == 3.0);
	CHECK(point3.Y() == 1.0);
	CHECK(point3.Z() == 0.0);
}