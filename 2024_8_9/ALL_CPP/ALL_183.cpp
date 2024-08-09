/* "[[nodiscard]] LineS Normal(const Point3& p)\t @return The line passing through a point and perpendicular to the line\n\t @param p The point\n\t @brief Get a line passing through a point and perpendicular to the line\n,\n",
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
TEST_CASE("case1: Derived class interface unit testing", "[math][Line3][p1]")
{
	SECTION("Normal")
	{
		Line3 line(Point3(94., 32., 4.8), Direction3(2.65, 3.28, 5.14));
		Line3 line2 = line.Normal(Point3(2.1, 3.4, 11.2));
		CHECK(line.Direction().Dot(line2.Direction()) == Approx(0.).margin(1e-6));
	}}