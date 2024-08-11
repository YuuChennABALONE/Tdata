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
	SECTION("SquaredDistance")
	{
		Line3 line(Point3(), Direction3(0., 1., 0.));
		Point3 point(1., 2., 3.);
		double squaredDis = line.SquaredDistance(point);
		double distance = line.Distance(point);
		CHECK(squaredDis == SQUARE(distance));
	}}