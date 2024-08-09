/* "[[nodiscard]] auto Angle(const LineBase& other)\t @return The angle between the line and the other line\n\t @param other The other line\n\t @brief Compute the angle between the line and the other line\n,\n",
      */
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
		Line2 line3(Point2(), Direction2(2., 3.));
		Line2 line4(Point2(), Direction2(5., -8.));
		CHECK(line4.Angle(line3) == Approx(
			std::acos((2. * 5. + 3. * (-8.)) / (std::sqrt(4. + 9.) * std::sqrt(25. + 64.)))
		).margin(1e-5 * ONE_RADIAN));
	}}