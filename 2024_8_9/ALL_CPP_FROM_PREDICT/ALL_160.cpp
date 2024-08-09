 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaParameter() [1/2] ", "[math][CurveCalculation][P1][ParabolaParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	double parameter = AMCAX::CurveCalculation::ParabolaParameter(defaultFrame3, focal, Point3(0.0, 1.0, 0.0)); 
	CHECK(parameter == M_PI_2);
}