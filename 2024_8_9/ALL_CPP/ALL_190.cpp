/* "void SetPosition(const AxisT<double, DIM>& axis)\t @param axis The axis\n\t @brief Set the axis of the line\n,\n",
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
	SECTION("SetPosition")
	{
		Axis3 axis(Point3(0.1, -2.3, 0.3), Direction3(1.2, -8.9, 3.));
		Line3 line;
		line.SetPosition(axis);
		CHECK(line.Location().IsEqual(axis.Location(), std::numeric_limits<double>::min()));
		CHECK(line.Direction().IsEqual(axis.Direction(), std::numeric_limits<double>::min()));
	}}