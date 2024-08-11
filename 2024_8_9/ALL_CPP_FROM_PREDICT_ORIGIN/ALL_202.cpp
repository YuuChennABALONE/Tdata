 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoExplorerTool.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
	TopoEdge e1,e2;
	TopoWire w;
	OCCTIO::OCCTTool::Read(e1, INPUT_PATH_PREFIX"edge.brep");
	OCCTIO::OCCTTool::Read(e2, INPUT_PATH_PREFIX"edge2.brep");
	w = MakeFace(e1, false);
	CHECK( w.Type() == AMCAX::Face::Type());
	w = MakeFace(e2, false);
	CHECK( w.Type() == AMCAX::Face::Type());
}