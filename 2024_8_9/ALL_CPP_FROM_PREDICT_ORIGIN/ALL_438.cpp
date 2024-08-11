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
TEST_CASE("case1: CurveCalculation::D1() parabola2[1/20] ", "[math][CurveCalculation][P1][D1]") {
	Axis2 axis;
	double focal = 3.0;
	Point2 defaultPoint(0.0, 0.0);
	Direction2 defaultDirection(1.0, 0.0);
	Direction2 focalDirection(0.0, 1.0);
	Frame2 defaultFrame2(axis, defaultDirection, focalDirection);
	Parabola2 parabola2(defaultFrame2, focal);
	SECTION("u =0") {
		Vector2 vector2 = CurveCalculation::D1(0.0, parabola2);
		CHECK(vector2.X() == 0.0);
		CHECK(vector2.Y() == -3.0);
	}}