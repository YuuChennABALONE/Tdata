/* "[[nodiscard]] double FocalParameter()\t @return The focal parameter\n\t          Focal parameter = 2 * focalLength.\n\t @details The focal parameter of parabola is the distance from the focus to the directrix.\n\t @brief Get the focal parameter of the parabola\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/ParabolaT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Parabola2", "[math][Parabola2][P1]")
{
	Axis2 axis;
	double focal = 5.0;
	bool isRight = true;
	Parabola2 parabola(axis, focal, isRight);
	SECTION("FocalParameter")
	{
		double FP = parabola.FocalParameter();
		double fp = 2 * focal;
		CHECK(FP == fp);
	}}