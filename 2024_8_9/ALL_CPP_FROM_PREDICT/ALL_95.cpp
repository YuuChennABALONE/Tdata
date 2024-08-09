 #include <catch.hpp>
#include <testHelper.h>
#include <common/DirectionT.hpp>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/HyperbolaT.hpp>
#include <occtio/OCCTTool.hpp>
#include <common/VectorT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola2", "[math][Hyperbola2][p1]") {
	Point2 point2_Hy(0.0, 0.0);	
	Direction2 dir2_Hy(1.0, 0.0);
	Axis2 major2_Axis(point2_Hy, dir2_Hy);
	double major2 = 3.0, minor2 = 4.0;
	Hyperbola2 hyperbola2d_ax(major2_Axis, major2, minor2, true);
	Point2 point2_fr(1.0, 1.0);
	Direction2 dir2_fr(0.0, 1.0);
	Frame2 frame2(point2_fr, dir2_fr);
	Hyperbola2 hyperbola2d_fr(frame2, major2, minor2);
	SECTION("Default()") {
		Hyperbola2 hyperbola2d_de;	
		CHECK(hyperbola2d_de.Location().X() == Approx(0.0));
		CHECK(hyperbola2d_de.Location().Y() == Approx(0.0));
		hyperbola2d_de.SetMajorRadius(3.0);
		hyperbola2d_de.SetMinorRadius(4.0);
		CHECK(hyperbola2d_de.MajorRadius() == Approx(3.0));
		CHECK(hyperbola2d_de.MinorRadius() == Approx(4.0));
		CHECK(hyperbola2d_de.Focal() == Approx(10.0));
		CHECK(hyperbola2d_de.Focus1().X() == Approx(5.0));
		CHECK(hyperbola2d_de.Focus1().Y() == Approx(0.0));
	}}