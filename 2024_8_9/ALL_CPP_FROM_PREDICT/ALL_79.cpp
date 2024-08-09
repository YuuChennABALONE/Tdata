 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Sphere.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeSphere.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Sphere", "[math][Sphere][P1]")
{
	Point3 point1(0.0, 0.0, 0.0);
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 frame1(point1, dir3);
	double radius = 5.0;
	Sphere sphere1(frame1, radius);
	SECTION("SetRadius")
	{
		sphere1.SetRadius(10.0);
		CHECK(sphere1.Radius() == Approx(10.0));
	}
}