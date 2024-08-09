 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CalculateTangent3", "[math][CurveCalculation][P1][CalculateTangent3]") {
	Direction3 defaultDirection(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), defaultDirection);
	double tolerance = 0.1;
	SECTION("tangent vector") {
		Direction3 tangent = CurveCalculation::CalculateTangent3(defaultFrame3, 0.0, tolerance);
		CHECK(tangent.X() == 0.0);
		CHECK(tangent.Y() == 1.0);
		CHECK(tangent.Z() == 0.0);
	}}