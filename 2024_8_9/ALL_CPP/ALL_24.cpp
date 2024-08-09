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
TEST_CASE("bug3: TestBridgeTrimmedPeriodicFace ", "[nurbs][Blend][fixbug]")
{
	OUTPUT_DIRECTORY(nurbs, Blend/bug684/testBlendFaces);
	std::string filedir = INPUT_PATH_PREFIX "/TestNURBS/TestBlendFaces/";
	TopoFace f1 = ReadBRepFace(filedir + "surfaceShapeFrom1.brep");
	TopoFace f2 = ReadBRepFace(filedir + "surfaceShapeFrom2.brep");
	vector<TopoEdge>vec1;
	vector<TopoEdge>vec2;
	for (TopoExplorer exp(f1, ShapeType::Edge); exp.More(); exp.Next())
	{
		TopoEdge c1 = static_cast<const TopoEdge&>(exp.Current());
		vec1.push_back(c1);
	}
	for (TopoExplorer expE(f2, ShapeType::Edge); expE.More(); expE.Next())
	{
		TopoEdge c2 = static_cast<const TopoEdge&>(expE.Current());
		vec2.push_back(c2);
	}
	vector<double>parameters1 = { 1.0, 1.0 };
	vector<double>parameters2 = { 1.0, 1.0 };
	vector<double>tol = { 0.001, 0.1 * M_PI / 180.0, 0.05 };
	for (int i = 0; i < vec1.size(); i++)
	{
		for (int j = 0; j < vec2.size(); j++)
		{
			shared_ptr<Geom3BSplineSurface> blendSurface = NURBSAPIBlend::BlendFaces(f1, vec1[i], ContinuityType::G2, parameters1, f2, vec2[j], ContinuityType::G2, parameters2, true, true, tol);
			OCCTIO::OCCTTool::Write(MakeFace(blendSurface, 0.0), outdir + "G2-result" + to_string(i + 1) + to_string(j + 1) + ".brep");
		}
	}
	OCCTIO::OCCTTool::Write(f1, outdir + "f1.brep");
	OCCTIO::OCCTTool::Write(f2, outdir + "f2.brep");
	OCCTIO::OCCTTool::Write(vec1[0], outdir + "e1.brep");
	OCCTIO::OCCTTool::Write(vec1[1], outdir + "e2.brep");
	OCCTIO::OCCTTool::Write(vec1[2], outdir + "e3.brep");
	OCCTIO::OCCTTool::Write(vec1[3], outdir + "e4.brep");
	OCCTIO::OCCTTool::Write(vec2[0], outdir + "e11.brep");
	OCCTIO::OCCTTool::Write(vec2[1], outdir + "e22.brep");
	OCCTIO::OCCTTool::Write(vec2[2], outdir + "e33.brep");
	OCCTIO::OCCTTool::Write(vec2[3], outdir + "e44.brep");
}