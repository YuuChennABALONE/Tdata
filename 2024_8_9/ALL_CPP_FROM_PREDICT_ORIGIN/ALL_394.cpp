 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD0 1/2 ", "[math][CurveCalculation][P1][CircleD0]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	double 	r = 2.0;
	double u = 0.0;
	Point2  pointOnCirecle = CurveCalculation::CircleD0(u, defaultFrame2, r);
	std::cout << pointOnCirecle.X() << " " << pointOnCirecle.Y() << " " << std::endl;
	CHECK(pointOnCirecle.X() == 1.0);
	CHECK(pointOnCirecle.Y() == 3.0);
}