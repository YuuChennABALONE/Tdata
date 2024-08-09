 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation ", "[math][CurveCalculation][P1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double radius = 2.0; 
	double segmentLength = 1.0; 
	double n = AMCAX::CurveCalculation::CircleCalculation(segmentLength, radius); 
	SECTION("Parameter") {
		double t1 = n / (2 * M_PI); 
		CHECK(AMCAX::IsEqual(AMCAX::PointT3(0.0, 2.0, 0.0), AMCAX::CurveCalculation::CirclePoint3(defaultFrame2, t1)));
		double x = radius * cos(n);
		double y = radius * sin(n);
		double z = 0;
		CHECK(x == Approx(2.0).margin(1e-14));
		CHECK(y == Approx(0.0).margin(1e-14));
		CHECK(z == Approx(0.0).margin(1e-14));
	}}