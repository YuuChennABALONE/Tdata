 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/PointT.hpp>
#include <math/CircleT.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeEdge2d", "[modeling][MakeEdge2d][fixbug]")
{
	TopoEdge edge;
	SECTION("SetInitialPoints")
{
	AMCAX::Point2 p1(-1.0, 0.0);
	AMCAX::Point2 p2(1.0, 0.0);
	MakeEdge2d edge;
	bool b = edge.SetInitialPoints(p1, p2);
	CHECK(b == true);
	CHECK(edge.Length() == Approx(2.0));
	CHECK(edge.NDArclen(0.0) == Approx(-1.0));
	CHECK(edge.NDArclen(1.0) == Approx(1.0));
	CHECK(edge.NDArclen(2.0) == Approx(2.0));
	AMCAX::Point2 p3 = edge LastPoint();
	CHECK(p3.X() == 1.0);
	CHECK(p3.Y() == 0.0);
}
}