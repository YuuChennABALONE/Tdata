 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD0 1/2 ", "[math][CurveCalculation][P1][ConeD0]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double angle = M_PI / 3; 
	Point3 point3 = ConeD0(angle, radius, angle, defaultFrame3); 
	CHECK(point3.X() == 1.0);
	CHECK(point3.Y() == Approx(1.0/sqrt(3)));
	CHECK(point3.Z() == Approx(1.0/sqrt(3)));
}