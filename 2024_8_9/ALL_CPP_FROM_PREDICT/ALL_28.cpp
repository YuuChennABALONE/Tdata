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
TEST_CASE("case1: CurveCalculation::Circle3 ConeVIso 1/2 ", "[math][CurveCalculation][P1][ConeVIso]") {
	Frame3 frame;
	double radius = 5.0;
	double angle = M_PI_2;
	AMCAX::Circle3 circle(frame, radius, angle);
	SECTION("v =0") {
		double u = 0.0;
		double v = 0.0;
		CHECK(circle.ConeVIso(u, v, 0.1) == Approx(5.0));
	}}