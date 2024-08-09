/* "[[nodiscard]] AMCAX_API double SemilatusRectum()\t @return The semilatus rectum\n\t          Semilatus rectum = 2 * focalLength\n\t @details The semilatus rectum of parabola is half of the length of the chord through a focus parallel to the directrix.\n\t @brief Get the semilatus rectum of the parabola\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <geometry/Geom3Parabola.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom3Parabola", "[math][Geom3Parabola][P1]")
{
	Frame3 frame;
	double focal = 5.0;
	Geom3Parabola g3p(frame, focal);
	SECTION("SemilatusRectum")
	{
		double SR = g3p.SemilatusRectum();
		double sr = 2 * focal;
		CHECK(SR == sr);
	}
}