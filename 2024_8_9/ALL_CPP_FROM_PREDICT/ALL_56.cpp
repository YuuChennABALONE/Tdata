 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::PlaneD3 1/4 ", "[math][CurveCalculation][P1][PlaneD3]") {
	Direction3 D(0.0, 0.0, 1.0);
	Frame3 frame;
	frame.SetLocation(Point3(1.0, 1.0, 0.0));
	frame.SetDirection(D);
	Vector3 dir2 = frame.Direction();
	double a = frame.Location().X();
	double b = frame.Location().Y();
	double c = frame.Location().Z();
	double d = -a * dir2.X() - b * dir2.Y() - c * dir2.Z();
	Vector3 normal = frame.Direction();
	SECTION("u = 0 v = 0") {
		Vector3 vecu, vecv, vecuu, vecuv, vecvv, vecuuu, vecuuv, vecuvv, vecvvv;
		Point3 p;
		AMCAX::CurveCalculation::PlaneD3(0.0, 0.0, frame, p, vecu, vecv, vecuu, vecuv, vecvv, vecuuu, vecuuv, vecuvv, vecvvv);
		CHECK(p.X() == 1.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(vecu.X() == Approx(0.0));
		CHECK(vecu.Y() == Approx(1.0));
		CHECK(vecu.Z() == Approx(0.0));
		CHECK(vecv.X() == Approx(-1.0));
		CHECK(vecv.Y() == Approx(0.0));
		CHECK(vecv.Z() == Approx(0.0));
		CHECK(vecuu.X() == Approx(0.0));
		CHECK(vecuu.Y() == Approx(0.0));
		CHECK(vecuu.Z() == Approx(0.0));
		CHECK(vecuv.X() == Approx(0.0));
		CHECK(vecuv.Y() == Approx(0.0));
		CHECK(vecuv.Z() == Approx(0.0));
		CHECK(vecvv.X() == Approx(0.0));
		CHECK(vecvv.Y() == Approx(0.0));
		CHECK(vecvv.Z() == Approx(0.0));
	}}