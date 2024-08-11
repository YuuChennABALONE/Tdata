 #include<catch.hpp>
#include <sstream>
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
	SECTION("Mirror")
	{
		Line3 line(Point3(), Direction3(1., 1., 1.));
		Line3 line2(Point3(), Direction3(-1., -1., -1.));
		CHECK(line.Mirrored(line2).IsEqual(line, 1e-6 * ONE_RADIAN, 1e-6, 1e-6));
	}}