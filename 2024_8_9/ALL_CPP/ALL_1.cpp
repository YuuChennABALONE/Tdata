/* "AMCAX_API static Array2<std::shared_ptr<Geom3BSplineSurface>> ExplodeSurface(const std::shared_ptr<Geom3BSplineSurface>& surface)\t @return The result surfaces\n\t @param surface The given surface\n\t @brief Explode a surface into patches at C0 isocurves\n,\n",
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
TEST_CASE("case1: this is a test for Explode-ExplodeSurface", "[nurbs][Explode][P1]")
{
	int num = 1000;
	double sTol = DEFAULT_TOLERANCE;
	double ratio = 0.1;
	double linTol = DEFAULT_TOLERANCE;
	SECTION("isUPeriodic+nonVPeriodic")
	{
		OUTPUT_DIRECTORY(nurbs, Explode/ExplodeSurface3);
		string filedir = INPUT_PATH_PREFIX"./TestNURBS/TestJoinSurface/";
		std::vector<std::shared_ptr<Geom3BSplineSurface>> surfaces;
		surfaces.push_back(ReadBRepSurface(filedir + "surface0.brep"));
		surfaces.push_back(ReadBRepSurface(filedir + "surface1.brep"));
		surfaces.push_back(ReadBRepSurface(filedir + "surface2.brep"));
		surfaces.push_back(ReadBRepSurface(filedir + "surface3.brep"));
		auto [sortedSurfaces, isUIso, isFrontBackReverse, isIsoReverse, isLocalUPeriodic, isLocalVPeriodic] = NURBSAPIJoin::JoinSurfacesPrepare(surfaces, 0.0001);
		auto [isSucceed, result] = NURBSAPIJoin::JoinSurfaces(sortedSurfaces, isUIso, isFrontBackReverse, isIsoReverse, isLocalUPeriodic, isLocalVPeriodic);
		Throw_Construction_Error_if(!isSucceed, "failed");
		CHECK(isSucceed == true);
		auto explodeResult = NURBSAPIExplode::ExplodeSurface(result);
		int row = explodeResult.NRow();
		int col = explodeResult.NCol();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				OCCTIO::OCCTTool::Write(MakeFace(explodeResult(i, j), 0.0), outdir +  "expSurface" + to_string(i) + to_string(j) +".brep");
			}
		}
		CHECK(row*col == 4);
		TopoShape f1 = MakeFace(surfaces[0],0.0);
		TopoShape f2 = MakeFace(surfaces[1], 0.0);
		TopoShape f3 = MakeFace(surfaces[2], 0.0);
		TopoShape f4 = MakeFace(surfaces[3], 0.0);
		TopoShape f = MakeFace(result,0.0);
		TopoShape exp1 = MakeFace(explodeResult(0, 0), 0.0);
		TopoShape exp2 = MakeFace(explodeResult(1, 0), 0.0);
		TopoShape exp3 = MakeFace(explodeResult(2, 0), 0.0);
		TopoShape exp4 = MakeFace(explodeResult(3, 0), 0.0);
		GlobalProperty props1, props2, props3, props4, props5, props6, props7, props8;
		double surf1 = GetSurfaceProperties(f1, props1, true, false);
		double surf2 = GetSurfaceProperties(f2, props2, true, false);
		double surf3 = GetSurfaceProperties(f3, props3, true, false);
		double surf4 = GetSurfaceProperties(f4, props4, true, false);
		double surface = GetSurfaceProperties(f, props5, true, false);
		double exSurf1 = GetSurfaceProperties(exp1, props5, true, false);
		double exSurf2 = GetSurfaceProperties(exp2, props6, true, false);
		double exSurf3 = GetSurfaceProperties(exp3, props7, true, false);
		double exSurf4 = GetSurfaceProperties(exp4, props8, true, false);
		double surf = surf1 + surf2 + surf3 + surf4;
		double dif = abs(surface - surf);
		double dif1 = abs(surf1 - exSurf1);
		double dif2 = abs(surf2 - exSurf2);
		double dif3 = abs(surf3 - exSurf3);
		double dif4 = abs(surf4 - exSurf4);
		CHECK(dif1 < 0.1);
		CHECK(dif2 < 0.1);
		CHECK(dif3 < 0.1);
		CHECK(dif4 < 0.1);
		double res1 = NurbsSampleSurface(num, sTol, surfaces[0], explodeResult(0, 0));
		double res2 = NurbsSampleSurface(num, sTol, surfaces[1], explodeResult(1, 0));
		double res3 = NurbsSampleSurface(num, sTol, surfaces[2], explodeResult(2, 0));
		double res4 = NurbsSampleSurface(num, sTol, surfaces[3], explodeResult(3, 0));
		CHECK(res1 <= ratio);
		CHECK(res2 <= ratio);
		CHECK(res3 <= ratio);
		CHECK(res4 <= ratio);
		OCCTIO::OCCTTool::Write(MakeFace(surfaces[0], 0.0), outdir + "surf1.brep");
		OCCTIO::OCCTTool::Write(MakeFace(surfaces[1], 0.0), outdir + "surf2.brep");
		OCCTIO::OCCTTool::Write(MakeFace(surfaces[2], 0.0), outdir + "surf3.brep");
		OCCTIO::OCCTTool::Write(MakeFace(surfaces[3], 0.0), outdir + "surf4.brep");
		OCCTIO::OCCTTool::Write(MakeFace(result, 0.0), outdir + "joinSurface.brep");
	}}