/* "AMCAX_API static std::shared_ptr<Geom3BSplineCurve> BuildCurve(const std::vector<Point3>& poles, int degree, bool isPeriodic)\t @return The built curve. If building curve is failed, return nullptr\n\t @param isPeriodic Whether the curve is periodic or not\n\t @param degree The curve degree\n\t @param poles Curve poles. If it is a periodic curve, don't include the point at the end that repeats the first point\n\t @brief Build BSpline curve\n,\n",
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
TEST_CASE("case1: this is a test for testBuildCurve", "[nurbs][BuildCurve][P1]")
{
	SECTION("TestBuildCurve()")
	{
		OUTPUT_DIRECTORY(nurbs, BuildCurve/BuildCurve);
		std::vector<Point3> poles;
		Point3 p1(0.0, 0.0, 0.0);
		Point3 p2(-0.1, 1.0, -0.2);
		Point3 p3(0.1, 2.0, -0.1);
		Point3 p4(0.2, 3.0, 0.1);
		Point3 p5(0.1, 4.0, 0.0);
		Point3 p6(0.0, 5.0, -0.1);
		poles.push_back(p1);
		poles.push_back(p2);
		poles.push_back(p3);
		poles.push_back(p4);
		poles.push_back(p5);
		poles.push_back(p6);
		bool isPeriodic = false;
		int degree = NURBSAPIBuildCurve::ValidMaxDegree(static_cast<int>(poles.size()), isPeriodic);
		degree = std::min(3, degree);
		auto curve = NURBSAPIBuildCurve::BuildCurve(poles, degree, isPeriodic);
		Point3 sp1 = curve->StartPoint();
		Point3 ep1 = curve->EndPoint();
		CHECK(sp1.X() == Approx(p1.X()));
		CHECK(sp1.Y() == Approx(p1.Y()));
		CHECK(sp1.Z() == Approx(p1.Z()));
		CHECK(ep1.X() == Approx(p6.X()).margin(1e-7));
		CHECK(ep1.Y() == Approx(p6.Y()).margin(1e-7));
		CHECK(ep1.Z() == Approx(p6.Z()).margin(1e-7));
		CHECK(curve->Degree() == degree);
		CHECK(curve->NPoles() == 6);
		CHECK(curve->IsPeriodic() == false);
		vector<Point3> vec = curve->Poles();
		CHECK(vec.size() == 6);
		CHECK(vec[0].X() == Approx(p1.X()));
		CHECK(vec[0].Y() == Approx(p1.Y()));
		CHECK(vec[0].Z() == Approx(p1.Z()));
		CHECK(vec[1].X() == Approx(p2.X()));
		CHECK(vec[1].Y() == Approx(p2.Y()));
		CHECK(vec[1].Z() == Approx(p2.Z()));
		CHECK(vec[2].X() == Approx(p3.X()));
		CHECK(vec[2].Y() == Approx(p3.Y()));
		CHECK(vec[2].Z() == Approx(p3.Z()));
		CHECK(vec[3].X() == Approx(p4.X()));
		CHECK(vec[3].Y() == Approx(p4.Y()));
		CHECK(vec[3].Z() == Approx(p4.Z()));
		CHECK(vec[4].X() == Approx(p5.X()));
		CHECK(vec[4].Y() == Approx(p5.Y()));
		CHECK(vec[4].Z() == Approx(p5.Z()));
		CHECK(vec[5].X() == Approx(p6.X()));
		CHECK(vec[5].Y() == Approx(p6.Y()));
		CHECK(vec[5].Z() == Approx(p6.Z()));
		OCCTIO::OCCTTool::Write(MakeVertex(p1), outdir + "p1.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p2), outdir + "p2.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p3), outdir + "p3.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p4), outdir + "p4.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p5), outdir + "p5.brep");
		OCCTIO::OCCTTool::Write(MakeVertex(p6), outdir + "p6.brep");
		OCCTIO::OCCTTool::Write(MakeEdge(curve), outdir + "result.brep");
	}}