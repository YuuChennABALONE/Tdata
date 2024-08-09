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
TEST_CASE("case1: CurveCalculation::LineDN 1/2 ", "[math][CurveCalculation][P1][Line]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double lineConductance = 0.0;
	Vector2 lineDistance = Vector2(0.0, 0.0);
	AMCAX::Line2 line2(defaultFrame2, lineConductance, lineDistance);
	SECTION("u =0") { 
		Vector2 vector2 = CurveCalculation::LineDN(0.0, line2);
		CHECK(vector2.X() == 1.0);
		CHECK(vector2.Y() == 0.0);
	}}