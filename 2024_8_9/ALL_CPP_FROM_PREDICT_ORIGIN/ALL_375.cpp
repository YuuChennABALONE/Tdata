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
		Axis3 axis(Point3(1., 2., 3.), Direction3(1., 2., 3.));
		Line3 line;
		line.SetPosition(axis);
		CHECK(line.Location().IsEqual(axis.Location(), 1e-6));
		CHECK(line.Direction().IsEqual(axis.Direction(), 1e-6));
	}}