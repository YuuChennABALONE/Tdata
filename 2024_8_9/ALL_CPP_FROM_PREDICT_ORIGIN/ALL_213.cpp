 #include<catch.hpp>
#include<testHelper.h>
#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <common/FrameT.hpp>
#include <math/CircleT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeGeom2TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: GccCircle3Tangent 3/27/2019 ", "[math][GccCircle3Tangent][P1]") {
	SECTION("3 points on a line") {
        Point2 point1(0.0, 0.0);
        Point2 point2(1.0, 1.0);
        Point2 point3(2.0, 2.1);
        Circle2 circle2(point1, point2, point3);
        double radius = Approx(circle2.Radius());
        CHECK(radius.isApprox(0.0, 1e-6 * 0.01));
    }}