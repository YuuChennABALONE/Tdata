 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIConvert.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: CurveNetworkSurfaceGordon ", "[nurbs][CurveNetworkSurfaceGordon][fixbug]")
{
    std::vector<std::shared_ptr<Geom3BSplineCurve>> verticalCurves;
    std::vector<std::shared_ptr<Geom3BSplineCurve>> horizontalCurves;
    verticalCurves.push_back(ReadBRepCurve(inputPathPrefix + "curve2346.brep"));
    verticalCurves.push_back(ReadBRepCurve(inputPathPrefix + "curve2346_1.brep"));
    verticalCurves.push_back(ReadBRepCurve(inputPathPrefix + "curve2346_2.brep"));
    verticalCurves.push_back(ReadBRepCurve(inputPathPrefix + "curve2346_3.brep"));
    horizontalCurves.push_back(ReadBRepCurve(inputPathPrefix + "line.brep"));
    horizontalCurves.push_back(ReadBRepCurve(inputPathPrefix + "line2.brep"));
    CHECK(CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves).IsValid() == true);
    CHECK(static_cast<bool>(CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves)) == true);
    std::vector<double> z1, z2;
    for (int i = 0; i < 1000; i++) {
        double x = i / 1000.0;
        double y = i / 1000.0;
        z1.push_back(GetX(CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves, x, y)));
        z2.push_back(GetX(CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves, x, y)));
    }
    for (int i = 0; i < z1.size(); i++) {
        CHECK(z1[i] == z2[i]);
    }
    TopoFace face = ToTopoFace(CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves));
    CHECK(face.Type() == AMCAX::Face);
    CHECK(face area = Approx(0.));
}