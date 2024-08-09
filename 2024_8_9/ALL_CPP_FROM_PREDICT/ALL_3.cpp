 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation 1/20 ", "[math][CurveCalculation][CircleCalculation][P1]") {
	Frame3 frame;
	double radius = 2.0;
	double u1 = 0;
	double u2 = 2 * M_PI;
	std::shared_ptr<CurveCalculation> calc = CurveCalculation::CircleCalculation(frame, radius, u1, u2);
}