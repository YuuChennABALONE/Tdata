 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CartesianT.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Cartesian2::To3d() [4/10] ", "[math][Cartesian2][P1][To3d]") {
	Frame2 frame;
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	MakeArcOfHyperbola2d arc(frame, major, minor, isRight);
	SECTION("To3d()") {
		Vector2 vector2(0.0, 0.0);
		Vector3 vector3 = Cartesian2::To3d(frame, vector2);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == 0.0);
	}}