 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation 1 /", "[math][CurveCalculation][CircleCalculation][P1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	double radius = 2.0; 
	double sectionLength = 1.0;
	std::vector<Point2> expectedPoints = {
		Point2(1.0, 1.0),
		Point2(0.0, 3.0),
		Point2(-2.0, 1.0),
		Point2(-1.0, -1.0),
		Point2(0.0, -3.0),
		Point2(2.0, 1.0),
		Point2(1.0, 3.0),
	};
	auto circleCalculation = CurveCalculation::CircleCalculation(defaultFrame2, radius, sectionLength);
	auto resultPoints = circleCalculation.Calculate();
	CHECK(resultPoints.size() == expectedPoints.size());
	for (size_t i = 0; i < resultPoints.size(); i++) {
		auto resultPoint = resultPoints[i];
		auto expectedPoint = expectedPoints[i];
		CHECK(resultPoint.X() == expectedPoint.X());
		CHECK(resultPoint.Y() == expectedPoint.Y());
	}
}