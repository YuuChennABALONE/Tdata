/* "void SetDirection(const DirectionT<double, DIM>& dir)\t @param dir The line direction\n\t @brief Set the line direction\n,\n",
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
	SECTION("SetDirection")
	{
		Direction3 dir(1., 1., 1.);
		Line3 line;
		line.SetDirection(dir);
		CHECK(line.Direction().IsEqual(dir, std::numeric_limits<double>::min()));
	}}