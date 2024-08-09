/* "[[nodiscard]] auto SquaredDistance(const LineS& l)\t @return The squared distance between two lines\n\t @param l The other line\n\t @brief Compute the squared distance between two lines\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case1: Line basic interface test", "[math][Line2][p1]")
{
	SECTION("Distance and SquaredDistance test")
	{
		auto pointToLine = [](const Point2& point, const Line2& line) {
			double a, b, c;
			line.Coefficients(a, b, c);
			return std::fabs(a * point.X() + b * point.Y() + c);
		};
		auto lineToLine = [](const Line2& line1, const Line2& line2) {
			double a1, b1, c1, a2, b2, c2;
			line1.Coefficients(a1, b1, c1);
			line2.Coefficients(a2, b2, c2);
			if (a1 != a2 || b1 != b2) return 0.;
			return std::fabs(c1 - c2);
		};
		Line2 line(3., 4., -30.);
		Point2 point1(6., 3.);
		Point2 point2(6., 2.);
		Line2 line2(3., 4., -29.);
		Line2 line3(2., 1., -99.);
		CHECK(line.Distance(point1) == Approx(pointToLine(point1, line)).margin(0.01));
		CHECK(line.SquaredDistance(point1) == Approx(pointToLine(point1, line) * pointToLine(point1, line)).margin(0.01));
		CHECK(line.Distance(point2) == Approx(pointToLine(point2, line)));
		CHECK(line.SquaredDistance(point2) == Approx(pointToLine(point2, line) * pointToLine(point2, line)).margin(0.01));
		CHECK(line.Distance(line2) == Approx(lineToLine(line, line2)));
		CHECK(line.SquaredDistance(line2) == Approx(lineToLine(line2, line) * lineToLine(line2, line)).margin(0.01));
		CHECK(line.Distance(line3) == Approx(lineToLine(line, line3)));
		CHECK(line.SquaredDistance(line3) == Approx(lineToLine(line3, line) * lineToLine(line3, line)).margin(0.01));
	}}