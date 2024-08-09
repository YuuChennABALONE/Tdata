 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CartesianAlgebra.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CartesianAlgebra::Project(Point3, Direction3, Plane3) ", "[math][CartesianAlgebra][P1][Project]") {
	Point3 point3(1.0, 1.0, 1.0);
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 frame3(point3, dir3);
	Plane3 plane(frame3);
	Point3 point4(1.0, 1.0, 2.0);
	Index3 index3 = plane.Location().Index(point4);
	CHECK(CartesianAlgebra::Project(point3, dir3, plane).X() == point3.X());
	CHECK(CartesianAlgebra::Project(point3, dir3, plane).Y() == point3.Y());
	CHECK(CartesianAlgebra::Project(point3, dir3, plane).Z() == point3.Z());
}