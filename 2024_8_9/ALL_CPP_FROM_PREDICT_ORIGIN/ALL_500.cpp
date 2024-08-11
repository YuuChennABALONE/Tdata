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
TEST_CASE("case1: CurveCalculation::ComputeParameterInSegment() ", "[math][CurveCalculation][P1][ComputeParameterInSegment]") {
	AMCAX::Point2 P1(0.0, 0.0);
	AMCAX::Direction2 D1(1.0, 0.0);
	AMCAX::Axis2  axis2(P1, D1);
	float radius = 2.0f;
	AMCAX::Circle2 circle2(axis2, radius, AMCAX::CSYS::StateType::Fixed);
	float t1 = M_PI_2;
	float t2 = M_PI;
	float t3 = M_PI_2 + 0.1;
	float t4 = M_PI_2 - 0.1;
	float para1 = CurveCalculation::ComputeParameterInSegment(circle2, t1, t2, true);
	float para2 = CurveCalculation::ComputeParameterInSegment(circle2, t3, t4, true);
	CHECK(para1 > t1);
	CHECK(para1 < t2);
	CHECK(para2 > t3);
	CHECK(para2 < t4);
}