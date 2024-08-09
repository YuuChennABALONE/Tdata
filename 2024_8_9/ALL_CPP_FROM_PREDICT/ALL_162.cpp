 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaDN 1/2 ", "[math][CurveCalculation][P1][ParabolaDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	double tolerance = 0.05;
	std::vector<double> parameters = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	for (double paramater : parameters) {
		SECTION(std::to_string(paramater)) {
			Vector3 tangent = CurveCalculation::ParabolaDN(paramater, defaultFrame3, focal, 1);
			CHECK(tangent.X() == Approx(0.0).margin(1e-5));
			CHECK(tangent.Y() == Approx(0.0).margin(1e-5));
			CHECK(tangent.Z() == Approx(0.0).margin(1e-5));
		}}
}