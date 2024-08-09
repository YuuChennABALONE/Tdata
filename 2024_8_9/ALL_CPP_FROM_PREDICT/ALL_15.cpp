 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusValue ", "[math][CurveCalculation][P1][TorusValue]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir); 
	double majorRadius = 3.0;
	double minorRadius = 2.0; 
	Point3 point3 = AMCAX::CurveCalculation::TorusValue(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	CHECK(point3.X() == 3.0);
	CHECK(point3.Y() == 0.0);
	CHECK(point3.Z() == 0.0);
}