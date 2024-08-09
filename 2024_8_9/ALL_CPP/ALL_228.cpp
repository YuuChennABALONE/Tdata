/* "[[nodiscard]] double FocalParameter()\t @return The focal parameter\n\t          Focal parameter = 2 * focalLength.\n\t @details The focal parameter of parabola is the distance from the focus to the directrix.\n\t @brief Get the focal parameter of the parabola\n,\n",
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
	SECTION("FocalParameter")
	{
		double FP = g2p.FocalParameter();
		double fp = 2 * focal;
		CHECK(FP == fp);
	}}