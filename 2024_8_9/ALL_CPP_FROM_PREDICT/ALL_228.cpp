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
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	AMCAX::Point3 point3(0.0, 0.0, 0.0);
	AMCAX::Direction3 dir3(0.0, 0.0, 1.0);
	AMCAX::Axis3  axis3(point3, dir3);
	double radius = 2.0;
	AMCAX::Circle3 circle3(axis3, radius, AMCAX::Frame3::Transformation());
	SECTION("parameter 0") {
		CHECK(CurveCalculation::Parameter(circle3, point3) == 0.0);
	}}