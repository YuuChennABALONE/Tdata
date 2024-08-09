 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseParameter() [1/2] ", "[math][CurveCalculation][P1][EllipseParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 1.0; 
	double u = 0.0;
	double ellipseParameter = AMCAX::CurveCalculation::EllipseParameter(defaultFrame3, major, minor, u);
	CHECK(ellipseParameter == 0.0);
}