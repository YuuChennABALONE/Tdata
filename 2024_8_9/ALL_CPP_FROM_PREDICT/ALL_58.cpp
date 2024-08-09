 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::PlaneD2() ellipse3[4/20] ", "[math][CurveCalculation][PlaneD2][P1]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir);
	double major = 5.0;
	double minor = 4.0;
	AMCAX::Ellipse3 ellipse3(defaultFrame3, major, minor);
	Point3 p;
	Vector3 vecu, vecv, vecuu, vecuv, vecvv;
	SECTION("u =0 v =0") {
		 AMCAX::CurveCalculation::PlaneD2(0.0, 0.0, ellipse3, p, vecu, vecv, vecuu, vecuv, vecvv);
		CHECK(p.X() == 5.0);
		CHECK(p.Y() == 0.0);
		CHECK(p.Z() == 0.0);
		CHECK(vecu.X() == Approx(0.0));
		CHECK(vecu.Y() == Approx(20.0 / 25.0));
		CHECK(vecu.Z() == Approx(0.0));
		CHECK(vecv.X() == Approx(-4.0 / 25.0));
		CHECK(vecv.Y() == Approx(-16.0 / 25.0));
		CHECK(vecv.Z() == Approx(0.0));
		CHECK(vecuu.X() == Approx(0.0));
		CHECK(vecuu.Y() == Approx(-48.0 / 25.0));
		CHECK(vecuu.Z() == Approx(0.0));
		CHECK(vecuv.X() == Approx(4.0 / 25.0));
		CHECK(vecuv.Y() == Approx(16.0 / 25.0));
		CHECK(vecuv.Z() == Approx(0.0));
		CHECK(vecvv.X() == Approx(0.0));
		CHECK(vecvv.Y() == Approx(20.0 / 25.0));
		CHECK(vecvv.Z() == Approx(0.0));
	}}