 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/Geom3Line.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeVertex2d.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoShape.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
TEST_CASE("bug1: This is a bug report case for AMCAX  ", "[geometry][Geom3OffsetCurve][fixbug]")
{
	SECTION("Construct")
	{
		Geom3BezierCurve b3c;
		b3c.Set(0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
		Geom3BSplineCurve s3c(0.0, 0.0, 0.0, 1.0, 1.0, 0.0);
		Geom3BezierCurve b3c1(b3c);
		Geom3OffsetCurve g3o(s3c, 0.0);
		TopoFace face;
		MakeFace mkf(face);
		mkf.Add(face, g3o);
		CHECK(mkf.IsDone() == true);
		TopoEdge e = std::dynamic_pointer_cast<TopoEdge>(face.Edges().Front());
		CHECK(e->Type() == ShapeType::Edge);
	}
}