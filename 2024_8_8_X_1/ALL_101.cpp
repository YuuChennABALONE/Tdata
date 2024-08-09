/* "Geom2Parabola()\t @brief Default constructor\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <geometry/Geom2Parabola.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom2Parabola", "[math][Geom2Parabola][P1]")
{
	Axis2 axis;
	double focal = 5.0;
	bool isRight = true;
	Geom2Parabola g2p(axis, focal, isRight);
	SECTION("SemilatusRectum")
	{
		double SR = g2p.SemilatusRectum();
		double sr = 2 * focal;
		CHECK(SR == sr);
	}
}