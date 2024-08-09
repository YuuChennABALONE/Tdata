/* "AMCAX_API static void D2(double u, const Ellipse2& ellipse, Point2& p, Vector2& v1, Vector2& v2)\t @param[out] v2 The second derivative\n\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] ellipse The ellipse\n\t @param[in] u The parameter\n\t @brief Compute the point and the first two derivatives on a 2D ellipse at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() circle2[2/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	Point2 p;
	Vector2 v1,v2;
	SECTION("u =0") {
		CurveCalculation::D2(0.0, circle2, p, v1,v2);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(v1.X() == 0.0);
		CHECK(v1.Y() == 2.0);
		CHECK(v2.X() == -2.0);
		CHECK(v2.Y() == 0.0);
	}}