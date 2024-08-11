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
	AMCAX::Ellipse3 ellipse3(AMCAX::Axis3(AMCAX::Point3(0.0, 0.0, 1.0), AMCAX::Direction3(0.0, 0.0, 1.0)), 5.0, 3.0);
	Point3 point3 = AMCAX::CurveCalculation::D0(M_PI_2, ellipse3);
	CHECK(point3.X() == 0.0);
	CHECK(point3.Y() == 3.0);
	CHECK(point3.Z() == 1.0);
	CHECK(AMCAX::CurveCalculation::D1(M_PI_2, ellipse3, 0.0, 0.0, 1.0) == M_SQRT3);
}