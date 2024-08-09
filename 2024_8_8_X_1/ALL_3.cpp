/* "[[nodiscard]] LineS Rotated(const Axis3& axis, double angle)\t @return The rotated line\n\t @param angle The rotation angle\n\t @param axis The rotation axis\n\t @brief Get the line rotated around an axis with an angle in 3D\n,\n",
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
	SECTION("Rotate")
	{
		Axis3 axis(Point3(0., 0., 0.), Direction3(0., 1., 0.));
		Line3 line(Point3(0., 0., 0.), Direction3(1., 1., -1.));
		Line3 rotateLine = line.Rotated(axis, 90. * ONE_RADIAN);  
		TopoEdge edge1 = MakeEdge(line);
		TopoEdge edge2 = MakeEdge(rotateLine);
		TopoEdge edge3 = MakeEdge(Line3(axis));
		bool isWriteSuccess1 = AMCAX::OCCTIO::OCCTTool::Write(edge1, OUTPUT_PATH_PREFIX"Line3_Rotate_line.brep");
		bool isWriteSuccess2 = AMCAX::OCCTIO::OCCTTool::Write(edge2, OUTPUT_PATH_PREFIX"Line3_Rotate_lineRotate.brep");
		bool isWriteSuccess3 = AMCAX::OCCTIO::OCCTTool::Write(edge3, OUTPUT_PATH_PREFIX"Line3_Rotate_axis.brep");
		REQUIRE(isWriteSuccess1);
		REQUIRE(isWriteSuccess2);
		REQUIRE(isWriteSuccess3);
		auto pointToPoint = [](const Point3& p1, const Point3& p2) {
			return std::sqrt(
				SQUARE(p1.X() - p2.X()) +
				SQUARE(p1.Y() - p2.Y()) +
				SQUARE(p1.Z() - p2.Z())
			);
		};
		CHECK(line.Distance(Line3(axis)) == Approx(rotateLine.Distance(Line3(axis))).margin(std::numeric_limits<double>::min()));
		CHECK(pointToPoint(line.Location(), Point3()) == Approx(pointToPoint(rotateLine.Location(), Point3())).margin(std::numeric_limits<double>::min()));
		Point3 p(-1., 1., -1.);
		CHECK(rotateLine.Contains(p, 1e-6) == true);
	}
}