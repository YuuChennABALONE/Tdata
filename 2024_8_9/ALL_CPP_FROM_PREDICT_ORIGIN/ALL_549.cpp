 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/GeometryTool.hpp>
#include <healing/MakeShapeRebuilder.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/GeometryTool.hpp>
#include <healing/MakeShapeRebuilder.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
TEST_CASE("bug1: NURBS surface sweeping ", "[geometry][NURBSSurfaceSweep][fixbug]")
{
	SECTION("SweepWithThreeGuides")
{
    shared_ptr<Geom3BSplineCurve> sp;
    shared_ptr<Geom3BSplineCurve> g1;
    shared_ptr<Geom3BSplineCurve> g2;
    shared_ptr<Geom3BSplineCurve> g3;
    double tol = 0.001;
    g1 = make_shared<Geom3BSplineCurve>(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 0.0, 0.0))));
    g2 = make_shared<Geom3BSplineCurve>(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 1.0, 0.0))));
    g3 = make_shared<Geom3BSplineCurve>(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0))));
    sp = SweepWithThreeGuides(g1, g2, g3, g1, -1.0, 1.0);
    CHECK(sp->IsPeriodicInU() == false);
    CHECK(sp->IsPeriodicInV() == false);
    TopoFace face = MakeFace(*sp, tol);
    shared_ptr<Geom3Surface> s = GeometryTool::Surface(face);
    shared_ptr<Geom3BSplineSurface> spb = dynamic_cast<Geom3BSplineSurface*>(s.get());
    double u1 = 0.0, v1 = 0.0, u2 = 0.0, v2 = 0.0, u3 = 0.0, v3 = 0.0, u4 = 0.0, v4 = 0.0;
    spb->Bounds(u1, v1, u2, v2, u3, v3, u4, v4);
    CHECK(u1 == Approx(0.0));
    CHECK(v1 == Approx(0.0));
    CHECK(u2 == Approx(0.0));
    CHECK(v2 == Approx(0.0));
    CHECK(u3 == Approx(0.0));
    CHECK(v3 == Approx(0.0));
    CHECK(u4 == Approx(0.0));
    CHECK(v4 == Approx(0.0));
    double u = 0.0, v = 0.0;
    Point3 p1 = spb->Value(u, v);
    Point3 p2 = spb->Value(u1, v1);
    Vector3 v1 = spb->DN(u, v, 1);
    Vector3 v2 = spb->DN(u1, v1, 1);
    CHECK(p1.X() == p2.X());
    CHECK(p1.Y() == p2.Y());
    CHECK(p1.Z() == p2.Z());
    CHECK(v1.X() == v2.X());
    CHECK(v1.Y() == v2.Y());
    CHECK(v1.Z() == v2.Z());
    CHECK(s->Type() == SurfaceType::BSplineSurface);
    MakeShapeRebuilder rebuild;
    rebuild.AddFace(face);
    rebuild.Build();
    TopoShape shape = rebuild.Shape();
    CHECK( TopoTool::IsPointInOnEdge(shape, Point3(0.0, 0.0,"}