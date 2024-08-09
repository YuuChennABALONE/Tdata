 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD0 1/2 ", "[math][CurveCalculation][P1][CylinderD0]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0; 
	AMCAX::Point3 point3 = AMCAX::CurveCalculation::CylinderD0(0.0, 0.0, defaultFrame3, radius);
	AMCAX::PointT<double, 3> point1(3.0, 1.0, 0.0);
	CHECK(point3.X() == point1.X());
	CHECK(point3.Y() == point1.Y());
	CHECK(point3.Z() == point1.Z());
}