 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD1 1/4 ", "[math][CurveCalculation][P1][ParabolaD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	Vector3 tangentAt0 = AMCAX::CurveCalculation::ParabolaD1(0.0, defaultFrame3, focal);
	std::cout << tangentAt0.X() << std::endl;
	CHECK(tangentAt0.X() == Approx(0.0));
	CHECK(tangentAt0.Y() == Approx(0.707107));
	CHECK(tangentAt0.Z() == Approx(-0.707107));
}