 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/Boolean.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoVertex.hpp>
#include <math/Plane.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeShape.hpp>
#include <occtio/OCCTTool.hpp>
#include <io/STLTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3ÂÝÐýÏß.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3Cone.hpp>
#include <geometry/Geom3Cylinder.hpp>
using namespace AMCAX;
TEST_CASE("bug1: Boolean  ", "[boolean][fixbug]") {
	TopoShape shape1, shape2;
	OCCTIO::OCCTTool::Read(shape1, INPUT_PATH_PREFIX"boolean/part.brep");
	OCCTIO::OCCTTool::Read(shape2, INPUT_PATH_PREFIX"boolean/booleanTestShape.brep");
	TopoShape result = Boolean::Cut(shape1, shape2);
	CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"testBooleanCut.brep"));
	IndexSet<TopoShape> shapeFace, shapeEdge, shapeVertex, shapeEdge2, shapeFace2;
	CHECK( TopoTool::MapShapeFace(result, shapeFace, 0.1) == 1);
	CHECK( TopoTool::MapShapeEdge(result, shapeEdge, 0.1) == 0);
	CHECK( TopoTool::MapShapeVertex(result, shapeVertex, 0.1) == 0);
	CHECK( TopoTool::MapShapeEdge(result, shapeEdge2, 0.1) == 0);
	CHECK( TopoTool::MapShapeFace(result, shapeFace2, 0.1) == 0);
	bool isWriteSuccess = STLTool::Write(shapeFace, OUTPUT_PATH_PREFIX"shapeFace.stl");
	CHECK(isWriteSuccess == true);
	bool isWriteSuccess2 = STLTool::Write(shapeEdge, OUTPUT_PATH_PREFIX"shapeEdge.stl");
	CHECK(isWriteSuccess2 == true);
	bool isWriteSuccess3 = STLTool::Write(shapeVertex, OUTPUT_PATH_PREFIX"shapeVertex.stl");
	CHECK(isWriteSuccess3 == true);
	bool isWriteSuccess4 = STLTool::Write(shapeEdge2, OUTPUT_PATH_PREFIX"shapeEdge2.stl");
	CHECK(isWriteSuccess4 == true);
	bool isWriteSuccess5 = STLTool::Write(shapeFace2, OUTPUT_PATH_PREFIX"shapeFace2.stl");
	CHECK(isWriteSuccess5 == true);
}