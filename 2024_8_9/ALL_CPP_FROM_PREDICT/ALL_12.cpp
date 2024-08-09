 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD1 1/4 ", "[math][CurveCalculation][P1][TorusD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 2.0;
	double minorRadius = 1.0;
	Vector3 vector3 = AMCAX::CurveCalculation::TorusD1(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector31 = AMCAX::CurveCalculation::TorusD1(0.0, M_PI_2, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector32 = AMCAX::CurveCalculation::TorusD1(M_PI_2, 0.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector33 = AMCAX::CurveCalculation::TorusD1(M_PI_2, M_PI_2, defaultFrame3, majorRadius, minorRadius);
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 1.0);
	CHECK(vector3.Z() == 0.0);
	CHECK(vector31.X() == 0.0);
	CHECK(vector31.Y() == 1.0);
	CHECK(vector31.Z() == 0.0);
	CHECK(vector32.X() == Approx(-1.0 / std::sqrt(2)).margin(1e-14));
	CHECK(vector32.Y() == Approx(0.0).margin(1e-14));
	CHECK(vector32.Z() == Approx(1.0 / std::sqrt(2)).margin(1e-14));
	CHECK(vector33.X() == Approx(1.0 / std::sqrt(2)).margin(1e-14));
	CHECK(vector33.Y() == Approx(-1.0 / std::sqrt(2)).margin(1e-14));
	CHECK(vector33.Z() == Approx(0.0).margin(1e-14));
}