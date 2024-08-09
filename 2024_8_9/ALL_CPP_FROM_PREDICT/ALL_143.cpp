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
TEST_CASE("case1: CurveCalculation::HyperbolaD3 1/4 ", "[math][CurveCalculation][P1][HyperbolaD3]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), initialDir); 
	double major = 5.0;
	double minor = 4.0;
	AMCAX::Hyperbola2 hyperbola2d(defaultFrame2, major, minor);
	SECTION("u =0") {
		Vector2 vector2 = CurveCalculation::HyperbolaD3(0.0, hyperbola2d);
		CHECK(vector2.X() == 5.0);
		CHECK(vector2.Y() == 0.0);
	}}