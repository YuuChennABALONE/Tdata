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
TEST_CASE("case1: CurveCalculation::D2() hyperbola2[11/20] ", "[math][CurveCalculation][P1][D2]") {
	Axis2 majorAxis;
	double major_radius = 5;
	double minor_radius = 3;
	Hyperbola2 hyperbola2(majorAxis, major_radius, minor_radius); 
	Point2 p;
	Vector2 v1,v2;
	CurveCalculation::D2(0.0, hyperbola2, p, v1,v2); 
	CHECK(p.X() == 5.0);
	CHECK(p.Y() == 0.0);
	CHECK(v1.X() == 0.0);
	CHECK(v1.Y() == 3.0);
	CHECK(v2.X() == 5.0);
	CHECK(v2.Y() == 0.0);
}