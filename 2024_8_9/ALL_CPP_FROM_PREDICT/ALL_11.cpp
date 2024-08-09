 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD2 1/4 ", "[math][CurveCalculation][P1][TorusD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double majorRadius = 3.0;
	double minorRadius = 2.0;
	std::tuple<std::function<double(double, double)>, std::tuple<double, double>> torus2 = AMCAX::CurveCalculation::TorusD2(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	double u = 0.0, v = 0.0;
	std::function<double(double, double)> f = std::get<0>(torus2);
	std::tuple<double, double> parameters = std::get<1>(torus2);
	double du2 = std::get<0>(f(u, v));
	double duv = std::get<1>(f(u, v));
	double dv2 = std::get<2>(f(u, v));
	CHECK(du2 > 0);
	CHECK(duv == Approx(0).margin(1e-14));
	CHECK(dv2 > 0);
}