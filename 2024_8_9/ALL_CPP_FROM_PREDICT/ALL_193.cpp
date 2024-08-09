 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD1 1/4 ", "[math][CurveCalculation][P1][EllipseD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 1.0;
	Vector3 tangentAt0 = AMCAX::CurveCalculation::EllipseD1(0.0, defaultFrame3, major, minor);
	Vector3 tangentAt90Deg = AMCAX::CurveCalculation::EllipseD1(M_PI_2, defaultFrame3, major, minor);
	Vector3 tangentAt180Deg = AMCAX::CurveCalculation::EllipseD1(M_PI, defaultFrame3, major, minor);
	Vector3 tangentAt270Deg = AMCAX::CurveCalculation::EllipseD1(3 * M_PI_2, defaultFrame3, major, minor);
	Vector3 tangentAt360Deg = AMCAX::CurveCalculation::EllipseD1(2 * M_PI, defaultFrame3, major, minor);
	CHECK(tangentAt0.X() == Approx(-1.0));
	CHECK(tangentAt0.Y() == Approx(0.0));
	CHECK(tangentAt0.Z() == Approx(0.0));
	CHECK(tangentAt90Deg.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt90Deg.Y() == Approx(1.0).margin(1e-14));
	CHECK(tangentAt90Deg.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.X() == Approx(1.0).margin(1e-14));
	CHECK(tangentAt180Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt270Deg.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt270Deg.Y() == Approx(-1.0).margin(1e-14));
	CHECK(tangentAt270Deg.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360Deg.X() == Approx(-1.0).margin(1e-14));
	CHECK(tangentAt360Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360Deg.Z() == Approx(0.0).margin(1e-14));
}