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
	AMCAX::Point3 point3(0.0, 0.0, 0.0);
	AMCAX::Direction3 dir3(0.0, 0.0, 1.0);
	AMCAX::Frame3 fram3(point3, dir3);
	double radius = 5.0;
	AMCAX::Curve3 curve3 = AMCAX::MakeArcOfHyperbola2d(fram3, 5.0, 3.0, 2.0);
	AMCAX::Point3 point = AMCAX::CurveCalculation::Value(0.0, 0.0, curve3);
	CHECK(point.X() == 5.0);
	CHECK(point.Y() == 0.0);
	CHECK(point.Z() == 0.0);
}