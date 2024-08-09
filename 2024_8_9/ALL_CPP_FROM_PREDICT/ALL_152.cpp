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
TEST_CASE("case1: CurveCalculation::HyperbolaD1 1/4 ", "[math][CurveCalculation][P1][HyperbolaD1]") {
	Axis2 majorAxis;
	double majorRadius = 3.0;
	double minorRadius = 4.0;
	double angle = M_PI / 4;
	Point2 point(0.0, 0.0);
	Frame2 frame2(majorAxis, point);
	Hyperbola2 hyperbola2(frame2, majorRadius, minorRadius);
	Vector2 vector2 = CurveCalculation::HyperbolaD1(M_PI / 4, frame2, majorRadius, minorRadius);
	CHECK(vector2.X() == Approx(-0.4469285714).margin(1e-12));
	CHECK(vector2.Y() == 0.9903422415);
}