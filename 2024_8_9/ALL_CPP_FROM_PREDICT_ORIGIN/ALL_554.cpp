 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/NURBS/NURBSAPIConvert.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/NURBS/NURBSAPIGeomAlgo.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
using namespace AMCAX;
TEST_CASE("case1: this is a test for TestNURBSAPIConvert ", "[geometry][NURBS][Convert][P1]") {
	SECTION("SweepWithOneGuideAndTangencySurface") {
        std::cout << "test: NURBSAPIConvert:SweepWithOneGuideAndTangencySurface" << std::endl;
        std::shared_ptr<Geom3BSplineCurve> guideCurve;
        guideCurve = std::make_shared<Geom3BSplineCurve>(Frame3(), 0.0, 1.0);
        double tol = 0.1;
        guideCurve->IncreaseDegree(2, tol);
        std::shared_ptr<Geom3BSplineSurface> tangencySurface;
        tangencySurface = std::make_shared<Geom3BSplineSurface>(Frame3(), 0.0, 1.0, 0.0, 1.0);
        tangencySurface->IncreaseDegree(2, tol);
        std::shared_ptr<Geom3BSplineCurve> spineCurve;
        spineCurve = std::make_shared<Geom3BSplineCurve>(Frame3(), 0.0, 1.0);
        spineCurve->IncreaseDegree(2, tol);
        double spineLeftBound = 0.0;
        double spineRightBound = 1.0;
        double tol1 = 0.0;
        std::shared_ptr<Geom3Surface> surface = NURBSAPIGeomAlgo::SweepWithOneGuideAndTangencySurface(guideCurve, tangencySurface, spineCurve, spineLeftBound, spineRightBound, tol1);
        TopoFace face1;
        face1 = MakeFace(surface, 0.0);
        double s = spineCurve->FirstParameter();
        double e = spineCurve->LastParameter();
        Point3 p1 = spineCurve->Value(s);
        Point3 p2 = spineCurve->Value(e);
        std::cout << "p1: " << p1 << std::endl;
        std::cout << "p2: " << p2 << std::endl;
        GlobalProperty props1, props2;
        double s1 = spineCurve->Value(s).X();
        double s2 = spineCurve->Value(s).Y();
        double e1 = spineCurve->Value(e).X();
        double e2 = spineCurve->Value(e).Y();
        std::cout << "spineCurve: " << spineCurve->FirstParameter() << " " << spineCurve->LastParameter() << std::endl;
        std::cout << "surface: " << surface->FirstUParameter() << " " << surface->LastUParameter() << std::endl;
        std::cout << "surface: " << surface->FirstVParameter() << " " << surface->LastVParameter() << std::endl;
        CHECK(BRepClassificationTools::IsPointInOnSurface(face1, Point3(s1, s2, 0.0), 0.0) == true);
        CHECK(BRepClassificationTools::IsPointInOnSurface(face1, Point3(e1, e2, 0.0), 0.0) == true);
        CHECK(BRepClassificationTools::IsPointInOnSurface(face1, Point3(s1, s2, 0.0), 0.0) == true);
        CHECK(BRepClassificationTools::IsPointInOnSurface(face1, Point3(e1, e2, 0.0), 0.0) == true);
        std::cout << "surface: " << surface->FirstUParameter() << " " << surface->LastUParameter() << std::endl;
        CHECK(static_cast<bool>(NURBSAPIConvert::GetNURBSFromSurface(surface, 1e-6, 1, true, true)) == true);
        CHECK(static_cast<bool>(NURBSAPIConvert::GetNURBSFromSurface(surface, 1e-6, 2, true, true)) == true);
        CHECK"}