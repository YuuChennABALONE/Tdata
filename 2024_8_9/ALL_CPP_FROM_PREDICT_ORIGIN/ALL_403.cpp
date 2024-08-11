 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD3 1/4 ", "[math][CurveCalculation][P1][CircleD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0; 
	Vector3 tangentAt0 = AMCAX::CurveCalculation::CircleD3(0.0, defaultFrame3, radius);
	Vector3 tangentAt180 = AMCAX::CurveCalculation::CircleD3(M_PI, defaultFrame3, radius);
	Vector3 tangentAt360 = AMCAX::CurveCalculation::CircleD3(2 * M_PI, defaultFrame3, radius);
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == -2.0);
	CHECK(tangentAt0.Z() == 0.0);
	CHECK(tangentAt180.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180.Y() == 2.0);
	CHECK(tangentAt180.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360.Y() == -2.0);
	CHECK(tangentAt360.Z() == Approx(0.0).margin(1e-14));
}