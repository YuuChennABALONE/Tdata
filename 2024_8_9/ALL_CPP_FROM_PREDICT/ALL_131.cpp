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
TEST_CASE("case1: CurveCalculation::Circle2To3D 1/2 ", "[math][CurveCalculation][P1][Circle2To3D]") {
	AMCAX::Ellipse2 ellipse2(AMCAX::Frame2(), 5.0, 3.0);
	AMCAX::Ellipse3 ellipse3 = AMCAX::CurveCalculation::Circle2To3D(ellipse2, AMCAX::Frame3());
	auto[rx, ry, rz] = ellipse3.MajorRadius();
	CHECK(rx == 5.0);
	CHECK(ry == 3.0);
	CHECK(rz == Approx(0.0).margin(1e-14));
}