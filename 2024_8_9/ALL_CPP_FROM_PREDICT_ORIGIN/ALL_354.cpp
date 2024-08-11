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
		Line2 line2(Point2(), Direction2(1., 1.));
		CHECK(line.Angle(line2) == Approx(2 * M_PI / 4));
		CHECK(line2.Angle(line) == Approx(2 * M_PI / 4).margin(0.1 * ONE_RADIAN));
		Line2 line3(Point2(), Direction2(1., -1.));
		CHECK(line.Angle(line3) == Approx(3. * M_PI / 4));
		CHECK(line3.Angle(line) == Approx(3. * M_PI / 4).margin(0.1 * ONE_RADIAN));
		Line2 line4(Point2(), Direction2(-1., 1.));
		CHECK(line.Angle(line4) == Approx(5. * M_PI / 4));
		CHECK(line4.Angle(line) == Approx(5. * M_PI / 4).margin(0.1 * ONE_RADIAN));
		Line2 line5(Point2(), Direction2(-1., -1.));
		CHECK(line.Angle(line5) == Approx(7. * M_PI / 4));
		CHECK(line5.Angle(line) == Approx(7. * M_PI / 4).margin(0.1 * ONE_RADIAN));
	}}