/* "[[nodiscard]] AMCAX_API static Vector3 D2(double u, const Line3& line)\t @return The second derivative vector\n\t @param line The line\n\t @param u The parameter\n\t @brief Compute the second derivative on a 3D line at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D2() circle3[3/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 0.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Circle3 circle3(defaultFrame3, radius);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::D2(0.0, circle3);
		CHECK(vector3.X() == -2.0 );
		CHECK(vector3.Y() == 0.0 );
	}}