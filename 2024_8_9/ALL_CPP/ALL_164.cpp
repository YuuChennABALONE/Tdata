/* "[[nodiscard]] AMCAX_API static Vector2 CircleD2(double u, const Frame2& pos, double radius)\t @return The second derivative vector\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the second derivative on a 2D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD2 1/4 ", "[math][CurveCalculation][P1][CircleD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 2.0;
	double u = 0.0; 
	Vector2  vector2 = CurveCalculation::CircleD2(u, defaultFrame2, r); 
	std::cout << vector2.X() << " " << vector2.Y() << " " << std::endl;
	CHECK(vector2.X() == -2.0);
	CHECK(vector2.Y() == Approx(0.0).margin(1e-14));
}