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
TEST_CASE("case1: CurveCalculation::D0() [9/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	float focal = 2.0;
	float pointX = 0.5 * focal;
	float pointY = std::sqrt(focal * focal - pointX * pointX);
	AMCAX::Parabola2 parabola2(axis2, focal);
	Point2 point = CurveCalculation::D0(0.0, parabola2);
	CHECK(point.X() == pointX);
	CHECK(point.Y() == pointY);
}