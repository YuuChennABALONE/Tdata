/* "[[nodiscard]] auto Angle(const LineBase& other)\t @return The angle between the line and the other line\n\t @param other The other line\n\t @brief Compute the angle between the line and the other line\n,\n",
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
	SECTION("Angle")
	{
		Line3 line(Point3(0., 1., 0.), Direction3(1., 1., 1.));
		Line3 line2(Point3(0., 3.4, 0.), Direction3(2., -1., -1.5));
		CHECK(line.Angle(line2) == Approx(std::acos(line.Direction().Dot(line2.Direction()))).margin(1e-6 * ONE_RADIAN));
	}}