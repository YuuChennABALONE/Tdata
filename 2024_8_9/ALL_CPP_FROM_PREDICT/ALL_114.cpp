 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePrism.hpp>
#include <common/CartesianCoordinate.hpp>
#include <topology/TopoVertex.hpp>
#include <common/Builder.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeCompound.hpp>
#include <topology/BRepExtremaProximityTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakePrism ", "[modeling][MakePrism][fixbug]") {
	IndexSet<TopoShape> vertices;
	MakePrism prism1;
	SECTION("NVertices") {
		CHECK(prism1.NVertices() == 5);
	}}