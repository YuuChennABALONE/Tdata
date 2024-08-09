/* "[[nodiscard]] LineS Rotated(const Point2& point, double angle)\t @return The rotated line\n\t @param angle The rotation angle\n\t @param point The rotation center point\n\t @brief Get the line rotated around a point with an angle in 2D\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Rotated Test")
	{
		Line2 line(Point2(0., 1.), Direction2(1., 1.));  
		Line2 rotateLine = line.Rotated(Point2(), (3. / 4) * M_PI);  
		CHECK(rotateLine.Direction().X() == Approx(-1.).margin(1e-5));
		CHECK(rotateLine.Direction().Y() == Approx(0.).margin(1e-5));
		double a, b, c;
		rotateLine.Coefficients(a, b, c);
		CHECK((c - b) == Approx(0.).margin(0.5));
		CHECK(line.Distance(Point2()) == rotateLine.Distance(Point2()));  
		TopoShape lineShape1 = MakeEdge2d(line);
		TopoShape lineShape2 = MakeEdge2d(rotateLine);
		REQUIRE(OCCTIO::OCCTTool::Write(lineShape1, OUTPUT_PATH_PREFIX"Line2_Rotated_before_p1.brep"));
		REQUIRE(OCCTIO::OCCTTool::Write(lineShape2, OUTPUT_PATH_PREFIX"Line2_Rotated_later_p1.brep"));
	}
}