 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/BRepExtremaDistShapeToShape.hpp>
#include <modeling/TransformShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <io/OBJTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoVertex.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/LocalProperty.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoExplorer.hpp>
#include <healing/BRepExtremaDistShapeToShape.hpp>
#include <modeling/TransformShape.hpp>
#include <option/OptionTool.hpp>
#include <healing/BRepGlobalProperty.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/LocalProperty.hpp>
#include <math/Sphere.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/BRepExtremaDistShapeToShape.hpp>
TEST_CASE("bug1: Test that a polygon is added to a triangular mesh", "[modeling][MakePolygonOnTriangularMesh][fixbug]")
{
    TopoShape tri_mesh;
    OCCTIO::OCCTTool::Read(tri_mesh, INPUT_PATH_PREFIX"meshes/monkey.brep");
    TopoShape poly;
    OCCTIO::OCCTTool::Read(poly, INPUT_PATH_PREFIX"meshes/polygon.brep");
    TopoShape result = MakePolygonOnTriangularMesh(poly, tri_mesh);
    CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"testbug1.brep"));
    IndexSet<TopoShape> shapes;
    CHECK( TopoTool::MapShapes(result, ShapeType::Face, shapes) );
    CHECK(shapes.size() == 1);
    TopoFace face = TopoCast::Face(result);
    CHECK(BRepClassificationTools::IsPointInOnFace(face, GetRandomPointOnFace(face), 0.001) == true);
}