 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Sphere.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <common/DirectionT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoTool.hpp>
#include <common/MethodT.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("bug1: Sphere ", "[math][Sphere][fixbug]")
{
	Point3 point3_fr(0.0, 0.0, 0.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3(point3_fr, dir3_fr);
	Sphere sphere(frame3, 5.0);
	SECTION("SetRadius")
	{
		sphere.SetRadius(1.0);
		CHECK(sphere.Radius() == Approx(1.0));
		CHECK(sphere.Area() == Approx(4.0 * M_PI));
		CHECK(sphere.Volume() == Approx(4.0 * M_PI / 3.0));
	}
}