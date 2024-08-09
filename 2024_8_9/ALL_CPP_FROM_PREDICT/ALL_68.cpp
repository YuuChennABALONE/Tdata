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
	AMCAX::Point3 point2(0.0, 0.0, 0.0);
	AMCAX::Direction3 dir2(0.0, 0.0, 1.0);
	AMCAX::Frame3 fram3(point2, dir2);
	double radius2 = 5.0;
	AMCAX::Circle3 circle3(fram3, radius2);
	SECTION("Parameter() [1/2]") {
		Point3 pointOnCircle = circle3.Location();
		double uv1 = CurveCalculation::Parameter(circle3, pointOnCircle, 0.0);
		CHECK(uv1 == 0.0);
		CHECK(circle3.Parameter(0.0) == pointOnCircle);
	}}