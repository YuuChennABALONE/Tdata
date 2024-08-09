/* "[[nodiscard]] auto Distance(const Point3& p)\t @return The distance between the point and the line\n\t @param p The point\n\t @brief Compute the distance from a point to the line\n,\n",
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
	SECTION("Distance and SquaredDistance")
	{
		auto pointToLine = [](const Point3& p, const Line3& line) {
			const Point3& p1 = line.Location();
			double dX = p1.X() - p.X();
			double dY = p1.Y() - p.Y();
			double dZ = p1.Z() - p.Z();
			double pp1Square = SQUARE(dX) + SQUARE(dY) + SQUARE(dZ);
			Direction3 dir(dX, dY, dZ);
			double cos = std::fabs(dir.Dot(line.Direction()));
			return std::sqrt(pp1Square - SQUARE(cos*std::sqrt(pp1Square)));
		};
		auto lineToLine = [&pointToLine](const Line3& line1, const Line3& line2) {
			if (line1.Direction().IsParallel(line2.Direction(), std::numeric_limits<double>::min()))
				return pointToLine(line1.Location(), line2);
			Direction3 line1Dir = line1.Direction();
			Direction3 line2Dir = line2.Direction();
			double x3 = line1Dir.Y() * line2Dir.Z() - line2Dir.Y() * line1Dir.Z();
			double y3 = -(line1Dir.X() * line2Dir.Z() - line2Dir.X() * line1Dir.Z());
			double z3 = line1Dir.X() * line2Dir.Y() - line2Dir.X() * line1Dir.Y();
			Direction3 line3Dir(x3, y3, z3);
			Direction3 line12Dir(line1.Location().X() - line2.Location().X(), 
								 line1.Location().Y() - line2.Location().Y(), line1.Location().Z() - line2.Location().Z());
			return std::fabs(line3Dir.Dot(line12Dir));
		};
		Line3 line(Point3(99., 2., 33.), Direction3(2.3, 4.6, 9.8));
		CHECK(line.Distance(Point3(0., 1., 0.)) == Approx(pointToLine(Point3(0., 1., 0.), line)).margin(1e-5));
		Line3 line2(Point3(0., 0., 0.), Direction3(1., 0., 0.));
		Line3 line3(Point3(0., 1., 0.), Direction3(1., 0., 0.));
		CHECK(line2.Distance(line3) == Approx(lineToLine(line2, line3)).margin(std::numeric_limits<double>::min()));
		CHECK(line2.SquaredDistance(line3) == Approx(SQUARE(lineToLine(line2, line3))).margin(std::numeric_limits<double>::min()));
		Line3 line4(Point3(0., 0., 0.), Direction3(1., 0., 0.));
		Line3 line5(Point3(0., 1., 0.), Direction3(1., 1., 0.));
		CHECK(line4.Distance(line5) == Approx(lineToLine(line4, line5)).margin(std::numeric_limits<double>::min()));
		Line3 line6(Point3(0., 0., 0.), Direction3(0., 0., 1.));
		Line3 line7(Point3(0., 1., 0.), Direction3(1., 1., 0.));
		CHECK(line6.Distance(line7) == Approx(lineToLine(line6, line7)).margin(std::numeric_limits<double>::min()));
	}}