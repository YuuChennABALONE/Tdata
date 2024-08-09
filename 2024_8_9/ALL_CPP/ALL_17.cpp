/* "AMCAX_API static int ValidMaxDegree(int npoles, bool isPeriodic)\t @return The maximum valid degree\n\t @param isPeriodic Whether the curve is periodic\n\t @param npoles The number of control points\n\t @brief Given the number of the control points, calculate the maximum valide degree of a BSpline curve\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBuildCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <nurbs/NURBSAPIExtend.hpp>
#include <geomAlgo/LawConstant.hpp>
#include <nurbs/NURBSAPILinearSweep.hpp>
#include <modeling/MakeFace.hpp>
std::shared_ptr<AMCAX::Geom3BSplineCurve> BuildBSpCurve(const std::vector<AMCAX::Point3>& poles, int degree, bool isPeriodic)
{
	int npoles = static_cast<int>(poles.size());
	if (isPeriodic)
	{
		return AMCAX::NURBSAPIBuildCurve::BuildCurve(poles, std::min(degree, npoles), true);
	}
	else
	{
		return AMCAX::NURBSAPIBuildCurve::BuildCurve(poles, std::min(degree, npoles - 1), false);
	}
}
TEST_CASE("case1: this is a test for testBuildCurve-IncreaseDegree", "[nurbs][BuildCurve][P2]")
{
	int num = 1000;
	double ratio = 0.1;
	double refTol = DEFAULT_TOLERANCE;
	SECTION("TestExtendFourPointsDynamic")
	{
		OUTPUT_DIRECTORY(nurbs,BuildCurve/ExtendFourPointsDynamic);
		std::vector<Point3> poles;
		Point3 p1(0.0, 0.0, 0.0);
		Point3 p2(0.0, 1.0, 0.0);
		Point3 p3(1.0, 1.0, 0.0);
		Point3 p4(1.0, 0.0, 0.0);
		poles.push_back(p1);
		poles.push_back(p2);
		poles.push_back(p3);
		poles.push_back(p4);
		std::vector<double> weights;
		weights.push_back(1.0);
		weights.push_back(1.2);
		weights.push_back(1.1);
		weights.push_back(1.0);
		auto oldcurve = NURBSAPIBuildCurve::BuildCurve(poles, weights, 3, false);
		int maxDeg = NURBSAPIBuildCurve::ValidMaxDegree(static_cast<int>(poles.size()), false);
		auto curve = NURBSAPIBuildCurve::BuildCurve(poles, weights, maxDeg, false);
		CHECK(curve->Degree() == maxDeg);
		double res33 = NurbsSampleCurve(num, ratio, oldcurve, curve);
		CHECK(res33 <= refTol);
		Point3 sp1 = curve->StartPoint();
		Point3 ep1 = curve->EndPoint();
		CHECK(sp1.X() == Approx(p1.X()));
		CHECK(sp1.Y() == Approx(p1.Y()));
		CHECK(sp1.Z() == Approx(p1.Z()));
		CHECK(ep1.X() == Approx(p4.X()));
		CHECK(ep1.Y() == Approx(p4.Y()));
		CHECK(ep1.Z() == Approx(p4.Z()));
		CHECK(curve->IsPeriodic() == false);
		OCCTIO::OCCTTool::Write(MakeVertex(p1), outdir + "p1.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p2), outdir + "p2.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p3), outdir + "p3.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p4), outdir + "p4.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curve), outdir + "result.brep");
		Point3 p(-1.0, -1.0, 0.0);
		auto extendedCurve = NURBSAPIExtend::ExtendCurveToDynamicPoint(curve, false, p);
	}}