 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD1 1/4 ", "[math][CurveCalculation][P1][CircleD1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 2.0;
	double u = 0.0; 
	Point2  pointOnCirecle = CurveCalculation::CircleD1(u, defaultFrame2, r);
	std::cout << pointOnCirecle.X() << " " << pointOnCirecle.Y() << " "  << std::endl;
	CHECK(pointOnCirecle.X() == 2.0);
	CHECK(pointOnCirecle.Y() == 0.0);
}