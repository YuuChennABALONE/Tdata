 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD0 1/4 ", "[math][CurveCalculation][P1][EllipseD0]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double major = 3.0;
	double minor = 2.0;
	Point3 point1 = AMCAX::CurveCalculation::EllipseD0(0.0, defaultFrame3, major, minor);
	Point3 point2 = AMCAX::CurveCalculation::EllipseD0(M_PI_2, defaultFrame3, major, minor);
	CHECK(point1.X() == 1.0);
	CHECK(point1.Y() == 2.0);
	CHECK(point1.Z() == Approx(0.0).margin(1e-14));
	CHECK(point2.X() == -3.0);
	CHECK(point2.Y() == 0.0);
	CHECK(point2.Z() == Approx(0.0).margin(1e-14));
}