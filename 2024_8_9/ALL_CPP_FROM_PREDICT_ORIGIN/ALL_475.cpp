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
		Point3 point15(1.0, 0.0, 1.0);
		Direction3 dir15(0.0, 1.0, 0.0);
		Frame3 frame15(point15, dir15);
		Hyperbola3 hyperbola3d_fr1(frame15, major3, minor3);
		CHECK(hyperbola3d_fr.ConjugateBranch1().IsEqual(hyperbola3d_fr1, 0.001, 0.001));
	}}