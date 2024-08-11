 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/GeometryTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom2Surface.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/BRepAdaptorCurve3.hpp>
#include <topology/TopoTool.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoShape.hpp>
#include <iostream>
using namespace AMCAX;
TEST_CASE("bug1: MakeArcOfCircle2d  add 11 cases ", "[geometry][MakeArcOfCircle2d][fixbug]") {
	SECTION("test260") {
        Point2 p(0.0, 0.0);
        Direction2 d(1.0, 0.0);
        Vector2  v(1.0, 1.0);
        MakeArcOfCircle2d arc(p, d, v);
        double angle1 = ArcLength(arc);
        CHECK(angle1 == Approx(0.785398));
        TopoEdge e = MakeEdge(arc);
        TopoShape shape = MakeFace(e, 0.0);
        bool bWriteresult = OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeArcOfCircle2d_case260.brep", true, 5);
        CHECK(bWriteresult == true);
    }}