/* "AMCAX_API static void D1(double u, const Hyperbola3& hyperbola, Point3& p, Vector3& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] hyperbola The hyperbola\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 3D hyperbola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D1() Hyperbola3 [12/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	Point3 p;
	Vector3 v;
	CurveCalculation::D1(0.0, hyperbola3,p,v); 
	CHECK(p.X() == 5.0);
	CHECK(p.Y() == 0.0);
	CHECK(p.Z() == 0.0);
	CHECK(v.X() == 0.0);
	CHECK(v.Y() == 3.0);
	CHECK(v.Z() == 0.0);
}