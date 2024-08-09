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
TEST_CASE("case1: CurveCalculation::Value() [9/10] ", "[math][CurveCalculation][P1][Value]") {
	AMCAX::Torus torus;
	SECTION("u =0,v =0") {
		Point3 point = AMCAX::CurveCalculation::Value(0.0, 0.0, torus);
		CHECK(point.X() == torus.R());
		CHECK(point.Y() == 0.0);
		CHECK(point.Z() == 0.0);
	}}