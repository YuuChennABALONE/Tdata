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
TEST_CASE("case1: CurveCalculation::Parameter() [9/10] ", "[math][CurveCalculation][P1][Parameter]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	float focal = 2.0;
	AMCAX::Parabola2 parabola2(axis2,focal);
	SECTION("point on the directrix") {
		Point2 pointOnDirectrix(1.0, 0.0);
		CHECK(CurveCalculation::Parameter(parabola2, pointOnDirectrix) == Approx(0).margin(1e-12));
	}}