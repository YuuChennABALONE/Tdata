/* "AMCAX_API static void D2(double u, const Ellipse3& ellipse, Point3& p, Vector3& v1, Vector3& v2)\t @param[out] v2 The second derivative\n\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] ellipse The ellipse\n\t @param[in] u The parameter\n\t @brief Compute the point and the first two derivatives on a 3D ellipse at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() circle3[4/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	Point3 p;
	Vector3 v1, v2;
	SECTION("u =0") {
		CurveCalculation::D2(0.0, circle3, p, v1,v2);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(v1.X() == Approx(0.0));
		CHECK(v1.Y() == Approx(2.0));
		CHECK(v1.Z() == Approx(0.0));
		CHECK(v2.X() == Approx(-2.0));
		CHECK(v2.Y() == Approx(0.0));
		CHECK(v2.Z() == Approx(0.0));
	}}