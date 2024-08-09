 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	Cylinder cylinder;
	double u = CurveCalculation::Parameter(cylinder, Point3(0.0, 0.0, 1.0));
	CHECK(u == M_PI_2);
}