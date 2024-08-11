 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CircleT.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CircleT base method Test", "[math][CircleT][p1]")
{
	CircleT circle1(Point3(0.0, 0.0, 0.0), 5.0);
	SECTION("MakeBox")
	{
		TopoShape shape = circle1.MakeBox(Point3(2.0, 3.0, 4.0), Point3(4.0, 1.0, 5.0));
		CHECK(OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeBox3.arc"));
		AMCAX::GlobalProperty props1, props2;
		CHECK(GetSurfaceProperties(shape, props1, true, false) == Approx(100.0 * M_PI));
		CHECK(GetVolumeProperties(shape, props2, true, false) == Approx(0.0));
	}}