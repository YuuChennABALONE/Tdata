/* "AMCAX_API static void D1(double u, const Circle3& circle, Point3& p, Vector3& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] circle The circle\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 3D circle at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D1() circle3[4/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	Point3 p;
	Vector3 v;
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("u =0") {
		CurveCalculation::D1(0.0, circle3,p,v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
		CHECK(v.Z() == Approx(0.0));
	}}