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
TEST_CASE("case1: CurveCalculation::DN() ellipse3[3/20] ", "[math][CurveCalculation][P1][DN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir); 
	Ellipse3 ellipse3(defaultFrame3, 5.0, 3.0);
	MakeEdge edge= MakeEdge(ellipse3);
	bool bWriteresult = OCCTIO::OCCTTool::Write(edge, OUTPUT_PATH_PREFIX"ellipse3CurveCalculation_case1.brep", true, 3);
	SECTION("n == 2") {
		Vector3 vector3 = CurveCalculation::DN(0.0, ellipse3, 2);
		CHECK(vector3.X() == Approx(-5.0));
		CHECK(vector3.Y() == Approx(0.0));
		CHECK(vector3.Z() == Approx(0.0));
	}}