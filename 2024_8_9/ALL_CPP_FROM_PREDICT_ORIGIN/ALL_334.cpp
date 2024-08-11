 #include <catch.hpp>
#include <testHelper.h>
#include <common/DirectionT.hpp>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/EllipseT.hpp>
#include <occtio/OCCTTool.hpp>
#include <common/VectorT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Scale method(Ellipse2)", "[math][Ellipse2][p1]") {
	Point2 point2_H(0.0, 0.0);
	Direction2 dir2_H(1.0, 0.0);
	Axis2 major2_A(point2_H, dir2_H);
	double major2 = 5.0, minor2 = 4.0;
	Ellipse2 ellipse2d_m(major2_A, major2, minor2, true);
	SECTION("Scale") {
		Point2 point2(1.0, 1.0);
		Ellipse2 ellipse2d_s = ellipse2d_m.Scale(point2, 0.5);
		CHECK(ellipse2d_s.Location().X() == Approx(0.3125));
		CHECK(ellipse2d_s.Location().Y() == Approx(0.3125));
	MakeEdge2d edge1(ellipse2d_m);
	MakeEdge2d edge2(ellipse2d_s);
	bool bWriteresult1 = OCCTIO::OCCTTool::Write(edge1, OUTPUT_PATH_PREFIX"Ellipse2d_before_scale.brep");
	bool bWriteresult2 = OCCTIO::OCCTTool::Write(edge2, OUTPUT_PATH_PREFIX"Ellipse2d_after_scale.brep");
	CHECK(bWriteresult1 == true);
	CHECK(bWriteresult2 == true);
	std::vector<TopoShape> listShape1 = { edge1 };
	std::vector<TopoShape> listShape2 = { edge2 };
	bool isWrite1 = BRepClassificationTools::IsPointInOnShape(edge1, point2_H, 0.0);
	bool isWrite2 = BRepClassificationTools::IsPointInOnShape(edge2, point2, 0.0);
	CHECK(isWrite1 == true);
	CHECK(isWrite2 == true);
	double s1 = edge1.Length();
	double s2 = edge2.Length();
	CHECK(s1 != s2);
	double s11 = edge1.SurfaceArea();
	double s22 = edge2.SurfaceArea();
	CHECK(s11 == s22);
}}