/* "[[nodiscard]] AMCAX_API static Point3 D0(double u, const Ellipse3& ellipse)\t @return The resulting point\n\t @param ellipse The ellipse\n\t @param u The parameter\n\t @brief Compute the point on a 3D ellipse at a parameter\n,\n",
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
TEST_CASE("case1: CurveCalculation::D0() [4/10] ", "[math][CurveCalculation][P1][D0]") {
	Frame3 fram3 = Frame3(Point3(0.0, 0.0, 1.0), Direction3(0.0, 0.0, 1.0));
	AMCAX::Ellipse3 ellipse3(fram3, 5.0, 3.0);
	Point3 point3 = AMCAX::CurveCalculation::D0(M_PI_2, ellipse3);
	CHECK(point3.X() == Approx(0.0).margin(1e-12));
	CHECK(point3.Y() == 3.0);
	CHECK(point3.Z() == 1.0);
}