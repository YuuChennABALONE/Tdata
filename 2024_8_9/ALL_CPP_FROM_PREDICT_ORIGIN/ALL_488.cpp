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
#include <common/TransformationT.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola3", "[math][Hyperbola3][p1]") {
	Point3 point3_fr(0.0, 0.0, 1.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3(point3_fr, dir3_fr);
	double major3 = 3.0, minor3 = 4.0;
	Hyperbola3 hyperbola3d_fr(frame3, major3, minor3);
	SECTION("Directrix2()") {
		Axis3 axis3d_dir = hyperbola3d_fr.Directrix2();
		CHECK(axis3d_dir.Direction().X() == Approx(0.0));
		CHECK(axis3d_dir.Direction().Y() == Approx(1.0));
		CHECK(axis3d_dir.Direction().Z() == Approx(0.0));
		CHECK(axis3d_dir.Location().X() == Approx(-3.0));
		CHECK(axis3d_dir.Location().Y() == Approx(0.0));
		CHECK(axis3d_dir.Location().Z() == Approx(1.0));
	}}