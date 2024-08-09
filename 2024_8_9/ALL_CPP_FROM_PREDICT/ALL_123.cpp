 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Parameterized constructor")
	{
		Axis2 axis(Point2(2., 1.), Direction2(3., 4.));
		Line2 line(axis);
		CHECK(line.Location().IsEqual(Point2(2., 1.), 1e-5));
		CHECK(line.Direction().IsEqual(Direction2(3., 4.), 1e-5 * ONE_RADIAN));
	}}