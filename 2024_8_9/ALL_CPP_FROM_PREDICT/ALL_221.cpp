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
TEST_CASE("case1: CurveCalculation::Parameter() [4/10] ", "[math][CurveCalculation][P1][Parameter]") {
	AMCAX::Ellipse2 ellipse2(AMCAX::Axis2(AMCAX::Point2(0.0, 0.0), AMCAX::Direction2(1.0, 0.0)), 5.0, 3.0);
	double t1 = AMCAX::CurveCalculation::Parameter(ellipse2, AMCAX::Point2(0.0, 3.0));
	std::cout << "t1: " << t1 << std::endl;
	CHECK(t1 == M_PI_2);
}