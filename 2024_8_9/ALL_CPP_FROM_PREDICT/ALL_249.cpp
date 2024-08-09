 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::InPeriod ", "[math][CurveCalculation][P1]") {
	SECTION("u =0") {
		double u = 0;
		double ufirst = 0;
		double ulast = 2 * M_PI;
		double ui = AMCAX::CurveCalculation::InPeriod(u, ufirst, ulast);
		CHECK(ui == 0);
	}}