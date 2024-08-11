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
TEST_CASE("case1: CurveCalculation::D1() Hyperbola3 [11/20] ", "[math][CurveCalculation][P1][D1]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	Vector3 vector3 = CurveCalculation::D1(0.0, hyperbola3); 
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 3.0);
	CHECK(vector3.Z() == 0.0);
}