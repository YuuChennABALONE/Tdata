 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Mirror line")
	{
		Line2 line;
		Line2 line2(Axis2(Point2(2., 0.), Direction2(1., 1.)));
		line.Mirror(line2);
		CHECK(line.Direction().IsEqual(line2.Direction(), 1e-5 * ONE_RADIAN));
		CHECK(line.Contains(Point2(2., 0.), 1e-5));
		Line2 line3(Axis2(Point2(3., 0.), Direction2(1., 1.)));
		line.Mirror(line3);
		CHECK(line.Direction().IsEqual(line3.Direction(), 1e-5 * ONE_RADIAN));
		CHECK(line.Contains(Point2(3., 0.), 1e-5));
	}}