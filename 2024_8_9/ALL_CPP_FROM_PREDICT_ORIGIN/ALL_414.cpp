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
	AMCAX::Point3 P(0.0, 0.0, 0.0);
	AMCAX::Direction3 D(0.0, 0.0, 1.0);
	AMCAX::Axis3  axis3(P, D);
	float focal = 2.0f;
	AMCAX::Parabola3 parabola3(axis3, focal);
	SECTION("u =0") {
		Point3 point1 = CurveCalculation::D0(0.0, parabola3);
		CHECK(point1.X() == 0.0);
		CHECK(point1.Y() == 0.0);
		CHECK(point1.Z() == 0.0);
	}}