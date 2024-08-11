 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/NURBS/NURBSExtent.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
TEST_CASE("case1: this is a test for TestNURBSMethods", "[geometry][NURBS][p1]") {
	SECTION("SweepWithTwoGuidesAndRadius") {
        std::shared_ptr<Geom3BSplineCurve> guide1, guide2, spine;
        guide1 = std::make_shared<Geom3BSplineCurve>(Frame3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0))), 0.0, 2.0 * M_PI);
        guide2 = std::make_shared<Geom3BSplineCurve>(Frame3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 1.0, 0.0))), 0.0, 2.0 * M_PI);
        spine = std::make_shared<Geom3BSplineCurve>(Frame3(Frame3(Point3(1.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0))), 0.0, 2.0 * M_PI);
        double r = 1.0;
        double r2 = 2.0;
        std::vector<std::shared_ptr<Geom3BSplineSurface>> surfaces;
        NURBSExtent nurextent;
        nurextent.SweepWithTwoGuidesAndRadius(guide1, guide2, spine, 0.0, 2.0 * M_PI, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, surfaces);
        for (const auto& surface : surfaces) {
            CHECK(OCCTIO::OCCTTool::Write(*surface, OUTPUT_PATH_PREFIX"SurfWithGuideSurfWithGuideSurf45.brep"));
            TopoFace face = MakeFace(*surface, 0.0);
            TopoEdge edge = face.Edge(1);
            CHECK(BRepClassificationTools::IsPointInOnEdge(edge, Point3(1.0, 0.0, 0.0), 0.001));
        }
    }}