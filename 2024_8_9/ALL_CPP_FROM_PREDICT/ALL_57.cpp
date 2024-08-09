 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::PlaneD3 1/4 ", "[math][CurveCalculation][P1][PlaneD3]") {
	Direction3 Z(0.0, 0.0, 1.0);
	Frame3 frame(Point3(1.0, 1.0, 0.0), Z);
	double du3 = AMCAX::CurveCalculation::PlaneD3(0.0, 0.0, frame);
	double dv3 = AMCAX::CurveCalculation::PlaneD3(0.0, 1.0, frame);
	double duv2 = AMCAX::CurveCalculation::PlaneD3(0.5, 0.5, frame);
	CHECK(du3 == 0.0);
	CHECK(dv3 == 0.0);
	CHECK(duv2 == 0.0);
}