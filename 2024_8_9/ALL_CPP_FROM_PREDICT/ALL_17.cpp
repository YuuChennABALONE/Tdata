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
TEST_CASE("case1: CurveCalculation::Circle3::SphereUIso 1/2 ", "[math][CurveCalculation][Circle3][P1][SphereUIso]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("u =0") {
		double u = 0;
		Point3 point3 = circle3.SphereUIso(u, 0.0);
		CHECK(point3.X() == 3.0);
		CHECK(point3.Y() == 1.0);
		CHECK(point3.Z() == 0.0);
	}}