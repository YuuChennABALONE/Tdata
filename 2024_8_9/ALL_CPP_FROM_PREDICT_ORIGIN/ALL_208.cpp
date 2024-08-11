 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <topology/TopoFace.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <modeling/MakeShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeWire2d.hpp>
#include <modeling/MakeFace2d.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3SurfaceOfExponentialSurface.hpp>
#include <geometry/Geom3HyperbolicSurface.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
	SECTION("surface and wire")
{
    TopoFace result;
    TopoEdge e;
    TopoWire w;
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(0.0, 1.0, 0.0);
    Point3 p3(1.0, 1.0, 0.0);
    Point3 p4(1.0, 0.0, 0.0);
    std::vector<Point3> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    e = MakeEdge(v);
    w = MakeWire(e);
    std::shared_ptr<Geom3Surface> s = std::make_shared<Geom3Plane>(Frame3(), 2.0);
    result = MakeFace(s, w);
    if (result)
    {
        OutputResult(result, OUTPUT_PATH_PREFIX"MakeFace_bug0412.brep");
    }
    FileAMCAX amcax;
    amcax.Read(result, OUTPUT_PATH_PREFIX"MakeFace_bug0412.brep");
    AMCAXAPI::GlobalProperty props;
    CHECK(GetSurfaceProperties(result, props, true, false) == Approx(4.0));
    CHECK(GetVolumeProperties(result, props, true, false) == Approx(0.0));
    TopoShape s1 = ProjectShape(result, Frame3(), 1.0);
    Output result_out(result);
    result_out.Write(OUTPUT_PATH_PREFIX"MakeFace_bug0412.brep");
    CHECK(amcax.Write(OUTPUT_PATH_PREFIX"MakeFace_bug0412.brep", s1));
    TopoFace face;
    std::vector<TopoShape> shapes;
    result topomesh::BRepMeshIncrementalMesh(face, 0.01, true);
    CHECK(face.IsNull() == true);
}}