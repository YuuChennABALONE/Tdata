 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaValue()[1/2] ", "[math][CurveCalculation][P1][HyperbolaValue]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	std::vector<Point3> result = AMCAX::CurveCalculation::HyperbolaValue(0.0, defaultFrame3, major, minor);
	CHECK(result.size() == 1);
	CHECK(result[0].X() == 3.0);
	CHECK(result[0].Y() == 1.0);
	CHECK(result[0].Z() == Approx(0.0).margin(1e-14));
}