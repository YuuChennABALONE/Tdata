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
TEST_CASE("case1: CurveCalculation::Value() [1/2] ", "[math][CurveCalculation][P1][Value]") {
	AMCAX::Circle3 circle3D;
	double radius = 5.0;
	double u = 0.0;
	double x = AMCAX::CurveCalculation::Value(u, circle3D);
	double y = AMCAX::CurveCalculation::Value(u, circle3D, 0);
	double z = AMCAX::CurveCalculation::Value(u, circle3D, 2);
	CHECK(x == radius);
	CHECK(y == 0.0);
	CHECK(z == 0.0);
}