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
TEST_CASE("case1: CurveCalculation::D2() parabola2[1/20] ", "[math][CurveCalculation][P1][D2]") {
	Axis2 axis;
	double focal = 3.0;
	bool isRight = true;
	Parabola2 parabola(axis, focal);
	SECTION("u =0") {
		Vector2 vector2 = CurveCalculation::D2(0.0, parabola);
		CHECK(vector2.X() == 0.0);
		CHECK(vector2.Y() == -3.0);
	}}