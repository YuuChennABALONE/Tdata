/* "[[nodiscard]] auto Distance(const Point2& p)\t @return The distance between the point and the line\n\t @param p The point\n\t @brief Compute the distance from a point to the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("SetDirection")
	{
		Line2 line(Point2(), Direction2(1., 1.));  
		CHECK(line.Direction().IsEqual(Direction2(1., 1.), 1e-5 * ONE_RADIAN));
		CHECK(line.Distance(Point2(1., 2.)) > 0.);
		line.SetDirection(Direction2(1., 2.));  
		CHECK(line.Direction().IsEqual(Direction2(1., 2.), 1e-5 * ONE_RADIAN));
		CHECK(line.Distance(Point2(1., 2.)) == Approx(0.).margin(1e-5));
		double a, b, c;
		line.Coefficients(a, b, c);
		CHECK(a == Approx(2. / std::sqrt(5)).margin(1e-5));
		CHECK(b == Approx(-1. / std::sqrt(5)).margin(1e-5));
		CHECK(c == Approx(0. / std::sqrt(5)).margin(1e-5));
	}}