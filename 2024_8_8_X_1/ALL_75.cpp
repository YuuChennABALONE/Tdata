/* "AMCAX_API MakeArcOfCircle2d(const Point2& p1, const Vector2& v, const Point2& p2)\t @param p2 The end point\n\t @param v The tangent vector at p1\n\t @param p1 The start point\n\t @brief Construct an arc of circle from two points p1, p2 and a tangent vector v at p1\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>
using namespace AMCAX;
TEST_CASE("bug1: MakeArcOfCircle2d  add 1 cases", "[geomAlgo][MakeArcOfCircle2d][fixbug]") {
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;
	auto case1 = output.str();
	auto expect1 = "8 4.71239 6.28319";
	auto expect2 = "2 0 -0 1 0 0 -1 1";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);
}