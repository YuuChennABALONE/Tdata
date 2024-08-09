/* "LineS& Rotate(const Point2& point, double angle)\t @return The reference to self\n\t @param angle The rotation angle\n\t @param point The rotation center point\n\t @brief Rotate the line around a point with an angle in 2D\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Rotate Test")
	{
		Line2 line(Point2(0., 1.), Direction2(1., 1.));  
		Line2 line2(Point2(0., 1.), Direction2(1., 1.));  
		line.Rotate(Point2(), (5. / 4) * M_PI);  
		CHECK(line.Direction().X() == Approx(0.).margin(1e-5));
		CHECK(line.Direction().Y() == Approx(-1.).margin(1e-5));
		double a, b, c;
		line.Coefficients(a, b, c);
		CHECK((a + c) == Approx(0.).margin(0.5));
		CHECK(line2.Distance(Point2()) == line.Distance(Point2()));  
		CHECK(line.Contains(Point2(std::sqrt(2.) / 2., 0.), 1e-6) == true);
	}}