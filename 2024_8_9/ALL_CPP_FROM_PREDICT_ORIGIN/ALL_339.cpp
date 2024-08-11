 #include <catch.hpp>
#include <testHelper.h>
#include <math/ParabolaT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Parabola3", "[math][Parabola3][P1]")
{
	Frame3 frame;
	double focal = 5.0;
	Parabola3 parabola(frame, focal);
	SECTION("FocalParameter")
	{
		double FP = parabola.FocalParameter();
		double fp = 2 * focal;
		CHECK(FP == fp);
	}}