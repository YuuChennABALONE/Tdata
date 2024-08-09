 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD2 1/4 ", "[math][CurveCalculation][P1][ParabolaD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	Vector3 vector3 = CurveCalculation::ParabolaD2(0.0, defaultFrame3, focal);
	Vector3 vector31 = CurveCalculation::ParabolaD2(1.0 / 3.0, defaultFrame3, focal);
	Vector3 vector32 = CurveCalculation::ParabolaD2(2.0 / 3.0, defaultFrame3, focal);
	Vector3 vector33 = CurveCalculation::ParabolaD2(3.0 / 3.0, defaultFrame3, focal);
	std::cout << vector3 << std::endl;
	std::cout << vector31 << std::endl;
	std::cout << vector32 << std::endl;
	std::cout << vector33 << std::endl;
	CHECK(vector3.X() == Approx(0.0));
	CHECK(vector3.Y() == Approx(2.0));
	CHECK(vector31.X() == Approx(0.0).margin(1e-14));
	CHECK(vector31.Y() == Approx(2.0 / std::sqrt(3.0)).margin(1e-14));
	CHECK(vector32.X() == Approx(-2.0 / std::sqrt(3.0)).margin(1e-14));
	CHECK(vector32.Y() == Approx(0.0).margin(1e-14));
	CHECK(vector33.X() == Approx(-2.0).margin(1e-14));
	CHECK(vector33.Y() == Approx(0.0).margin(1e-14));
}