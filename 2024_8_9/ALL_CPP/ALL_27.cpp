/* "AMCAX_API static std::shared_ptr<Geom3BSplineCurve> BlendCurves( const std::shared_ptr<Geom3BSplineCurve>& curve1, bool isFront1, ContinuityType cont1, const std::shared_ptr<Geom3BSplineCurve>& curve2, bool isFront2, ContinuityType cont2),\n",
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
TEST_CASE("case1: this is a test for testBlendCurves", "[nurbs][Blend][P1]")
{
	int num = 1000;	
	double ratio = 0.1;
	double refTol = DEFAULT_TOLERANCE;
	SECTION("testBlendCurves")
	{
		OUTPUT_DIRECTORY(nurbs, Blend/BlendCurves);
		auto cont1 = ContinuityType::G2;
		auto cont2 = ContinuityType::G2;
		bool isFront1 = true;
		bool isFront2 = true;
		std::shared_ptr<Geom3BSplineCurve> bsp1, bsp2;
		{
			std::vector<Point3> poles;
			poles.push_back(Point3(0., -1., 0.));
			poles.push_back(Point3(.7, -.7, 0.));
			poles.push_back(Point3(1., -.3, 0.));
			poles.push_back(Point3(1.2, 0., 0.));
			poles.push_back(Point3(2., .3, 0.));
			poles.push_back(Point3(.7, 1.7, 0.));
			poles.push_back(Point3(0., 1., 0.));
			std::vector<double> weights;
			weights.push_back(1.0);
			weights.push_back(1.3);
			weights.push_back(1.2);
			weights.push_back(0.7);
			weights.push_back(1.3);
			weights.push_back(1.0);
			weights.push_back(1.2);
			std::vector<double> knots;
			knots.push_back(0.);
			knots.push_back(.25);
			knots.push_back(.5);
			knots.push_back(.75);
			knots.push_back(1.);
			std::vector<int> mults(5, 1);
			mults.front() = 4;
			mults.back() = 4;
			bsp1 = std::make_shared<Geom3BSplineCurve>(poles, weights, knots, mults, 3);
		}
		{
			std::vector<Point3> spinePoles;
			std::vector<double> spineKnots(4);
			std::vector<int> spineMults(4, 1);
			spinePoles.push_back(Point3(0.0, 0.0, 0.0));
			spinePoles.push_back(Point3(-0.1, 1.0, -0.2));
			spinePoles.push_back(Point3(0.1, 2.0, -0.1));
			spinePoles.push_back(Point3(0.2, 3.0, 0.1));
			spinePoles.push_back(Point3(0.1, 4.0, 0.0));
			spinePoles.push_back(Point3(0.0, 5.0, -0.1));
			std::vector<double> weights;
			weights.push_back(1.0);
			weights.push_back(1.3);
			weights.push_back(1.2);
			weights.push_back(0.7);
			weights.push_back(1.3);
			weights.push_back(1.0);
			spineKnots[0] = 0;
			spineKnots[1] = 1.0 / 3.0;
			spineKnots[2] = 2.0 / 3.0;
			spineKnots[3] = 1;
			spineMults.front() = 4;
			spineMults.back() = 4;
			bsp2 = std::make_shared<Geom3BSplineCurve>(spinePoles, weights, spineKnots, spineMults, 3);
		}
		std::vector<double> params1, params2;
		auto bsp3 = NURBSAPIBlend::BlendCurves(bsp1, isFront1, cont1, params1, bsp2, isFront2, cont2, params2);
		Point3 sp1 = bsp1->StartPoint();
		Point3 ep1 = bsp1->EndPoint();
		Point3 sp2 = bsp2->StartPoint();
		Point3 ep2 = bsp2->EndPoint();
		Point3 sp3 = bsp3->StartPoint();
		Point3 ep3 = bsp3->EndPoint();
		CHECK(sp3.X() == Approx(sp1.X()).margin(1e-7));
		CHECK(sp3.Y() == Approx(sp1.Y()));
		CHECK(sp3.Z() == Approx(sp1.Z()));
		CHECK(ep3.X() == Approx(sp2.X()).margin(1e-7));
		CHECK(ep3.Y() == Approx(sp2.Y()).margin(1e-7));
		CHECK(ep3.Z() == Approx(sp2.Z()).margin(1e-7));
		shared_ptr<Geom3BSplineCurve> bspCurve = ReadBRepCurve(INPUT_PATH_PREFIX "/TestNURBS/TestBlendCurves/Rhino/rhinoResult.brep");
		double res = NurbsSampleCurve(num, refTol, bsp3, bspCurve);
		CHECK(res <= ratio);
		OCCTIO::OCCTTool::Write(MakeEdge(bsp1), outdir + "src1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bsp2), outdir + "src2.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bsp3), outdir + "result.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bspCurve), outdir + "rhinoResult.brep");
	}}