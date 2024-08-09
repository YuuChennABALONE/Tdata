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
TEST_CASE("case1: CurveCalculation::Circle3 TorusVIso 1/2 ", "[math][CurveCalculation][P1][TorusVIso]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double major = 3.0;
	double minor = 1.0;
	double u1 = 0.0;
	double u2 = 2 * M_PI;
	AMCAX::Circle3 circle3(defaultFrame3, major, minor, u1, u2);
	SECTION("v =0") {
		double u = 0.0;
		double x = CurveCalculation::TorusVIso(circle3, u, minor, major, defaultFrame3);
		CHECK(x == 1.0);
	}
}