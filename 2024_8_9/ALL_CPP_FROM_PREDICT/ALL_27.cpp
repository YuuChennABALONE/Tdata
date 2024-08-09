 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereValue()[1 / 2] ", "[math][CurveCalculation][P1][SphereValue]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	Point3 point3 = AMCAX::CurveCalculation::SphereValue(M_PI_2, M_PI, defaultFrame3, radius);
	CHECK(point3.X() == Approx(-1.0));
	CHECK(point3.Y() == Approx(1.0));
	CHECK(point3.Z() == Approx(0.0));
}