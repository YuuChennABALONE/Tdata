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
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Hyperbola3 hyperbola3(frame, major, minor);
	SECTION("ConjugateBranch2()") {
		Hyperbola3 hyperbola31 = hyperbola3.ConjugateBranch2();
		CHECK(hyperbola31.Location().X() == Approx(0.0));
		CHECK(hyperbola31.Location().Y() == Approx(0.0));
		CHECK(hyperbola31.Location().Z() == Approx(0.0));
		CHECK(hyperbola31.MajorRadius() == Approx(4.0));
		CHECK(hyperbola31.MinorRadius() == Approx(3.0));
	}}