 #include<catch.hpp>
#include<testHelper.h>
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
	SECTION("SemiAngle") {
		double sa = hyperbola3d_fr.SemiAngle();
		Point3 point1(0.0, 0.0, 1.0);
		Direction3 dir1(0.0, 1.0, 0.0);
		Axis3 axis3(point1, dir1);
		double angle = std::acos(axis3.Direction().X() / sqrt(axis3.Direction().X() * axis3.Direction().X() + axis3.Direction().Y() * axis3.Direction().Y() + axis3.Direction().Z() * axis3.Direction().Z()));
		CHECK(sa == angle);
	}}