 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::AdjustPeriodic ", "[math][CurveCalculation][P1]") {
	double u1 = 0.0;
	double u2 = 2 * M_PI;
	double ufirst = 0.0;
	double ulast = 2 * M_PI; 
	double precision = 0.001; 
	AMCAX::CurveCalculation::AdjustPeriodic(ufirst, ulast, precision, u1, u2);
	CHECK(u1 == 0);
	CHECK(u2 == 2 * M_PI);
}