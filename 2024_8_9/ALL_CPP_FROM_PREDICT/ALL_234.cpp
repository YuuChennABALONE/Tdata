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
TEST_CASE("case1: CurveCalculation::DN 3D ", "[math][CurveCalculation][DN][P1]") {
	Frame3 fram3 = Frame3(Point3(0.0, 0.0, 1.0), Direction3(0.0, 0.0, 1.0));
	double major = 3.0, minor = 4.0;
	Hyperbola3 hyperbola3(fram3, major, minor);
	SECTION("1 derivative") {
		Vector3 vector3 = CurveCalculation::DN(1, hyperbola3);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == 3.0);
	}}