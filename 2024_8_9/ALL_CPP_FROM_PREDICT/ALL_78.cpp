 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Position  [3/20] ", "[math][CurveCalculation][P1][Position]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double u = 0.0; 
	Point3 point3 = CurveCalculation::Position(defaultFrame3, u, 0.0, 0.0, true); 
	CHECK(point3.X() == 1.0);
	CHECK(point3.Y() == 1.0);
	CHECK(point3.Z() == 0.0);
}