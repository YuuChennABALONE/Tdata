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
TEST_CASE("case1: CurveCalculation::LineParameter() [3/10] ", "[math][CurveCalculation][P1][LineParameter]") {
	Direction3 dir(0.0, 0.0, 1.0);
	Frame3 frame(Point3(1.0, 1.0, 0.0), dir);
	Axis3 axis(frame);
	double param = CurveCalculation::LineParameter(axis, Point3(2.0, 1.0, 0.0));
	CHECK(param == 0.0);
}