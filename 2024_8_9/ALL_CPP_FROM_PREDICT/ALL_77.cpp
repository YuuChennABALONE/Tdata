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
TEST_CASE("case1: CurveCalculation::Value() [1/2] ", "[math][CurveCalculation][P1][Value]") {
	AMCAX::Cylinder cylinder(AMCAX::Point3(0.0, 0.0, 2.0), 3.0, 4.0);
	SECTION("u =0 v =0") {
		double u = 0;
		double v = 0;
		Point3 point = AMCAX::CurveCalculation::Value(u, v, cylinder);
		CHECK(point.X() == 3.0);
		CHECK(point.Y() == 0.0);
		CHECK(point.Z() == 2.0);
	}}