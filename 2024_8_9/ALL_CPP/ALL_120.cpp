/* "[[nodiscard]] AMCAX_API static Vector3 D2(double u, const Ellipse3& ellipse)\t @return The second derivative vector\n\t @param ellipse The ellipse\n\t @param u The parameter\n\t @brief Compute the second derivative on a 3D ellipse at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() ellipse3[7/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir); 
	Ellipse3 ellipse3(defaultFrame3, 5.0, 3.0);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::D2(0.0, ellipse3);
		CHECK(vector3.X() == Approx(-5.0));
		CHECK(vector3.Y() == Approx(0.0));
		CHECK(vector3.Z() == Approx(0.0));
	}}