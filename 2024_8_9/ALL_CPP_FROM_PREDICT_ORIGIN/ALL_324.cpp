 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/CircleT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Circle3", "[math][Circle3][p1]") {
	Circle3 circle3(Frame3(), 5.0);
	SECTION("SetRadius") {
		circle3.SetRadius(3.0);
		CHECK(circle3.Radius() == Approx(3.0));
	}}