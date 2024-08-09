/* "[[nodiscard]] Derived Translated(const VectorT<double, DIM>& vec)\t @return The translated line\n\t @param vec The translation vector\n\t @brief Get the line translated by a vector\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <math/Plane.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
using AMCAX::Line3;
using AMCAX::MakeEdge;
using AMCAX::MakeFace;
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
TEST_CASE("case2: Line3 base method Test", "[math][Line3][p1]")
{
	SECTION("Translate")
	{
		Line3 line(Point3(), Direction3(1., 1., 1.));
		Line3 originalLine(Point3(), Direction3(1., 1., 1.));
		line.Translate(Point3(), Point3(0., 1., 0.));
		CHECK(originalLine.Direction().IsEqual(line.Direction(), 1e-6 * ONE_RADIAN));
		CHECK(line.Contains(Point3(0., 1., 0.), 1e-6));
		Line3 line2 = line.Translated(Vector3(Direction3(1., -1., 1.)));
		CHECK(line.Direction().IsEqual(line2.Direction(), 1e-6 * ONE_RADIAN));
		CHECK(line2.Contains(Point3(0. + 1. / std::sqrt(3.), 1 - 1. / std::sqrt(3.), 0. + 1. / std::sqrt(3.)), 1e-6));
	}
}