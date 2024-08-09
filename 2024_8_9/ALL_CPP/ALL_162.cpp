/* "[[nodiscard]] AMCAX_API static Vector3 CircleD3(double u, const Frame3& pos, double radius)\t @return The third derivative vector\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the third derivative on a 3D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD3 3/4 ", "[math][CurveCalculation][P1][CircleD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	Vector3 tangentAt0 = AMCAX::CurveCalculation::CircleD3(0.0, defaultFrame3, radius);
	Vector3 tangentAt90Deg = AMCAX::CurveCalculation::CircleD3(M_PI_2, defaultFrame3, radius);
	Vector3 tangentAt180Deg = AMCAX::CurveCalculation::CircleD3(M_PI, defaultFrame3, radius);
	Vector3 tangentAt270Deg = AMCAX::CurveCalculation::CircleD3(3 * M_PI_2, defaultFrame3, radius);
	Vector3 tangentAt360Deg = AMCAX::CurveCalculation::CircleD3(2 * M_PI, defaultFrame3, radius);
	CHECK(tangentAt0.X() == Approx(0.0));
	CHECK(tangentAt0.Y() == Approx(-2.0));
	CHECK(tangentAt0.Z() == Approx(-0.0));
	CHECK(tangentAt90Deg.X() == Approx(2.0).margin(1e-14));
	CHECK(tangentAt90Deg.Y() == Approx(-0.0).margin(1e-14));
	CHECK(tangentAt90Deg.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.X() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt180Deg.Y() == Approx(2.0).margin(1e-14));
	CHECK(tangentAt180Deg.Z() == Approx(0.0));
	CHECK(tangentAt270Deg.X() == Approx(-2.0).margin(1e-14));
	CHECK(tangentAt270Deg.Y() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt270Deg.Z() == Approx(0.0).margin(1e-14));
	CHECK(tangentAt360Deg.X() == Approx(-0.0).margin(1e-14));
	CHECK(tangentAt360Deg.Y() == Approx(-2.0).margin(1e-14));
	CHECK(tangentAt360Deg.Z() == Approx(0.0).margin(1e-14));
	std::cout << "Tangent at 0 deg: " << tangentAt0 << std::endl;
	std::cout << "Tangent at 90 deg: " << tangentAt90Deg << std::endl;
	std::cout << "Tangent at 180 deg: " << tangentAt180Deg << std::endl;
	std::cout << "Tangent at 270 deg: " << tangentAt270Deg << std::endl;
	std::cout << "Tangent at 360 deg: " << tangentAt360Deg << std::endl;
}