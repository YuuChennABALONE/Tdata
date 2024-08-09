/* "void SetPosition(const AxisT<double, DIM>& axis)\t @param axis The axis\n\t @brief Set the axis of the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("SetPosition")
	{
		Line2 line;
		CHECK(line.Location().IsEqual(Point2(0., 0.), 1e-5));
		CHECK(line.Direction().IsEqual(Direction2(1., 0.), 1e-5 * ONE_RADIAN));
		Axis2 axis(Point2(2., 1.), Direction2(1., 1.));
		line.SetPosition(axis);  
		double a, b, c;
		line.Coefficients(a, b, c);
		CHECK(a == Approx(1. / std::sqrt(2)).margin(1e-5));
		CHECK(b == Approx(-1. / std::sqrt(2)).margin(1e-5));
		CHECK(c == Approx(-1. / std::sqrt(2)).margin(1e-5));
	}}