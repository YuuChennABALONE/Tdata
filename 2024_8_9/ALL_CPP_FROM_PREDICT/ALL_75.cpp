 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Position  [2/20] ", "[math][CurveCalculation][P1][Position]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	Sphere sphere1(defaultFrame3, 2.0); 
	Point3 point3 = CurveCalculation::Value(0.0, 0.0, sphere1); 
	CHECK(point3.X() == Approx(1.0));
	CHECK(point3.Y() == Approx(1.0));
	CHECK(point3.Z() == Approx(0.0));
}