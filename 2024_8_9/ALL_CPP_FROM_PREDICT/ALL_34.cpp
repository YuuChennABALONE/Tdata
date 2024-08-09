 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD2 1/4 ", "[math][CurveCalculation][P1][ConeD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	double semiAngle = M_PI / 4;
	SECTION("u,v =0,v =0") {
		Vector3 vecu, vecv, vecuu, vecuv, vecvv;
		Point3 p;
		AMCAX::CurveCalculation::ConeD2(0.0, 0.0, defaultFrame3, 2.0, M_PI_4, p, vecu, vecv, vecuu, vecuv, vecvv);
		CHECK(p.X() == Approx(1.0 + 2.0 / std::sqrt(2)));
		CHECK(p.Y() == Approx(1.0 + 2.0 / std::sqrt(2)));
		CHECK(p.Z() == Approx(0.0));
		CHECK(vecu.X() == Approx(-2.0 / std::sqrt(2)));
		CHECK(vecu.Y() == Approx(-2.0 / std::sqrt(2)));
		CHECK(vecu.Z() == Approx(0.0));
		CHECK(vecv.X() == Approx(2.0 / std::sqrt(2)));
		CHECK(vecv.Y() == Approx(2.0 / std::sqrt(2)));
		CHECK(vecv.Z() == Approx(0.0));
		CHECK(vecuu.X() == Approx(2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecuu.Y() == Approx(2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecuu.Z() == Approx(-2.0 / 3.0));
		CHECK(vecuv.X() == Approx(-2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecuv.Y() == Approx(-2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecuv.Z() == Approx(2.0 / 3.0));
		CHECK(vecvv.X() == Approx(-2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecvv.Y() == Approx(-2.0 / 3.0 / std::sqrt(2)));
		CHECK(vecvv.Z() == Approx(2.0 / 3.0));
	}}