/* "[[nodiscard]] double FocalParameter()\t @return The focal parameter\n\t          Focal parameter = 2 * focalLength.\n\t @details The focal parameter of parabola is the distance from the focus to the directrix.\n\t @brief Get the focal parameter of the parabola\n,\n",
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
	SECTION("FocalParameter")
	{
		double FP = g3p.FocalParameter();
		double fp = 2 * focal;
		CHECK(FP == fp);
	}}