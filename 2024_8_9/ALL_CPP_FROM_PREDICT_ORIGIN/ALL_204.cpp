 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeShapeTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <modeling/TransformShape.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoEdge.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Circle.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <topology/TopoExplorer.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]") {
    TopoFace face;
    face = MakeFace(Cylinder(), Cylinder());
    CHECK(face.Type() == AMCAX::Face);
    CHECK(face.IsNull() == false);
    face = MakeFace(Cylinder(), MakeShapeTool(Cylinder(), Point3(0.0, 0.0, 0.0), Direction3(1.0, 0.0, 0.0), 1.0));
    CHECK(face.Type() == AMCAX::Face);
    CHECK(face.IsNull() == false);
    face = MakeFace(Cylinder(), TopoWire());
    CHECK(face.Type() == AMCAX::Face);
    CHECK(face.IsNull() == false);
}