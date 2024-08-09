/* "[[nodiscard]] const PointT<double, DIM>& Location()\t @return The location of the line\n\t @brief Get the location point of the line\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Parameterless constructor test")
	{
		Line2 line;  
		CHECK(line.Location().IsEqual(Axis2().Location(), 0.001));
		CHECK(line.Direction().IsEqual(Axis2().Direction(), 1e-5 * ONE_RADIAN));
	}}