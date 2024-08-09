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
TEST_CASE("case1: CurveCalculation::LineD3 1/2 ", "[math][CurveCalculation][P1][LineD3]") {
	Axis2 axis2(Point2(0.0, 0.0), Direction2(1.0, 0.0)); 
	double radius = 0.0;
	Vector2  pos = axis2.Position();
	double  u = 0.0;
	Vector2 vector2 = CurveCalculation::LineD3(u, axis2);
	Vector2 vector3 = CurveCalculation::LineD3(1.0, axis2);
	Vector2 vector4 = CurveCalculation::LineD3(2.0, axis2);
	CHECK(vector2.X() == 0.0);
	CHECK(vector2.Y() == 0.0);
	CHECK(vector3.X() == -1.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector4.X() == -2.0);
	CHECK(vector4.Y() == 0.0);
}