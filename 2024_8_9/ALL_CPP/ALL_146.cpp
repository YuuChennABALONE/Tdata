/* "[[nodiscard]] AMCAX_API static Point2 D0(double u, const Parabola2& parabola)\t @return The resulting point\n\t @param parabola The parabola\n\t @param u The parameter\n\t @brief Compute the point on a 2D parabola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [9/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	double focal = 2.0;
	AMCAX::Parabola2 parabola2(axis2,focal );
	SECTION("u =0") {  
		Point2 point2 = CurveCalculation::D0(0.0, parabola2); 
		CHECK(point2.X() == 0.0);
		CHECK(point2.Y() == 0.0);
	}}