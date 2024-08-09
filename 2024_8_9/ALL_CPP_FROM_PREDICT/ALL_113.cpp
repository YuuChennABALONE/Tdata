 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CalculateCircle2", "[math][CurveCalculation][P1][CalculateCircle2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	SECTION("CalculateCircle2") {
		double u = 0.0;
		double x = circle2.Location().X();
		double y = circle2.Location().Y();
		double radius = circle2.Radius();
		double tempX = x + radius * cos(u);
		double tempY = y + radius * sin(u);
		Point2 pointOnCir2 = circle2.PointAt(u);
		CHECK(tempX == pointOnCir2.X());
		CHECK(tempY == pointOnCir2.Y());
		double v = CurveCalculation::CalculateCircle2(circle2, 0.0);
		CHECK(v == 0.0);
	}}