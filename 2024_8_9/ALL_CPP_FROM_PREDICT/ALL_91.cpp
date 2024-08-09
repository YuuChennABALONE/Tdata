 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation 1/2 ", "[math][CurveCalculation][CircleCalculation][P1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	double radius = 2.0; 
	AMCAX::Circle2 circle2(defaultFrame2, radius);
	OCCTIO::OCCTTool::Write(circle2, OUTPUT_PATH_PREFIX"Circle2 initial.brep");
	SECTION("Vertices") {
		std::vector<Point2> expectedV = { Point2(1.0, 1.0), Point2(3.0, 1.0), Point2(2.0, 2.0) };
		CHECK(circle2.Vertices().size() == 3);
		for (int i = 0; i < circle2.Vertices().size(); i++) {
			CHECK(circle2.Vertices().at(i).X() == Approx(expectedV[i].X()));
			CHECK(circle2.Vertices().at(i).Y() == Approx(expectedV[i].Y()));
		}
	}}