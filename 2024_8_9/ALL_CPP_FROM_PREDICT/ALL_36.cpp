 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD1 ", "[math][CurveCalculation][P1][ConeD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double  radius = 2.0; 
	double  semiAngle = M_PI / 3; 
	Point3  p;
	Vector3 vecu, vecv;
	SECTION("v =0") {
		AMCAX::CurveCalculation::ConeD1(0.0, 0.0, defaultFrame3, 2.0, M_PI_3, p, vecu, vecv);
		CHECK(p.X() == 1.0);
		CHECK(p.Y() == 1.0 + 2.0 / std::sqrt(3.0));
		CHECK(p.Z() == 0.0);
		CHECK(vecu.X() == Approx(0.0));
		CHECK(vecu.Y() == Approx(2.0 / std::sqrt(3.0)));
		CHECK(vecu.Z() == Approx(0.0));
		CHECK(vecv.X() == Approx(0.0).margin(1e-14));
		CHECK(vecv.Y() == Approx(-2.0 / std::sqrt(3.0)).margin(1e-14));
		CHECK(vecv.Z() == Approx(0.0));
	}}