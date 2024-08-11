 #include<catch.hpp>
#include<testHelper.h>
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
	SECTION("Scale")
	{
		Point3 point(10.0, 0.0, 0.0);
		cylinder.Scale(point, 0.5);
		CHECK(cylinder.Radius() == Approx(2.5));
		CHECK(cylinder.Location().X() == Approx(10.0));
		CHECK(cylinder.Location().Y() == Approx(0.0));
		CHECK(cylinder.Location().Z() == Approx(0.0));
	}}