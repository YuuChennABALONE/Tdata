 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Cylinder.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeCylinder.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Cylinder", "[math][Cylinder][P1]")
{
	Frame3 frame;
	double radius = 5.0;
	Cylinder cylinder(frame, radius);
	SECTION("Cylinder::Cylinder")
	{
		CHECK(cylinder.Radius() == Approx(radius));
		CHECK(cylinder.Location().X() == Approx(frame.Location().X()));
		CHECK(cylinder.Location().Y() == Approx(frame.Location().Y()));
		CHECK(cylinder.Location().Z() == Approx(frame.Location().Z()));
	}}