/* "LineS(double a, double b, double c)\t @param a,b,c The coefficients\n\t @brief Construct from the algebraic coefficients of 2D line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Parameterized constructor test")
	{
		Line2 line1(Axis2(Point2(1., 0.), Direction2(2., 1.)));
		Line2 line2(Point2(1., 0.), Direction2(2., 1.));  
		Line2 line3(1, -2, -1);
		double a, b, c;
		line1.Coefficients(a, b, c);
		CHECK(a == Approx(1.0 / std::sqrt(5)));
		CHECK(b == Approx(-2.0 / std::sqrt(5)));
		CHECK(c == Approx(-1.0 / std::sqrt(5)));
		line2.Coefficients(a, b, c);
		CHECK(a == Approx(1.0 / std::sqrt(5)));
		CHECK(b == Approx(-2.0 / std::sqrt(5)));
		CHECK(c == Approx(-1.0 / std::sqrt(5)));
		line3.Coefficients(a, b, c);
		CHECK(a == Approx(1.0 / std::sqrt(5)));
		CHECK(b == Approx(-2.0 / std::sqrt(5)));
		CHECK(c == Approx(-1.0 / std::sqrt(5)));
	}}