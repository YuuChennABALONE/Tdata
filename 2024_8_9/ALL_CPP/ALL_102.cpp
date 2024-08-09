/* "[[nodiscard]] AMCAX_API static Vector3 D3(double u, const Circle3& circle)\t @return The third derivative vector\n\t @param circle The circle\n\t @param u The parameter\n\t @brief Compute the third derivative on a 3D circle at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D3() circle3[3/20] ", "[math][CurveCalculation][P1][D3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 0.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::D3(0.0, circle3);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == -2.0);
		CHECK(vector3.Z() == 0.0);
	}}