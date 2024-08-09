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
	AMCAX::Line3 line(AMCAX::Point3(0.0, 0.0, 0.0), AMCAX::Direction3(1.0, 1.0, 2.0));
	Point3 point3 = AMCAX::CurveCalculation::Value(0.0, line);
	CHECK(point3.X() == 0.0);
	CHECK(point3.Y() == 1.0);
	CHECK(point3.Z() == 2.0);
}