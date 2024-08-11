 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: GeomAPI-SweepWithTwoGuideCurves ", "[geometry][GeomAPI][fixbug]") {
    std::shared_ptr<Geom3BSplineCurve> profile = MakeBSplineCurve(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), Point3(0.0, 1.0, 0.0), Direction3(0.0, 0.0, 1.0));
    std::shared_ptr<Geom3BSplineCurve> guide1 = MakeBSplineCurve(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), Point3(1.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0));
    std::shared_ptr<Geom3BSplineCurve> guide2 = MakeBSplineCurve(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), Point3(0.0, 1.0, 0.0), Direction3(0.0, 0.0, 1.0));
    Point3 anchorPoint1(0.0, 0.0, 0.0);
    Point3 anchorPoint2(1.0, 0.0, 0.0);
    std::shared_ptr<Geom3BSplineCurve> spine = MakeBSplineCurve(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), Point3(0.0, 1.0, 0.0), Direction3(0.0, 0.0, 1.0));
    double spineLeftBound = 0.0;
    double spineRightBound = 1.0;
    std::pair<NURBSSweepStatus, std::shared_ptr<Geom3BSplineSurface>> result = GeomAPI::SweepWithTwoGuideCurves(profile, guide1, guide2, anchorPoint1, anchorPoint2, spine, spineLeftBound, spineRightBound);
    CHECK(result.first == NURBSSweepStatus::Success);
    CHECK(result.second->Type() == Geom3BSplineSurface::Type());
    OutputSurface out;
    GlobalProperty sp, pr, ra, ri;
    GetSurfaceProperties(result.second, sp, pr, ra, ri);
    std::cout << "Surface area : " << sp.Area() << std::endl;
    std::cout << "Surface param: " << result.second->Bounds() << std::endl;
    CHECK(sp.Area() == Approx(1.0));
    CHECK(pr.Mass() == Approx(0.5));
    CHECK(ra.RadiusOfCurvature(0.0) == Approx(0.5));
    CHECK(ra.RadiusOfCurvature(1.0) == Approx(0.5));
    CHECK(ri.Eigenvalues().front() == Approx(0.5));
    CHECK(ri.Eigenvalues().back() == Approx(0.5));
    TopoFace face = MakeFace(result.second, 0.0);
    bool isWriteSuccess = AMCAX::OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"GeomAPI-SweepWithTwoGuideCurves_case1.brep");
    CHECK(isWriteSuccess == true);
}