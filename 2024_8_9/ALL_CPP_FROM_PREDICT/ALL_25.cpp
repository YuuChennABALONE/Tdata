 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereD1 1/4 ", "[math][CurveCalculation][P1][SphereD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::VectorT<double, 3> tangentAt0 = AMCAX::CurveCalculation::SphereD1(0.0, 0.0, defaultFrame3, radius);
	VectorT<double, 3> expected(0.0, -2.0, 0.0); 
	CHECK(tangentAt0.X() == expected.X());
	CHECK(tangentAt0.Y() == expected.Y());
	CHECK(tangentAt0.Z() == expected.Z());
}