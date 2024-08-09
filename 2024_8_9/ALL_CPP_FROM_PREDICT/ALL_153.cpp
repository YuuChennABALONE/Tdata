 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD1 1/4 ", "[math][CurveCalculation][P1][HyperbolaD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	Vector3 tangentAt0 = HyperbolaD1(0.0, defaultFrame3, major, minor);
	Vector3 tangentAt90Deg = HyperbolaD1(M_PI_2, defaultFrame3, major, minor);
	Vector3 tangentAt180Deg = HyperbolaD1(M_PI, defaultFrame3, major, minor);
	Vector3 tangentAt270Deg = HyperbolaD1(3 * M_PI_2, defaultFrame3, major, minor);
	Vector3 tangentAt360Deg = HyperbolaD1(2 * M_PI, defaultFrame3, major, minor);
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == Approx(3.0 / 2.0));
	CHECK(tangentAt0.Z() == 0.0);
	CHECK(tangentAt90Deg.X() == Approx(-2.0 / 3.0));
	CHECK(tangentAt90Deg.Y() == Approx(0.0));
	CHECK(tangentAt90Deg.Z() == 0.0);
	CHECK(tangentAt180Deg.X() == Approx(-1.0));
	CHECK(tangentAt180Deg.Y() == Approx(-3.0));
	CHECK(tangentAt180Deg.Z() == 0.0);
	CHECK(tangentAt270Deg.X() == Approx(2.0 / 3.0));
	CHECK(tangentAt270Deg.Y() == Approx(0.0));
	CHECK(tangentAt270Deg.Z() == 0.0);
	CHECK(tangentAt360Deg.X() == Approx(0.0));
	CHECK(tangentAt360Deg.Y() == Approx(-3.0 / 2.0));
	CHECK(tangentAt360Deg.Z() == 0.0);
}