 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Cone.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeCylinder.hpp>
#include <modeling/MakeCone.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for TestCone", "[math][Cone][P1]")
{
	Frame3 frame;
	double radius = 5.0;
	double height = 8.0;
	Cone cone(frame, radius, height);
	SECTION("Scale")
	{
		Point3 point(10.0, 0.0, 0.0);
		cone.Scale(point, 0.8);
		CHECK(cone.Radius() == Approx(4.0));
		CHECK(cone.Location().X() == Approx(10.0));
		CHECK(cone.Location().Y() == Approx(0.0));
		CHECK(cone.Location().Z() == Approx(0.0));
	}}