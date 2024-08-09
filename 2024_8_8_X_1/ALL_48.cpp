/* "[[nodiscard]] double SemilatusRectum()\t @return The semilatus rectum\n\t          Semilatus rectum = 2 * focalLength\n\t @details The semilatus rectum of parabola is half of the length of the chord through a focus parallel to the directrix.\n\t @brief Get the semilatus rectum of the parabola\n,\n",
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