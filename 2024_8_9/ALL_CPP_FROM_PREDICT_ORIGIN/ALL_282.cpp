 #include <catch.hpp>
#include <testHelper.h>
#include <math/EllipseT.hpp>
#include <geometry/Geom2Hyperbola.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom2Hyperbola", "[math][Geom2Hyperbola][P1]")
{
	Axis2 axis;
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	Geom2Hyperbola g2h(axis, major, minor, isRight);
	SECTION("FocalParameter")
	{
		double FP = g2h.FocalParameter();
		double focal = 2 * sqrt(major * major + minor * minor);
		double fp = 2 * minor * minor / focal;;
		CHECK(FP == fp);
	}}