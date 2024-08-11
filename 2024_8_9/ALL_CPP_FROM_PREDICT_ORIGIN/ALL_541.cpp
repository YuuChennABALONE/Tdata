 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBlend.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <io/OBJTool.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <topology/TopoExplorer.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <topology/TopoVertex.hpp>
#include <modeling/MakeVertex.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoShape.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoExplorer.hpp>
TEST_CASE("bug1: ", "[nurbs][Blend][fixbug]")
{
	TopoFace face1 = ReadBRepFace(inputPathPrefix"testface.brep");
	TopoEdge edge1 = ReadBRepEdge(inputPathPrefix"testedge.brep");
	TopoFace face2 = ReadBRepFace(inputPathPrefix"testface2.brep");
	TopoEdge edge2 = ReadBRepEdge(inputPathPrefix"testedge2.brep");
	SECTION("TestContType 1")
	{
		TopoEdge edge1 = ReadBRepEdge(inputPathPrefix"testedge.brep");
		TopoEdge edge2 = ReadBRepEdge(inputPathPrefix"testedge2.brep");
		TopoFace face1 = ReadBRepFace(inputPathPrefix"testface.brep");
		TopoFace face2 = ReadBRepFace(inputPathPrefix"testface2.brep");
		std::vector<double> parameters1(3);
		std::vector<double> parameters2(3);
		CONTINUITY cont1 = CONTINUITY_DISCONTINUOUS;
		CONTINUITY cont2 = CONTINUITY_DISCONTINUOUS;
		bool isPrecise = true;
		std::vector<double> tol = {0.0, 0.0, 0.0};
		TopoShape result = NurbsAPIBlend::BlendFaces(face1, edge1, cont1, parameters1, face2, edge2, cont2, parameters2, true, isPrecise, tol);
		CHECK(OCCTIO::OCCTTool::Write(result, outputPathPrefix"bug445.brep"));
		CHECK(OCCTIO::OCCTTool::Write(face1, outputPathPrefix"bug445face1.brep"));
		CHECK(OCCTIO::OCCTTool::Write(face2, outputPathPrefix"bug445face2.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge1, outputPathPrefix"bug445edge1.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge2, outputPathPrefix"bug445edge2.brep"));
		std::vector<TopoShape> shape1 = OCCTIO::OCCTTool::ReadBRepShape(outputPathPrefix"bug445face1.brep");
		std::vector<TopoShape> shape2 = OCCTIO::OCCTTool::ReadBRepShape(outputPathPrefix"bug445face2.brep");
		std::vector<TopoShape> shape3 = OCCTIO::OCCTTool::ReadBRepShape(outputPathPrefix"bug445edge1.brep");
		std::vector<TopoShape> shape4 = OCCTIO::OCCTTool::ReadBRepShape(outputPathPrefix"bug445edge2.brep");
		std::vector<TopoShape> shape5 = OCCTIO::OCCTTool::ReadBRepShape(outputPathPrefix"bug445.brep");
		CHECK(ShapeTool::IsPointInOnSurface(M"}