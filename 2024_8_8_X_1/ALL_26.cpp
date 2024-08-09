/* "[[nodiscard]] LineS Normal(const Point2& p)\t @return The line passing through a point and perpendicular to the line\n\t @param p The point\n\t @brief Get a line passing through a point and perpendicular to the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Normal Test")
	{
		Line2 line(3., 4., 5.);  
		Line2 normalLine = line.Normal(Point2(1., 5.));
		double a, b, c;
		normalLine.Coefficients(a, b, c);
		CHECK((a * 3 + b * 4) == Approx(0.0).margin(0.1));
		CHECK((a * 1 + b * 5 + c) == Approx(0.0).margin(0.1));
	}}