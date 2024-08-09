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
TEST_CASE("case1: CurveCalculation::DN() circle2[1/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	SECTION("n = 1") {
		Vector2 vector2 = CurveCalculation::DN(0.0, circle2, 1);
		CHECK(vector2.X() == Approx(0.0));
		CHECK(vector2.Y() == -2.0);
	}}