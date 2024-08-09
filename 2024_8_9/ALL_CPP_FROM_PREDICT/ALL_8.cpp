 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD3 1/4 ", "[math][CurveCalculation][P1][TorusD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 2.0;
	double minorRadius = 1.0;
	Vector3 tangentAtU0 = AMCAX::CurveCalculation::TorusD3(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 tangentAtV0 = AMCAX::CurveCalculation::TorusD3(0.0, M_PI_2, defaultFrame3, majorRadius, minorRadius);
	Vector3 tangentAtU2Pi = AMCAX::CurveCalculation::TorusD3(2 * M_PI, 0.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 tangentAtV2Pi = AMCAX::CurveCalculation::TorusD3(2 * M_PI, M_PI_2, defaultFrame3, majorRadius, minorRadius);
	CHECK(tangentAtU0.X() == Approx(0.0));
	CHECK(tangentAtU0.Y() == Approx(-1.0));
	CHECK(tangentAtU0.Z() == Approx(0.0));
	CHECK(tangentAtV0.X() == Approx(-0.0));
	CHECK(tangentAtV0.Y() == Approx(-1.0));
	CHECK(tangentAtV0.Z() == Approx(0.0));
	CHECK(tangentAtU2Pi.X() == Approx(0.0));
	CHECK(tangentAtU2Pi.Y() == Approx(1.0));
	CHECK(tangentAtU2Pi.Z() == Approx(0.0));
	CHECK(tangentAtV2Pi.X() == Approx(0.0));
	CHECK(tangentAtV2Pi.Y() == Approx(1.0));
	CHECK(tangentAtV2Pi.Z() == Approx(0.0));
}