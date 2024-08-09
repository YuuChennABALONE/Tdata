/* "[[nodiscard]] auto Distance(const Point3& p)\t @return The distance between the point and the line\n\t @param p The point\n\t @brief Compute the distance from a point to the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <math/Plane.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
using AMCAX::Line3;
using AMCAX::MakeEdge;
using AMCAX::MakeFace;
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
TEST_CASE("case2: Line3 base method Test", "[math][Line3][p1]")
{
	SECTION("Scale")
	{
		Line3 line(Point3(), Direction3(0., 1., 0.));
		Point3 point(1., 1., 0.);
		double originalDistance = line.Distance(point);
		Line3 line1 = line.Scaled(point, 1.1);
		CHECK(line1.Distance(point) > originalDistance);
		Line3 line2 = line.Scaled(point, 1.);
		CHECK(line2.Distance(point) == originalDistance);
		Line3 line3 = line.Scaled(point, 0.8);
		CHECK(line3.Distance(point) < originalDistance);
		Line3 line4 = line.Scaled(point, 0.);
		CHECK(line4.Contains(point, 1e-6));
		Line3 line5 = line.Scaled(point, -1.);
		CHECK(line5.Direction().IsEqual(Direction3(0., -1., 0.), 1e-6 * ONE_RADIAN));
	}}