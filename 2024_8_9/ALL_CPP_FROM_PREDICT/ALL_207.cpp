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
TEST_CASE("case1: CurveCalculation::LineD2() circle3[3/20] ", "[math][CurveCalculation][P1][LineD2]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	Point2 p;
	Vector2 v1,v2;
	SECTION("u =0") {
		CurveCalculation::LineD2(0.0, circle2, p, v1,v2);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(v1.X() == Approx(0.0));
		CHECK(v1.Y() == Approx(2.0));
		CHECK(v2.X() == Approx(-2.0));
		CHECK(v2.Y() == Approx(0.0));
	}}