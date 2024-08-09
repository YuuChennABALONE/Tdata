/* "Derived& Translate(const VectorT<double, DIM>& vec)\t @return The reference to self\n\t @param vec The translation vector\n\t @brief Translate the line by a vector\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Translate Test")
	{
		Line2 line;
		line.Translate(Vector2(2., 0.));  
		CHECK(line.Direction().IsEqual(Direction2(), 1e-5 * ONE_RADIAN));
		CHECK(line.Contains(Point2(2., 0.), 1e-5));
		Line2 translateLine = line.Translated(Point2(2., 0.), Point2(-10., 0.));
		CHECK(translateLine.Contains(Point2(-10., 0.), 1e-5));
	}
}