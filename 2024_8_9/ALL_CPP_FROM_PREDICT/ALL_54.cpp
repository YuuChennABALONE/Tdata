 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/PlaneParameter.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: PlaneParameter(p, pos) [2/2] ", "[math][PlaneParameter][P1][1/2]") {
	Frame3 frame;
	double a = 5.0;
	double b = 4.0;
	Plane3 plane(frame);
	SECTION("Point3(0.0, 0.0, 0.0) [2/2]") {
		Point3 point(0.0, 0.0, 0.0);
		double u,v;
		auto status = PlaneParameter::PlaneParameter(point, plane, u, v);
		CHECK(u == 0.0);
		CHECK(v == 0.0);
	}
}