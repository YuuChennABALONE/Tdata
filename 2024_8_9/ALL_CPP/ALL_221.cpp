/* "[[nodiscard]] double SemilatusRectum()\t @return The semilatus rectum\n\t          Semilatus rectum = 2 * focalLength\n\t @details The semilatus rectum of parabola is half of the length of the chord through a focus parallel to the directrix.\n\t @brief Get the semilatus rectum of the parabola\n,\n",
      */
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