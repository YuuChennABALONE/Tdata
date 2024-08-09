/* "[[nodiscard]] AMCAX_API static Vector3 CircleDN(double u, const Frame3& pos, double radius, int n)\t @return The n-th derivative vector\n\t @param n The order of derivative\n\t @param radius The radius\n\t @param pos The local frame where the circle lies\n\t @param u The parameter\n\t @brief Compute the n-th derivative on a 3D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleDN 2/2 ", "[math][CurveCalculation][P1][CircleDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double u = 0.0;
	SECTION("2 derivative vector") {
		Vector3  vector3 = CurveCalculation::CircleDN(u, defaultFrame3, radius, 2); 
		std::cout << vector3.X() << " " << vector3.Y() << " " << std::endl;
		CHECK(vector3.X() == -2.0);
		CHECK(vector3.Y() == Approx(0.0).margin(1e-14));
	}}