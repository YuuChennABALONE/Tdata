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
TEST_CASE("case1: CurveCalculation::LineD3 1/4 ", "[math][CurveCalculation][P1][LineD3]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double lineConductance = 0.0;
	Axis2 axis2(defaultFrame2, lineConductance);
	Point2 p;
	Vector2 v1, v2,v3;
	SECTION("u =0") {
		CurveCalculation::LineD3(0.0, axis2, p, v1,v2,v3);
		CHECK(p.X() == 1.0);
		CHECK(p.Y() == 1.0);
		CHECK(v1.X() == 1.0);
		CHECK(v1.Y() == 0.0);
		CHECK(v2.X() == Approx(0.0));
		CHECK(v2.Y() == Approx(0.0));
		CHECK(v3.X() == Approx(-1.0));
		CHECK(v3.Y() == Approx(0.0));
	}}