/* "void SetLocation(const PointT<double, DIM>& point)\t @param point The location point\n\t @brief Set the location of the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("SetLocation")
	{
		Line2 line(Point2(0., 0.), Direction2(1., 1.));  
		CHECK(line.Location().IsEqual(Point2(), 1e-5));
		line.SetLocation(Point2(2., 1.));  
		CHECK(line.Location().IsEqual(Point2(2., 1.), 1e-5));
		double a, b, c;
		line.Coefficients(a, b, c);
		CHECK(a == Approx(1. / std::sqrt(2)).margin(1e-5));
		CHECK(b == Approx(-1. / std::sqrt(2)).margin(1e-5));
		CHECK(c == Approx(-1. / std::sqrt(2)).margin(1e-5));
	}}