 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Scale Test")
	{
		Line2 line;
		Line2 line2(Point2(), Direction2(1., 1.));
		line.Scale(line.Location().X(), line.Location().Y(), 2.);
		line2.Scale(line.Location().X(), line.Location().Y(), 2.);
		CHECK(line.Direction().IsEqual(line2.Direction(), 1e-5 * ONE_RADIAN));
		double a, b, c;
		line.Coefficients(a, b, c);
		line2.Coefficients(a, b, c);
		CHECK(a == Approx(1. / std::sqrt(2)).margin(1e-5));
		CHECK(b == Approx(1. / std::sqrt(2)).margin(1e-5));
		CHECK(c == Approx(-1. / std::sqrt(2)).margin(1e-5));
	}
}