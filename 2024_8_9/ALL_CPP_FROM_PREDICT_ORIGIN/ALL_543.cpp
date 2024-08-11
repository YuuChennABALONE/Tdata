 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBlend.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3Line3.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3Cone.hpp>
#include <geometry/Geom3Cylinder.hpp>
#include <geometry/Geom3FlatSurface.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Torus.hpp>
#include <geometry/Geom3SweptCurve.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfRevolution.hpp>
#include <geometry/Geom3TransformCurve.hpp>
#include <geometry/Geom3TransformSurface.hpp>
#include <geometry/Geom3Untrim.hpp>
#include <geometry/Geom3OffsetSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3CurveOnSurface.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3CurveOnSurface.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3CurveOnSurface.hpp>
TEST_CASE("test the continuity of the blending curves and surfaces ", "[nurbs][Blend][P1]")
{
	SECTION("2D")
	{
		std::shared_ptr<Geom3BSplineCurve> curve1 = ReadBRepCurve(fileDir + "curve2d/BRepCurve022.brep");
		std::shared_ptr<Geom3BSplineCurve> curve2 = ReadBRepCurve(fileDir + "curve2d/BRepCurve023.brep");
		TopoVertex v1 = ToTopoVertex(curve1->StartPoint());
		TopoVertex v2 = ToTopoVertex(curve2->StartPoint());
		CHECK(v1.X() == Approx(v2.X()).margin(1e-6));
		CHECK(v1.Y() == Approx(v2.Y()).margin(1e-6));
		TopoEdge e1 = MakeEdge(curve1);
		TopoEdge e2 = MakeEdge(curve2);
		TopoShape shape1 = MakeVertex(v1);
		TopoShape shape2 = MakeEdge(e2);
		TopoShape result = NurbsAPIBlend(e1, true, e2, true, ContinuityType::C0, parameters1, parameters2);
		CHECK(result.Type() == ShapeType::Edge);
		TopoEdge edge = static_cast<const TopoEdge&>(result);
		auto edge1 = static_cast<const TopoEdge&>(e1);
		auto edge2 = static_cast<const TopoEdge&>(e2);
		auto edge3 = static_cast<const TopoEdge&>(MakeEdge(curve1));
		auto edge4 = static_cast<const TopoEdge&>(MakeEdge(curve2));
		CHECK(OCCTIO::OCCTTool::Write(edge, outDir + "EdgeBlend022.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge1, outDir + "EdgeBlend022_1.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge2, outDir + "EdgeBlend022_2.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge3, outDir + "EdgeBlend022_3.brep"));
		CHECK(OCCTIO::OCCTTool::Write(edge4, outDir + "EdgeBlend022_4.brep"));
		auto result1 = TopoTool::ExtremaCurveCurve(edge3, edge);
"}