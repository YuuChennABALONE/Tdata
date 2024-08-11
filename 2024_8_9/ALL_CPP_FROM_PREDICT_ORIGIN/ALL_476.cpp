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
TEST_CASE("case1:this is a case for Hyperbola3", "[math][Hyperbola3][p1]") {
	Point3 point3_fr(0.0, 0.0, 1.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3(point3_fr, dir3_fr);
	double major3 = 3.0, minor3 = 4.0;
	Hyperbola3 hyperbola3d_fr(frame3, major3, minor3);
	SECTION("ConjugateBranch1()") {		
		Point3 point3_c(0.0, 0.0, 1.0);
		Direction3 dir3_c(0.0, 0.0, 1.0);
		Frame3 frame3_c(point3_c, dir3_c);
		Hyperbola3 hyperbola3d_c(frame3_c, major3, minor3);
		Point3 point3(0.0, 0.0, 1.0);
		Direction3 dir3(0.0, 1.0, 0.0);
		Line3 line3(point3, dir3);
		bool isOnLine3 = hyperbola3d_c.Contains(line3, 0.001);
		CHECK(isOnLine3 == true);
		Point3 point1(0.0, 0.0, 1.0);
		Vector3 vector1(0.0, 3.0, 0.0);
		Point3 point2(0.0, 3.0, 1.0);
		MakeEdge edge1(hyperbola3d_c);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point2, 0.001) == true);
		Hyperbola3 hyperbola3d_con = hyperbola3d_c.ConjugateBranch1();
		CHECK(hyperbola3d_con.Location().X() == Approx(0.0));
		CHECK(hyperbola3d_con.Location().Y() == Approx(0.0));
		CHECK(hyperbola3d_con.Location().Z() == Approx(1.0));
		double major3d_con = hyperbola3d_con.MajorRadius();
		double minor3d_con = hyperbola3d_con.MinorRadius();
		CHECK(major3d_con == Approx(4.0));
		CHECK(minor3d_con == Approx(3.0));
		Point3 point3_con(0.0, 0.0, 1.0);
		Direction3 dir3_con(0.0, 1.0, 0.0);
		Frame3 frame3_con(point3_con, dir3_con);
		Hyperbola3 hyperbola3d_con(frame3_con, major3, minor3);
		bool isOnLine3_con = hyperbola3d_con.Contains(line3, 0.001);
		CHECK(isOnLine3_con == true);
		Point3 point1_con(0.0, 0.0, 1.0);
		Vector3 vector1_con(0.0, 3.0, 0.0);
		Point3 point2_con(0.0, 3.0, 1.0);
		MakeEdge edge1_con(hyperbola3d_con);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1_con, point1_con, 0.001) == true);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1_con, point2_con, 0.001) == true);
	}}