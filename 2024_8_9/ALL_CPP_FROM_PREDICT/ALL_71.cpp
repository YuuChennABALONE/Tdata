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
TEST_CASE("case1: CurveCalculation::DN() cone3[1/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 0.0, 0.0), initialDir); 
	AMCAX::Cone cone3(defaultFrame3, 5.0, 3.0);
	SECTION("u =0 v =0 nu = 1 nv = 1") {
		Vector3 vector3 = CurveCalculation::DN(0.0, 0.0, cone3, 1, 1);
		CHECK(vector3.X() == Approx(-5.0));
		CHECK(vector3.Y() == Approx(0.0));
		CHECK(vector3.Z() == Approx(0.0));
	}}