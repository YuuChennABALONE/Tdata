/* "[[nodiscard]] auto Distance(const Point3& p)\t @return The distance between the point and the line\n\t @param p The point\n\t @brief Compute the distance from a point to the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Scale")
	{
		Line2 line(Point2(0., -1.), Direction2());
		Point2 point;
		double distance = line.Distance(point);
		Line2 lineScale1 = line.Scaled(point, 1.1);
		CHECK(lineScale1.Distance(point) > distance);
		CHECK(lineScale1.Contains(Point2(0., -1.1), 1e-5));
		Line2 lineScale2 = line.Scaled(point, 1.);
		CHECK(lineScale2.Distance(point) == Approx(distance).margin(1e-5));
		CHECK(lineScale2.Contains(Point2(0., -1.), 1e-5));
		Line2 lineScale3 = line.Scaled(point, 0.8);
		CHECK(lineScale3.Distance(point) < distance);
		CHECK(lineScale3.Contains(Point2(0., -0.8), 1e-5));
		Line2 lineScale4 = line.Scaled(point, 0.);
		line.SetDirection(Direction2(-1.0, 4.0));
		Line2 lineScale5 = line.Scaled(Point2(-1., 2.), 0.);
		CHECK(lineScale4.Contains(Point2(0., 0.), 1e-5));
		CHECK(lineScale4.Direction().IsEqual(Direction2(), 1e-6 * ONE_RADIAN));
		CHECK(lineScale5.Contains(Point2(-1., 2.), 1e-5));
		CHECK(lineScale5.Direction().IsEqual(Direction2(-1., 4.), 1e-6 * ONE_RADIAN));
		Line2 lineScale6 = line.Scaled(point, -1.);
		CHECK(lineScale6.Direction().IsEqual(Direction2(1., -4.), 1e-5 * ONE_RADIAN));
	}}