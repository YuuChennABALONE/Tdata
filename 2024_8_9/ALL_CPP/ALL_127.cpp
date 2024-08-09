/* "AMCAX_API static void D1(double u, const Parabola2& parabola, Point2& p, Vector2& v1)\t @param[out] v1 The first derivative\n\t @param[out] p The point\n\t @param[in] parabola The parabola\n\t @param[in] u The parameter\n\t @brief Compute the point and the first derivative on a 2D parabola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D1() ellipse3 [8/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir); 
	Ellipse3 ellipse3(defaultFrame3, 5.0, 3.0);
	Point3 p;
	Vector3 v;
	MakeEdge edge = MakeEdge(ellipse3);
	bool bWriteresult = OCCTIO::OCCTTool::Write(edge, OUTPUT_PATH_PREFIX"ellipse3CurveCalculation_case1.brep", true, 3);
	SECTION("u = M_PI_2") {
		CurveCalculation::D1(M_PI_2, ellipse3,p,v);
		CHECK(p.X() == Approx(0.0).margin(1e-12));
		CHECK(p.Y() == 3.0);
		CHECK(p.Z() == 0.0);
		CHECK(v.X() == Approx(-5.0));
		CHECK(v.Y() == Approx(0.0).margin(1e-14));
		CHECK(v.Z() == Approx(0.0));
	}
}