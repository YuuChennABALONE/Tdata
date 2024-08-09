/* "AMCAX_API static std::shared_ptr<Geom3BSplineCurve> ApproxPoints(const std::vector<Point3>& points, int degree, int npoles, bool isClosed = false, ApproxParameterizationType ptype = ApproxParameterizationType::ChordLength)\t @return curve\n\t @param ptype parameterization type\n\t @param isClosed Is curve closed\n\t @param npoles Target number of poles\n\t @param degree Target degree\n\t @param points Data points to be approximated\n\t @brief Approx points to a curve\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIApprox.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <modeling/MakeEdge.hpp>
#include <nurbs/NURBSAPIInterpolate.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeVertex.hpp>
#include <nurbs/NURBSAPIBuildCurve.hpp>
TEST_CASE("case1: this is a test for Approx", "[nurbs][Approx][P1]")
{
	double refTol = DEFAULT_TOLERANCE;
	SECTION("TestApproxPoints")
	{
		OUTPUT_DIRECTORY(nurbs, Approxs/ApproxPoints);
		std::vector<Point3> points;
		Point3 p1(0.0, 0.0, 0.0);
		Point3 p2(-0.1, 1.0, -0.2);
		Point3 p3(0.1, 2.0, -0.1);
		Point3 p4(0.2, 3.0, 0.1);
		Point3 p5(0.1, 4.0, 0.0);
		Point3 p6(0.0, 5.0, -0.1);
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
		points.push_back(p4);
		points.push_back(p5);
		points.push_back(p6);
		int degree = 3;
		int npoles = 5;
		auto curve = NURBSAPIApprox::ApproxPoints(points, degree, npoles);
		TopoVertex v1 = MakeVertex(p1);
		TopoVertex v2 = MakeVertex(p2);
		TopoVertex v3 = MakeVertex(p3);
		TopoVertex v4 = MakeVertex(p4);
		TopoVertex v5 = MakeVertex(p5);
		TopoVertex v6 = MakeVertex(p6);
		TopoEdge edge = MakeEdge(curve);
		BRepExtremaDistShapeShape dist1(v1, edge);
		BRepExtremaDistShapeShape dist2(v2, edge);
		BRepExtremaDistShapeShape dist3(v3, edge);
		BRepExtremaDistShapeShape dist4(v4, edge);
		BRepExtremaDistShapeShape dist5(v5, edge);
		BRepExtremaDistShapeShape dist6(v6, edge);
		CHECK(dist1.Value() <= Approx(refTol));
		CHECK(dist2.Value() <= Approx(refTol));
		CHECK(dist3.Value() <= Approx(refTol));
		CHECK(dist4.Value() <= Approx(refTol));
		CHECK(dist5.Value() <= Approx(refTol));
		CHECK(dist6.Value() <= Approx(refTol));
		Point3 sp = curve->StartPoint();
		Point3 ep = curve->EndPoint();
		CHECK(sp.X() == p1.X());
		CHECK(sp.Y() == p1.Y());
		CHECK(sp.Z() == p1.Z());
		CHECK(ep.X() == p6.X());
		CHECK(ep.Y() == p6.Y());
		CHECK(ep.Z() == p6.Z());
		CHECK(curve->Degree() == 3);
		CHECK(curve->NPoles() == 5);
		CHECK(curve->IsClosed() == false);
		CHECK(curve->IsPeriodic() == false);
		OCCTIO::OCCTTool::Write(v1, outdir + "v1.brep");
		OCCTIO::OCCTTool::Write(v2, outdir + "v2.brep");
		OCCTIO::OCCTTool::Write(v3, outdir + "v3.brep");
		OCCTIO::OCCTTool::Write(v4, outdir + "v4.brep");
		OCCTIO::OCCTTool::Write(v5, outdir + "v5.brep");
		OCCTIO::OCCTTool::Write(v6, outdir + "v6.brep");
		OCCTIO::OCCTTool::Write(edge, outdir + "result.brep");
	}}