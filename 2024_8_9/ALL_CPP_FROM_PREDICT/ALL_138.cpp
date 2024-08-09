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
TEST_CASE("case1: Cartesian3::To3d() [9/10] ", "[math][Cartesian3][P1][To3d]") {
	Point2 point2(2.0, 3.0);
	Point3 point3 = Cartesian3::To3d(Frame3(), point2);
	CHECK(point3.X() == 2.0);
	CHECK(point3.Y() == 3.0);
	CHECK(point3.Z() == Approx(0.0).margin(1e-14));
}