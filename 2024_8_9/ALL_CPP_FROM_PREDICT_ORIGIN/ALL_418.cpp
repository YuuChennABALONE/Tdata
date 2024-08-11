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
TEST_CASE("case1: CurveCalculation::D0() [4/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Ellipse2 ellipse2(AMCAX::Axis2(AMCAX::Point2(0.0, 0.0), AMCAX::Direction2(1.0, 0.0)), 5.0, 3.0);
	Point2 point2 = AMCAX::CurveCalculation::D0(M_PI_2, ellipse2);
	CHECK(point2.X() == Approx(0.0).margin(1e-12));
	CHECK(point2.Y() == 3.0);
}