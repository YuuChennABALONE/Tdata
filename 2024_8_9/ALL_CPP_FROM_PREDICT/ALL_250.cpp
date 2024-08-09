 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CircleT.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
using AMCAX::Circle3;
using AMCAX::MakeEdge;
using AMCAX::MakeFace;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Circle3 base method Test", "[math][Circle3][p1]")
{
	SECTION("Construct from a local frame and a radius")
	{
		Frame3 frame(Point3(0., 1., 0.), Direction3(1., 0., 0.), Direction3(0., 0., 1.));
		double radius = 3.;
		Circle3 circle(frame, radius);
		CHECK(circle.Location().IsEqual(Point3(0., 1., 0.), 1e-5));
		CHECK(circle.Radius() == Approx(radius));
		double a, b, c, d;
		circle.Coefficients(a, b, c, d);
		CHECK(a == Approx(0.).margin(1e-6));
		CHECK(b == Approx(1.).margin(1e-6));
		CHECK(c == Approx(-3.).margin(1e-6));
		CHECK(d == Approx(0.).margin(1e-6));
	}}