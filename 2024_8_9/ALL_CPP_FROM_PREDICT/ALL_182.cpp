 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseDN 1/2 ", "[math][CurveCalculation][P1][EllipseDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 1.0;
	std::vector<Point3> points;
	double u = 0.0;
	bool isRight = CurveCalculation::EllipseDN(u, defaultFrame3, major, minor, 1, points);
	CHECK(isRight == false);
}