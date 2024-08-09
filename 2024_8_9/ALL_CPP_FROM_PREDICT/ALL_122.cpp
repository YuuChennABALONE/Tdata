 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Parameterized constructor")
	{
		Direction2 dir2(0.0, 1.0);
		Point2 point2(1.0, 1.0);
		Line2 line2(point2, dir2);
		CHECK(line2.Location().IsEqual(point2, 1e-5));
		CHECK(line2.Direction().IsEqual(dir2, 1e-5 * ONE_RADIAN));
	}}