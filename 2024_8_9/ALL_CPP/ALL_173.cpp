/* "[[nodiscard]] AMCAX_API static Point2 CircleValue(double u, const Frame2& pos, double radius)\t @return The point\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the point on a 2D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleValue()[1 / 2] ", "[math][CurveCalculation][P1][CircleValue]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	Point2 point2 = AMCAX::CurveCalculation::CircleValue(0.0, defaultFrame2, 3.0);
	CHECK(point2.X() == 4.0);
	CHECK(point2.Y() == 1.0);
}