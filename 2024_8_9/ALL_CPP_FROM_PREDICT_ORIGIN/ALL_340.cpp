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
	SECTION("SemilatusRectum")
	{
		double SR = parabola.SemilatusRectum();
		double sr = 2 * focal;
		CHECK(SR == sr);
	}
}