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
#include <geometry/Geom3CurveLocalProperty.hpp>
TEST_CASE("Not Fix bug1: testBlendCurves2-Extend ", "[nurbs][Blend][bug]")
{
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
	double lp1 = bsp1->LastParameter();
	Point3 p1, pp1, p2, pp2;
	Vector3 ev1;
	bsp1->D1(lp1, pp1, ev1);
	std::vector<double> params1, params2;
	auto cont1 = ContinuityType::G2;
	auto cont2 = ContinuityType::G2;
	SECTION("false+true")
	{
		OUTPUT_DIRECTORY(nurbs, Blend/Extend/bug792);
		bool isFront1 = false;
		bool isFront2 = true;
		auto bsp3 = NURBSAPIBlend::BlendCurves(bsp1, isFront1, cont1, params1, bsp2, isFront2, cont2, params2);
		double fp3 = bsp3->FirstParameter();
		Point3 p3;
		Vector3 sv3;
		bsp3->D1(fp3, p3, sv3);
		bool res1 = Direction3(sv3).IsParallel(Direction3(ev1), Precision::Angular());
		CHECK(res1 == true);
		OCCTIO::OCCTTool::Write(MakeVertex(p3), outdir + "p3.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(pp1), outdir + "pp1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bsp1), outdir + "src1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bsp2), outdir + "src2.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(bsp3), outdir + "result.brep");
	}
}