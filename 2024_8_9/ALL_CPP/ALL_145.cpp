/* "[[nodiscard]] AMCAX_API static Point2 D0(double u, const Hyperbola2& hyperbola)\t @return The resulting point\n\t @param hyperbola The hyperbola\n\t @param u The parameter\n\t @brief Compute the point on a 2D hyperbola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [5/10] ", "[math][CurveCalculation][P1][D0]") {
	Axis2 majorAxis;
	double major_radius = 5;
	double minor_radius = 3;
	Hyperbola2 hyperbola(majorAxis, major_radius, minor_radius);
	Point2 point2 = CurveCalculation::D0(0.0, hyperbola);
	CHECK(point2.X() == 5.0);
	CHECK(point2.Y() == 0.0);
}