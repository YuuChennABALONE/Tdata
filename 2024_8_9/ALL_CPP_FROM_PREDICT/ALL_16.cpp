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
TEST_CASE("case1: CurveCalculation::Circle3::SphereVIso 1/2 ", "[math][CurveCalculation][Circle3][P1][SphereVIso]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("v =0") {
		double u1 = AMCAX::CurveCalculation::Circle3::SphereVIso(0.0, 2.0, 0.0);
		CHECK(u1 == M_PI_2);
		double x = 1.0 + 2.0*cos(M_PI_2);
		double y = 1.0 + 2.0*sin(M_PI_2);
		double z = 0.0;
		CHECK(circle3.Location().X() == x);
		CHECK(circle3.Location().Y() == y);
		CHECK(circle3.Location().Z() == z);
	}}