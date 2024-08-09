/* "AMCAX_API static void D1(double u, const Circle2& circle, Point2& p, Vector2& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] circle The circle\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 2D circle at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D1() circle2[1/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
    double radius = 2.0;
    AMCAX::Circle2 circle2(defaultFrame2,radius);
	SECTION("u = M_PI") {
		Vector2 vector2 = CurveCalculation::D1(M_PI, circle2);
		CHECK(vector2.X() == Approx(-0.0).margin(1e-12));
		CHECK(vector2.Y() == -2.0);
	}
}