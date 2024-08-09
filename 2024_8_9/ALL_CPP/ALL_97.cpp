/* "[[nodiscard]] AMCAX_API static Vector2 D3(double u, const Circle2& circle)\t @return The third derivative vector\n\t @param circle The circle\n\t @param u The parameter\n\t @brief Compute the third derivative on a 2D circle at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D3() circle2[1/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	SECTION("u =0") {
		Vector2 vector2 = CurveCalculation::D3(0.0, circle2);
		CHECK(vector2.X() == 0.0);
		CHECK(vector2.Y() == -2.0);
	}}