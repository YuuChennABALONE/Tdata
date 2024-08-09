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
TEST_CASE("case1: CurveCalculation::Value() [9/10] ", "[math][CurveCalculation][P1][Value]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	Parabola3 parabola3(defaultFrame3,focal);
	SECTION("u =0") {
		Point3 point3 = CurveCalculation::Value(0.0, parabola3);
		CHECK(point3.X() == 1.0);
		CHECK(point3.Y() == 1.0);
		CHECK(point3.Z() == 0.0);
	}
}