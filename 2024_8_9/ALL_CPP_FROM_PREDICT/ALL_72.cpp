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
TEST_CASE("case1: CurveCalculation::DN() circle3[3/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 0.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("u =0 v =0") {
		Vector3 vector3 = CurveCalculation::DN(0.0, 0.0, circle3, 1, 1);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == -2.0);
		CHECK(vector3.Z() == 0.0);
	}}