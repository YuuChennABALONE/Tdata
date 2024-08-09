/* "[[nodiscard]] AMCAX_API static Point3 D0(double u, const Line3& line)\t @return The resulting point\n\t @param line The line\n\t @param u The parameter\n\t @brief Compute the point on a 3D line at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [6/10] ", "[math][CurveCalculation][P1][D0]") {
	Frame3 fram3;
	double major_radius = 1000.0;
	double minor_radius = 10.0;
	Hyperbola3 hyperbola(fram3, major_radius, minor_radius);
	Point3 point3 = CurveCalculation::D0(0.0, hyperbola);
	CHECK(point3.X() == 1000.0);
	CHECK(point3.Y() == 0.0);
	CHECK(point3.Z() == 0.0);
}