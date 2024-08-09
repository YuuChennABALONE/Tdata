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
TEST_CASE("case1: CurveCalculation::LineD3 1/4 ", "[math][CurveCalculation][P1][LineD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double lineRadius = 5.0; 
	Vector3 start(1.0, 1.0, 0.0);
	Vector3 end(6.0, 6.0, 0.0);
	Axis3 axis3(defaultFrame3);
	double lineLength = 5.0;
	Vector3 startVector = axis3.Location().X() + lineRadius;
	Vector3 startVector2 = axis3.Location().Y() + lineRadius;
	Vector3 endVector = axis3.Location().X() - lineRadius;
	Vector3 endVector2 = axis3.Location().Y() - lineRadius;
	Vector3 vector1 = (endVector - startVector);
	Vector3 vector2 = (endVector2 - startVector2);
	Line3 line3(axis3); 
	SECTION("u =0") { 
		Vector3 vector = CurveCalculation::LineD3(0.0, axis3); 
		CHECK(vector.X() == 0.0);
		CHECK(vector.Y() == 0.0);
		CHECK(vector.Z() == 0.0);
	}}