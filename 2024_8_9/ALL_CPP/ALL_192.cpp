/* "void SetLocation(const PointT<double, DIM>& point)\t @param point The location point\n\t @brief Set the location of the line\n,\n",
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
	SECTION("SetLocation")
	{
		Line3 line(Point3(2., 3., 2.), Direction3(2., 3.4, -2.));
		line.SetLocation(Point3(1., -2., 8.));
		CHECK(line.Location().IsEqual(Point3(1., -2., 8.), std::numeric_limits<double>::min()));
	}}