/* "AMCAX_API static std::vector<std::pair<double, bool>> CalcParamCorrespondece( const std::vector<std::shared_ptr<Geom3Curve>>& curves, bool isPeriodic, bool isConsiderReverse),\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPICorrespondence.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
using namespace std;
TEST_CASE("case1: this is a test for CalcParamCorrespondece", "[nurbs][Correspondence][P1]")
{
	OUTPUT_DIRECTORY(nurbs, Correspondence);
	vector<shared_ptr<Geom3Curve>> curves;
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
		OCCTIO::OCCTTool::Write(MakeEdge(vbsp1), outdir + "vbsp1.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(vbsp2), outdir + "vbsp2.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(vbsp3), outdir + "vbsp3.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(vbsp4), outdir + "vbsp4.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(hbsp1), outdir + "hbsp1.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(hbsp2), outdir + "hbsp2.brep");
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
		OCCTIO::OCCTTool::Write(MakeEdge(hbsp3), outdir + "hbsp3.brep");
	}
	curves.push_back(vbsp1);
	curves.push_back(vbsp2);
	curves.push_back(vbsp3);
	curves.push_back(vbsp4);
	curves.push_back(hbsp1);
	curves.push_back(hbsp2);
	curves.push_back(hbsp3);
	SECTION("isPeriodic+isConsiderReverse")
	{
		bool isPeriodic = true;
		bool isConsiderReverse = true;
		vector<pair<double, bool>> corrs = NURBSAPICorrespondence::CalcParamCorrespondece(curves, isPeriodic, isConsiderReverse);
		CHECK(corrs[0].first == 0.0);
		CHECK(corrs[0].second == false);
		CHECK(corrs[1].first > 0.0);
		CHECK(corrs[1].second == true);
		CHECK(corrs[2].first > 0.0);
		CHECK(corrs[2].second == true);
		CHECK(corrs[3].first > 0.0);
		CHECK(corrs[3].second == true);
		CHECK(corrs[4].first > 0.0);
		CHECK(corrs[4].second == true);
		CHECK(corrs[5].first > 0.0);
		CHECK(corrs[5].second == true);
		CHECK(corrs[6].first > 0.0);
		CHECK(corrs[6].second == true);
		CHECK(corrs.size() == 7);
	}}