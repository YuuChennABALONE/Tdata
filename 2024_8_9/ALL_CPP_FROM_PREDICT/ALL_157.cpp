 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaValue ", "[math][CurveCalculation][P1]") {
	Direction2 defaultDirection(1.0, 1.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	double major = 2.0;
	double minor = 3.0;
	std::vector<Point2> expectedResult{
		Point2(2.0, 0.0),
		Point2(1.66667, 0.833333),
		Point2(1.33333, 1.66667),
		Point2(1.0, 2.5),
		Point2(0.66667, 3.33333),
		Point2(0.33333, 4.16667),
		Point2(0.0, 5.0),
		Point2(-0.33333, 5.83333),
		Point2(-0.66667, 6.66667),
		Point2(-1.0, 7.5),
		Point2(-1.33333, 8.33333),
		Point2(-1.66667, 9.16667),
		Point2(-2.0, 10.0),
	};
	for (int i = 0; i < 14; i++) {
		double u = static_cast<double>(i) / 10;
		Point2 result = CurveCalculation::HyperbolaValue(u, defaultFrame2, major, minor);
		CHECK(result.X() == Approx(expectedResult[i].X()));
		CHECK(result.Y() == Approx(expectedResult[i].Y()));
	}
}