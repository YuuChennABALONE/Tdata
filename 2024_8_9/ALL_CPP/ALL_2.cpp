/* "AMCAX_API static std::vector<std::shared_ptr<Geom3BSplineCurve>> ExplodeCurve(const std::shared_ptr<Geom3BSplineCurve>& curve)\t @return The result curves\n\t @param curve The given curve\n\t @brief Explode a curve into curves at C0 points\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIExplode.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoTool.hpp>
#include <nurbs/NURBSAPIJoin.hpp>
#include <nurbs/NURBSAPIExplode.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
TEST_CASE("case1: this is a test for Explode-ExplodeCurve", "[nurbs][Explode][P1]")
{
	int num = 1000;
	double sTol = DEFAULT_TOLERANCE;
	double ratio = 0.1;
	double linTol = DEFAULT_TOLERANCE;
    string filename;
	string filedir = INPUT_PATH_PREFIX"./TestNURBS/TestJoinCurve/";
	SECTION("isPeriodic")
	{
		OUTPUT_DIRECTORY(nurbs, Explode/ExplodeCurve1);
		filename = "periodicCurve";
		std::vector<std::shared_ptr<Geom3BSplineCurve>> curves;
		for (int i = 0; i < 3; i++)
		{
			curves.push_back(ReadBRepCurve(filedir + filename + std::to_string(i) + ".brep"));
		}
		auto [sortedCurves, isReverse, isResultPeriodic] = NURBSAPIJoin::JoinCurvePrepare(curves, 0.0001);
		auto results = NURBSAPIJoin::JoinCurves(sortedCurves, isReverse, isResultPeriodic);
		int nresults = static_cast<int>(results.size());
		for (int i = 0; i < nresults; i++)
		{
			OCCTIO::OCCTTool::Write(MakeEdge(results[i]), outdir + "joinCurve" + to_string(i) + ".brep");
		}
		auto explodeResult = NURBSAPIExplode::ExplodeCurve(results.front());
		int expResults = static_cast<int>(explodeResult.size());
		for (int j = 0; j < expResults; j++)
		{
			OCCTIO::OCCTTool::Write(MakeEdge(explodeResult[j]), outdir + "expCurve" + to_string(j) + ".brep");
		}
		CHECK(results.size() == 1);
		CHECK(explodeResult.size() == 3);
		Point3 p1, p2, p3, p4;
		p1 = curves[0]->StartPoint();
		p2 = curves[2]->EndPoint();
		p3 = results[0]->StartPoint();
		p4 = results[0]->EndPoint();
		CHECK(p1.X() == Approx(p3.X()));
		CHECK(p1.Y() == Approx(p3.Y()));
		CHECK(p1.Z() == Approx(p3.Z()));
		CHECK(p2.X() == Approx(p4.X()));
		CHECK(p2.Y() == Approx(p4.Y()));
		CHECK(p2.Z() == Approx(p4.Z()));
		TopoShape c1 = MakeEdge(curves[0]);
		TopoShape c2 = MakeEdge(curves[1]);
		TopoShape c3 = MakeEdge(curves[2]);
		TopoShape c = MakeEdge(results[0]);
		TopoShape e1 = MakeEdge(explodeResult[0]);
		TopoShape e2 = MakeEdge(explodeResult[1]);
		TopoShape e3 = MakeEdge(explodeResult[2]);
		GlobalProperty props1, props2, props3, props4, props5, props6, props7;
		double len1 = GetLinearProperties(c1, props1, true, false);
		double len2 = GetLinearProperties(c2, props2, true, false);
		double len3 = GetLinearProperties(c3, props3, true, false);
		double joinLen = GetLinearProperties(c, props4, true, false);
		double exLen1 = GetLinearProperties(e1, props5, true, false);
		double exLen2 = GetLinearProperties(e2, props6, true, false);
		double exLen3 = GetLinearProperties(e3, props7, true, false);
		double cuvLen = len1 + len2 + len3;
		double len = abs(cuvLen - joinLen);
		double len11 = abs(len1 - exLen1);
		double len22 = abs(len2 - exLen2);
		double len33 = abs(len3 - exLen3);
		CHECK(len < 0.1);
		CHECK(len11 < 0.1);
		CHECK(len22 < 0.1);
		CHECK(len33 < 0.1);
		double res1 = NurbsSampleCurve(num, sTol, curves[0], explodeResult[0]);
		double res2 = NurbsSampleCurve(num, sTol, curves[1], explodeResult[1]);
		double res3 = NurbsSampleCurve(num, sTol, curves[2], explodeResult[2]);
		CHECK(res1 <= ratio);
		CHECK(res2 <= ratio);
		CHECK(res3 <= ratio);
		OCCTIO::OCCTTool::Write(MakeEdge(curves[0]), outdir + "curve0.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curves[1]), outdir + "curve1.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curves[2]), outdir + "curve2.brep");
	}}