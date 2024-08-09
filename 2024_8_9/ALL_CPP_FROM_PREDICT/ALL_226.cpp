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
TEST_CASE("case1: CurveCalculation::Parameter() [1/10] ", "[math][CurveCalculation][P1][Parameter]") {
	AMCAX::Ellipse3 ellipse3(AMCAX::Axis3(AMCAX::Point3(0.0, 0.0, 0.0), AMCAX::Direction3(0.0, 0.0, 1.0)), 5.0, 3.0);
	double t = AMCAX::CurveCalculation::Parameter(ellipse3, AMCAX::Point3(0.0, 3.0, 0.0));
	std::cout << "t: " << t << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	CHECK(t == M_PI_2);
}