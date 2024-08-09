 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::DN 1/2 ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double u1 = 0.0;
	double u2 = M_PI_2;
	Vector3 vector3_1 = CurveCalculation::DN(u1, M_PI_2, defaultFrame3, 1, 1);
	Vector3 vector3_2 = CalculateDN1(defaultFrame3, 1, 0, M_PI_2);
	CHECK(vector3_1.X() == vector3_2.X());
	CHECK(vector3_1.Y() == vector3_2.Y());
	CHECK(vector3_1.Z() == vector3_2.Z());
}