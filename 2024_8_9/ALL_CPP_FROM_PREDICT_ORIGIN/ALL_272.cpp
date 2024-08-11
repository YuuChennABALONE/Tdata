 #include <catch.hpp>
#include <testHelper.h>
#include <math/EllipseT.hpp>
#include <geometry/Geom2Ellipse.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom2Ellipse", "[math][Geom2Ellipse][P1]")
{
	Axis2 axis;
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	Ellipse2 ellipse(axis, major, minor, isRight);
	Geom2Ellipse g2e(ellipse);
	SECTION("FocalParameter")
	{
		double FP = g2e.FocalParameter();
		double focal = 2 * sqrt(major * major - minor * minor);
		double fp = 2 * minor * minor / focal;;
		CHECK(FP == fp);
	}}