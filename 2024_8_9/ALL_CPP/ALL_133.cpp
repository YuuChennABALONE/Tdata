/* "AMCAX_API static void D1(double u, const Line2& line, Point2& p, Vector2& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] line The line\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 2D line at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::D1() circle2[2/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	Point2 p;
	Vector2 v;
	SECTION("u =0") {
		CurveCalculation::D1(0.0, circle2,p,v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
	}}