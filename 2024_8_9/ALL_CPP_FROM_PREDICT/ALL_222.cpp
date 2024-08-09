 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 2.0;
	double l = 2 * M_PI * r;
	CurveCalculation calc = CurveCalculation::Parameter(Frame2, l);
	double u = calc.Parameter(Point2(2.0, 0.0));
	CHECK(u == Approx(0.0));
}