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
TEST_CASE("case1: CurveCalculation::D0() [1/2] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Circle3 circle3D;
	SECTION("D0()") {
		Point3 point1 = AMCAX::CurveCalculation::D0(0.0, circle3D);
		CHECK(point1.X() == 0.0);
		CHECK(point1.Y() == 0.0);
		CHECK(point1.Z() == 0.0);
	}}