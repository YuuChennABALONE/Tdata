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
TEST_CASE("case1: CurveCalculation::LineValue() [1/10] ", "[math][CurveCalculation][P1][LineValue]") {
	AMCAX::Axis3 axis;
	double length = 4.0;
	AMCAX::Point3 start = axis.Position();
	AMCAX::Point3 end = axis.Position() + AMCAX::Direction(axis.Position().X(), axis.Position().Y()) * length;
	AMCAX::Frame3 frame;
	std::shared_ptr< AMCAX::Curve3> curve = AMCAX::MakeArcOfHyperbola2d(axis, 0.0, 10.0);
	Point3 lineValuePoint = AMCAX::CurveCalculation::LineValue(0.0, axis);
	CHECK(lineValuePoint.X() == start.X());
	CHECK(lineValuePoint.Y() == start.Y());
	CHECK(lineValuePoint.Z() == start.Z());
}