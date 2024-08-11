 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBlend.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
#include <geometry/GeomAPIIntSurfaceCurve.hpp>
#include <geometry/GeomAPIExtraordinaryPointOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIIntSurfaceCurve.hpp>
#include <geometry/GeomAPIIntCurveCurve.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
TEST_CASE("case1: BlendFaces 1/2 ", "[nurbs][Blend][P1][BRepExtremaDistShapeShape]") {
	TopoFace face1, face2;
	bool isRead1 = ReadBRepShape(inputAMCAX::GetInputPath("testNURBSData/BlendFaceSurfaceFace1.brep", INPUT_PATH_PREFIX), face1);
	bool isRead2 = ReadBRepShape(inputAMCAX::GetInputPath("testNURBSData/BlendFaceSurfaceFace2.brep", INPUT_PATH_PREFIX), face2);
	CHECK(isRead1 == true);
	CHECK(isRead2 == true);
	TopoEdge edge1 = MakeEdge(face1);
	TopoEdge edge2 = MakeEdge(face2);
	std::vector<double> parameters1, parameters2;
	SECTION("AutoReverse=true isPrecise=true tol=0.001") {
		CONTINUITY_TYPE cont1 = CONTINUITY_TYPE::G2;
		CONTINUITY_TYPE cont2 = CONTINUITY_TYPE::G2;
		std::shared_ptr<Geom3BSplineSurface> surf1 = NURBSAPIConvert::ToGeom3BSplineSurface(face1);
		std::shared_ptr<Geom3BSplineSurface> surf2 = NURBSAPIConvert::ToGeom3BSplineSurface(face2);
		CHECK(surf1 != nullptr);
		CHECK(surf2 != nullptr);
		double tol = 0.001;
		auto surf = NURBSAPIBlend::BlendFaces(face1, edge1, cont1, parameters1, face2, edge2, cont2, parameters2, true, true, { tol });
		CHECK(surf != nullptr);
		double z1 = surf1->Value(parameters1[0], parameters1[1]);
		double z2 = surf2->Value(parameters2[0], parameters2[1]);
		CHECK(z1 == Approx(z2));
		CHECK(surf->IsPeriodic() == surf1->IsPeriodic());
		CHECK(surf->IsClosed() == surf1->IsClosed());
		CHECK(surf->Degree() == surf1->Degree());
		CHECK(surf->Dimension() == surf1->Dimension());
		CHECK(surf->IsSmooth() == surf1->IsSmooth());
		CHECK(surf->Type() == surf1->Type());
		CHECK(surf->Bounds() == surf1->Bounds());
	"}