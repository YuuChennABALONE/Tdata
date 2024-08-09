 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeEdge.hpp>
#include <common/IndexT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <modeling/MakeVertex.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
AMCAX::TopoEdge edge;
TEST_CASE("case1: MakeEdge2d construction and methods Test", "[modeling][MakeEdge2d][p1]")
{
	SECTION("Vertices")
	{
		OCCTIO::OCCTTool::Read(edge, INPUT_PATH_PREFIX"edge2.brep");
		auto vertices = AMCAX::MakeEdge2d::Vertices();
		AMCAX::GlobalProperty props1;
		AMCAX::BRepGlobalProperty::SurfaceProperties(edge, props1);
		CHECK(vertices.size() == 2);
	}
}