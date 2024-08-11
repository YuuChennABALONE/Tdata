 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Adaptor3CurveOnSurface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorerTool.hpp>
TEST_CASE("case1: this is a test for TestGeometry", "[geometry][Geom3BSplineCurve][P1]")
{
	SECTION("SweepWithCenterAndTwoAngles")
{
    std::shared_ptr<Geom3BSplineCurve> centerCurve = makeBSplineCurveOnSurface(sphere, 12);
    std::shared_ptr<Geom3BSplineCurve> spine = makeBSplineCurveOnSurface(sphere, 12);
    std::shared_ptr<Geom3BSplineCurve> firstCurve = makeBSplineCurveOnSurface(sphere, 12);
    double spineMin = spine->MinParameter();
    double spineMax = spine->MaxParameter();
    double angle1 = spine->Value(spineMin);
    double angle2 = spine->Value(spineMax);
    std::shared_ptr<Geom3BSplineCurve> refCurve = makeBSplineCurveOnSurface(sphere, 12, angle1, angle2);
    double u1 = 0;
    double u2 = 2 * M_PI;
    double v1 = 0;
    double v2 = 2 * M_PI;
    GlobalProperty prop1, prop2;
    double s1 = GetCurveLength(centerCurve);
    double s2 = GetCurveLength(spine);
    double s3 = GetCurveLength(refCurve);
    double s4 = GetCurveLength(firstCurve);
    double s5 = GetSurfaceArea(sphere);
    CHECK(s3 == Approx(s4));
    CHECK(s5 == Approx(s1 * s2 / (2 * M_PI) + s3));
    double tolerance = 0.1;
    std::shared_ptr<Geom3BSplineSurface> surface = MakeFace(*centerCurve, *spine, angle1, angle2, tolerance);
    Adaptor3CurveOnSurface surfaceCurve(surface);
    CHECK(GeomAPIProjectPointOnCurve3(firstCurve->StartPoint(), surfaceCurve) == true);
    CHECK(Contains(TopoCast::Face(BRepExtremaDistShapeShape(*centerCurve, *surface, 0.0, Precision::Confusion())), *firstCurve));
    CHECK(Contains(TopoCast::Face(BRepExtremaDistShapeShape(*spine, *surface, 0.0, Precision::Confusion())), *refCurve));
    double z = 0;
    double u = 0;
    double v = 0;
    Point3 p1, p2, p3, p4;
    GetSurfaceCoordinates(surface, u, v, p1, p2, p3, p4);
    double x = p1.X() + (p2.X() - p1.X()) * z / (p3.X() - p1.X()) + (p4.X() - p1.X()) * (u - z) / (p3.X() - p1.X());
    double y = p1.Y() + (p2.Y() - p1.Y()) * z / (p3.Y() - p1.Y()) + (p4.Y() - p1.Y()) * (u - z) / (p3.Y() - p1.Y());
    double s = GetCurveLength(centerCurve);
    double s1 = GetCurveLength(spine);
    double s2 = GetCurveLength(refCurve);
    double s3 = GetCurveLength(firstCurve);
    double s4 = GetSurfaceArea(sphere);
    CHECK(s1 * s2 / (2 * M_PI) + s3 == Approx(s4));
    CHECK(p1.X() == Approx(s * s1 / (2 * M_PI)));
    CHECK(p1.Y() == Approx(s * s2 / (2 * M_PI)));
    CHECK(p1.Z() == Approx(z));
    MakeEdge edge1, edge2, edge3, edge4;
    CHECK(OCCTIO::OCCTTool::Write(edge1, outdir + "Geom3BSplineCurve4.brep"));
    CHECK(OCCTIO"}