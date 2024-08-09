 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusParameter 1/2 ", "[math][CurveCalculation][P1][TorusParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double majorRadius = 3.0;
	double minorRadius = 2.0;
	auto torusParams = CurveCalculation::TorusParameter(defaultFrame3, majorRadius, minorRadius, Point3(1.0, 1.0, 0.0));
	CHECK(torusParams.first == Approx(0));
	CHECK(torusParams.second == Approx(M_PI_2));
}