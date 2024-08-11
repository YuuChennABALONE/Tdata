 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeBox.hpp>
#include <modeling/MakeSphere.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("bug1: BRepClassificationTools::IsPointInOnEdge False case 1 ", "[hatch][BRepClassificationTools][fixbug]") {
	TopoEdge e = MakeEdge(OffsetCurveOnSurface(MakeSphere(2.0, 20, 20), Point3(0.0, 0.0, 2.0), 0.0));
	TopoShape edgeShape = TopoTool::Shape(e);
	bool isPointOnEdge = BRepClassificationTools::IsPointInOnEdge(edgeShape, Point3(0.0, 0.0, 2.0));
	CHECK(isPointOnEdge == false);
}