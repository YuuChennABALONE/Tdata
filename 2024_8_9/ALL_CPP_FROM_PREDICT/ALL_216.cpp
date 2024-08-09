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
TEST_CASE("case1: CurveCalculation::CircleD3 2/2 ", "[math][CurveCalculation][P1][CircleD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3d(defaultFrame3, radius);
	SECTION("LineD0") {
		double u = 0;
		Point3 pointOnCirecle = CurveCalculation::LineD0(u, circle3d);
		CHECK(pointOnCirecle.X() == 3.0);
		CHECK(pointOnCirecle.Y() == 1.0);
		CHECK(pointOnCirecle.Z() == Approx(0.0).margin(1e-14));
	}}