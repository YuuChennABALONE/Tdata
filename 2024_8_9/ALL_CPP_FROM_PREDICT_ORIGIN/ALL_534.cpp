 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeShapeTool.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <common/Transformation.hpp>
#include <topology/TopoBuilder.hpp>
#include <occtio/OCCTTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoVertex.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeFace2d.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeVertex2d.hpp>
TEST_CASE("bug1: MakeShapeTool::SewShape ", "[modeling][MakeShapeTool][fixbug]")
{
	TopoShape result;
	TopoShape shape1, shape2;
	OCCTIO::OCCTTool::Read(shape1, INPUT_PATH_PREFIX"shape_bug2.brep");
	OCCTIO::OCCTTool::Read(shape2, INPUT_PATH_PREFIX"shape_bug2.brep");
	std::list<TopoShape> shapes;
	shapes.push_back(shape1);
	shapes.push_back(shape2);
	MakeShapeTool::SewShape(shapes, 0.0);
	result = MakeShapeTool::SewShape(shapes, 0.0);
	CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"MakeShapeTool_SewShape_bug2.brep"));
}