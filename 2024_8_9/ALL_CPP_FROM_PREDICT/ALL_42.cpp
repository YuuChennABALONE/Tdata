 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderParameter 1/2 ", "[math][CurveCalculation][P1][CylinderParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	Point3 point2 = AMCAX::CurveCalculation::CylinderParameter(defaultFrame3, radius, Point3(2.0, 1.0, 0.0)); 
	CHECK(point2.X() == 3.0);
	CHECK(point2.Y() == 1.0);
	CHECK(point2.Z() == 0.0);
}