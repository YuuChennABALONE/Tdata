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
TEST_CASE("Not Fix bug1: testBlendSurfaces-Extend ", "[nurbs][Blend][bug]")
{
	bool isAutoReverse = true;
	bool isPrecise = true;
	std::vector<double> tol;
	tol.push_back(0.001);
	tol.push_back(M_PI / 180.0);
	tol.push_back(0.0005);
	std::vector<double> params1, params2;
	auto surf1 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface1.brep");
	auto surf2 = ReadBRepSurface(INPUT_PATH_PREFIX "/TestNURBS/TestBridgeSurf/surface2.brep");
	SECTION("ContinuityType::C0")
	{
		ContinuityType cont1 = ContinuityType::C0;
		ContinuityType cont2 = ContinuityType::C0;
		bool isU1 = false;
		bool isU2 = false;}
}