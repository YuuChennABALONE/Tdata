/* "[[nodiscard]] AMCAX_API static Point2 D0(double u, const Line2& line)\t @return The resulting point\n\t @param line The line\n\t @param u The parameter\n\t @brief Compute the point on a 2D line at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [1/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	float radius = 2.0f;
	AMCAX::Circle2 circle2(axis2, radius, true);
	Point2 point2 = AMCAX::CurveCalculation::D0(0.0, circle2);
	CHECK(point2.X() == 2.0);
	CHECK(point2.Y() == 0.0);
}