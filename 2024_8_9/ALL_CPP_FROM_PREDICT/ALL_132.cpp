 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CircleT.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1:this is a case for Circle3", "[math][Circle3][p1]") {
	Point3 point3_fr(0.0, 0.0, 1.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3(point3_fr, dir3_fr);
	double radius3 = 2.0;
	Circle3 circle3d_fr(frame3, radius3);
	SECTION("To3d 2D circle to 3D circle") {
		Circle3 circle3d = Circle3::To3d(frame3, c);
		CHECK(circle3d Fr() == circle3d_fr);
	}
}