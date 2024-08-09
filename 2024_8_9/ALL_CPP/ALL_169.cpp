/* "AMCAX_API static void CircleD1(double u, const Frame3& pos, double radius, Point3& p, Vector3& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] radius The radius\n\t @param[in] pos The local frame where the circle lies\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 3D circle represented by a local frame and a radius at a parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD1 4/4 ", "[math][CurveCalculation][P1][CircleD1]") {
	Direction3 initialDir(0.0, 0.0,1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0,0.0), initialDir);
	double radius = 2.0;
	Point3 p;
	Vector3 v;
	SECTION("0 deg case") {
		AMCAX::CurveCalculation::CircleD1(0.0, defaultFrame3, radius, p, v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
		CHECK(v.Z() == Approx(0.0));
	}}