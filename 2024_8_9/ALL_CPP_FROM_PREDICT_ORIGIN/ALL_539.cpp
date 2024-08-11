 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBlend.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: NURBSAPIBlend::BlendCurves ", "[nurbs][Blend][fixbug]")
{
	std::shared_ptr<Geom3BSplineCurve> curve1 = readBRepCurve(inputDirPath + "curve1.brep");
	std::shared_ptr<Geom3BSplineCurve> curve2 = readBRepCurve(inputDirPath + "curve2.brep");
	SECTION("Test1: continuity type is C0")
	{
		std::vector<double> parameters1;
		parameters1.push_back(0.0);
		parameters1.push_back(0.2);
		parameters1.push_back(0.4);
		parameters1.push_back(0.6);
		parameters1.push_back(0.8);
		parameters1.push_back(1.0);
		std::vector<double> parameters2;
		parameters2.push_back(0.0);
		parameters2.push_back(0.2);
		parameters2.push_back(0.4);
		parameters2.push_back(0.6);
		parameters2.push_back(0.8);
		parameters2.push_back(1.0);
		auto blendCurve = NURBSAPIBlend::BlendCurves(curve1, true, ContinuityType::C0, parameters1, curve2, true, ContinuityType::C0, parameters2);
		CHECK(blendCurve->Continuity() == ContinuityType::C0);
	}}