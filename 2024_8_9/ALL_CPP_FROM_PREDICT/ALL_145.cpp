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
TEST_CASE("case1: CurveCalculation::HyperbolaD3 1/4 ", "[math][CurveCalculation][P1][HyperbolaD3]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 frame3(Point3(0.0, 0.0, 0.0), dir3);
	double major3 = 3.0, minor3 = 4.0;
	double u = 0.0;
	Vector3 vector3 = CurveCalculation::HyperbolaD3(u, frame3, major3, minor3);
	Vector3 vector31(0.0, 0.0, 1.0);
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector3.Z() == 1.0);
	CHECK(vector3.Dot(vector31) == Approx(1.0).margin(1e-12));
}