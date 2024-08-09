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
TEST_CASE("case1: CurveCalculation::LineD1() [4/10] ", "[math][CurveCalculation][P1][LineD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
    double radius = 0.0;
    AMCAX::Line3 line3 = AMCAX::Line3(defaultFrame3, radius);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::LineD1(0.0, line3);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == 1.0);
	}}