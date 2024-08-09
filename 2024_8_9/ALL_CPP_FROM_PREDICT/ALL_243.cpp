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
TEST_CASE("case1: CurveCalculation::Value() [1/10] ", "[math][CurveCalculation][P1][Value]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	float radius = 2.0f;
	AMCAX::Circle2 circle2(axis2, radius, true);
	Point2 point2 = AMCAX::CurveCalculation::Value(0.0, circle2);
	CHECK(point2.X() == 0.0);
	CHECK(point2.Y() == 2.0);
}