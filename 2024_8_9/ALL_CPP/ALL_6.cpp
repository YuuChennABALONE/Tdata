/* "AMCAX_API static std::shared_ptr<Geom3BSplineSurface> CurveNetworkSurfaceGordon(const std::vector<std::shared_ptr<Geom3BSplineCurve>>& verticalCurves, const std::vector<std::shared_ptr<Geom3BSplineCurve>>& horizontalCurves)\t @return The Gordon surface which go through the curves\n\t @param horizontalCurves Horizontal network curves\n\t @param verticalCurves Vertical network curves\n\t @brief Coons-Gordon surface\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPICurveNetworkSurface.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/MakeFace.hpp>
#include <nurbs/NURBSAPILoft.hpp>
#include <common/Precision.hpp>
#include <modeling/MakeEdge.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
using namespace std;
using namespace AMCAX;
double NurbsSampleCurveOnSurface(int num, double tol, const shared_ptr<Geom3Curve>& curve, const shared_ptr<Geom3Surface>& surf)
{
	const int nsample = num;
	double fp1 = curve->FirstParameter();
	double lp1 = curve->LastParameter();
	double delta1 = (lp1 - fp1) / nsample;
	Point3 p;
	int n = 0;
	for (int i = 0; i < nsample; i++)
	{
		double t1 = fp1 + i * delta1;
		curve->D0(t1, p);
		GeomAPIProjectPointOnSurface projector(p, surf);
		double dis = projector.LowerDistance();
		if (dis <= tol)
		{
			n++;
		}
	}
	double res = 1.0 * (num - n) / num;
	return res;
}
vector< shared_ptr<Geom3BSplineCurve>> ConstructBSplineCurve()
{
	vector<shared_ptr<Geom3BSplineCurve>> vec;
	shared_ptr<Geom3BSplineCurve> vbsp1, vbsp2, vbsp3, vbsp4, hbsp1, hbsp2, hbsp3;
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(0.0, -1.0, 0.1));
		poles.push_back(Point3(0.07, -0.7, 0.2));
		poles.push_back(Point3(0.1, -0.3, 0.1));
		poles.push_back(Point3(0.12, 0.0, -0.1));
		poles.push_back(Point3(0.20, 0.3, -0.2));
		poles.push_back(Point3(0.07, 0.7, -0.3));
		poles.push_back(Point3(0.0, 1.0, 0.0));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		vbsp1 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(2.0, -2.0, -0.1));
		poles.push_back(Point3(2.1, -1.3, -0.2));
		poles.push_back(Point3(2.15, -0.8, -0.1));
		poles.push_back(Point3(1.83, -0.2, 0.1));
		poles.push_back(Point3(1.48, 0.1, 0.2));
		poles.push_back(Point3(1.0, 1.0, 0.1));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		vbsp2 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(3.0, -2.0, 0.1));
		poles.push_back(Point3(3.07, -1.3, 0.2));
		poles.push_back(Point3(3.1, -0.3, 0.1));
		poles.push_back(Point3(3.12, 0.0, -0.1));
		poles.push_back(Point3(3.0, 0.3, -0.2));
		poles.push_back(Point3(2.57, 0.7, -0.3));
		poles.push_back(Point3(2.2, 1.0, 0.0));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		vbsp3 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(4.0, -1.5, -0.1));
		poles.push_back(Point3(4.1, -1.3, -0.2));
		poles.push_back(Point3(4.15, -0.8, -0.1));
		poles.push_back(Point3(3.83, -0.2, 0.1));
		poles.push_back(Point3(3.48, 0.1, 0.2));
		poles.push_back(Point3(3.0, 1.0, 0.1));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		vbsp4 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(0.0, -1.0, 0.1));
		poles.push_back(Point3(0.9, -1.5, -0.1));
		poles.push_back(Point3(3.0, -1.8, 0.1));
		poles.push_back(Point3(4.0, -1.5, -0.1));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		hbsp1 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		std::vector<Point3> poles;
		poles.push_back(Point3(0.0, 0.0, 0.0));
		poles.push_back(Point3(1.2, -1.15, -0.1));
		poles.push_back(Point3(2.7, -1.05, 0.1));
		poles.push_back(Point3(3.7, -1.3, -0.1));
		poles.push_back(Point3(5.0, -1.0, 0.1));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		std::vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		std::vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		hbsp2 = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	{
		int deg = 3;
		vector<Point3> poles;
		poles.push_back(Point3(0.0, 1.0, 0.0));
		poles.push_back(Point3(0.9, 0.15, -0.1));
		poles.push_back(Point3(1.7, 0.05, 0.1));
		poles.push_back(Point3(2.7, 0.3, -0.1));
		poles.push_back(Point3(3.0, 1.0, 0.1));
		int nknots = static_cast<int>(poles.size()) - deg + 1;
		vector<double> knots(nknots);
		for (int i = 0; i < nknots; i++)
		{
			knots[i] = (double)i / (double)(nknots - 1.0);
		}
		vector<int> mults(nknots, 1);
		mults.front() = deg + 1;
		mults.back() = deg + 1;
		hbsp3 = make_shared<Geom3BSplineCurve>(poles, knots, mults, deg);
	}
	vec.push_back(vbsp1);
	vec.push_back(vbsp2);
	vec.push_back(vbsp3);
	vec.push_back(vbsp4);
	vec.push_back(hbsp1);
	vec.push_back(hbsp2);
	vec.push_back(hbsp3);
	return vec;
}
TEST_CASE("bug1: CurveNetworkSurface ", "[nurbs][CurveNetworkSurface][fixbug]")
{
	OUTPUT_DIRECTORY(nurbs, CurveNetworkSurface/bug464);
	double refTol = 0.1;
	vector< shared_ptr<Geom3BSplineCurve>> vec = ConstructBSplineCurve();
	TopoEdge edge1 = MakeEdge(vec[0]);
	TopoEdge edge2 = MakeEdge(vec[1]);
	TopoEdge edge3 = MakeEdge(vec[2]);
	TopoEdge edge4 = MakeEdge(vec[3]);
	TopoEdge edge5 = MakeEdge(vec[4]);
	TopoEdge edge6 = MakeEdge(vec[5]);
	TopoEdge edge7 = MakeEdge(vec[6]);
	vector<shared_ptr<Geom3BSplineCurve>> horizontalCurves, verticalCurves;
	verticalCurves.push_back(vec[0]);
	verticalCurves.push_back(vec[1]);
	verticalCurves.push_back(vec[2]);
	verticalCurves.push_back(vec[3]);
	horizontalCurves.push_back(vec[4]);
	horizontalCurves.push_back(vec[5]);
	horizontalCurves.push_back(vec[6]);
	shared_ptr<Geom3BSplineSurface> surf = NURBSAPICurveNetworkSurface::CurveNetworkSurfaceGordon(verticalCurves, horizontalCurves);
	TopoShape surface = MakeFace(surf, 0.0);
	BRepExtremaDistShapeShape dist1(edge1, surface);
	BRepExtremaDistShapeShape dist2(edge2, surface);
	BRepExtremaDistShapeShape dist3(edge3, surface);
	BRepExtremaDistShapeShape dist4(edge4, surface);
	BRepExtremaDistShapeShape dist5(edge5, surface);
	BRepExtremaDistShapeShape dist6(edge6, surface);
	BRepExtremaDistShapeShape dist7(edge7, surface);
	CHECK(dist3.Value() <= Approx(refTol));
	CHECK(dist4.Value() <= Approx(refTol));
	CHECK(dist7.Value() <= Approx(refTol));
	OCCTIO::OCCTTool::Write(MakeEdge(vec[0]), outdir + "vbsp1.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[1]), outdir + "vbsp2.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[2]), outdir + "vbsp3.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[3]), outdir + "vbsp4.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[4]), outdir + "hbsp1.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[5]), outdir + "hbsp2.brep");
	OCCTIO::OCCTTool::Write(MakeEdge(vec[6]), outdir + "hbsp3.brep");
	OCCTIO::OCCTTool::Write(surface, outdir + "surfResult.brep");
}