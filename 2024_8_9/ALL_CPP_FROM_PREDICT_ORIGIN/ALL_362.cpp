 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Rotate")
	{
		Line2 line(Point2(), Direction2(1., 1.));  
		Line2 line2(Point2(), Direction2(1., 1.));  
		line.Rotate(Point2(), 0.);  
		CHECK(line.Direction().IsEqual(line2.Direction(), 1e-6 * ONE_RADIAN));
		line2.Rotate(Point2(), 90.);  
		CHECK(line.Direction().IsEqual(line2.Direction(), 1e-6 * ONE_RADIAN));
	}}