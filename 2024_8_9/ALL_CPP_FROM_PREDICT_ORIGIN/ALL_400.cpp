 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD2 1/4 ", "[math][CurveCalculation][P1][CircleD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	Vector3 tangentAt0 = AMCAX::CurveCalculation::CircleD2(0.0, defaultFrame3, radius);
	Vector3 tangentAt180 = AMCAX::CurveCalculation::CircleD2(M_PI, defaultFrame3, radius);
	Vector3 tangentAt360 = AMCAX::CurveCalculation::CircleD2(2 * M_PI, defaultFrame3, radius);
	CHECK(tangentAt0.X() == Approx(0.0));
	CHECK(tangentAt0.Y() == Approx(2.0));
	CHECK(tangentAt0.Z() == Approx(0.0));
	CHECK(tangentAt180.X() == Approx(-2.0));
	CHECK(tangentAt180.Y() == Approx(0.0));
	CHECK(tangentAt180.Z() == Approx(0.0));
	CHECK(tangentAt360.X() == Approx(0.0));
	CHECK(tangentAt360.Y() == Approx(-2.0));
	CHECK(tangentAt360.Z() == Approx(0.0));
}