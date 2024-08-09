/* "AMCAX_API static void D2(double u, const Parabola2& parabola, Point2& p, Vector2& v1, Vector2& v2)\t @param[out] v2 The second derivative\n\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] parabola The parabola\n\t @param[in] u The parameter\n\t @brief Compute the point and the first two derivatives on a 2D parabola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() parabola2 [18/20] ", "[math][CurveCalculation][P1][D2][kk]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0); 
	AMCAX::Axis2  axis2(P, D);
	double focal = 2.0;
	AMCAX::Parabola2 parabola2(axis2, focal);
	Point2 p;
	Vector2 v1,v2;
	SECTION("u =0") {
		CurveCalculation::D2(0.0, parabola2, p, v1,v2);
		CHECK(p.X() == 0.0);
		CHECK(p.Y() == 0.0);
		CHECK(v1.X() == 0.0);
		CHECK(v1.Y() == 1.0);
	}}