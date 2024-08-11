 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Contains")
	{
		Line2 line(Axis2(Point2(0., 0.), Direction2(1., 1.)));
		Point2 point1(0., 0.);
		Point2 point2(1., 1.);
		Point2 point3(1., 0.);
		SECTION("Is on the line")
		{
			CHECK(line.Contains(point1, 1e-5));
			CHECK(line.Contains(point2, 1e-5));
			CHECK(line.Contains(point3, 1e-5));
		}}
}