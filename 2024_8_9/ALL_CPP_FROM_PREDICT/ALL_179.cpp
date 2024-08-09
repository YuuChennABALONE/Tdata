 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseParameter() [1/2] ", "[math][CurveCalculation][P1][EllipseParameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 2.0; 
	double u = 0.0;
	double ellipseParameter = AMCAX::CurveCalculation::EllipseParameter(defaultFrame2, major, minor, u);
	CHECK(ellipseParameter == 0.0);
}