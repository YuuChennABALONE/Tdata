 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::DN() circle3[3/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius1 = 2.0;
	double radius2 = 1.0;
	SECTION("DN dv1") {
		Vector3 tangentAt0 = CurveCalculation::DN(0.0, 0.0, defaultFrame3, radius1, radius2, 1);
		CHECK(tangentAt0.X() == 0.0);
		CHECK(tangentAt0.Y() == -2.0);
		CHECK(tangentAt0.Z() == 0.0);
	}}