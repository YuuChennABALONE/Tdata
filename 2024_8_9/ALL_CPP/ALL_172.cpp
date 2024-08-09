/* "[[nodiscard]] AMCAX_API static Point3 CircleD0(double u, const Frame3& pos, double radius)\t @return The point\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the point on a 3D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD0 2/2 ", "[math][CurveCalculation][P1]") {
	Direction3 defaultDirection(-1.0, 0.0,0.0); 
	Frame3 defaultFrame3(Point3(1.0, 0.0,0.0), defaultDirection);
	double 	r = 3.0;
	double u = 2 * M_PI / 4; 
	Point3  pointOnCirecle = CurveCalculation::CircleD0(u, defaultFrame3, r);
	std::cout << pointOnCirecle.X() << " " << pointOnCirecle.Y() << " " << pointOnCirecle.Y() << std::endl;
	CHECK(pointOnCirecle.X() == Approx(1.0).epsilon(1e-12));
	CHECK(pointOnCirecle.Y() == -3.0);
	CHECK((pointOnCirecle.X() - 1.0) * (pointOnCirecle.X() - 1.0) + pointOnCirecle.Y() * pointOnCirecle.Y() == r * r);
}