/* "[[nodiscard]] AMCAX_API static Vector3 D2(double u, const Parabola3& parabola)\t @return The second derivative vector\n\t @param parabola The parabola\n\t @param u The parameter\n\t @brief Compute the second derivative on a 3D parabola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() parabola2 [19/20] ", "[math][CurveCalculation][P1][D2]") {
	Point3 point3(0.0, 0.0, 0.0);
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 fram3(point3, dir3);
	double focal = 2.0;
	Parabola3 parabola3(fram3, focal);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::D2(0.0, parabola3);
		CHECK(vector3.X() == 0.25);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == 0.0);
	}}