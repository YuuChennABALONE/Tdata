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
TEST_CASE("case1: CurveCalculation::D0() Hyperbola3 [12/20] ", "[math][CurveCalculation][P1][D0]") {
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Hyperbola3 hyperbola3(frame, major, minor);
	Point3 point3 = AMCAX::CurveCalculation::D0(M_PI_2, hyperbola3);
	CHECK(point3.X() == 5.0);
	CHECK(point3.Y() == 0.0);
	CHECK(point3.Z() == 0.0);
}