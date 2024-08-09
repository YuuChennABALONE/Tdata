/* "AMCAX_API static std::shared_ptr<Geom3BSplineSurface> BlendSurfaces( const std::shared_ptr<Geom3BSplineSurface>& surf1, bool isUIso1, bool isFront1, ContinuityType cont1, std::vector<double>& parameters1, const std::shared_ptr<Geom3BSplineSurface>& surf2, bool isUIso2, bool isFront2, ContinuityType cont2, std::vector<double>& parameters2, bool autoReverse, bool isPrecise, const std::vector<double>& tol),\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBlend.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeVertex.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/BRepAdaptorCurve3.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <nurbs/NURBSAPIGetGeometry.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
double NURBSSampleEdge(int num, double tol, const shared_ptr<Geom3Curve>& curve, const TopoEdge& edge)
{
	double fpu1 = curve->FirstParameter();
	double lpu1 = curve->LastParameter();
	double delta = (lpu1 - fpu1) / num;
	Point3 p;
	int n = 0;
	for (int i = 0; i < num; i++) {
		double t = fpu1 + i * delta;
		curve->D0(t, p);
		if (BRepClassificationTools::IsPointInOnEdge(edge, p, tol))
		{
			n++;
		}
	}
	double r1 = 1.0 * (num - n) / num;
	return r1;
}
TopoEdge ChooseSimilarEdge(const TopoShape& shape, const TopoEdge& edge)
{
	int nsample = 1000;
	Point3 p1, p2;
	BRepAdaptorCurve3 refC(edge);
	double refFp = refC.FirstParameter();
	double refLp = refC.LastParameter();
	for (TopoExplorer ex(shape, ShapeType::Edge); ex.More(); ex.Next())
	{
		const TopoEdge& cre = static_cast<const TopoEdge&>((ex.Current()));
		BRepAdaptorCurve3 crC(edge);
		double crFp = crC.FirstParameter();
		double crLp = crC.LastParameter();
		if (std::abs(refFp - crFp) < 0.001 && std::abs(refLp - crLp) < 0.001)
		{
			bool isOK = true;
			for (int i = 0; i < nsample; i++)
			{
				double t1 = refFp + i * (refLp - refFp) / (nsample - 1);
				double t2 = crFp + i * (crLp - crFp) / (nsample - 1);
				refC.D0(t1, p1);
				crC.D0(t2, p2);
				if (p1.Distance(p2) > 0.001)
				{
					isOK = false;
					break;
				}
			}
			if (isOK)
			{
				return cre;
			}
		}
	}
	TopoEdge e;
	return e;
}
TEST_CASE("case1: this is a test for testBlendSurf", "[nurbs][Blend][P1]")
{
	int num = 1000;
	double ratio = 0.1;
	double refTol = DEFAULT_TOLERANCE;
	SECTION("testBridgeSurf")
	{
		OUTPUT_DIRECTORY(nurbs, Blend/BridgeSurf);
		auto surf1 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface1.brep");
		auto surf2 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface2.brep");
		bool isU1 = true, isFront1 = true, isU2 = true, isFront2 = true;
		ContinuityType cont1 = ContinuityType::G2;
		ContinuityType cont2 = ContinuityType::G2;
		bool isAutoReverse = true;
		bool isPrecise = true;
		std::vector<double> tol;
		tol.push_back(0.001);
		tol.push_back(M_PI / 180.0);
		tol.push_back(0.0005);
		std::vector<double> params1, params2;
		shared_ptr<Geom3BSplineSurface> bspSurf3 = NURBSAPIBlend::BlendSurfaces(surf1, isU2, isFront2, cont1, params1, surf2, isU1, isFront1, cont2, params2, isAutoReverse, isPrecise, tol);
		BRepExtremaDistShapeShape dist1(MakeFace(surf1, 0.0), MakeFace(bspSurf3, 0.0));
		BRepExtremaDistShapeShape dist2(MakeFace(surf2, 0.0), MakeFace(bspSurf3, 0.0));
		CHECK(dist1.Value() == Approx(0.0).margin(0.1));
		CHECK(dist2.Value() == Approx(0.0).margin(0.1));
		double fpu1 = bspSurf3->FirstUParameter();
		double lpu1 = bspSurf3->LastUParameter();
		shared_ptr<Geom3Curve> u1 = bspSurf3->UIso(fpu1);
		shared_ptr<Geom3Curve> u2 = bspSurf3->UIso(lpu1);
		double f1 = surf1->FirstUParameter();
		double f2 = surf2->FirstUParameter();
		shared_ptr<Geom3Curve> c1 = surf1->UIso(f1);
		shared_ptr<Geom3Curve> c2 = surf2->UIso(f2);
		bool res1 = IsCurveOnSurf(num, ratio, u1, surf1);
		bool res2 = IsCurveOnSurf(num, ratio, u2, surf2);
		CHECK(res1 == true);
		CHECK(res2 == true);
		double res3 = NurbsSampleCurve(num, refTol, c1, u1);
		double res4 = NurbsSampleCurve(num, refTol, c2, u2);
		CHECK(res3 <= ratio);
		CHECK(res4 <= ratio);
		OCCTIO::OCCTTool::Write(MakeEdge(u1), outdir + "u1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(u2), outdir + "u2.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(c1), outdir + "c1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(c2), outdir + "c2.brep");
		OCCTIO::OCCTTool::Write(MakeFace(surf1, 0.0), outdir + "src1.brep");
		OCCTIO::OCCTTool::Write(MakeFace(surf2, 0.0), outdir + "src2.brep");
		OCCTIO::OCCTTool::Write(MakeFace(bspSurf3, 0.0), outdir + "result.brep");
	}}