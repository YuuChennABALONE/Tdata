/* "[[nodiscard]] AMCAX_API static Vector3 D2(double u, const Hyperbola3& hyperbola)\t @return The second derivative vector\n\t @param hyperbola The hyperbola\n\t @param u The parameter\n\t @brief Compute the second derivative on a 3D hyperbola at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() hyperbola3[11/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	Vector3 vector3 = CurveCalculation::D2(0.0, hyperbola3); 
	CHECK(vector3.X() == 5.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector3.Z() == 0.0);
}