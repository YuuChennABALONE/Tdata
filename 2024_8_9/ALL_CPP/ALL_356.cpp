/* "AMCAX_API explicit MakeFace(const TopoWire& w, bool onlyPlane = false)\t @param onlyPlane If true, the surface will be a plane\n\t @param w The wire\n\t @brief Construct from a wire\n,\n",
      */
 "?#include<catch.hpp>
#include<testHelper.h>
#include <topology/TopoExplorerTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <offset/MakeFaceExtension.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <io/OBJTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
using namespace AMCAX;
TEST_CASE("Not fix bug:case2:PerformWithEdgeAndLength  ", "[offset][PerformWithEdgeAndLength][P1][bug]") {
	Circle3 c1(Frame3(), 10.);
	Circle3 c2(Frame3(), 4.);
	TopoEdge e1 = MakeEdge(c1);
	TopoWire w1 = MakeWire(e1);
	TopoEdge e2 = MakeEdge(c2);
	TopoWire w2 = MakeWire(e2);
	w2.Reverse();
	MakeFace mkF(w1);
	mkF.Add(w2);
	mkF.Build();
	TopoFace face = mkF.Face();
	BRepMeshIncrementalMesh meshF(face, 0.01);
	IndexSet<TopoShape> fedge;
	TopoExplorerTool::MapShapes(face, ShapeType::Edge, fedge);
	MakeFaceExtension mkExt;
	mkExt.SetFace(face);
	SECTION("PerformWithEdgeAndLength 5.0 内径到圆心超过") {
			TopoEdge edge = static_cast<const TopoEdge&>(fedge[1]);
			mkExt.PerformWithEdgeAndLength(edge, 5.0);
			CHECK(mkExt.IsDone() == false);
		}}