 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Transform")
	{
		Line2 line;
		Line2 line2(Point2(2., 1.), Direction2(1., 1.));  
		Transformation2 tran;
		tran.SetRotation(Point2(0., 0.), M_PI_2);
		CHECK(line.Transform(tran).IsEqual(line2, 1e-5 * ONE_RADIAN));
	}}