/* "[[nodiscard]] bool Contains(const PointT<double, DIM>& p, double tol)\t @return True if the point is on the line under the tolerance\n\t @param tol The tolerance\n\t @param p The point\n\t @brief Does the line contain a point under a distance tolerance\n,\n",
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
	SECTION("Contains")
	{
		Line3 line(Point3(), Direction3(1., 1., 1.));
		Point3 point1(2., 2., 2.);
		Point3 point2(2., 1., 2.);
		auto isContains = [](const Line3& line, const Point3& point) {
			Direction3 dir(line.Location().X() - point.X(), line.Location().Y() - point.Y(), line.Location().Z() - point.Z());
			return line.Direction().IsParallel(dir, 1e-5);
		};
		CHECK(line.Contains(point1, 1e-5) == isContains(line, point1));
		CHECK(line.Contains(point2, 1e-5) == isContains(line, point2));
	}}