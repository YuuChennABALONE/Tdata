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
	AMCAX::Circle3 circle3D;
	double radius = 5.0;
	double tolU = 0.1;
	double tolV = 0.1;
	AMCAX::Point3 start(0.0, 0.0, 0.0);
	AMCAX::Point3 dir(0.0, 0.0, 1.0);
	AMCAX::Frame3 fram3D(start, dir);
	circle3D.SetRadius(radius);
	circle3D.SetLocation(fram3D);
	SECTION("u =0,v =0") {
		CHECK(CurveCalculation::Parameter(circle3D, 0.0, 0.0, tolU, tolV) == 0.0);
	}}