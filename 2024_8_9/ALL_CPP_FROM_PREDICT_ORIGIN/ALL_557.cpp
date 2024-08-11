 #include<catch.hpp>
#include<testHelper.h>
#include <common/Exception.hpp>
#include <math/Geom3BSplineSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/GeometryTool.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
TEST_CASE("bug1: Convert a surface to a BSpline surface and output the result to the file ", "[math][Geom3BSplineSurface][fixbug]")
{
    std::shared_ptr<Geom3BSplineSurface> s;
    std::ifstream ifile(INPUT_PATH_PREFIX"surface.brep");
    std::shared_ptr<Geom3Surface> surface = ReadBRepSurface(ifile);
    if (surface == nullptr)
    {
        return;
    }
    s = Geom3Surface::ToBSpline(surface);
    if (s == nullptr)
    {
        return;
    }
    OUTPUT_PATH_PREFIX"Geom3BSplineSurface_bug1.brep";
    {
        std::ofstream out(OUTPUT_PATH_PREFIX"Geom3BSplineSurface_bug1.brep");
        MakeFace face(s, 0.0, 1.0, 0.0, 1.0);
        out << face;
    }
}