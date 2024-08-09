/* "[[nodiscard]] AMCAX_API static Vector2 D1(double u, const Hyperbola2& hyperbola)\t @return The first derivative vector\n\t @param hyperbola The hyperbola\n\t @param u The parameter\n\t @brief Compute the first derivative on a 2D hyperbola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D1() Hyperbola2 [9/20] ", "[math][CurveCalculation][P1][D1]") {
	Axis2 majorAxis;
	double major_radius = 5;
	double minor_radius = 3;
	Hyperbola2 hyperbola2(majorAxis, major_radius, minor_radius); 
	 Vector2 vector2 = CurveCalculation::D1(0.0, hyperbola2); 
	CHECK(vector2.X() == 0.0);
	CHECK(vector2.Y() == 3.0);
}