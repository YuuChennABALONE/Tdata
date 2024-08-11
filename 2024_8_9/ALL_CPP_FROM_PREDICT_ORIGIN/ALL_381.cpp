 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Distance")
	{
		Line2 line(Point2(), Direction2(0., 1.));
		double p1 = line.Distance(Point2());
		double p2 = line.Distance(Point2(0., 1.));
		CHECK(p1 == 0.);
		CHECK(p1 == p2);
	}}