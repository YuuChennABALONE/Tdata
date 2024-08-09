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
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Axis3 axis3(point3, dir3);
	Vector3 v3 = CurveCalculation::LineD3(0.0, axis3);
	Vector3 v4 = CurveCalculation::LineD3(1.0, axis3);
	Vector3 v5 = CurveCalculation::LineD3(2.0, axis3);
	CHECK(v3.X() == 0.0);
	CHECK(v3.Y() == 0.0);
	CHECK(v3.Z() == 1.0);
	CHECK(v4.X() == 1.0);
	CHECK(v4.Y() == 0.0);
	CHECK(v4.Z() == 0.0);
	CHECK(v5.X() == 2.0);
	CHECK(v5.Y() == 0.0);
	CHECK(v5.Z() == -1.0);
}