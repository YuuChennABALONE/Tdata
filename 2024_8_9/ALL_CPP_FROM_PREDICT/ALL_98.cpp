 #include <catch.hpp>
#include <testHelper.h>
#include <math/ParabolaT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Parabola2;
TEST_CASE("case1:this is a case for Test Parabola2", "[math][Parabola2][P1]")
{
	SECTION("Default constructor")
	{
		Parabola2 parabola2;
		CHECK(parabola2.Location().IsEqual(Axis2().Location(), 0.001));
		CHECK(parabola2.Direction().IsEqual(Axis2().Direction(), 1e-5 * deg));
		CHECK(parabola2.Focus().IsEqual(Point2(0.0, 0.0), 0.001));
		CHECK(parabola2.DiametralLine().IsEqual(Line2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), 1e-5));
		double a, b, c;
		parabola2.Coefficients(a, b, c);
		CHECK(a == Approx(0.0));
		CHECK(b == Approx(0.0));
		CHECK(c == Approx(1.0));
	}}