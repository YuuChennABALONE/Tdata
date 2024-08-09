/* "AMCAX_API static std::shared_ptr<Geom3BSplineSurface> BlendFaces( const TopoFace& face1, const TopoEdge& edge1, ContinuityType cont1, std::vector<double>& parameters1, const TopoFace& face2, const TopoEdge& edge2, ContinuityType cont2, std::vector<double>& parameters2, bool autoReverse, bool isPrecise, const std::vector<double>& tol),\n",
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
#include <geometry/Geom3CurveLocalProperty.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
double NURBSSampleEdge1(int num, double tol, const shared_ptr<Geom3Curve>& curve, const TopoEdge& edge)
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
TopoEdge ChooseSimilarEdge1(const TopoShape& shape, const TopoEdge& edge)
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
TEST_CASE("case1: this is a test for testBlendSurfaces-Extend", "[nurbs][Blend][P1]")
{
	int num = 1000;
	double ratio = 0.1;
	double refTol = DEFAULT_TOLERANCE;
	bool isAutoReverse = true;
	bool isPrecise = true;
	std::vector<double> tol;
	tol.push_back(0.001);
	tol.push_back(M_PI / 180.0);
	tol.push_back(0.0005);
	std::vector<double> params1, params2;
	auto surf1 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface1.brep");
	auto surf2 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface2.brep");
	double fup1 = surf1->FirstUParameter();
	double lup1 = surf1->LastUParameter();
	double fvp1 = surf1->FirstVParameter();
	double lvp1 = surf1->LastVParameter();
	shared_ptr<Geom3Curve> fuc1 = surf1->UIso(fup1);
	shared_ptr<Geom3Curve> luc1 = surf1->UIso(lup1);
	shared_ptr<Geom3Curve> fvc1 = surf1->VIso(fvp1);
	shared_ptr<Geom3Curve> lvc1 = surf1->VIso(lvp1);
	double uf1 = fuc1->FirstParameter();
	double ul1 = luc1->FirstParameter();
	double vf1 = fvc1->FirstParameter();
	double vl1 = lvc1->FirstParameter();
	Point3 p1, p2 , p3, p4;
	Vector3 fuv1, luv1, fvv1, lvv1;
	fuc1->D1(uf1, p1, fuv1);
	luc1->D1(ul1, p2, luv1);
	fvc1->D1(vf1, p3, fvv1);
	lvc1->D1(vl1, p4, lvv1);
	double fup2 = surf2->FirstUParameter();
	double lup2 = surf2->LastUParameter();
	double fvp2 = surf2->FirstVParameter();
	double lvp2 = surf2->LastVParameter();
	shared_ptr<Geom3Curve> fuc2 = surf2->UIso(fup2);
	shared_ptr<Geom3Curve> luc2 = surf2->UIso(lup2);
	shared_ptr<Geom3Curve> fvc2 = surf2->VIso(fvp2);
	shared_ptr<Geom3Curve> lvc2 = surf2->VIso(lvp2);
	double uf2 = fuc2->FirstParameter();
	double ul2 = luc2->FirstParameter();
	double vf2 = fvc2->FirstParameter();
	double vl2 = lvc2->FirstParameter();
	Point3 p5, p6, p7, p8;
	Vector3 fuv2, luv2, fvv2, lvv2;
	fuc2->D1(uf2, p5, fuv2);
	luc2->D1(ul2, p6, luv2);
	fvc2->D1(vf2, p7, fvv2);
	lvc2->D1(vl2, p8, lvv2);
	SECTION("isFront:true+true")
			{
				OUTPUT_DIRECTORY(nurbs, Blend/Extend/BlendSurfaces/G2/tt/tt);
				bool isFront1 = true;
				bool isFront2 = true;
				shared_ptr<Geom3BSplineSurface> bspSurf3 = NURBSAPIBlend::BlendSurfaces(surf1, isU1, isFront1, cont1, params1, surf2, isU2, isFront2, cont2, params2, isAutoReverse, isPrecise, tol);
				double fpu3 = bspSurf3->FirstUParameter();
				double lpu3 = bspSurf3->LastUParameter();
				shared_ptr<Geom3Curve> fuc3 = bspSurf3->UIso(fpu3);
				shared_ptr<Geom3Curve> luc3 = bspSurf3->UIso(lpu3);
				double res1 = NurbsSampleCurve(num, refTol, fuc3, fuc1);
				double res2 = NurbsSampleCurve(num, refTol, luc3, fuc2);
				CHECK(res1 <= ratio);
				CHECK(res2 <= ratio);
				pair<double, double> res3 = NurbsContinousSample(num, fuc3, fuc1);
				pair<double, double> res4 = NurbsContinousSample(num, luc3, fuc2);
				CHECK(res3.first == 0.0);
				CHECK(res3.second == 0.0);
				CHECK(res4.first == 0.0);
				CHECK(res4.second == 0.0);
				OCCTIO::OCCTTool::Write(MakeEdge(fuc1), outdir + "fuc1.brep");
				OCCTIO::OCCTTool::Write(MakeEdge(fvc1), outdir + "fvc1.brep");
				OCCTIO::OCCTTool::Write(MakeEdge(fuc2), outdir + "fuc2.brep");
				OCCTIO::OCCTTool::Write(MakeEdge(fvc2), outdir + "fvc2.brep");
				OCCTIO::OCCTTool::Write(MakeEdge(fuc3), outdir + "fuc3.brep");
				OCCTIO::OCCTTool::Write(MakeFace(surf1, 0.0), outdir + "src1.brep");
				OCCTIO::OCCTTool::Write(MakeFace(surf2, 0.0), outdir + "src2.brep");
				OCCTIO::OCCTTool::Write(MakeFace(bspSurf3, 0.0), outdir + "result.brep");
			}}