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
TEST_CASE("case1: CurveCalculation::LineD2() [1/2] ", "[math][CurveCalculation][P1][LineD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double lineLength = 6.0;
	Vector3 endDir(0.0, 0.0, 1.0); 
	Vector3 startDir(0.0, 0.0, 1.0);
	double a = lineLength / 2.0;
	double b = sqrt(a * a - 1.0);
	Vector3 lineDirection = startDir - endDir;
	Vector3 lineVector(lineDirection.X() / lineLength, lineDirection.Y() / lineLength, lineDirection.Z() / lineLength);
	Axis3 axis3(defaultFrame3); 
	double tol = 0.1;
	SECTION("u =0") {
		Vector3 vector3 = CurveCalculation::LineD2(0.0, axis3);
		CHECK(vector3.X() == 0.0);
		CHECK(vector3.Y() == 0.0);
		CHECK(vector3.Z() == -1.0);
	}}