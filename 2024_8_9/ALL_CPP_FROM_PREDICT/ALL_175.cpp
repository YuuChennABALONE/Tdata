 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD0 1/2 ", "[math][CurveCalculation][P1][ParabolaD0]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double focal = 3.0;
	Point2 point2 = CurveCalculation::ParabolaD0(0.0, defaultFrame2, focal);
	std::cout << point2.X() << " " << point2.Y() << " " << std::endl;
	CHECK(point2.X() == 0.0);
	CHECK(point2.Y() == 0.0);
}