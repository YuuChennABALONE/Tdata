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
TEST_CASE("case1: CurveCalculation::CircleD3() circle2[1/20] ", "[math][CurveCalculation][P1][CircleD3]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0; 
	Vector2 tangentAt0 = CurveCalculation::CircleD3(0.0, defaultFrame2, radius);
	Vector2 tangentAt90Deg = CurveCalculation::CircleD3(M_PI_2, defaultFrame2, radius);
	Vector2 tangentAt180Deg = CurveCalculation::CircleD3(M_PI, defaultFrame2, radius);
	Vector2 tangentAt270Deg = CurveCalculation::CircleD3(3 * M_PI_2, defaultFrame2, radius);
	Vector2 tangentAt360Deg = CurveCalculation::CircleD3(2 * M_PI, defaultFrame2, radius);
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == -2.0);
	CHECK(tangentAt90Deg.X() == -2.0);
	CHECK(tangentAt90Deg.Y() == 0.0);
	CHECK(tangentAt180Deg.X() == 0.0);
	CHECK(tangentAt180Deg.Y() == 2.0);
	CHECK(tangentAt270Deg.X() == 2.0);
	CHECK(tangentAt270Deg.Y() == 0.0);
	CHECK(tangentAt360Deg.X() == -0.0);
	CHECK(tangentAt360Deg.Y() == -2.0);
}