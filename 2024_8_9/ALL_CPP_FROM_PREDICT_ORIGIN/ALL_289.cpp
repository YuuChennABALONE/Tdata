 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: Geom3BSplineSurface ", "[geometry][Geom3BSplineSurface][fixbug]")
{
	TopoFace face;
	AMCAX::OCCTIO::OCCTTool::Read(face, INPUT_PATH_PREFIX"face.brep");
	auto surf = TopoTool::Surface(face);
	auto bsp = std::dynamic_pointer_cast<Geom3BSplineSurface>(surf);
	SECTION("uDegree")
	{
		int uDegree = bsp->Degree();
		int vDegree = bsp->Degree(1);
		CHECK(uDegree == 2);
		CHECK(vDegree == 2);
	}}