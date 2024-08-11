 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBuildCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoShape.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
TEST_CASE("bug1: Test the bug1 of BuildCurve ", "[nurbs][BuildCurve][fixbug]")
{
    std::vector<Point3> poles;
    poles.push_back(Point3(0.0, 0.0, 0.0));
    poles.push_back(Point3(1.0, 0.0, 0.0));
    poles.push_back(Point3(2.0, 0.0, 0.0));
    poles.push_back(Point3(3.0, 0.0, 0.0));
    poles.push_back(Point3(4.0, 0.0, 0.0));
    TopoVertex v1,v2,v3,v4,v5;
    v1 = MakeVertex(poles[0]);
    v2 = MakeVertex(poles[1]);
    v3 = MakeVertex(poles[2]);
    v4 = MakeVertex(poles[3]);
    v5 = MakeVertex(poles[4]);
    TopoEdge e1,e2,e3,e4,e5;
    e1 = MakeEdge(v1,v2);
    e2 = MakeEdge(v2,v3);
    e3 = MakeEdge(v3,v4);
    e4 = MakeEdge(v4,v5);
    e5 = MakeEdge(v5,v1);
    TopoShape shape1 = MakePrism(e1);
    for (int i = 1; i <= 5; i++)
    {
        TopoShape shape2 = MakeEdge(ei);
        shape1 = MakeFace(shape1, shape2);
    }
    BRepMeshIncrementalMesh mesher(shape1, 0.005, true);
    CHECK(NURBSAPIBuildCurve::BuildCurve(poles, 4, true) == nullptr);
}