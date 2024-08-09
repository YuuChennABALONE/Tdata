/* "[[nodiscard]] AMCAX_API static Point2 CircleD0(double u, const Frame2& pos, double radius)\t @return The point\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the point on a 2D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD0 1/2 ", "[math][CurveCalculation][P1]") {
	Direction2 defaultDirection(1.0,0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 3.0;
	double u = 4 * M_PI ; 
	Point2  pointOnCirecle = CurveCalculation::CircleD0(u, defaultFrame2, r);
	std::cout << pointOnCirecle.X() << " " << pointOnCirecle.Y() << " "  << std::endl;
	CHECK(pointOnCirecle.X() == 3.0);
	CHECK(pointOnCirecle.Y() == Approx(0.0).margin(1e-14));
	CHECK(pointOnCirecle.X() * pointOnCirecle.X() + pointOnCirecle.Y() * pointOnCirecle.Y() == r * r);
}