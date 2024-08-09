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
TEST_CASE("case1: CurveCalculation::LineD1() [1/10] ", "[math][CurveCalculation][P1][LineD1]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double lineConstrLength = 3.0;
	AMCAX::Line2 line2d(defaultFrame2, lineConstrLength);
	SECTION("u =0") {
		Vector2 vector2d = CurveCalculation::LineD1(0.0, line2d);
		CHECK(vector2d.X() == Approx(0.0));
		CHECK(vector2d.Y() == Approx(1.0));
	}}