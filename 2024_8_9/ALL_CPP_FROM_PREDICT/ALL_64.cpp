 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double majorRadius = 3.0;
	double minorRadius = 2.0;
	AMCAX::Torus torus(defaultFrame3, majorRadius, minorRadius);
	SECTION("Parameter() Point On Torus") {
		Point3 point3_onTorus(1.0, 1.0, 0.0);
		double u = CurveCalculation::Parameter(torus, point3_onTorus);
		double v = 0.0;
		CHECK(u == Approx(0.0));
		CHECK(v == Approx(0.0));
	}}