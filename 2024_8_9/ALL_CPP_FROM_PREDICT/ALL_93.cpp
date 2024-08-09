 #include <catch.hpp>
#include <testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/MakeEdge2d.hpp>
#include <geometry/Polygon2.hpp>
#include <sstream>
using namespace AMCAX;
TEST_CASE("case1: Polygon2", "[geometry][Polygon2][p1]") {
	std::vector<Point2> v;
	v.push_back(Point2(0.0, 0.0));
	v.push_back(Point2(1.0, 1.0));
	v.push_back(Point2(2.0, 0.0));
	v.push_back(Point2(3.0, 1.0));
	v.push_back(Point2(4.0, 0.0));
	Polygon2 polygon(v);
	SECTION("Area") {
		CHECK(polygon.Area() == Approx(8.0));
	}
	}