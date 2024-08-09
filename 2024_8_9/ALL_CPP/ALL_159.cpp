/* "AMCAX_API static void CircleD3(double u, const Frame2& pos, double radius, Point2& p, Vector2& v1, Vector2& v2, Vector2& v3)\t @param[out] v3 The third derivative\n\t @param[out] v2 The second derivative\n\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] radius The radius\n\t @param[in] pos The local frame where the circle lies\n\t @param[in] u The parameter\n\t @brief Compute the point and the first three derivatives on a 2D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD3 1/4 ", "[math][CurveCalculation][P1][CircleD3]") {
	Direction2 defaultDir2(1.0, 0.0);
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDir2);
	double radius = 2.0;
	Vector2 tangentAt0 = AMCAX::CurveCalculation::CircleD3(0.0, defaultFrame2, radius);
	Vector2 tangentAt180 = AMCAX::CurveCalculation::CircleD3(M_PI, defaultFrame2, radius);
	Vector2 tangentAt360 = AMCAX::CurveCalculation::CircleD3(2 * M_PI, defaultFrame2, radius);
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == -2.0);
	CHECK(tangentAt180.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180.Y() == 2.0 );
	CHECK(tangentAt360.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360.Y() == -2.0 );
}