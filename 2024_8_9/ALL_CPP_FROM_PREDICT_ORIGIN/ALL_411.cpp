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
TEST_CASE("case1: CurveCalculation::D0() [1/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Point3 P(0.0, 0.0, 0.0);
	AMCAX::Direction3 V(0.0, 0.0, 1.0);
	AMCAX::Axis3  axis3(P, V);
	float radius = 2.0f;
	AMCAX::Frame3  defaultFrame3 = axis3;
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	Point3 point3 = AMCAX::CurveCalculation::D0(0.0, circle3);
	CHECK(point3.X() == 0.0);
	CHECK(point3.Y() == 2.0);
	CHECK(point3.Z() == 0.0);
}