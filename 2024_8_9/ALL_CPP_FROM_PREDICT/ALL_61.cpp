 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/PlaneD1.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: PlaneD1 3D [1/2] ", "[math][PlaneD1][P1]") {
	Frame3 frame;
	double u = 0.0;
	double v = 0.0;
	PlaneD1 plane(frame, u, v);
	SECTION("du dv") {
		double du = plane.Du();
		double dv = plane.Dv();
		std::cout << "du=" << du << ", dv=" << dv << "
";
		CHECK(du == Approx(0.0));
		CHECK(dv == Approx(1.0));
	}}