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
TEST_CASE("case1: CurveCalculation::D1() circle3[4/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	Point3 p;
	Vector3 v;
	SECTION("u =0") {
		CurveCalculation::D1(0.0, circle3,p,v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
		CHECK(v.Z() == Approx(0.0));
	}}