/* "[[nodiscard]] AMCAX_API static Point3 D0(double u, const Circle3& circle)\t @return The resulting point\n\t @param circle The circle\n\t @param u The parameter\n\t @brief Compute the point on a 3D circle at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [2/10] ", "[math][CurveCalculation][P1][D0]") {
	AMCAX::Circle3 circle3D;
	AMCAX::Point3  center3D(1.0, 1.0, 1.0);
	double radius3D = 5.0;
	double tol = 0.1;
	circle3D.SetLocation(center3D);
	circle3D.SetRadius(radius3D);
	Point3 point3 = AMCAX::CurveCalculation::D0(M_PI_2, circle3D);
	CHECK(point3.X() == Approx(1.0));
	CHECK(point3.Y() == 6.0);
	CHECK(point3.Z() == 1.0);
}