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
	SECTION("Default constructor")
	{
		Line3 line;
		CHECK(line.Location().IsEqual(Point3(0., 0., 0.), 1e-5));
		CHECK(line.Direction().IsEqual(Direction3(0., 0., 1.), 1e-5 * ONE_RADIAN));
	}}