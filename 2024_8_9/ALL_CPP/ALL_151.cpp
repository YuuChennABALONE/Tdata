/* "[[nodiscard]] AMCAX_API static Point3 D0(double u, const Parabola3& parabola)\t @return The resulting point\n\t @param parabola The parabola\n\t @param u The parameter\n\t @brief Compute the point on a 3D parabola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [10/10] ", "[math][CurveCalculation][P1][D0]") {
	Point3 point3(0.0, 0.0, 0.0);
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 fram3(point3, dir3);
	double focal = 2.0;
	Parabola3 parabola3(fram3, focal);
	SECTION("u =0") {
		Point3 point3 = CurveCalculation::D0(0.0, parabola3);
		CHECK(point3.X() == 0.0);
		CHECK(point3.Y() == 0.0);
		CHECK(point3.Z() == 0.0);
	}}