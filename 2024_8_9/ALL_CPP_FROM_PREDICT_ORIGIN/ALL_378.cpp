 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Angle")
	{
		Line2 line;
		Line2 line2(Point2(), Direction2(0., 1.));
		CHECK(line.Angle(line2) == Approx(M_PI_2));
		CHECK(line2.Angle(line) == Approx(-M_PI_2));
		Line2 line3(Point2(), Direction2(1., 1.));
		CHECK(line.Angle(line3) == Approx(3. * M_PI_2 / 4.).margin(1e-5 * ONE_RADIAN));
		CHECK(line3.Angle(line) == Approx(-3. * M_PI_2 / 4. + M_PI_2).margin(1e-5 * ONE_RADIAN));
	}}