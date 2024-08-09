 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeDN 1/2 ", "[math][CurveCalculation][P1][ConeDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0;
	double angle = M_PI_2;
	Vector3 tangentAt0 = AMCAX::CurveCalculation::ConeDN(0.0, 0.0, defaultFrame3, radius, angle);
	Vector3 tangentAt90 = AMCAX::CurveCalculation::ConeDN(M_PI_2, 0.0, defaultFrame3, radius, angle);
	Vector3 tangentAt180 = AMCAX::CurveCalculation::ConeDN(M_PI, 0.0, defaultFrame3, radius, angle);
	Vector3 tangentAt270 = AMCAX::CurveCalculation::ConeDN((2 * M_PI_2), 0.0, defaultFrame3, radius, angle);
	Vector3 tangentAt360 = AMCAX::CurveCalculation::ConeDN(M_PI_2, 0.0, defaultFrame3, radius, angle);
	CHECK(tangentAt0.X() == Approx(0.0));
	CHECK(tangentAt0.Y() == Approx(-2.0));
	CHECK(tangentAt0.Z() == Approx(0.0));
	CHECK(tangentAt90.X() == Approx(2.0));
	CHECK(tangentAt90.Y() == Approx(0.0));
	CHECK(tangentAt90.Z() == Approx(0.0));
	CHECK(tangentAt180.X() == Approx(0.0));
	CHECK(tangentAt180.Y() == Approx(2.0));
	CHECK(tangentAt180.Z() == Approx(0.0));
	CHECK(tangentAt270.X() == Approx(-2.0));
	CHECK(tangentAt270.Y() == Approx(0.0));
	CHECK(tangentAt270.Z() == Approx(0.0));
	CHECK(tangentAt360.X() == Approx(-2.0));
	CHECK(tangentAt360.Y() == Approx(0.0));
	CHECK(tangentAt360.Z() == Approx(0.0));
}