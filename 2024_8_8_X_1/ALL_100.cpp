/* "AMCAX_API Geom2Parabola(const Axis2& axis, double focal, bool isRight = true)\t @param isRight Is the local frame right-handed\n\t @param focal The focal length\n\t @param axis The axis\n\t @brief Construct from an axis and a focal length\n,\n",
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