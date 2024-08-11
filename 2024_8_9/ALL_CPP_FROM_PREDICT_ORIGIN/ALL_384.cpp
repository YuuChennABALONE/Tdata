 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Rotate")
	{
		Line2 line(Point2(0., 1.), Direction2(1., 1.));  
		Line2 line2(Point2(0., 1.), Direction2(1., 1.));
		CHECK(line.Rotated(Direction2(1., 1.), M_PI_2).IsEqual(line2, 1e-5 * ONE_RADIAN));
		CHECK(line.Rotated(Direction2(1., 1.), -M_PI_2).IsEqual(line2, 1e-5 * ONE_RADIAN));
		CHECK(line.Rotated(Direction2(1., 1.), -180 * ONE_RADIAN).IsEqual(line2, 1e-5 * ONE_RADIAN));
	}}