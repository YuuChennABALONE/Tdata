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
TEST_CASE("case1: CurveCalculation::D2() hyperbola3[11/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	Point3 p;
	Vector3 v1, v2;
	SECTION("u =0") {
		CurveCalculation::D2(0.0, hyperbola3, p, v1,v2);
		CHECK(p.X() == 5.0);
		CHECK(p.Y() == 0.0);
		CHECK(p.Z() == 0.0);
		CHECK(v1.X() == Approx(3.0));
		CHECK(v1.Y() == Approx(0.0));
		CHECK(v1.Z() == Approx(0.0));
		CHECK(v2.X() == Approx(-2.5).margin(1e-14));
		CHECK(v2.Y() == Approx(0.0));
		CHECK(v2.Z() == Approx(0.0));
	}}