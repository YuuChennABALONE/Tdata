 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD2 1/2 ", "[math][CurveCalculation][P1][ParabolaD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	double u = 0.0;
	SECTION("FocalParameter") {
		Vector3 vector3 = CurveCalculation::ParabolaD2(u, defaultFrame3, focal);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == -2.0);
	}}