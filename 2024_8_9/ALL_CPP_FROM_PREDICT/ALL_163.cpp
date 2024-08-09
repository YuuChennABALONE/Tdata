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
TEST_CASE("case1: CurveCalculation::ParabolaD3 1/4 ", "[math][CurveCalculation][P1][ParabolaD3]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double focal = 2.0;
	Vector2 vector2 = CurveCalculation::ParabolaD3(0.0, defaultFrame2, focal);
	Vector2 vector21 = CurveCalculation::ParabolaD3(1.0, defaultFrame2, focal);
	Vector2 vector22 = CurveCalculation::ParabolaD3(2.0, defaultFrame2, focal);
	CHECK(vector2.X() == 1.0);
	CHECK(vector2.Y() == 1.0 / 8.0);
	CHECK(vector21.X() == Approx(2.0).margin(1e-12));
	CHECK(vector21.Y() == Approx(-1.0).margin(1e-12));
	CHECK(vector22.X() == Approx(1.0).margin(1e-12));
	CHECK(vector22.Y() == Approx(-8.0 / 8.0).margin(1e-12));
}