 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::DN() circle3[2/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double u1 = 0;
	double v1 = 0;
SECTION("DN order 1 v 0") {
	Vector3 vector3 = CurveCalculation::DN(0, 0, defaultFrame3, radius, 0);
	Vector3 vector31(-2.0 / sqrt(2.0), 2.0 / sqrt(2.0), 0);
	CHECK(vector3.X() == vector31.X());
	CHECK(vector3.Y() == vector31.Y());
	CHECK(vector3.Z() == vector31.Z());
}}