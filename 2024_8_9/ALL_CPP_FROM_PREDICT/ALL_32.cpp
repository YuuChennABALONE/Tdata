 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD3 [1/10] ", "[math][CurveCalculation][P1][ConeD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double 	r = 2.0;
	double 	h = 2.0;
	double 	r2 = AMCAX::CurveCalculation::ConeD3(0.0, 0.0, defaultFrame3, r, h, 1.0, 1.0);
	Vector3  expectedD3(0.0, -2.0, 0.0);
	CHECK(r2.X() == expectedD3.X());
	CHECK(r2.Y() == expectedD3.Y());
	CHECK(r2.Z() == expectedD3.Z());
}