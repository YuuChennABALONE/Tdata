 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation 1 /", "[math][CurveCalculation][P1][CircleCalculation]") {
	Frame3 frame;
	double radius = 2.0;
	double n = 10;
	double interval = 2 * M_PI / n;
	auto sampling = AMCAX::CurveCalculation::CircleCalculation(frame, radius, n);
	for (int i = 0; i < n; i++) {
		double t = i * interval;
		Point3 point1(frame.X(t));
		Point3 point2(frame.Location(t));
		CHECK(point1.X() == point2.X());
		CHECK(point1.Y() == point2.Y());
		CHECK(point1.Z() == point2.Z());
	}
	Point3 point1(frame.X(0.0));
	Point3 point2(frame.Location(0.0));
	CHECK(point1.X() == point2.X());
	CHECK(point1.Y() == point2.Y());
	CHECK(point1.Z() == point2.Z());
}