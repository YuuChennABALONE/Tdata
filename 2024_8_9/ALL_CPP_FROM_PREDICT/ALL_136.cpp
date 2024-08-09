 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CartesianAlgorityhm.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CartesianAlgorityhm::To3d() [9/10] ", "[math][CartesianAlgorityhm][P1][To3d]") {
	Point2 point2(0.0, 0.0);
	Direction2 dir2(1.0, 0.0);
	Frame2 frame2(point2, dir2);
	Direction3 dir3 = CartesianAlgorityhm::To3d(frame2, dir2);
	CHECK(dir3.X() == Approx(1.0));
	CHECK(dir3.Y() == Approx(0.0));
	CHECK(dir3.Z() == Approx(0.0));
}