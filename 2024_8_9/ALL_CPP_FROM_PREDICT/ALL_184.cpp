 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD3 1/4 ", "[math][CurveCalculation][P1][EllipseD3]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 2.0;
	Vector2 tangentAt0 = AMCAX::CurveCalculation::EllipseD3(0.0, defaultFrame2, major, minor);
	Vector2 tangentAt90Deg = AMCAX::CurveCalculation::EllipseD3(M_PI_2, defaultFrame2, major, minor);
	Vector2 tangentAt180Deg = AMCAX::CurveCalculation::EllipseD3(M_PI, defaultFrame2, major, minor);
	Vector2 tangentAt270Deg = AMCAX::CurveCalculation::EllipseD3(3 * M_PI_2, defaultFrame2, major, minor);
	Vector2 tangentAt360Deg = AMCAX::CurveCalculation::EllipseD3(2 * M_PI, defaultFrame2, major, minor);
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == 3.0);
	CHECK(tangentAt90Deg.X() == 3.0);
	CHECK(tangentAt90Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.X() == Approx(-3.0).margin(1e-14));
	CHECK(tangentAt180Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt270Deg.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt270Deg.Y() == -2.0);
	CHECK(tangentAt360Deg.X() == 0.0);
	CHECK(tangentAt360Deg.Y() == Approx(-3.0).margin(1e-14));
}