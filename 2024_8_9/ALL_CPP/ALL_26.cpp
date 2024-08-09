/* "AMCAX_API static std::shared_ptr<Geom3BSplineCurve> BlendCurves( const std::shared_ptr<Geom3BSplineCurve>& curve1, bool isFront1, ContinuityType cont1, std::vector<double>& parameters1, const std::shared_ptr<Geom3BSplineCurve>& curve2, bool isFront2, ContinuityType cont2, std::vector<double>& parameters2),\n",
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
TEST_CASE("bug2: TestBridgeTrimmedPeriodicFace ", "[nurbs][Blend][fixbug]")
{
	int num = 1000;
	double ratio = 0.1;
	double refTol = DEFAULT_TOLERANCE;
	SECTION("TestBridgeCurve2")
	{
		OUTPUT_DIRECTORY(nurbs, Blend/bug680/BridgeCurve2);
		std::string filedir = INPUT_PATH_PREFIX "/TestNURBS/TestBridgeCurve2/";
		auto curve1 = ReadBRepCurve(filedir + "curve1.brep");
		auto curve2 = ReadBRepCurve(filedir + "curve2.brep");
		auto bridge = NURBSAPIBlend::BlendCurves(curve1, false, ContinuityType::G2, curve2, true, ContinuityType::G2);
		Point3 sp1 = curve1->StartPoint();
		Point3 ep1 = curve1->EndPoint();
		Point3 sp2 = curve2->StartPoint();
		Point3 ep2 = curve2->EndPoint();
		Point3 sp3 = bridge->StartPoint();
		Point3 ep3 = bridge->EndPoint();
		CHECK(sp3.X() == Approx(ep1.X()).margin(1e-7));
		CHECK(sp3.Y() == Approx(ep1.Y()));
		CHECK(sp3.Z() == Approx(ep1.Z()));
		CHECK(ep3.X() == Approx(sp2.X()).margin(1e-7));
		CHECK(ep3.Y() == Approx(sp2.Y()).margin(1e-7));
		CHECK(ep3.Z() == Approx(sp2.Z()).margin(1e-7));
		auto curve = ReadBRepCurve(filedir + "Rhino/rhinoResult.brep");
		double res = NurbsSampleCurve(num, refTol, bridge, curve);
		OCCTIO::OCCTTool::Write(MakeEdge(curve1), outdir + "src1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curve2), outdir + "src2.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bridge), outdir + "result.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curve), outdir + "rhinoResult.brep");
	}
}