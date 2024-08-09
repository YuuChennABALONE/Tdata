/* "[[nodiscard]] const PointT<double, DIM>& Location()\t @return The location of the line\n\t @brief Get the location point of the line\n,\n",
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
TEST_CASE("case1: Derived class interface unit testing", "[math][Line3][p1]")
{
	SECTION("constructor")
	{
		Line3 line;  
		CHECK(line.Location().IsEqual(Point3(0., 0., 0.), 1e-5));
		CHECK(line.Direction().IsEqual(Direction3(0., 0., 1.), 1e-5 * ONE_RADIAN));
		Axis3 axis(Point3(1., 1., 1.), Direction3(3., 3., 4.));
		Line3 line2(axis);
		CHECK(line2.Position().IsCoaxial(axis, 1e-5 * ONE_RADIAN, 1e-5));  
		Line3 line3(Point3(1., 2., 3.), Direction3(3., 2., 1.));
		CHECK(line3.Location().IsEqual(Point3(1., 2., 3.), 1e-5));
		CHECK(line3.Direction().IsEqual(Direction3(3., 2., 1.), 1e-5 * ONE_RADIAN));
	}}