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
	AMCAX::Circle2 circle2(AMCAX::Point2(0.0, 0.0), 5.0);
	SECTION("u =0") {
		Point2 point2 = AMCAX::CurveCalculation::Value(0.0, circle2);
		CHECK(point2.X() == 5.0);
		CHECK(point2.Y() == 0.0);
	}}