 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/EllipseT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Ellipse2", "[math][Ellipse2][P1]")
{
	Axis2 axis;
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	Ellipse2 ellipse(axis, major, minor, isRight);
	SECTION("Area")
	{
		double S = ellipse.Area();
		CHECK(S == Approx(M_PI * major * minor));
	}}