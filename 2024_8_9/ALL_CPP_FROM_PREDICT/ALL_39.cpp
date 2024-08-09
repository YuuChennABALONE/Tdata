 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Cone1 ", "[math][CurveCalculation][P1][Cone]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double conean = M_PI_4; 
	std::function<Point3(double, double, const Frame3&)> cone = std::bind(
		AMCAX::CurveCalculation::Cone, 
		std::placeholders::_1, 
		std::placeholders::_2, 
		defaultFrame3
	);
	SECTION("u,v =0") {
		Point3 point = cone(0.0, 0.0, defaultFrame3);
		CHECK(point.X() == Approx(1.0));
		CHECK(point.Y() == Approx(1.0));
		CHECK(point.Z() == Approx(0.0));
	}}