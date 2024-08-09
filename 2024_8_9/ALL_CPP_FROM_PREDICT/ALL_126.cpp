 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/HyperbolaT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola2", "[math][Hyperbola2][p1]")
{
	Axis2 axis;
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	Hyperbola2 hyperbola(axis, major, minor, isRight);
	SECTION("FocalParameter")
	{
		double FP = hyperbola.FocalParameter();
		double focal = 2 * sqrt(major * major + minor * minor);
		double fp = 2 * minor * minor / focal;;
		CHECK(FP == fp);
	}}