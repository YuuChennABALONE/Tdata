/* "Derived& Reverse()\t @return The reference to self\n\t @brief Reverse the line direction\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Reverse")
	{
		Line2 line;
		line.Reverse();
		CHECK(line.Direction().IsEqual(Direction2(-1., 0.), 1e-5 * ONE_RADIAN));
		Line2 line2(Point2(), Direction2(-3., 98.));
		line2.Reverse();
		CHECK(line2.Direction().IsEqual(Direction2(3., -98.), 1e-5 * ONE_RADIAN));
	}}