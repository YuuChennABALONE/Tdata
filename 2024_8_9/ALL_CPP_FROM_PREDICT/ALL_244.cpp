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
	AMCAX::Hyperbola3 hyperbola3(focal1, focal2, major, minor, frame);
	Point3 point3 = AMCAX::CurveCalculation::Value(0.0, hyperbola3);
	CHECK(point3.X() == 4.0);
	CHECK(point3.Y() == 0.0);
	CHECK(point3.Z() == 0.0);
}