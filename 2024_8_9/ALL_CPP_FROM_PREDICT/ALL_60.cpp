 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Plane.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: PlaneD1 ", "[math][Plane][D1]") {
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Plane plane(frame);
	SECTION("u =0 v =0") {
		Vector3 vector3 = plane.Differential(0.0, 0.0);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == 0.0);
	}}