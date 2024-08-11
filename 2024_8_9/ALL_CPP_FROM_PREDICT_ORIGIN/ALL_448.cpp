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
TEST_CASE("case1: CurveCalculation::D2() parabola3[2/20] ", "[math][CurveCalculation][P1][D2]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir);
	double focal = 2.0;
	Parabola3 parabola3(defaultFrame3, focal);
	MakeEdge edge = MakeEdge(parabola3);
	bool bWriteresult = OCCTIO::OCCTTool::Write(edge, OUTPUT_PATH_PREFIX"Parabola3CurveCalculation_case1.brep", true, 3);
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::D2(0.0, parabola3);
		CHECK(vector3.X() == Approx(0.0));
		CHECK(vector3.Y() == Approx(2.0));
		CHECK(vector3.Z() == Approx(0.0));
	}}