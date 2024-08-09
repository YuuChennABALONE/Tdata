/* "[[nodiscard]] AMCAX_API static Vector2 D1(double u, const Circle2& circle)\t @return The first derivative vector\n\t @param circle The circle\n\t @param u The parameter\n\t @brief Compute the first derivative on a 2D circle at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD1 1/4 ", "[math][CurveCalculation][P1][CircleD1]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0; 
	Vector2 tangentAt0 = AMCAX::CurveCalculation::CircleD1(0.0, defaultFrame2, radius);
	Vector2 tangentAt90Deg = AMCAX::CurveCalculation::CircleD1(M_PI_2, defaultFrame2, radius);
	Vector2 tangentAt180Deg = AMCAX::CurveCalculation::CircleD1(M_PI, defaultFrame2, radius);
	Vector2 tangentAt270Deg = AMCAX::CurveCalculation::CircleD1(3 * M_PI_2, defaultFrame2, radius);
	Vector2 tangentAt360Deg = AMCAX::CurveCalculation::CircleD1(2 * M_PI, defaultFrame2, radius);
	CHECK(tangentAt0.X() == Approx(-0.0));
	CHECK(tangentAt0.Y() == Approx(2.0));
	CHECK(tangentAt90Deg.X() == Approx(-2.0));
	CHECK(tangentAt90Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.X() == Approx(-0.0).margin(1e-14));
	CHECK(tangentAt180Deg.Y() == Approx(-2.0));
	CHECK(tangentAt270Deg.X() == Approx(2.0));
	CHECK(tangentAt270Deg.Y() == Approx(-0.0).margin(1e-14));
	CHECK(tangentAt360Deg.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360Deg.Y() == Approx(2.0));
	std::cout << "Tangent at 0 deg: " << tangentAt0 << std::endl;
	std::cout << "Tangent at 90 deg: " << tangentAt90Deg << std::endl;
	std::cout << "Tangent at 180 deg: " << tangentAt180Deg << std::endl;
	std::cout << "Tangent at 270 deg: " << tangentAt270Deg << std::endl;
	std::cout << "Tangent at 360 deg: " << tangentAt360Deg << std::endl;
}